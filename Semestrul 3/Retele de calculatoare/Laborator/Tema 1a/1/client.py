import socket


TCP_IP = "127.0.0.1"
TCP_PORT = 8888

# creare socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

# mesajul initial
MESSAGE = (input("Nr: "))
s.send(MESSAGE.encode())
print("Am trimis la server: ", MESSAGE)

# trimitere sir de numere
for i in range(0, int(MESSAGE)):
    numar = input("Numar " + str(i+1) + ": ")
    s.send(numar.encode())
    print("Am trimis la server: ", numar)

# primeste suma de la server
suma = s.recv(10)
s.close()

print("Suma este: ", suma.decode())


