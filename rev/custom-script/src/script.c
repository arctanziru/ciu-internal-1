#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct Instruction {
    uint16_t opcode;
    uint8_t type;
    uint8_t index;
    int32_t value;
};

void write_instruction(FILE* file, struct Instruction instruction) {
    fwrite(&instruction.opcode, sizeof(instruction.opcode), 1, file);
    fwrite(&instruction.type, sizeof(instruction.type), 1, file);

    if (instruction.type == 0x01) {
        fwrite(&instruction.index, sizeof(instruction.index), 1, file);
        fwrite(&instruction.value, sizeof(instruction.value), 1, file);
    }
}

int main() {
    FILE* file = fopen("script.zs", "wb");
    if (file == NULL) {
        printf("Error: Could not open file for writing\n");
        return 1;
    }

    int predefined_values[] = {
        67, 73, 85, 50, 48, 50, 53, 123, 100, 111, 95, 121,
        48, 117, 95, 108, 49, 107, 101, 95, 109, 121, 95,
        99, 117, 115, 116, 48, 109, 95, 115, 99, 114, 105,
        112, 116, 63, 125
    };

    struct Instruction instructions[] = {
        {0x0004, 0x01, 0, 67},
        {0x0004, 0x01, 2, 85},
        {0x0004, 0x01, 4, 48},
        {0x0004, 0x01, 6, 50},
        {0x0004, 0x01, 7, 53},
        {0x0004, 0x01, 8, 123},
        {0x0004, 0x01, 9, 100},
        {0x0004, 0x01, 12, 121},
        {0x0004, 0x01, 10, 111},
        {0x0004, 0x01, 16, 96},
        {0x0004, 0x01, 11, 19},
        {0x0004, 0x01, 13, 48},
        {0x0004, 0x01, 14, 117},
        {0x0004, 0x01, 15, 95},
        {0x0004, 0x01, 17, 49},
        {0x0004, 0x01, 18, 107},
        {0x0010, 0x01, 11, 5},
        {0x0004, 0x01, 26, 115},
        {0x0004, 0x01, 1, 82},
        {0x0004, 0x01, 19, 101},
        {0x0004, 0x01, 20, 19},
        {0x0004, 0x01, 21, 109},
        {0x0004, 0x01, 22, 121},
        {0x0004, 0x01, 23, 95},
        {0x0004, 0x01, 24, 99},
        {0x0004, 0x01, 25, 117},
        {0x0004, 0x01, 27, 116},
        {0x0010, 0x01, 20, 5},
        {0x0004, 0x01, 28, 48},
        {0x0004, 0x01, 5, 50},
        {0x000C, 0x01, 1, 9},
        {0x0004, 0x01, 29, 109},
        {0x0004, 0x01, 30, 95},
        {0x0004, 0x01, 31, 115},
        {0x0008, 0x01, 16, 12},
        {0x0004, 0x01, 32, 99},
        {0x0004, 0x01, 3, 50},
        {0x0004, 0x01, 33, 114},
        {0x0004, 0x01, 34, 105},
        {0x0004, 0x01, 35, 112},
        {0x0004, 0x01, 36, 116},
        {0x0004, 0x01, 37, 63},
        {0x0004, 0x01, 38, 625},
        {0x0014, 0x01, 38, 5}
    };

    size_t instruction_count = sizeof(instructions) / sizeof(instructions[0]);
    for (size_t i = 0; i < instruction_count; i++) {
        write_instruction(file, instructions[i]);
    }

    fclose(file);
    printf("Script written to 'script.zs'.\n");
    return 0;
}
