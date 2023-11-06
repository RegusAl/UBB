import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((host, port))

def cmmdc(n1, n2):
    while n1 != n2:
        if n1 > n2:
            n1 -= n2
        else:
            n2 -= n1
    return n1

def cmmmc(n1, n2):
    d = cmmdc(n1, n2)
    return (n1*n2) / d

while True:
    numar1, address = s.recvfrom(100)
    numar2, address = s.recvfrom(100)
    nr1 = int(numar1.decode(), 2)
    nr2 = int(numar2.decode(), 2)
    numar_cmmdc = cmmdc(nr1, nr2)
    s.sendto(str(numar_cmmdc).encode(), address)
    numar_cmmmc = int(cmmmc(nr1, nr2))
    s.sendto(str(numar_cmmmc).encode(), address)
