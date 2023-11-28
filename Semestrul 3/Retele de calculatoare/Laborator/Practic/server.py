import os
import socket
import threading

def este_numar_echilibrat(numar):
    str_number = str(numar)

    even_digits = [int(digit) for digit in str_number[1::2]]
    odd_digits = [int(digit) for digit in str_number[::2]]

    return sum(even_digits) == sum(odd_digits)

def urmatorul_numar_echilibrat(numar):
    numar_curent = numar + 1
    while not este_numar_echilibrat(numar_curent):
        numar_curent += 1
    return numar_curent


def handle_client(client_socket):
    while True:
        nr = int(client_socket.recv(10).decode())
        print("Numar primit: ", nr)
        if nr == 0:
            break
        nr_echilibrat = urmatorul_numar_echilibrat(nr)
        client_socket.send(str(nr_echilibrat).encode())


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
