#include "myshell.h"

int main(int argc, char *argv[])
{
    // Input buffer and commands
	// environ array stores information for 2 environment variables: [0] -> PWD [1] -> Shell
	char environ[2][MAX_BUFFER] = {0};
	char pwd[MAX_BUFFER] = {0};
	char myshell[MAX_BUFFER] = {0};
    char buffer[MAX_BUFFER] = {0};
    char command[MAX_BUFFER] = {0};
    char tokens[MAX_TOKENS][MAX_BUFFER] = {0};
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
	else {
		fp = stdin;
	}
	
	printf("\n\nWelcome to SimpleShell! Type 'help' to view the supported internal commands!\n\n");
	getcwd(pwd, MAX_BUFFER);
	getcwd(myshell, MAX_BUFFER);

	// Stores information for the cwd 
	strcpy(environ[0], "PWD: ");
	strcat(environ[0], pwd);

	// Stores information for the shell
	strcpy(environ[1], "MYSHELL: ");
	strcat(environ[1], myshell);
	
	// Working directory path is printed and appended with ':~$ ' to 
	printf("%s:$ ", pwd);

    // Loops until buffer is empty
    while (fgets(buffer, MAX_BUFFER, fp) != NULL){

        // String tokenization to get the command and argument
	    int index = 0;
		while (buffer[index] != '\n'){
			index++;
		}
		buffer[index] = '\0';
		
		token_count = string_tokenizer(buffer, tokens);
		strcpy(command, tokens[0]);
		
        // Check the command and execute the operations for each command

        if (strcmp(command, "pwd") == 0){
			printf("\n%s\n\n", pwd);
        }

        // check for cd
        else if (strcmp(command, "cd") == 0){
			change_dir(pwd, tokens[1]);
			strcpy(environ[0], "PWD: ");
			strcat(environ[0], pwd);
        }
		
		// check for clear
		else if (strcmp(command, "clear") == 0){
			clear_screen();
		}

		// lists the contents of the specified directory
		else if (strcmp(command, "dir") == 0){
			display_dir(tokens[1]);
			printf("\n");
		}
		
		// display environment variables
		else if (strcmp(command, "environ") == 0){
			display_environs(environ);
		}
		
		// run the echo command
		else if (strcmp(command, "echo") == 0){
			printf("%s:$ ", pwd);
			for (int i = 1; i < token_count; i++){
				printf("%s ", tokens[i]);
			}
			printf("\n");
		}

		// display help
		else if (strcmp(command, "help") == 0){
			display_help();
		}	
		
		// pause the shell
		else if (strcmp(command, "pause") == 0){
			pause_shell();
		}	
			
        // quit command -- exit the shell
        else if (strcmp(tokens[0], "quit") == 0 || strcmp(tokens[0], "exit") == 0){
            printf("\nThanks for trying out SimpleShell! Goodbye!\n\n\n");
			return EXIT_SUCCESS;
        }

        // Unsupported commands will be captured and handled here
        else{
			printf("%s:$ ", pwd);
            printf("%s: command not found. Type 'help' to view list of supported internal commands\n", command);
        }
		
		memset(buffer, 0, sizeof buffer);
		memset(command, 0, sizeof command);
		for (int i = 0; i < MAX_TOKENS; i++){
			memset(tokens[i], 0, sizeof tokens[i]);
		}
		
		printf("%s:$ ", pwd);
    }
    return EXIT_SUCCESS;
}
