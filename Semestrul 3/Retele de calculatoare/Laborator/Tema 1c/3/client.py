import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

sir = input("Sir: ")
s.sendto(sir.encode(), (host, port))

nr_spatii, address = s.recvfrom(100)
print("Numarul de spatii: " + nr_spatii.decode())
