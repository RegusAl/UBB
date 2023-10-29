import socket
import threading
import os

def interclasare(s1, s2):
    i = 0
    inter = str()
    while i < len(s1) and i < len(s2):
        inter += s1[i]
        inter += s2[i]
        i += 1
    if i < len(s1):
        inter+= s1[i::]
    elif i < len(s2):
        inter+= s2[i::]
    return inter

def handler(client_socket):
    sir1 = client_socket.recv(100).decode()
    sir2 = client_socket.recv(100).decode()
    sir_interclasat = interclasare(sir1, sir2)
    client_socket.send(sir_interclasat.encode())


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
