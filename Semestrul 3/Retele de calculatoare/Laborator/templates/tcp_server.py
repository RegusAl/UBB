import os
import socket
import threading


def handle_client(client_socket):
    client_socket.send(f"[*] Hello from {client_socket[0]}".encode())


def with_thread(s):
    while True:
        client, addr = s.accept()
        print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")
        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()


def main():
    host = '0.0.0.0'
    port = 8888

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((host, port))
    s.listen(5)

    print(f"[*] Listening on {host}:{port}")

    with_thread(s)


main()
