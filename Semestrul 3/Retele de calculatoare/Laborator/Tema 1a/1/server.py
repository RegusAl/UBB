import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

# creare socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

suma = 0

while 1:
    conn, addr = s.accept()
    print("Connection address: ", addr)
    # primeste numarul de numere
    data = conn.recv(10)
    if not data: break
    print("Am primit de la client: ", data.decode())
    # calculeaza suma numerelor primite de la client
    for i in range(0, int(data)):
        numar = conn.recv(10)
        if not numar: break
        print("Am primit de la client: ", numar.decode())
        suma += int(numar)
    # trimite suma la client
    print("Am trimis la client ", suma)
    conn.send((str(suma)).encode())

conn.close()