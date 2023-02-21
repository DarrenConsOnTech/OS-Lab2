#include "myshell.h"

int main(int argc, char *argv[])
{
    // Input buffer and commands
	// environ array stores information for 2 environment variables: [0] -> PWD [1] -> Shell
	char environ[2][MAX_BUFFER] = {0};
	// arrays are declared for the various types of buffers/handlers
	char pwd[MAX_BUFFER] = {0};
	char myshell[MAX_BUFFER] = {0};
    char buffer[MAX_BUFFER] = {0};
    char command[MAX_BUFFER] = {0};
    char tokens[MAX_ARGS][MAX_BUFFER] = {0};
	// used to keep track of the total number of arguments (token_count-1)
	int token_count = 0;

	FILE* fp = NULL;

    // Parse the commands provided using argc and argv
    if (argc > 1){
		fp = fopen(argv[1],"r");
		if (fp == NULL){
			printf("Error opening batch file...\n");
			return EXIT_FAILURE;
		}
	}

	// if not read from batchfile - commands will be entered by user
	else {
		fp = stdin;
	}
	
	printf("\n\nWelcome to SimpleShell! Type 'help' to view the supported internal commands\n\n");
	getcwd(pwd, MAX_BUFFER);
	getcwd(myshell, MAX_BUFFER);

	// Stores information for the cwd 
	strcpy(environ[0], "PWD: ");
	strcat(environ[0], pwd);

	// Stores information for the shell
	strcpy(environ[1], "MYSHELL: ");
	strcat(environ[1], myshell);
	
	// Working directory path is printed and appended with ':$ ' to mimic format of a Linux shell
	printf("%s:$ ", pwd);

    // Loops until buffer is empty
    while (fgets(buffer, MAX_BUFFER, fp) != NULL){

        // String tokenization to seperate command from other arguments
	    int index = 0;
		
		while (buffer[index] != '\n'){
			index++;
		}

		buffer[index] = '\0';
		
		token_count = string_tokenizer(buffer, tokens);
		strcpy(command, tokens[0]);
		
        // Checks if the user entered any of the supported internal commands and executes them

		// prints working directory
        if (strcmp(command, "pwd") == 0){
			printf("%s\n", environ[0]);
        }

        // changes directory
        else if (strcmp(command, "cd") == 0){
			change_dir(pwd, tokens[1]);
			// Update pwd environment variable information
			strcpy(environ[0], "PWD: ");
			strcat(environ[0], pwd);
        }
		
		// clears screen
		else if (strcmp(command, "clear") == 0){
			clear_screen();
		}

		// lists the contents of the specified directory
		else if (strcmp(command, "dir") == 0){
			display_dir(tokens[1]);
			printf("\n");
		}
		
		// displays environment variables
		else if (strcmp(command, "environ") == 0){
			display_environs(environ);
		}
		
		// echo command
		else if (strcmp(command, "echo") == 0){
			printf("%s:$ ", pwd);
			for (int i = 1; i < token_count; i++){
				printf("%s ", tokens[i]);
			}
			printf("\n");
		}

		// displays help menu
		else if (strcmp(command, "help") == 0){
			printf("\nSupported Internal Commands:\n\n");
			printf("help\t\t\t Lists the help menu\n");
			printf("pwd\t\t\t Prints the path of the working directory\n");
			printf("cd <path>\t\t Changes the current default directory to <directory>\n");
			printf("clr\t\t\t Clears the screen\n");
			printf("dir <directory>\t\t Lists the contents of the directory\n");
			printf("environ\t\t\t Lists all the environment strings\n");
			printf("echo <comment>\t\t Displays <comment> on the command line followed by a newline character\n");
			printf("pause\t\t\t Pauses operation of the shell until the ENTER key is hit\n");
			printf("quit\t\t\t Closes the shell [can also use 'exit']\n\n");
		}	
		
		// pauses the shell
		else if (strcmp(command, "pause") == 0){
			pause_shell();
		}	
			
        // quit - exits the shell
        else if (strcmp(tokens[0], "quit") == 0 || strcmp(tokens[0], "exit") == 0){
            printf("\nThanks for trying out SimpleShell! Goodbye!\n\n\n");
			return EXIT_SUCCESS;
        }

        // Unsupported commands will be captured and handled here
        else{
            printf("%s: Command not found. Type 'help' to view list of supported internal commands\n", command);
        }
		
		// frees the memory by filling all blocks with 0
		memset(buffer, 0, sizeof buffer);
		memset(command, 0, sizeof command);
		for (int i = 0; i < MAX_ARGS; i++){
			memset(tokens[i], 0, sizeof tokens[i]);
		}
		
		printf("%s:$ ", pwd);
    }
    return EXIT_SUCCESS;
}
