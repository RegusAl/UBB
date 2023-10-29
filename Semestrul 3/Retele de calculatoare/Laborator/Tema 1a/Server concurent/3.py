import socket
import threading
import os


def handler(client_socket):
    data = client_socket.recv(100).decode()
    data = data[::-1]
    client_socket.send(data.encode())


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
