#ifndef WEB_SERVER_HPP
#define WEB_SERVER_HPP

#include <string>

// Function that prints an error message and exits the program
void error(const char *msg); 
// Function that returns the HTML response
void runWebServer(const std::string& htmlFilePath);

#endif // WEB_SERVER_HPP
