import os
import socket
import threading

def handle_client(client_socket):
    nr = client_socket.recv(10).decode()
    sum = 0
    for i in range(0, int(nr)):
        sum += int (client_socket.recv(10).decode())
    client_socket.send(str(sum).encode())

def with_thread(s):
    while True:
        client, addr = s.accept()
        print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")
        # creates a Thread object
        # - target: function that the new thread is executing
        # - args: the args passed to the function
        client_handler = threading.Thread(target=handle_client, args=(client, ))
        client_handler.start()

def with_fork(s):
    while True:
        client, addr = s.accept()
        print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")

        child_pid = os.fork()  # creates a child process

        if child_pid == 0:
            handle_client(s)
            os._exit(0)
        else:
            client.close()


def main():

    host = '0.0.0.0'  # IN_ADDR
    port = 8888

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((host, port))
    s.listen(5)

    print(f"[*] Listening on {host}:{port}")

    # with_thread(s)

    with_fork(s)

main()