h = "E9E3FF32303235D1DE65D8C36D34F5C161D9C368F5DE65C63468F56D336DC8616EDEDFF5C1DFD7"
ignore = "WhenYhAdaSomeone"
t = ""

for i in range(0, len(h), 2):
    t += chr(int(h[i:i+2], 16))

print(t)

print("\nFlag: ", end="")
for i in range(len(t)):
    if t[i] in ignore or (ord(t[i]) >= 48 and ord(t[i]) <= 57):
        print(t[i], end="")
    else:
        print(chr(ord(t[i]) ^ 0xaa), end="")
