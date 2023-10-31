import socket
import os
import threading


def handler(socket_client):
    sir = socket_client.recv(100).decode()
    i = int(socket_client.recv(5).decode())
    l = int(socket_client.recv(5).decode())
    sir_nou = ''
    for c in range(i, i + l):
        sir_nou += sir[c]
    socket_client.send(sir_nou.encode())


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
