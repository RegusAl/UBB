import socket

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

nr_binar = input("dati numarul reprezentat pe un octet: ")
s.sendto(nr_binar.encode(), (host, port))

divizori, address = s.recvfrom(100)
print(divizori.decode())