#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/**
 * @brief: Create a socket and append it to a socket file
 * used by the operational system.
 *
 * @return: a file descriptor that points to the socket file.
 */
int
ps_create_socket()
{
  /* AF_INET: IPv4 Protocol */
  /* SOCK_RAW: Raw socket, so we have freedom to handle everything by ourselves */
  /* IPPROTO_TCP: TCP Protocol */
  int socket_file = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

  /* File descriptor is positive if successfull */
  if (socket_file < 0)
  {
    fprintf(stderr, "Couldn't create the socket");
    exit(1);
  }

  return socket_file;
}

/**
 * @brief: Close a socket given a socket file descriptor.
 */
void
ps_close_socket(int socket_descriptor)
{
  close(socket_descriptor);
}
