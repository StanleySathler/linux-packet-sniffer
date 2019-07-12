#include <netinet/tcp.h>

/**
 * @brief Get the total of bytes a TCP header has.
 *
 * @details The Data Offset field contains the total of lines
 *          the header has. Each line has 4 bytes (32 bits).
 *
 * @param ip_header IP Header structure.
 * @return Total of bytes the IP Header has.
 */
unsigned int
ps_tcp_header_length(struct tcphdr* tcp_hdr)
{
  return (tcp_hdr->doff * 4);
}

/**
 * @brief Parse a chunk of binary data into a "tcphdr" structure.
 */
struct tcphdr*
ps_tcp_parse(unsigned char* data)
{
  return (struct tcphdr*)data;
}
