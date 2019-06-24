#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

int create_socket()
{
  /**
   * AF_INET: IPv4 Internet Protocols
   * SOCK_RAW: Raw network protocol access - data is just a lot of bytes
   */
  int socket_id = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

  /** Socket file descriptor is always a positive number if successful */
  if (socket_id < 0)
  {
    fprintf(stderr, "Couldn't connect to a Socket \n");
    exit(1);
  }

  return socket_id;
}

int
main()
{
  int sock_addr_size;
  int sock_id = create_socket();
  unsigned char* data_buffer = malloc(65536);
  struct sockaddr source_addr;

  /* Keep the program running "forever" */
  while (1)
  {
    /* Read the socket file and write its content in "data_buffer" */
    ssize_t data_size = recvfrom(
      sock_id,
      data_buffer,
      65536,
      0,
      &source_addr,
      sizeof (source_addr)
    );

    /* If data size is less than 0, it means the program couldn't read
     * the socket file
     */
    if (data_size < 0)
    {
      fprintf(stderr, "Couldn't retrieve any data from socket \n");
      break;
    }

    printf("%s\n", data_buffer);
  }

  close(sock_id);
  printf("Closing Packet Sniffer");
  
  return(0);
}
