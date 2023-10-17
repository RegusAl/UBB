import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

while 1:
    conn, addr = s.accept()
    print("Connection Address: ", addr)

    nr1 = conn.recv(5).decode()
    if not nr1: break
    print("[Client --> Server] S-a primit: ", nr1)

    numere1 = []
    for i in range(0, int(nr1)):
        numar = conn.recv(10).decode()
        numere1.append(numar)
        print("[Client --> Server] S-a primit: ", numar)

    nr2 = conn.recv(5).decode()
    if not nr2: break
    print("[Client --> Server] S-a primit: ", nr2)

    numere2 = []
    for i in range(0, int(nr2)):
        numar = conn.recv(10).decode()
        numere2.append(numar)
        print("[Client --> Server] S-a primit: ", numar)

    numereComune = []
    for i in numere1:
        for j in numere2:
            if i == j and i not in numereComune:
                numereComune.append(j)

    numereComune = ' '.join(str(x) for x in numereComune)
    print("[Client <-- Server] S-a trimis")
    conn.send(numereComune.encode())

conn.close()
