#include <stdio.h>
#include <stdarg.h>

/**
 * @brief Print a bold text to the stdout.
 */
void
print_bold(const char* format, ...)
{
  va_list args;
  va_start(args, format);

  printf("\033[1m");
  vprintf(format, args);
  printf("\033[0m");

  va_end(args);
}
