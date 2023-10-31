import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((host, port))

while True:
    nr_binar, address = s.recvfrom(10)
    nr = int(nr_binar.decode(), 2)
    divizor = []
    for i in range(1, nr):
        if nr % i == 0:
            divizor.append(i)
    str_divizori = ' '.join(str(x) for x in divizor)
    s.sendto(str_divizori.encode(), address)

