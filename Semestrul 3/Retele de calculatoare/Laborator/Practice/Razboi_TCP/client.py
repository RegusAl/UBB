import socket

IP = '0.0.0.0'
PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((IP, PORT))

print(s.recv(50).decode())
n = input("N = ")
s.send(str(n).encode())
print(s.recv(40).decode())

ok = "ok"
while True:
    i = input("i = ")
    j = input("j = ")
    s.send(i.encode())
    s.send(j.encode())
    mesaj = s.recv(100).decode()
    print(mesaj)
    ok = s.recv(50).decode()
    if ok.startswith("stop"):
        break

print(s.recv(100).decode())
print(s.recv(100).decode())

s.close()
