// Group 10 - Operating Systems Lab 2 
// Instructor: Ghadeer Abdelkader
// Group Members:
// Darren Constantine - 100782701
// Md Fardin Rahman - 100704517
// Ram Baldeo Baldeo - 100701013

#include "myshell.h"

int string_tokenizer(char* str, char tokens[][MAX_BUFFER]){
	const char delimiter[1] = " ";
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
            printf("\n");
            getcwd(pwd, MAX_BUFFER);
		}
		else {
			printf("%s: No such file or directory\n", path);
		}
	}
}

// clears the screen
void clear_screen(){
	system("cls||clear");
}

// pauses the shell
void pause_shell(){
	printf("\n\nShell is now paused. Press ENTER key to continue..\n\n");
	char input = (char)getchar();
	while (input != '\n'){
		input = (char)getchar();
	}
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
		printf("\ndir: cannot access '%s': No such file or directory\n", path);  
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