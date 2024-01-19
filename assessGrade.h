#pragma once
#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARRAY_LENGTH 101
#define SUCCESS 1
#define FAILURE -1
#define TRUE 0
#define NUM_OF_ASSIGNMENTS 5
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define ONE_HUNDRED 100
#define A_PLUS 10
#define B_C_PLUS 5

#define A 85
#define B 72
#define C 62
#define D 57
#define F 50

const double kPass = 54.5;


//function prototypes
int assessGrade(char grade[]);
int assessGrade(double finalMark);
int assessGrade(int assignments[] = { 0 } );
int parseUserInput(char buffer[]);
void deleteNewLineCharacter(char string[]);