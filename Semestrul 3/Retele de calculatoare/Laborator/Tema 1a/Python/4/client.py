import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

sir1 = input("Sirul de caractere 1: ")  # ex: aceg
sir2 = input("Sirul de caractere 2: ")  # ex: bdfh

s.send(sir1.encode())
print("[Client]---->[Server]: ", sir1)

s.send(sir2.encode())
print("[Client]---->[Server]: ", sir2)

sirInterclasat = s.recv(200).decode()
print("[Server]---->[Client]: ", sirInterclasat)

print("Sirul interclasat este: ", sirInterclasat)

s.send("".encode())

s.close()
