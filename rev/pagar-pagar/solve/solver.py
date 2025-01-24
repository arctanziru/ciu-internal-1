from Crypto.Cipher import AES

f = open("../bin/aes.enc", "rb")
data = f.read()
f.close()

key = "y3NqUnA0sP1ZkQUlOUDBho0hXfNjVgbD"
iv = "pxfgpPAqq3YwCCHn"

cipher = AES.new(key, AES.MODE_CBC, iv)
decrypted = cipher.decrypt(data)
print(f"Flag: {decrypted}")
