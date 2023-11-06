import socket
from datetime import datetime

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

s.sendto("".encode(), (host, port))
secunde, address = s.recvfrom(100)
print(secunde.decode() + " secunde")

