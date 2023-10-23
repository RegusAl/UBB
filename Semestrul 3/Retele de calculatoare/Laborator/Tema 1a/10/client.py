import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

sir1 = input("Sir1: ")
s.send(sir1.encode())

sir2 = input("Sir2: ")
s.send(sir2.encode())

frecv = s.recv(100).decode()
print(frecv)


s.close()