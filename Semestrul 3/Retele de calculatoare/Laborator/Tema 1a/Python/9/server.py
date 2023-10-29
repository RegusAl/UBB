import ast
import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

while 1:
    conn, addr = s.accept()
    print("Connection Address: ", addr)

    sir1 = conn.recv(100).decode()
    if not sir1: break
    print("Am primit: ", sir1)

    sir2 = conn.recv(100).decode()
    if not sir2: break
    print("Am primit: ", sir2)

    sir1 = ast.literal_eval(sir1)
    sir2 = ast.literal_eval(sir2)

    unice = []
    for i in sir1:
        if i not in sir2 and i not in unice:
            unice.append(i)

    conn.send(str(unice).encode())

conn.close()