# minitalk

<p align="center">
    <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/minitalke.png" alt="minitalk 42 project badge">
</p>

[![42 School Project](https://img.shields.io/badge/42%20Project-printf-blue)](https://github.com/ugolinolle/ft_printf)
[![Language: C](https://img.shields.io/badge/language-C-green.svg)](<https://en.wikipedia.org/wiki/C_(programming_language)>)

## 💻・Description

Minitalk is a system programming project that involves creating a simple communication program in C. The project consists of developing a server and a client that communicate with each other using UNIX signals. The client sends a message to the server, which receives and displays it on the screen.

**Features:**

- Server: Displays its PID at startup and waits for messages from clients.
- Client: Sends a message to the server using its PID.

**Technologies Used:**

- C Language
- UNIX Signals (SIGUSR1, SIGUSR2)
- System Programming in UNIX

## ⌨️・Usage

1. Launch the server: (The server will display its PID)

```bash
./server
```

2. In another terminal, launch the client using the server's PID and the message to send:

```bash
./client [SERVER_PID] "Your message here"
```

## 🧑‍🤝‍🧑・Contributing

Contributions to this project are welcome. If you find any issues or want to improve the code, please feel free to open a pull request or issue.

## 📑・License

This project is licensed under the [MIT License](https://github.com/UgolinOlle/minitalk/blob/master/LICENSE) - see the LICENSE file for details.

## 📩・Contact

Pour toute question ou collaboration, n'hésitez pas à me contacter par [email](mailto:hello@ugolin-olle.com) ou [LinkedIn](https://linkedin.com/in/ugolin-olle)
