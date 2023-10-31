import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

nr = input("Dati un numar: ")
s.sendto(nr.encode(), (host, port))

prim, address = s.recvfrom(10)
if prim.decode() == "True":
    print("Prim!")
else:
    print("Nu este prim!")
