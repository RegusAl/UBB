import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((host, port))

while True:
    sir, address = s.recvfrom(100)
    caracter, address = s.recvfrom(10)
    poz = []
    sir = sir.decode()
    for i in range(0, len(sir)):
        if sir[i] == caracter.decode():
            poz.append(i)
    poz = ' '.join(str(x) for x in poz)
    s.sendto(poz.encode(), address)
