import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

while 1:
    conn, addr = s.accept()
    print("Connection Address: ", addr)

    SIR_CARACTERE = conn.recv(100).decode()
    if not SIR_CARACTERE: break
    print("[Client --> Server] S-a primit: ", SIR_CARACTERE)

    POZ = conn.recv(100).decode()
    if not POZ: break
    print("[Client --> Server] S-a primit: ", POZ)

    NR = conn.recv(100).decode()
    if not NR: break
    print("[Client --> Server] S-a primit: ", NR)

    if len(SIR_CARACTERE) < (int(POZ) + int(NR)):
        conn.send("Datele nu sunt valide!!! Server-ul s-a inchis".encode())
        break

    conn.send("Datele sunt valide!!!".encode())

    SUBSIR = ''
    for i in range(int(POZ), int(POZ)+int(NR)):
        SUBSIR += SIR_CARACTERE[i]

    conn.send(SUBSIR.encode())
    print("[Client <-- Server] S-a trimis: ", SUBSIR)

conn.close()
