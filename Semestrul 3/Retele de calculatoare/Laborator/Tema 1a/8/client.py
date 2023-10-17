import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

nr1 = input("N1 = ")
s.send(nr1.encode())
print("[Client --> Server] S-a trimis: ", nr1)

for i in range(0, int(nr1)):
    numar = input("Numarul " + str(i+1) + ": ")
    s.send(numar.encode())
    print("[Client --> Server] S-a trimis: ", numar)

nr2 = input("N2 = ")
s.send(nr2.encode())
print("[Client --> Server] S-a trimis: ", nr2)

for i in range(0, int(nr2)):
    numar = input("Numarul " + str(i+1) + ": ")
    s.send(numar.encode())
    print("[Client --> Server] S-a trimis: ", numar)

numereComune = s.recv(100).decode()
print("Numerele comune sunt: ", numereComune)


s.close()

