import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

sir = input("Sir: ")
s.sendto(sir.encode(), (host, port))

caracter = input("Caracterul pentru care se vor pozitiile: ")
s.sendto(caracter.encode(), (host, port))

pozitii, address = s.recvfrom(100)
print("Pozitiile caracterului " + caracter + " : " + pozitii.decode())