#include <stdio.h>

/**
 * @brief
 *
 * @param char_index
 * @return int
 */
static int
is_end_of_line(int char_index)
{
  return (char_index != 0 && char_index % 32 == 0);
}

/**
 * @brief
 *
 * @param char
 * @param data_size
 */
void
ps_data_print(unsigned char* data, int data_size)
{
  /* For each byte of data */
  for (int i = 0; i < data_size; i++)
  {
    /* If end of line, break the line */
    if (is_end_of_line(i))
      putchar('\n');

    /* If byte data is printable, print it; otherwise, print a dot */
    if (data[i] > 31 && data[i] < 127)
      putchar(data[i]);
    else
      putchar('.');
  }
}
