#include "assessGrade.h"

int main(void)
{
	char userInput[MAX_ARRAY_LENGTH] = "";
	char myArray[] = "";
	FILE* fp = NULL;

	while (true)
	{
		printf("Enter Students's Grade(s) >>> ");
		fgets(userInput, MAX_ARRAY_LENGTH, stdin);
		deleteNewLineCharacter(userInput);

		if ((strcmp(userInput, "X")) == TRUE) // if user enters an X, the program will end
		{
			break;
		}
		else if (userInput[0] == 'Z')
		{
			if ((fp = fopen(userInput + 2, "r")) == NULL) //will open a file two positions after the Z, so the space is important
			{
				printf("Error opening the file '%s'", userInput + 2);
			}
			while ((fgets(userInput, MAX_ARRAY_LENGTH, fp)) != NULL)
			{
				parseUserInput(userInput);
			}
			if (fclose(fp) != TRUE)
			{
				printf("Error: Can't close file.");
			}
		}
		else
		{
			parseUserInput(userInput);
		}
	}//end while loop


	return 0;
}