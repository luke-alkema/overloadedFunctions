#include "assessGrade.h"


// Function:	assessGrade()
// Parameters:	double finalMark: holds parsed input in form of double.	
// Returns:		int status: Integer variable to hold return code. Either SUCCESS(1) or FAILURE(-1).		
// Description: Takes finalMark and does a boundary check. Then determines if student pass or fails.
//              Overloaded function with 2 other overloaded function. Worker bee is this version. 

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
		status = FAILURE;
	}

	return status;
}

// Function:	assessGrade()
// Parameters:	int assignments[]: integer array to hold parsed input as integers.		
// Returns:		int status: Integer variable to hold return code. Either SUCCESS(1) or FAILURE(-1).			
// Description: Does a boundary check on each element, obtains average of grades obtained. Then proceeds to worker bee if SUCCESS.


int assessGrade(int assignments[])
{
	int status = SUCCESS;
	int total = 0;
	int i = 0;

	for (i = 0; i < NUM_OF_ASSIGNMENTS; i++)
	{
		if (assignments[i] > ONE_HUNDRED || assignments[i] < ZERO)
		{
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

// Function:	assessGrade()
// Parameters:	char stringGrade[]: Holds the parsed input in from of a c-style string.			
// Returns:		int status: Integer variable to hold return code. Either SUCCESS(1) or FAILURE(-1).			
// Description: Checks for special cases, then proceeds to checking letter grades. 

int assessGrade(char stringGrade[])
{
	int status = FAILURE;
	int grade = 0;
	// Array with elements matched to corresponding grades. If A+ add 10, if B+ or C+ add 5.
	int gradeList[TWO][FIVE] = { {'A', 'B', 'C', 'D', 'F'}, {A, B, C, D, F} };

	if (strcmp(stringGrade, "I") == TRUE)
	{
		printf("Student has Special Situation : %s (Incomplete) \n", stringGrade);
		status = SUCCESS;
	}

	else if (strcmp(stringGrade, "Q") == TRUE)
	{
		printf("Student has Special Situation : %s (Withdrawl After Drop/Refund Date) \n", stringGrade);
		status = SUCCESS;
	}

	else if (strcmp(stringGrade, "AU") == TRUE)
	{
		printf("Student has Special Situation : %s (Audit Condition) \n", stringGrade);
		status = SUCCESS;
	}

	else if (strcmp(stringGrade, "DNA") == TRUE)
	{
		printf("Student has Special Situation : %s (Did Not Attend) \n", stringGrade);
		status = SUCCESS;
	}

	else if (strcmp(stringGrade, "I/P") == TRUE)
	{
		printf("Student has Special Situation : %s (In Process) \n", stringGrade);
		status = SUCCESS;
	}

	else
	{

		for (int row = 0; row < FIVE; row++)
		{
			if (strchr(stringGrade, gradeList[ZERO][row]))
			{
				if (stringGrade[ONE] == '+' && row <= TWO && strlen(stringGrade) == TWO)
				{
					// If 'A' and '+' are present, add 10 to the grade associated with 'A'
					// Else add 5
					if (strchr(stringGrade, 'A') != NULL)
					{
						grade = (gradeList[ONE][row] + A_PLUS);
						status = assessGrade(grade);
						break;
					}
					else
					{
						grade = (gradeList[ONE][row] + FIVE);
						status = assessGrade(grade);
						break;
					}
				}
				else if (strlen(stringGrade) == ONE) //Only singular letter grade, since no '+' present
				{
					grade = gradeList[1][row];
					status = assessGrade((double)grade);
					break;
				}
			}
		}
	}

	return status;
}



// Function:	parseUserInput()
// Parameters:	char userInput[]: A c-style string to hold the users input.			
// Returns:		int status: Integer variable to hold return code. Either SUCCESS(1) or FAILURE(-1).			
// Description: Determines what type of data the user has input. Then transforms the data to its proper data type, then calls proper assessGrade() function
int parseUserInput(char userInput[])
{
	int status = SUCCESS;
	char* pDecimal = strchr(userInput, '.');
	int assignGrades[NUM_OF_ASSIGNMENTS] = { 0 };
	double result = 0.0;

	// Parses floating point cases
	if (pDecimal != NULL)
	{
		status = assessGrade(atof(userInput)); 
	}
	//Parses 5 ints cases
	else if (sscanf(userInput, "%d", assignGrades) == ONE)
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


	if (status == FAILURE)
	{
		printf("**ERROR : Invalid input \n");
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
