![Screenshot 2023-07-17 140214](https://github.com/El-gibbor/simple_shell/assets/107848793/61ebd16b-2f57-4528-ae36-43afccfaafe0)  
# ```hsh``` - Simple Shell 💥
```hsh``` is a simple shell program developed as part of our sprint 1 Final project in the [Alx](www.alxafrica.com) Software Engineering programme. This project aims to implement a basic shell that can execute various commands and manage processes in a Unix-like environment allowing users to interact with the operating system. The shell provides a prompt where users can input commands, and it will execute those commands and display the corresponding output.  

The purpose of this project is to demonstrate understanding and practical implementation of core concepts in C programming, including process management, file handling (I/O), string manipulation, and command execution.  
## 📖 Learning Objectives
Upon completion of this project, one will have acquired comprehensive knowledge and a deep understanding of the following key concepts:  
* Understand the original design and implementation of the Unix operating system.  
* Comprehend the functioning of a shell and its role as an interface between the user and the operating system.  
* Understanding the concepts of ```PID``` (Process ID) and ```PPID``` (Parent Process ID) and their significance in process management.  
* Gained knowledge about manipulating the environment variables of a process.  
* Differentiate between a function and a system call and understand their respective roles.  
* Understand the process creation mechanism and the ability to create child processes.  
* Recognize the three prototypes of the main function and their specific purposes.  
* Understand how the shell utilizes the ```PATH``` environment variable to locate executable programs.  
* Have good Knowledge of executing another program using the ```execve``` system call.  
* Understand process management techniques such as suspending the execution of a process until one of its child processes terminates.  
* Familiarity with the concept of `EOF` (End-of-File) and its significance in input/output operations.   
## Features and functionalities ⚙️  
Our ```hsh``` shell supports the following features:
* Interactive command line prompt.
* Execution of commands with or without arguments.
* Path resolution to locate executable programs using the ```PATH``` environment variable.
* Built-in support for exiting the shell with the ```exit``` command.
* Signal handling, allowing termination of processes using Ctrl + D or C.
* ```setenv```: Initialize a new environment variable, or modify an existing one  
    * Command syntax: ```setenv VARIABLE VALUE```
    *  print something on stderr on failure
* `unsetenv`: Remove an environment variable
    * Command syntax: `unsetenv VARIABLE`
    * prints something on stderr on failure
## Future Improvements💡
Although this shell implementation provides basic functionality, there are opportunities for further enhancement. Some potential areas for improvement include:  
* Implementing more built-in shell commands, such as `cd`
    * Command syntax: `cd [DIRECTORY]`
    * If no argument is given to `cd`, the command must be interpreted like `cd $HOME`
    * Update the environment variable `PWD` when you change directory and handle the command `cd -`
* Implementing more advanced features like I/O redirection and pipes
* Handle command separator `;` e.g  `($) ls /dir1; ls /dir2`  
## Expected Outputs 🔃  
This program has the exact same output as ```sh (/bin/sh)``` as well as the exact same error output. The only difference is that when you print an error, the name of the program is equivalent to your `argv[0]` (See below)   
  
__Example of error with ```sh```__ ⤵️
```shell
elgibbor@ubuntu~$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
elgibbor@ubuntu~$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
elgibbor@ubuntu~$
```
__Same error with the program ```hsh```__ ⤵️ 
```
elgibbor@ubuntu~$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
elgibbor@ubuntu~$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
elgibbor@ubuntu~$
```  
## ✔ Testing  
__How it works in interactive mode__:
```
elgibbor@ubuntu~$ ./hsh
($) /bin/ls
hsh main.c shell.c _getevn.c main.h file1
($)
($) exit
elgibbor@ubuntu~$
```
__Then, in non-interactive mode__:  
```
elgibbor@ubuntu~$ echo "/bin/ls" | ./hsh
hsh main.c shell.c _getevn.c main.h file1
elgibbor@ubuntu~$
elgibbor@ubuntu~$ cat file1
/bin/pwd
elgibbor@ubuntu~$ cat file1 | ./hsh
/home/elgibbor
elgibbor@ubuntu~$
```
## 🧠 Contributors  
This project was implemented by [Bernard Frimpong](www.teflon40/github.com) and [Chiagoziem Elgibbor](https://www.linkedin.com/in/elgibbor/). Contributions and suggestions are welcome. Feel free to submit a pull request or open an issue on the project repository🤝  
<p align="center"><em>Simple shell is not Simple!</em>😩</p>
