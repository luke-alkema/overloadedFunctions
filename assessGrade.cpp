#include "assessGrade.h"

int assessGrade(double finalMark)
{

	int status = SUCCESS;
	if (finalMark <= ONE_HUNDRED && finalMark >= ZERO)
	{
		if (finalMark >= kPass)
		{
			printf("Student achieved %6.2f %% which is a PASS condition.\n", finalMark);
		}
		else
		{
			printf("Student achieved %6.2f %% which is a FAIL condition.\n", finalMark);
		}
	}
	else
	{
		printf("**ERROR : Invalid Input\n");
		status = FAILURE;
	}
	
	return status;
}



int assessGrade(int assignments[])
{
	int status = SUCCESS;
	int total = 0;
	int i = 0;

	for (i = 0; i < NUM_OF_ASSIGNMENTS; i++)
	{
		if (assignments[i] > ONE_HUNDRED || assignments[i] < ZERO)
		{
			
			printf("**ERROR : Invalid Input\n");
			status = FAILURE;
			break;
		}

		total += assignments[i];

	}
	
	if (status == SUCCESS)
	{
		status = assessGrade((double)total / (double)NUM_OF_ASSIGNMENTS);
	}

	return status;
}

int assessGrade(char stringGrade[])
{
	int status = SUCCESS;
	int grade = 0;
	//i suggest using something like <<< if strcmp(stringGrade, "A+") { assessGrade (95.0) } >>> for most of the special cases, and then a final else at the end for all invalid strings--and set status to failure there
	//some special cases won't need to call the worker bee and can just output here

	return status;
}



int parseUserInput(char userInput[])
{
	int status = SUCCESS;
	char* pDecimal = strchr(userInput, '.');
	int assignGrades[NUM_OF_ASSIGNMENTS] = { 0 };
	double result = 0.0;

	// Parses floating point cases
	if (pDecimal != NULL)
	{
		status = assessGrade(atof(userInput)); //Sean won't be mean and test values with a decimal that don't work he said
	}
	//Parses 5 ints cases
	else if (sscanf(userInput, "%d", assignGrades) == 1) //if the first character in string is a integer number we will send to assessGrade(int[]),
	{
		if ((sscanf(userInput, "%d %d %d %d %d", assignGrades, assignGrades + ONE, assignGrades + TWO, assignGrades + THREE, assignGrades + FOUR)) > 0)
		{
			status = assessGrade(assignGrades);
		}
		else
		{
			status = FAILURE;
		}
	}
	//If not going to assessGrade(int[]) or assessGrade(double), go to assessGrade(char*)
	else 
	{
		status = assessGrade(userInput);
	}
	return status;
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
