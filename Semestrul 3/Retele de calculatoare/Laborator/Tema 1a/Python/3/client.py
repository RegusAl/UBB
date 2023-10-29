import socket

TCP_ID = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_ID, TCP_PORT))

sir = input("Dati un sir de caractere: ")
s.send(sir.encode())
print("----> Am trimis la Server: ", sir)

oglindit = s.recv(100).decode()
print("----> Am primit de la Server: ", oglindit)

print("Oglinditul sirului este: ", oglindit)

s.close()
