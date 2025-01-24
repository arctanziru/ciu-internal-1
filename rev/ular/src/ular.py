secret = [0] * 28

secret[0] = 67
secret[1] = 73
secret[2] = 85
secret[3] = 50
secret[4] = 48
secret[17] = 95
secret[6] = 53
secret[7] = 123
secret[9] = 121
secret[27] = 125
secret[10] = 116
secret[11] = 51
secret[12] = 95
secret[13] = 99
secret[8] = 98
secret[14] = 48
secret[15] = 100
secret[16] = 101
secret[18] = 100
secret[19] = 48
secret[20] = 97
secret[22] = 103
secret[5] = 50
secret[23] = 95
secret[24] = 107
secret[25] = 111
secret[26] = 107
secret[21] = 110

def verify_flag(flag):
    if flag == secret:
        print("Correct! Here's your flag:", secret)
    else:
        print("Incorrect! Try again.")

if __name__ == "__main__":
    user_input = input("Enter the flag: ")
    verify_flag(user_input)
