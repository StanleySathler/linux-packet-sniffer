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
 * @brief Get the total of bytes a given IP header has.
 *
 * @details The "IHL" (Internet Header Length) contains the total
 *          of lines the header has. Each line has 4 bytes (32 bits).
 *
 * @param ip_header IP Header structure.
 * @return Total of bytes the IP Header has.
 */
unsigned int
ps_ip_header_length(struct iphdr* ip_header)
{
  return (ip_header->ihl * 4);
}

/**
 * @brief Parse a chunk of binary data into an "iphdr" structure.
 */
struct iphdr*
ps_ip_parse(unsigned char* data)
{
  return (struct iphdr*)data;
}
