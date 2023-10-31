import socket
import os
import threading


def divizor(numar):
    poz = []
    for i in range(1, numar + 1):
        if numar % i == 0:
            poz.append(i)
    return poz


def handler(client_socket):
    numar = (client_socket.recv(10).decode())
    poz = divizor(int(numar))
    divizori = ' '.join(str(x) for x in poz)
    client_socket.send(divizori.encode())


def with_thread(s):
    while True:
        client, address = s.accept()
        print(f"[*] Accepted connection from {address[0]}:{address[1]}")
        client_handler = threading.Thread(target=handler, args=(client,))
        client_handler.start()


def with_fork(s):
    while True:
        client, address = s.accept()
        print(f"[*] Accepted connection from {address[0]}:{address[1]}")

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
