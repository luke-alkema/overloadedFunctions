#pragma once
#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_LENGTH 101
#define SUCCESS 1
#define FAILURE -1
#define TRUE 0
#define numOfAssignments 5  

//function prototypes
int assessGrade(char grade[], int one);
int assessGrade(double finalMark);
int assessGrade(int assignments[] = 0);
int parseUserInput(char buffer[]);
void deleteNewLineCharacter(char string[]);