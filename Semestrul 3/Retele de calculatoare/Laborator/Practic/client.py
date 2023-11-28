import socket

def main():

    TCP_IP = '127.0.0.1'
    TCP_PORT = 8888

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((TCP_IP, TCP_PORT))

    nr = input("Numar: ")
    while nr != '0':
        # print(nr)
        s.send(nr.encode())
        numar_echilibrat = int(s.recv(100).decode())
        print("Numarul echilibrat: ", numar_echilibrat)

        nr = input("Numar: ")

    s.send(nr.encode())


    s.close()

main()
