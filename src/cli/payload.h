#include <stdio.h>

/**
 * @brief Check if the line has reached its end. Currently we
 *        print 32 bytes per line.
 *
 * @return True if the line has reached its end.
 */
static int
is_end_of_line(int char_index)
{
  return (char_index != 0 && char_index % 32 == 0);
}

/**
 * @brief Print the payload content.
 */
void
ps_payload_print(unsigned char* payload, int payload_size)
{
  /* For each byte of data */
  for (int i = 0; i < payload_size; i++)
  {
    /* If end of line, break the line */
    if (is_end_of_line(i))
      putchar('\n');

    /* If byte data is printable, print it; otherwise, print a dot */
    if (payload[i] > 31 && payload[i] < 127)
      putchar(payload[i]);
    else
      putchar('.');
  }

  putchar('\n');
}
