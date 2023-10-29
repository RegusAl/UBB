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

    CARACTER = conn.recv(100).decode()
    if not CARACTER: break
    print("[Client --> Server] S-a primit: ", CARACTER)

    poz = []
    for i in range(0, len(SIR_CARACTERE)):
        if SIR_CARACTERE[i] == CARACTER[0]:
            poz.append(i)

    poz_str = ' '.join(str(x) for x in poz)
    conn.send(poz_str.encode())
    print("[Client <-- Server] S-a trimis: ", CARACTER)




conn.close()



