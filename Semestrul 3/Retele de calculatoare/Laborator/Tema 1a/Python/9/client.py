import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

sir1 = []
n1 = input("N1 = ")
for i in range(0, int(n1)):
    numar = int(input("Numar " + str(i+1) + "= "))
    sir1.append(numar)

s.send(str(sir1).encode())

sir2 = []
n2 = input("N2 = ")
for i in range(0, int(n2)):
    numar = int(input("Numar " + str(i+1) + "= "))
    sir2.append(numar)

s.send(str(sir2).encode())

unice = s.recv(100).decode()
print("Numerele unice din sir1 sunt: ", unice)

s.close()