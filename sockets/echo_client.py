import socket

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
    client_socket.connect(('127.0.0.1', 8080))
    client_socket.sendall(b"Hello, world")
    data = client_socket.recv(1024)

print(f"Recieved {data!r}")