import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

numar1 = input("Numar 1: ")
s.sendto(numar1.encode(), (host, port))

numar2 = input("Numar 2: ")
s.sendto(numar2.encode(), (host, port))

cmmdc, address = s.recvfrom(100)
cmmmc, address = s.recvfrom(100)

print("CMMDC: ", cmmdc.decode())
print("CMMMC: ", cmmmc.decode())