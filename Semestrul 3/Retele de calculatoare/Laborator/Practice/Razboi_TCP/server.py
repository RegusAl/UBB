import os
import socket
import threading
import numpy as np


def generate_random_matrix(n, num_positions):
    matrix = np.zeros((n, n), dtype=int)
    positions_to_mark = np.random.choice(n * n, num_positions, replace=False)
    row_indices, col_indices = np.unravel_index(positions_to_mark, (n, n))
    matrix[row_indices, col_indices] = 1

    return matrix


def handle_client(client_socket):
    client_socket.send("JOC RAZBOI".encode())
    n = int(client_socket.recv(5).decode())
    print(n)
    # generare matrice
    mat = generate_random_matrix(n, n)
    print(mat)
    client_socket.send("JOCUL A INCEPUT!".encode())
    pozitii = 0
    aux_n = n

    while True:

        x = int(client_socket.recv(5).decode())
        y = int(client_socket.recv(5).decode())

        if mat[x][y] == 1:
            aux_n -= 1
            mat[x][y] = 0
            client_socket.send("Da".encode())
        else:
            pozitii += 1
            client_socket.send("Nu".encode())
        print(mat, "\n")
        if pozitii == 5 or aux_n == 0:
            client_socket.send("stop".encode())
            break
        else:
            client_socket.send("ok".encode())

    print("Jocul s-a terminat!")
    client_socket.send("Jocul s-a terminat!!!".encode())
    if aux_n == 0:
        print("Clientul a castigat!")
        client_socket.send("Ati castigat!!!".encode())
    else:
        print("Clientul a pierdut!")
        client_socket.send("Ati pierdut!!!".encode())


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
