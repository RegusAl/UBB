import socket

TCP_ID = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_ID, TCP_PORT))
s.listen(1)

while 1:
    conn, addr = s.accept();
    print("Connection address: ", addr)
    data = conn.recv(100)
    if not data: break
    print("----> Am primit de la Client: " + data.decode())
    data = data[::-1].decode()
    conn.send(data.encode())
    print("----> Am trimis la Client: ", data)
conn.close()
