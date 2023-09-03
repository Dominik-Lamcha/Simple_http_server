#include "web_server.hpp"
#include <iostream>       // std::cerr
#include <fstream>        // std::ifstream
#include <sstream>        // std::stringstream
#include <cstring>        // memset
#include <unistd.h>       // close
#include <sys/types.h>    // socket
#include <sys/socket.h>   // socket
#include <netinet/in.h>   // socket
#include <arpa/inet.h>    // socket

// Function that prints an error message and exits the program
void error(const char *msg) {
    perror(msg);  // perror prints the error message to stderr
    exit(1); 
}

// Function that returns the HTML response
std::string getHtmlResponse(const std::string& htmlFilePath) {
    std::ifstream htmlFile(htmlFilePath); // Open the HTML file
    if (!htmlFile) {
        error("Could not open HTML file"); // Print an error message and exit the program if the HTML file could not be opened
    }
    
    std::stringstream buffer; // Read the HTML file into the buffer
    buffer << htmlFile.rdbuf(); // Read the buffer into a string
    
    std::string htmlContent = buffer.str(); // Get the HTML content from the string
    
    return "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n" + htmlContent; 
}

// Function that runs the web server and takes in the html file path as a parameter
void runWebServer(const std::string& htmlFilePath) {
    int sockfd, newsockfd, portno; // sockfd and newsockfd are file descriptors, portno stores the port number
    socklen_t clilen; // clilen stores the size of the address of the client
    char buffer[256]; // buffer stores the message from the client
    struct sockaddr_in serv_addr, cli_addr; // serv_addr stores the server address, cli_addr stores the client address
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a new socket
    if (sockfd < 0) {
        error("ERROR opening socket");  // Print an error message and exit the program if the socket could not be opened
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr)); // Clear serv_addr to 0 using memset
    portno = 8080; // Set the port number to 8080
    serv_addr.sin_family = AF_INET; // Set the address family to AF_INET (IPv4) 
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Set the IP address to the localhost
    serv_addr.sin_port = htons(portno); // Convert the port number to network byte order and store it in serv_addr

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    listen(sockfd, 5);  // Listen for connections on the socket, allow no more than 5 connections to wait
    clilen = sizeof(cli_addr);  // Get the size of cli_addr


    // Accept connections in a loop
    while (true) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen); // Accept a connection on the socket
        if (newsockfd < 0) {
            error("ERROR on accept");  // Print an error message and exit the program if the connection could not be accepted
        }

        memset(buffer, 0, 256);  // Clear buffer to 0 using memset
        n = read(newsockfd, buffer, 255);  // Read the message from the client into buffer
        if (n < 0) {
            error("ERROR reading from socket"); // Print an error message and exit the program if the message could not be read
        }

        std::string htmlResponse = getHtmlResponse(htmlFilePath);  // Get the HTML response

        n = write(newsockfd, htmlResponse.c_str(), htmlResponse.size()); // Write the HTML response to the client
        if (n < 0) {
            error("ERROR writing to socket"); // Print an error message and exit the program if the message could not be written
        }

        close(newsockfd); // Close the connection
    }

    close(sockfd);  // Close the socket
}
