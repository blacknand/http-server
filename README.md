# A simple HTTP 1.0 server
HTTP 1.0 server implementation to learn about communication protocols

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
   - the path of the document as an absoulete URL without the protocol or the domain name
   - the HTTP protocol version 
2. Subsequent lines represent an HTTP header, giving the server information about the type of appropriate data or other data altering its behaviour. These HTTP headers form a block which ends with an empty line.
3. The final block is an optional block which may contain further data mainly used by the ```POST``` method

# The server response
After the connected agent has sent its request, the web server processes it and ultimately returns a response. The server response is similar to the client request.
1. The first line, *the status line*, contains an acknowledgment of the HTTP version and a response status code and finally its human readable meaning
2. Subsequent lines represent specific HTTP headers, giving the client information about the data sent, again the HTTP headers form a block ending with an empty line
3. The final block is a data block which contains the optional data
