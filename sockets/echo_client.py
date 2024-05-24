import socket

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect(("127.0.0.1", 8080))
    s.sendall(b"Hello, world.")
    data = s.recv(1024)

print(f"Recieved data {data!r}")