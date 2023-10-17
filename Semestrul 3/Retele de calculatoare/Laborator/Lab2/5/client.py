# Un client trimite unui server un numar. Serverul va returna clientului sirul divizorilor acestui numar.

import socket

TCP_IP = "172.30.114.72"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

numar = input("Dati un numar: ")
s.send(numar.encode())
print("---> Am trimis catre server: ", numar)

sir_numere = s.recv(100)
print("<--- Am primit de la server: ", sir_numere)
print("Divizorii numarului " + numar + " este: " +sir_numere.decode())

s.close()
