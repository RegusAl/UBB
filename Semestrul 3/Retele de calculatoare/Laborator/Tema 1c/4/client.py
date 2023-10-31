import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

sir = input("Sir: ")
s.sendto(sir.encode(), (host, port))

oglindit, address = s.recvfrom(100)
print("Oglindutul sirului: " + oglindit.decode())