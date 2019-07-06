#include <netinet/ip.h>

/**
 * @brief: Check if IP Packet's payload is a TCP Segment.
 */
int
ps_ip_is_tcp(struct iphdr* ip_header)
{
  return (ip_header->protocol == 6);
}

/**
 * @brief Parse a chunk of binary data into an "iphdr" structure.
 */
struct iphdr*
ps_ip_parse(unsigned char* data)
{
  return (struct iphdr*)data;
}
