#include <netinet/tcp.h>

/**
 * @brief Parse a chunk of binary data into a "tcphdr" structure.
 */
struct tcphdr*
ps_tcp_parse(unsigned char* data)
{
  return (struct tcphdr*)data;
}
