import sys
from Crypto.Util.number import *
from flag import FLAG

p = getPrime(1024)
q = getPrime(1024)
n = p*q
phi = (p-1)*(q-1)

z = q*(n-(p+q)+1)
e = 0x10001
assert GCD(e, phi) == 1

pt = bytes_to_long(FLAG)
c = pow(pt, e, n)

print(f"{c=}")
print(f"{n=}")
print(f"{z=}")
