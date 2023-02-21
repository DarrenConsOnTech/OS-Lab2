# OS-Lab2
## Group 10 - Operating Systems Lab 2 
<strong>Instructor:</strong><br>
Ghadeer Abdelkader
<br>
<strong>Group Members:</strong><br>
Darren Constantine - 100782701<br>
Md Fardin Rahman - 100704517<br>
Ram Baldeo Baldeo - 100701013
<br>
<br>

## Description<hr>
This lab involved the contruction of a simple shell coded using the C programming language. The commands supported by the shell are shown below.<br><br>
<strong>Supported Internal Commands:</strong><br>
help -- Lists the help menu<br>
pwd -- Prints the path of the working directory<br>
cd <path> -- Changes the current default directory to <directory><br>
clr -- Clears the screen<br>
dir <directory> -- Lists the contents of the directory<br>
environ -- Lists all the environment strings<br>
echo <comment> -- Displays <comment> on the command line followed by a newline character<br>
pause -- Pauses operation of the shell until the ENTER key is hit<br>
quit -- Closes the shell [can also use 'exit']<br>
<br>
## Getting Started<hr>
### Prerequisites
 - An operating system with gcc installed
### Installation
1. Open command line and change directory path to local repository folder
2. Run the makefile
     ```sh
     make
     ```
3. Execute the shell
     ```sh
     ./myshell
     ```
     Batchfile can be used as another option for command input. Run the following command to do so.
    ```sh
     ./myshell batchfile
     ```
