import socket
import threading
import os

def handle_client(client_socket):
    data = client_socket.recv(100).decode('utf-8')
    print(data)
    nr = 0
    for el in data:
        if el == " ":
            nr += 1
    nr = str(nr).encode()
    client_socket.send(nr)

def with_thread(s):
    while True:
        client, addr = s.accept()
        print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")
        client_handler = threading.Thread(target=handle_client, args=(client, ))
        client_handler.start()

def with_fork(s):
    while True:
        client, addr = s.accept()
        print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")

        child_pid = os.fork()

        if child_pid == 0:
            handle_client(client)
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

    with_thread(s)

    # with_fork(s)

main()
