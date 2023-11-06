import socket

host = '127.0.0.1'
port = 8888

nr1 = str(input("Dati primul numar: "))

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.sendto(nr1.encode(), (host, port))

nr2 = str(input("Dati al doilea numar: "))

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.sendto(nr2.encode(), (host, port))

data, address = s.recvfrom(100)
print(nr1 + " + " + nr2 + " = " + data.decode())