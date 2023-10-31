import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((host, port))

while True:

    nr1, address = s.recvfrom(1000)
    print("Am primit de la client: ", nr1.decode())

    nr2, address = s.recvfrom(1000)
    print("Am primit de la client: ", nr2.decode())
    nr = str(int(nr1) + int(nr2))

    print("Trimit la client: ", nr)
    s.sendto(nr.encode(), address)
