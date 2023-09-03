# Simple C++ Web Server
This project is a basic example of a simple HTTP web server written in C++. It uses UNIX socket API to handle HTTP requests and responses.

## Features
Basic socket programming with C++
Minimal error handling
Serves a single, hard-coded HTML file
Single-threaded, handles one client at a time
## Prerequisites
C++ compiler (e.g., g++, clang)
UNIX-like operating system (Linux, macOS) and CMake installed
## Installation & Setup
Clone the repository:

```bash
git clone https://github.com/Dominik-Lamcha/Simple_http_server.git
```
Navigate into the project directory:


```bash
cd Simple_http_server
```
Compile the C++ file using CMake tools:

```bash
mkdir build
cd build
cmake ..
make
```
Run the server:

```bash
./SIMPLE_HTTP_SERVER path/to/index.html
```

## Usage
After running the server, navigate to http://localhost:8080 in your web browser. You should see the HTML content served by the server.

## Limitations
The server only serves a single, hard-coded HTML file.
No support for concurrent clients. Each client must wait for the previous one to disconnect before they can be served.
Does not fully parse incoming HTTP requests.
Minimal error handling.
## Contributing
Feel free to fork this repository and contribute. Pull requests are welcome.