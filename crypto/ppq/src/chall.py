from Crypto.Util.number import *
from random import random

p = getPrime(1024)
p2 = getPrime(1024)
q = getPrime(512)
n = p * q
e = 0x10001

FLAG = b"CIU2025{Y0u_4r3_v3ry_g00d_1n_RSA_Ch4ll3ng3_09}"

print(f"{p - q = }")
print(f"{p % q = }")
print(f"{p2 - q = }")
print(f"{p2 % q = }")
print(f"c = {pow(bytes_to_long(FLAG), e, n)}")