#include "assessGrade.h"


int assessGrade(char grade[], int one)
{
	return 0;
}

int assessGrade(double finalMark) 
{
	printf("I got a %.2f %% grade!\n", finalMark);
	return 0;
}


int assessGrade(int assignments[])
{
	int status = SUCCESS;
	int total = 0;
	int i = 0;

	for (i = 0; i < numOfAssignments; i++)
	{
		if (assignments[i] > 100 || assignments[i] < 0)
		{
			
			printf("MAYDAY, there has been a breach!\n");
			status = FAILURE;
			break;
		}

		total += assignments[i];

	}
	
	if (status == SUCCESS)
	{
		assessGrade((double)total / numOfAssignments);
	}
	else
	{
		return status;
	}
}


int parseUserInput(char buffer[])
{
	
	return 0;
}




// Function:	deleteNewLineCharacter()
// Parameters:	char: string[]: Any array of characters			
// Returns:		void			
// Description: This function simply replaces the '\n' character from the end of a C-string with null (if it is there) 
//				(normally used because fgets() adds a \n automatically to the end of a string) 

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
