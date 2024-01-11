#pragma once
#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_LENGTH 101
#define SUCCESS 1
#define FAILURE -1
#define TRUE 0

//function prototypes
void assessGrade(char grade[]);
void assessGrade(double finalMark);
void assessGrade(int assignment1 = 0, int assignment2 = 0, int assignment3 = 0, int assignment4 = 0, int assignment5 = 0);
int parseUserInput(char buffer[]);
void deleteNewLineCharacter(char string[]);