#include <stdio.h>
#include <netinet/ip.h>

/**
 * @brief: Print details of an IP Packet
 */
void
ps_ip_print(unsigned char* data_content, int data_size)
{
  /* Extract first N bytes from data content */
  struct iphdr* ip_header = (struct iphdr*)data_content;

  /* Print the details */
  /* @todo: implement all the other fields */
  printf("IP Header \n");
  printf("├── Version: ............. %u \n", ip_header->version);
  printf("├── IHL: ................. %u \n", ip_header->ihl);
  printf("├── ToS: ................. %u \n", ip_header->tos);
  printf("├── Total Length: ........ %u \n", ip_header->tot_len);
}
