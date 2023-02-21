// Group 10 - Operating Systems Lab 2 
// Instructor: Ghadeer Abdelkader
// Group Members:
// Darren Constantine - 100782701
// Md Fardin Rahman - 100704517
// Ram Baldeo Baldeo - 100701013

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h> 
#include <ctype.h>


#define MAX_BUFFER 1024  // max line buffer
#define MAX_ARGS 64  // max # args
#define SEPARATORS " \t\n"  // token sparators

// Function Definitions
int string_tokenizer(char* str, char tokens[][MAX_BUFFER]);
void change_dir(char* pwd, char* path);
void clear_screen();
void pause_shell();
void display_dir(char* path);
void display_environs(char env[][MAX_BUFFER]);
