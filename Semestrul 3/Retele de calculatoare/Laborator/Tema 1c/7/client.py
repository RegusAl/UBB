import socket

host  = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

sir = input("Sir: ")
s.sendto(sir.encode(), (host, port))

i = input("i: ")
s.sendto(i.encode(), (host, port))

l = input("l: ")
s.sendto(l.encode(), (host, port))

subsir, address = s.recvfrom(100)
print("Subsir: ", subsir.decode())
