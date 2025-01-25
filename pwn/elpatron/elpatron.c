#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chaleco = 3;
int balas = 3;

void cajaFuerteSecreta() {
    puts("Felicidades, has derrotado exitosamente a El Patrón.");
    puts("Abriendo la caja fuerte...");
    system("/bin/sh");
}

void comprarEquipo() {
    char s[112];
    puts("Veo que estás intentando comprar más equipos, qué quieres comprar?");
    printf("> ");
    fgets(s, 520, stdin);
    puts("Entendido, déjame mirar en el inventario.");
}

void init() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void menu() {
    puts("Bienvenidos a CIU2025!");
    puts("Tienes un kit de armas");
    puts("1. balas de pistola");
    puts("2. chaleco antibalas");
    puts("3. comprar mas equipos");
}

void balasDePistola() {
    if (balas <= 0) {
        puts("Te quedaste sin balas!");
        return;
    }
    puts("tu usas balas...");
    balas--;
}

void chalecoAntiBalas() {
    if (chaleco <= 0) {
        puts("Te quedaste sin chalecos!");
        return;
    }
    puts("tu usas chalecos...");
    chaleco--;
}

int main() {
    int choice;
    int running;
    init();

    running = 1;

    do {
        menu();
        printf("> ");
        scanf("%d", &choice);
        getchar();

        if (choice == 3) {
            comprarEquipo();
            continue;
        } if (choice <= 3) {
            if (choice == 2) {
                chalecoAntiBalas();
                continue;
            } if (choice <= 2) {
                if (choice == -1) {
                    running = 0;
                    continue;
                } if (choice == 1) {
                    balasDePistola();
                    continue;
                }
            }
        }
        puts("Tu elección es incorrecta");
        puts("");
    }
    while (running);
    puts("Adios amigo!");
    return 0;
}