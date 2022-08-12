#include <stdio.h>
#include <ostream>
#include <iostream>
#include <string.h>
#include <vector>
#include "pack109.hpp"
#include <unistd.h>

using namespace pack109;
using namespace std;

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

    //create sockets

    //store the bytes received

    //determine if it is a request/file

        //request

        //decrypt the request

        //deserialize the request

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