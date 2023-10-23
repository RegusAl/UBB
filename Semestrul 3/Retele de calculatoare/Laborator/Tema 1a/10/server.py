import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

def string_to_array(string):
    return [c for c in string]

while 1:
    conn, addr = s.accept()
    print("Connection Address: ", addr)

    sir1 = conn.recv(100).decode()
    if not sir1: break
    print("Am primit: ", sir1)

    sir2 = conn.recv(100).decode()
    if not sir2: break
    print("Am primit: ", sir2)

    sir1 = string_to_array(sir1)
    sir2 = string_to_array(sir2)
    print(sir1)

    frecv = [0] * 200
    for i in range(0, min(len(sir1), len(sir2))):
        if sir1[i] == sir2[i]:
            frecv[ord(sir1[i])] += 1

    nr_max = 0
    max = ''
    for i in frecv:
        if nr_max < frecv[i]:
            max = chr(i)


    print(max)
    conn.send(str(max).encode())


conn.close()