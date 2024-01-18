import socket
import sys
def main():
    print(sys.argv)
    TCP_IP = sys.argv[1]
    TCP_PORT = 8888

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((TCP_IP, TCP_PORT))

    MESSAGE = (input("Mesaj: "))
    s.send(MESSAGE.encode())

    MESSAGE_SERVER = s.recv(100).decode()
    s.close()

    print(MESSAGE_SERVER)

main()

