#include <stdio.h>
#include <time.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <core/parser/tcp.h>

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
  struct tcphdr* tcp_header = ps_tcp_parse(data_content + ip_header_len);

  /* Print TCP Packet details */
  printf("└──└─ TCP ");
  printf("%u > %u (", tcp_header->source, tcp_header->dest);
  printf("cksum 0x%x, ", tcp_header->check);
  printf("seq %u, ", tcp_header->seq);
  printf("ack %u, ", tcp_header->ack_seq);
  printf("win %u", tcp_header->window);
  printf(") \n");
}
