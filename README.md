# FileShare: Simplified Client-Server File Sharing System

`FileShare` is a lightweight file sharing system developed in C++. It comprises a server and a client that interact over Unix sockets, providing straightforward file storage and retrieval functionality.

## Project Overview

**File Server**: The server accepts files from clients for storage and can return these files upon request. It's designed to bind a socket to a specified IP address and port, listen for a connection, and handle the client's message, which can be either a `File` or a `Request`. 

**Client**: The client program connects to the server using the provided IP address and port. It can send files for storage or request stored files from the server.

The server can be started with the `--hostname address:port` flag, specifying the server's IP address and port. The server will exit with an error if launched without this flag.

## Functionalities

- The server reads client messages to a buffer and decrypts them for processing.
- Deserializes messages into the appropriate structure (`File` or `Request`).
- For a `File` message, the server stores the file on disk in a folder named `received`.
- For a `Request` message, the server searches for the requested file in the `received` folder.
  - If the file exists, it's read into memory, serialized into a `File` message, encrypted, and sent back to the client.
  - If the file doesn't exist, no response is sent to the client.
- After processing a request, the server will exit, necessitating a restart for further requests.

Please note, this project provides a basic and simplified version of a file sharing system. Enhancements can be made to improve efficiency and add more features.