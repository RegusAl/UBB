import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

SIR_CARACTERE = input("Dati sirul de caractere: ")
s.send(SIR_CARACTERE.encode())
print("[Client --> Server] S-a trimis: ", SIR_CARACTERE)

POZ = input("Dati pozitia de unde va incepe subsirul: ")
s.send(POZ.encode())
print("[Client --> Server] S-a trimis: ", POZ)

NR = input("Dati numarul de caractere a subsirului: ")
s.send(NR.encode())
print("[Client --> Server] S-a trimis: ", NR)

valid = s.recv(50).decode()
print(valid)

SUBSIR = s.recv(100).decode()
print(SUBSIR)

s.close()


