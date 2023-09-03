#include "web_server.hpp"
#include <iostream>


//Main function that runs the web server and takes in the html file path as a parameter 
int main(int argc, char *argv[]) { // argc is the number of arguments, argv is an array of arguments
    // Check if the user provided the path to the HTML file
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path-to-html-file>" << std::endl; // argv[0] is the name of the program 
        return 1;
    }
    // Run the web server
    runWebServer(argv[1]);
    return 0; 
}

