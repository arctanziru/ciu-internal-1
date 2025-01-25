#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win()
{
  printf("Congratulations! You found the win() function!\n");
  exit(1);
}

void call_me(int a, int b, int c)
{
  if (a == 0xdeadbeef && b == 0xcafebabe && c == 0x8badf00d)
  {
    printf("Congratulations! You found the win() function!\n");
    system("/bin/sh");
  }
  else
  {
    printf("Wrong arguments! Try again.\n");
    exit(1);
  }
}

void vuln()
{
  char buffer[64];
  printf("Enter some data: ");
  fflush(stdout);
  fgets(buffer, 128, stdin);
  printf("You entered: %s\n", buffer);
}

int main()
{
  setvbuf(stdout, NULL, _IONBF, 0);
  printf("No matter where you go, always return to me.\n");
  vuln();
  return 0;
}
