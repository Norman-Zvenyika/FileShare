#include <stdio.h>
#include <ostream>
#include <iostream>
#include <string.h>
#include <vector>
#include "pack109.hpp"
#include <unistd.h>

using namespace pack109;
using namespace std;

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