import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((host, port))

while True:
    sir, address = s.recvfrom(100)
    oglindit = sir.decode()[::-1]
    s.sendto(oglindit.encode(), address)