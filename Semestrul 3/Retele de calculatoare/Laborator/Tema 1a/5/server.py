import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

def divizori(numar):
    poz = []
    for i in range(1, numar+1):
        if numar % i == 0:
            poz.append(i)
    return poz


while 1:
    conn, addr = s.accept()
    print("Connection address: ", addr)
    NUMAR = conn.recv(10).decode()
    if not NUMAR: break
    print("[Client --> Server] S-a primit: ", NUMAR)
    poz = divizori(int(NUMAR))
    DIVIZORI = ' '.join(str(x) for x in poz)
    conn.send(DIVIZORI.encode())
    print("[Client <-- Server] S-a trimis: ", DIVIZORI)
conn.close()