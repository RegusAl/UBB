import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((host, port))


def prim(number):
    if number == 1:
        return False
    if number == 2:
        return True
    for i in range(2, number):
        if number % i == 0:
            return False
    return True


while True:
    nr, address = s.recvfrom(10)
    print("Am primit numarul ", nr.decode())

    s.sendto(str(prim(int(nr.decode()))).encode(), address)
