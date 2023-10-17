# Un client trimite unui server un sir de caractere si un caracter. Serverul va returna clientului toate pozitiile pe care caracterul primit se regaseste in sir.
import socket

TCP_IP = "127.0.0.1"
TCP_PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

while 1:
    conn, addr = s.accept()
    SIR_CARACTERE = conn.recv(100)
    if not SIR_CARACTERE: break
    SIR_CARACTERE = SIR_CARACTERE.decode()
    print(SIR_CARACTERE)
    CARACTER = conn.recv(10)
    if not CARACTER: break
    CARACTER = CARACTER.decode()
    print(CARACTER)
    poz = ""
    for i in range(0, len(SIR_CARACTERE)):
        if SIR_CARACTERE[i] == CARACTER[0]:
            print("..")
            poz += str(i) + " "
    conn.send(poz.encode())

conn.close()
