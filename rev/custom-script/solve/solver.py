f = open("../bin/script.zs", "rb")
data = f.read()
f.close()

variables = [0] * 256

i = 0
while i < len(data):
    # opcode: u16
    # type: u8
    # index: u8
    # value: u32

    opcode = data[i] | (data[i+1] << 8)
    type = data[i+2]

    if opcode == 0x0004: # SET_VAR_INT
        if type == 0x01:
            index = data[i+3]
            value = data[i+4] | (data[i+5] << 8) | (data[i+6] << 16) | (data[i+7] << 24)

            print(f"SET_VAR_INT {index} {value}")

            variables[index] = value
            i += 8
    elif opcode == 0x0008: # ADD_VAL_TO_INT_VAR
        if type == 0x01:
            index = data[i+3]
            value = data[i+4] | (data[i+5] << 8) | (data[i+6] << 16) | (data[i+7] << 24)

            print(f"ADD_VAL_TO_INT_VAR {index} {value}")

            variables[index] += value
            i += 8
    elif opcode ==0x000C: # SUB_VAL_FROM_INT_VAR
        if type == 0x01:
            index = data[i+3]
            value = data[i+4] | (data[i+5] << 8) | (data[i+6] << 16) | (data[i+7] << 24)

            print(f"SUB_VAL_FROM_INT_VAR {index} {value}")

            variables[index] -= value
            i += 8
    elif opcode == 0x0010: # MULT_INT_VAR_BY_VAL
        if type == 0x01:
            index = data[i+3]
            value = data[i+4] | (data[i+5] << 8) | (data[i+6] << 16) | (data[i+7] << 24)

            print(f"MULT_INT_VAR_BY_VAL {index} {value}")

            variables[index] *= value
            i += 8
    elif opcode == 0x0014: # DIV_INT_VAR_BY_VAL
        if type == 0x01:
            index = data[i+3]
            value = data[i+4] | (data[i+5] << 8) | (data[i+6] << 16) | (data[i+7] << 24)

            print(f"DIV_INT_VAR_BY_VAL {index} {value}")

            variables[index] /= value
            i += 8

print("\nFlag: ", end="")
for i in range(256):
    print(f"{chr(int(variables[i]))}", end="")
