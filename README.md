# Minitalk

A small communication program from the 42 curriculum that uses UNIX signals to send messages between processes.

## About

**Minitalk** is a project where two programs communicate using only UNIX signals (`SIGUSR1` and `SIGUSR2`).

The goal is to implement a simple client-server communication system where:
- The **server** receives and displays messages
- The **client** sends messages to the server
- Communication happens bit by bit using signals only

---

## How It Works

Each character is converted into binary and sent bit by bit:
- `SIGUSR1` → represents bit `0`
- `SIGUSR2` → represents bit `1`

The server reconstructs the message from received bits and prints it.

---

## Features

- Client-server architecture
- Signal-based communication (no sockets, no pipes)
- Character-by-character transmission
- Reliable message reconstruction
- Support for full strings
- Server displays its own PID for client connection

---

## Usage

- Start the server
```bash
./server
```

- The server will print its PID, for example:

```bash
Server PID: 12345
```

- Send a message from the client
   
```bash
./client 12345 "Hello World"
```

- Server output:

```bash
Server PID: 12345
Hello World
```

## Compliance

This project was developed in compliance with the requirements and constraints of the 42 network, respecting the imposed coding standards, allowed functions, and project guidelines.
