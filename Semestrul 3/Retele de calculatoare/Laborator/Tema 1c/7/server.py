import socket

host  = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((host, port))

while True:
    sir, address = s.recvfrom(100)
    i, address = s.recvfrom(10)
    l, address = s.recvfrom(10)
    subsir = ""
    for x in range(int(i.decode()), int(i.decode())+int(l.decode())):
        subsir += sir.decode()[x]
    s.sendto(subsir.encode(), address)


