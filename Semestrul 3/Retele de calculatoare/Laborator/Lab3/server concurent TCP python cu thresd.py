import socket
import threading

def handle_client(client_socket):
    data = client_socket.recv(1024).decode('utf-8')
    count_s = data.count('s')
    
    response = f'Numărul de litere "s" din șir: {count_s}\n'
    client_socket.send(response.encode('utf-8'))
    client_socket.close()

host = '0.0.0.0'
port = 12345

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen(5)

print(f"[*] Listening on {host}:{port}")

while True:
    client, addr = server.accept()
    print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")
    client_handler = threading.Thread(target=handle_client, args=(client,))
    client_handler.start()