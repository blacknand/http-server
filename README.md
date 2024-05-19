# A typical HTTP session
HTTP sessions consist of three phases:
1. The client establishes a TCP connection
2. The client sends a request, and waits for a response
3. The server processes the request, sends back a response which provides a status code and appropriate data

# Establishing a connection
HTTP is a client server protocol, meaning it is the client which establishes the request. Opening a connection in HTTP means initiating a connection in TCP. The default TCP port for a HTTP server on a computer is port 80.

# Sending a client request
Once connection has been established the user-agent can send the request. A client request consists of text directives, seperated by CRLF, divided into three blocks:
1. The first line contains a request method followed by its paramaters:
  - dkkd
