import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)


def interclasare(s1, s2):
    i = 0
    inter = str()
    while i < len(s1) and i < len(s2):
        inter += s1[i]
        inter += s2[i]
        i += 1
    if i < len(s1):
        inter+= s1[i::]
    elif i < len(s2):
        inter+= s2[i::]
    return inter


while 1:
    conn, addr = s.accept()
    print("Connection address: ", addr)

    sir1 = conn.recv(100).decode()
    if not sir1: break
    print("[Client]---->[Server]: ", sir1)

    sir2 = conn.recv(100).decode()
    if not sir2: break
    print("[Client]---->[Server]: ", sir2)

    interclasat = interclasare(sir1, sir2)
    conn.send(interclasat.encode())
    print("[Server]---->[Client]: ", interclasat)

    data = conn.recv(10).decode()
    if data == "": break

conn.close()
