#include <stdio.h>
#include <ostream>
#include <iostream>
#include <string.h>
#include <vector>
#include "pack109.hpp"
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace pack109;
using namespace std;
#define KEY 42;

// Encrypt/Decrypt text
vec security(vec bytes) {
    vec secure;
    for (int i=0; i<bytes.size(); i++){
        unsigned char c = bytes[i] ^ KEY;
        secure.push_back(c);
	}
    return secure;
}

// for string delimiter
//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main(int argc, char** argv) {
    //declare variables
    bool hostNamePresent = false;
    string address = "";
    string portString = "";
    int port = 0;

    //terminate if less than 2 arguments are given
    if (argc < 2) {
        cout << "Error: Expected mode" << endl;
        cout << "Usage: --hostname address:port" << endl;
        exit(1);
    }

    //parse the input arguments
    for(int i=0; i <argc; i++) {
        if(strcmp(argv[i], "--hostname")==0) {
            string hostNameWPort = argv[i+1];
            vector<string> v1 = split(hostNameWPort, ":");
            address = v1[0];
            portString = v1[1];
            hostNamePresent = true;
        }
    }

    //check if host name is present
    if(hostNamePresent == false) {
        cout << "Error. Hostname not found" << endl;
        exit(1);
    }

    //https://www.tutorialspoint.com/unix_sockets/socket_quick_guide.htm
    //create sockets
    int sockfd, newsockfd, portno;
    socklen_t  clilen;
    char buffer[10000];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    
    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = stoi(portString);
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
        
    /* Now start listening for the clients, here process will
        * go in sleep mode and will wait for the incoming connection
    */
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    cout << "New connection: 127.0.0.1:" << portString << endl;

    vec encryptedVec;
    n = read(newsockfd,buffer,255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    //store the bytes received
    for(int i=0; i<strlen(buffer); i++) {
        encryptedVec.push_back(buffer[i]);
    }

    cout << "Reading " << encryptedVec.size() << " bytes." << endl;

    //decrypt received bytes
    vec decrypted = security(encryptedVec);

    //determine if it is a request/file
    bool messageIsFile = isFile(decrypted);

        //request

        //deserialize the request
        struct File requestedFile = deserialize_fileRequest(decrypted);
        
        //get the name of the file

        //check if file exists

        //if file exists

            //open file and read in memory

            //create a struct and store the bytes

            //serialize the sendfile vec

            //encrypt the serializedSendFile vec

            //then send file to server

        //doesn't exist

            //notify the client
    
    //if it's the file

        //store the file

        //decrypt file contents

        //deserialize the decrypted vector

        //write to a file and store it in the received folder

    return 0;
}