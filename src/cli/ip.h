#include <stdio.h>
#include <time.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <core/parser/ip.h>

/**
 * @brief: Print details of an IP Packet.
 */
void
ps_ip_print(unsigned char* data_content, int data_size)
{
  /* Extract first N bytes from data content */
  struct iphdr* ip_header = ps_ip_parse(data_content);

  /* Get current time */
  time_t secs_since_epoch = time(NULL);
  struct tm* time = localtime(&secs_since_epoch);

  /* Print line with details  */
  printf("%02d:%02d:%02d IP ", time->tm_hour, time->tm_min, time->tm_sec);
  printf("192.168.0.17 > 192.168.0.21 (");
  printf("tos 0x%x, ", ip_header->tos);
  printf("ttl %u, ", ip_header->ttl);
  printf("id %u, ", ip_header->id);
  printf("offset %u, ", ip_header->frag_off);
  printf("proto %u, ", ip_header->protocol);
  printf("length %u", ip_header->tot_len);
  printf(") \n");
}
