import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

NUMAR = input("Dati numarul pentru care vreti sa aflati divizorii: ")
s.send(NUMAR.encode())
print("[Client --> Server] S-a trimis: ", NUMAR)

SIR_DIVIZORI = s.recv(100).decode()
print("[Client <-- Server] S-a primit: ", SIR_DIVIZORI)

print("Sirul de divizori este: ", SIR_DIVIZORI)

s.close()
