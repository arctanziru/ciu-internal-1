#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void vuln()
{
  char buffer[64];
  printf("To make your life eaaasy, address of buffer: %p\n", buffer);
  printf("Enter your note: ");
  fflush(stdout);
  gets(buffer);
  printf("Your note:\n%s\n", buffer);
}

int main()
{
  printf("===== Note =====\n");
  vuln();
  return 0;
}
