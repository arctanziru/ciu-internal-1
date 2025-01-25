import os
import base64
from Crypto.Util.number import bytes_to_long, getPrime
from Crypto.Cipher import AES
import binascii
import random

def generate_rsa_keys(bits=1024, e=3):
    while True:
        p = getPrime(bits // 2)
        q = getPrime(bits // 2)
        n = p * q
        phi = (p - 1) * (q - 1)
        if phi % e != 0:
            break
    d = pow(e, -1, phi)
    return ((e, n), (d, n))

def cube_root(n):
    lo = 0
    hi = n
    while lo < hi:
        mid = (lo + hi) // 2
        if mid ** 3 < n:
            lo = mid + 1
        else:
            hi = mid
    return lo

def random_with_N_digits(n):
    range_start = 10**(n-1)
    range_end = (10**n)-1
    return random.randint(range_start, range_end)

def generate_iv():
    iv = random_with_N_digits(16)
    seed = os.urandom(2)
    seed = int(binascii.hexlify(seed), 16)
    random.seed(seed)
    key = random.randint(0, 9999999999999999)

    return bytes(str(iv^key), 'utf-8')

def aes_encrypt(message, aes_key, iv):
    output = "error encryption"
    try:
        cipher = AES.new(aes_key, AES.MODE_CBC, iv)
        encrypted_message = cipher.encrypt(message.encode())
        output = base64.b64encode(encrypted_message).decode('utf-8')
    except:
        print("Encryption error! Retrying...")

    return output
    
flag = "CIU2025{REDACTED}"
aes_key = os.urandom(32)
iv = generate_iv()
encrypted_message = aes_encrypt(flag, aes_key, iv)

e = 3
public_keys = [generate_rsa_keys(e=e)[0] for _ in range(e)]
private_keys = [generate_rsa_keys(e=e)[1] for _ in range(e)]

message_int = bytes_to_long(aes_key)

ciphertexts = [pow(message_int, e, n) for e, n in public_keys]

ciphertexts_provided = [ct for ct in ciphertexts]
public_keys_provided = [(e, n) for e, n in public_keys]

with open('encrypted.txt', 'w') as f:
    f.write("Encrypted Message: ")
    f.write('\n')
    f.write(str(encrypted_message))
    f.write('\n')
    f.write("Initialization Vector (IV): ")
    f.write('\n')
    f.write(iv)
    f.write('\n')
    f.write("Ciphertexts: ")
    f.write('\n')
    f.write(str(ciphertexts_provided))
    f.write('\n')
    f.write("Public Keys: ")
    f.write('\n')
    f.write(str(public_keys_provided))
    print('\n')
    