import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

SIR_CARACTERE = input("Dati un sir de caractere: ")
s.send(SIR_CARACTERE.encode())
print("[Client --> Server] S-a trimis: ", SIR_CARACTERE)

CARACTER = input("Caracterul caruia vreti sa-i aflati pozitiile: ")
s.send(CARACTER.encode())
print("[Client --> Server] S-a trimis: ", CARACTER)

POZITII = s.recv(100).decode()
print("[Client <-- Server] S-a primit: ", POZITII)
print("Pozitiile caracterului " + CARACTER + " in sirul de caractere: ", POZITII)


s.close()