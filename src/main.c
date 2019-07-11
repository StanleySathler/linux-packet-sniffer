#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <core/socket/socket.h>
#include <cli/ip.h>
#include <cli/tcp.h>
#include <cli/data.h>

#define PACKET_CONTENT_SIZE 65536

void
print_packets(unsigned char *data_content, int data_size);

int
main()
{
  /* Socket address size in bytes */
  unsigned int s_address_size;

  /* Socket address details */
  struct sockaddr s_address;

  /* Received data size in bytes */
  int recv_data_size;

  /* Packet data content */
  unsigned char* recv_data_content = malloc(PACKET_CONTENT_SIZE);

  /* File descriptor pointing to a socket buffer */
  int socket_fd = ps_create_socket();

  /* Keep the program running "forever" */
  while(1)
  {
    s_address_size = sizeof(s_address);

    /* Receive data from socket file */
    recv_data_size = recvfrom(
      socket_fd,
      recv_data_content,
      PACKET_CONTENT_SIZE,
      0,
      &s_address,
      &s_address_size
    );

    if (recv_data_size < 0)
    {
      fprintf(stderr, "Received data length is less than 0, which means there was an error");
      break;
    }

    print_packets(recv_data_content, recv_data_size);
  }

  /* Close socket, so the file descriptor can be reused
   * by any other program.
   */
  ps_close_socket(socket_fd);

  return 0;
}

/**
 * @brief Convert a chunk of bytes into an unpacked data, then
 *        decide which handler should be chosen based on the
 *        packet protocol.
 */
void
print_packets(unsigned char* data_content, int data_size)
{
  /* Parse IP Header */
  struct iphdr* ip_header = ps_ip_parse(data_content);
  unsigned int ip_hdlen = ps_ip_header_length(ip_header);

  /* Parse TCP Header */
  struct tcphdr* tcp_hdr = ps_tcp_parse(data_content + ip_hdlen);
  unsigned int tcp_hdlen = ps_tcp_header_length(tcp_hdr);

  /* Print IP Packet details */
  ps_ip_print(ip_header);

  /* If TCP, print TCP Segment details */
  if (ps_ip_is_tcp(ip_header))
    ps_tcp_print((data_content + ip_hdlen), (data_size - ip_hdlen));

  /* 1 - ICMP Protocol */
  /* else if (ip_header->protocol == 1) */
  /*   ps_icmp_parse(data_content, data_size); */

  /* 17 - UDP Protocol */
  /* else if (ip_header->protocol == 17) */
  /*   ps_udp_parse(data_content, data_size); */

  ps_data_print(data_content, data_size);

  printf("\n");
}
