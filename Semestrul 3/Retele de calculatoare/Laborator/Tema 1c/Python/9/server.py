import socket
from datetime import datetime

host = '127.0.0.1'
port = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((host, port))

while True:

    cerere, address = s.recvfrom(100)
    current_datetime = datetime.now()
    epoch = datetime(1970, 1, 1)
    time_difference = current_datetime - epoch
    timestamp = int(time_difference.total_seconds())
    s.sendto(str(timestamp).encode(), address)