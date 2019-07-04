#include <stdio.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

/**
 * @brief: Print TCP packet details.
 */
void
ps_tcp_print(unsigned char* data_content, int data_size)
{
  /* Extract first N bytes from data content */
  struct iphdr* ip_header = (struct iphdr*)data_content;

  /* IHL is the total of lines. Each line has 4 bytes (32 bits) */
  unsigned short ip_header_len = (ip_header->ihl * 4);

  /* Extract first N bytes after the IP Header */
  struct tcphdr* tcp_header = (struct tcphdr*)(data_content + ip_header_len);

  /* @todo: print IP packet */

  /* Print TCP Packet details */
  printf("TCP Header \n");
  printf("├── Source Port: ............ %u \n", ntohs(tcp_header->source));
  printf("├── Destination Port: ....... %u \n", ntohs(tcp_header->dest));
  printf("├── Sequence Number: ........ %u \n", ntohl(tcp_header->seq));
  printf("├── ACK Number: ............. %u \n", ntohl(tcp_header->ack_seq));
  printf("├─────────────────────────────── \n");
}
