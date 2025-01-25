#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win() {
    puts("Tidak ada Jiko yang aman!!!.");
    system("/bin/sh");
}

int vuln() {
    char buffer[100];

    printf("Kirim jiko kamu di sini: ");
    fgets(buffer, sizeof(buffer), stdin);

    printf("Jiko kamu: ");
    printf(buffer);
    puts("");

    exit(1);
}

int main(int argc, char **argv) {
    vuln();
    return 0;
}