#include <stdio.h>
#include <time.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <cli/text.h>
#include <core/parser/ip.h>

/**
 * @brief Print the details of an IP Packet.
 */
void
ps_ip_print(struct iphdr* ip_header)
{
  /* Structs to properly handle binaries representing IP addresses */
  struct sockaddr_in source_addr, dest_addr;
  memset(&source_addr, 0, sizeof(struct sockaddr_in));
  memset(&dest_addr, 0, sizeof(struct sockaddr_in));
  source_addr.sin_addr.s_addr = ip_header->saddr;
  dest_addr.sin_addr.s_addr = ip_header->daddr;

  /* Get current time */
  time_t secs_since_epoch = time(NULL);
  struct tm* time = localtime(&secs_since_epoch);

  /* Print time line */
  printf("┌─ ");
  print_bold("%02d:%02d:%02d \n", time->tm_hour, time->tm_min, time->tm_sec);

  /* Print IP line */
  printf("├─ ");
  printf("IP %s > %s (", inet_ntoa(source_addr.sin_addr), inet_ntoa(dest_addr.sin_addr));
  printf("tos 0x%x, ", ip_header->tos);
  printf("ttl %u, ", ip_header->ttl);
  printf("id %u, ", ip_header->id);
  printf("offset %u, ", ip_header->frag_off);
  printf("proto %u, ", ip_header->protocol);
  printf("length %u", ip_header->tot_len);
  printf(") \n");
}
