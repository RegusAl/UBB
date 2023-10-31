import socket
import os
import threading


def handler(client_socket):
    nr1 = client_socket.recv(5).decode()
    numere1 = []
    for i in range(0, int(nr1)):
        numar = client_socket.recv(10).decode()
        numere1.append(numar)

    nr2 = client_socket.recv(5).decode()
    numere2 = []
    for i in range(0, int(nr2)):
        numar = client_socket.recv(10).decode()
        numere2.append(numar)

    numereComune = []
    for i in numere1:
        for j in numere2:
            if i == j and i not in numereComune:
                numereComune.append(j)

    numereComune = ' '.join(str(x) for x in numereComune)
    client_socket.send(numereComune.encode())


def with_thread(s):
    while True:
        client, address = s.accept()
        print(f"[*] Accepted connection on {address[0]}:{address[1]}")
        client_handler = threading.Thread(target=handler, args=(client,))
        client_handler.start()


def with_fork(s):
    while True:
        client, address = s.accept()
        print(f"[*] Accepted connection on {address[0]}:{address[1]}")

        child_pid = os.fork()

        if child_pid == 0:
            handler(client)
            os._exit(0)
        else:
            client.close()


def main():
    host = '0.0.0.0'
    port = 8888

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((host, port))
    s.listen(5)

    print(f"[*] Listening on {host}:{port}")

    # with_thread(s)

    with_fork(s)


main()
