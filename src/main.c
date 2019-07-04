#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include "socket/socket.h"
#include "ip/parser.h"

#define PACKET_CONTENT_SIZE 65536

void
unpack_data(unsigned char *data_content, int data_size);

int
main()
{
  /* Socket address size in bytes */
  int s_address_size;

  /* Socket address details */
  struct sockaddr s_address;

  /* Received data size in bytes */
  int recv_data_size;

  /* Packet data content */
  unsigned char* recv_data_content = malloc(PACKET_CONTENT_SIZE);

  /* File descriptor pointing to a socket buffer */
  int socket_fd = ps_create_socket();

  puts("[.] Packet Sniffer has started");

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
      exit(1);
    }

    unpack_data(recv_data_content, recv_data_size);
  }

  /* How do we ensure this is called, since there is
   * an infinite loop right before?
   */
  ps_close_socket(socket_fd);

  puts("[.] Packet Sniffer has been closed");

  return 0;
}

/**
 * @brief: Convert a chunk of bytes into an unpacked data,
 * then decide which handler should be chosen based on the
 * packet protocol.
 */
void
unpack_data(unsigned char* data_content, int data_size)
{
  /* Pick the first N bytes from the data content chunk */
  /* (N = sizeof(iphdr)) */
  struct iphdr* ip_header = (struct iphdr*)data_content;

  /* Show details for IP Packet */
  ps_ip_print(data_content, data_size);

  /* 6 - TCP Protocol */
  // if (ip_header->protocol == 6)
  //   ps_tcp_parse(data_content, data_size);

  /* 1 - ICMP Protocol */
  // else if (ip_header->protocol == 1)
  //   ps_icmp_parse(data_content, data_size);

  /* 17 - UDP Protocol */
  // else if (ip_header->protocol == 17)
  //   ps_udp_parse(data_content, data_size);
}
