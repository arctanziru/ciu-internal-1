#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct Instruction {
    uint16_t pc;
    uint8_t* buffer;
};

int32_t variables[64];

int main()
{
    struct Instruction instruction;
    instruction.pc = 0;
    instruction.buffer = (uint8_t*)malloc(512);

    FILE* file = fopen("script.zs", "rb");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    fread(instruction.buffer, 1, 512, file);
    fclose(file);

    while (instruction.pc < 512) {
        uint16_t opcode = instruction.buffer[instruction.pc];
        instruction.pc += 2;
        uint8_t type = instruction.buffer[instruction.pc++];

        switch (opcode) {
        case 0x0004: // SET_VAR_INT
            if (type == 0x01) {
                uint8_t index = *(uint8_t*)&instruction.buffer[instruction.pc++];
                int32_t value = *(int32_t*)&instruction.buffer[instruction.pc];
                instruction.pc += 4;

                variables[index] = value;
            }

            break;
        case 0x0008: // ADD_VAL_TO_INT_VAR
            if (type == 0x01) {
                uint8_t index = *(uint8_t*)&instruction.buffer[instruction.pc++];
                int32_t value = *(int32_t*)&instruction.buffer[instruction.pc];
                instruction.pc += 4;

                variables[index] += value;
            }

            break;
        case 0x000C: // SUB_VAL_FROM_INT_VAR
            if (type == 0x01) {
                uint8_t index = *(uint8_t*)&instruction.buffer[instruction.pc++];
                int32_t value = *(int32_t*)&instruction.buffer[instruction.pc];
                instruction.pc += 4;

                variables[index] -= value;
            }

            break;
        case 0x0010: // MULT_INT_VAR_BY_VAL
            if (type == 0x01) {
                uint8_t index = *(uint8_t*)&instruction.buffer[instruction.pc++];
                int32_t value = *(int32_t*)&instruction.buffer[instruction.pc];
                instruction.pc += 4;

                variables[index] *= value;
            }

            break;
        case 0x0014: // DIV_INT_VAR_BY_VAL
            if (type == 0x01) {
                uint8_t index = *(uint8_t*)&instruction.buffer[instruction.pc++];
                int32_t value = *(int32_t*)&instruction.buffer[instruction.pc];
                instruction.pc += 4;

                variables[index] /= value;
            }

            break;
        }
    }

    for (int i = 0; i < 64; i++) {
        printf("%d,", variables[i]);
    }   

    free(instruction.buffer);
    return 0;
}
