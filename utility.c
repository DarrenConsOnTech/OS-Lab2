#include "myshell.h"

int string_tokenizer(char* str, char tokens[][MAX_BUFFER]){
	const char delimiter[2] = " ";
	int tokens_count = 0;
	char* token = strtok(str, delimiter);
	while (token != NULL){
		strcpy(tokens[tokens_count], token);
		tokens_count++;
		token = strtok(NULL, delimiter);
	}
	return tokens_count;
}

// changes the directory
void change_dir(char* pwd, char* path){
	int changed = chdir(path);
	if (strcmp(path,"") != 0){
		if (changed == 0){
				getcwd(pwd, MAX_BUFFER);
		}
		else {
			printf("%s> No such path exists!\n", pwd);
		}
	}
}

// clears the screen
void clear_screen(){
	system("cls||clear");
}

// pauses the shell
void pause_shell(){
	printf("\n\nShell is now paused. Please press ENTER key to continue....\n\n");
	char code = (char)getchar();
	while (code != '\n'){
		code = (char)getchar();
	}
}

// displays help menu
void display_help(){
    printf("\nList of available commands:\n\n");
    printf("help\t\t\t Lists the help menu.\n");
    printf("dir <directory>\t\t Lists the contents of the directory\n");
    printf("environ\t\t\t Lists all the environment strings..\n");
    printf("echo <comment>\t\t Displays comment on the command line followed by a newline.\n");
	printf("cd <path>\t\t Changes the working directory to the specified path.\n");
    printf("clr\t\t\t Clears the screen.\n");
    printf("pause\t\t\t Pauses operation of the shell until the ENTER key is hit.\n");
    printf("quit\t\t\t Quits the shell.\n\n\n");
    
}

// displays the directory
void display_dir(char* path){
	struct dirent *de; 
	DIR *dr = NULL;
    if (strcmp(path, "") == 0){
        dr = opendir(".");
	}
    else {	
		dr = opendir(path); 
	}
	if (dr == NULL) { 
		printf("Could not find the directory specified!\n" );  
	} 
	while ((de = readdir(dr)) != NULL){ 
		printf("%s\n", de->d_name); 
	}
    closedir(dr);     
}

// displays the environment variables
void display_environs(char env[][MAX_BUFFER]){
	printf("%s\n%s\n", env[0], env[1]);
}