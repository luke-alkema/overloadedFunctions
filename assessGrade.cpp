#include "assessGrade.h"


void assessGrade(char grade[])
{

}

void assessGrade(double finalMark)
{

}


void assessGrade(int assignment1, int assignment2, int assignment3, int assignment4, int assignment5)
{

}


int parseUserInput(char buffer[])
{
	return 0;
}


// Function:	deleteNewLineCharacter()
// Parameters:	char: string[]: Any array of characters			
// Returns:		void			
// Description: This function simply replaces the '\n' character from the end of a C-string with null (if it is there) (normally used because fgets() adds a \n automatically to the end of a string) 

void deleteNewLineCharacter(char string[])
{
	int i = 0;

	while ((string[i] != '\0') && (string[i] != '\n'))
	{
		++i;
	}

	if (string[i] == '\n')
	{
		string[i] = '\0';
	}
}// credits: Segro, C. (2015, Oct 21). strequal.c. eConestoga,  https://conestoga.desire2learn.com/d2l/le/content/879640/viewContent/17227039/View
