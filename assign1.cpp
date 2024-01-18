#include "assessGrade.h"

int main(void)
{
	int status = SUCCESS;
	char userInput[MAX_ARRAY_LENGTH] = "";
	char fileInput[MAX_ARRAY_LENGTH] = "";
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
			if ((fp = fopen(userInput + TWO, "r")) == NULL) //will open a file two positions after the Z, so the space is important
			{
				printf("** File I/O ERROR\n");
			}
			while ((fgets(fileInput, MAX_ARRAY_LENGTH, fp)) != NULL)
			{
				parseUserInput(fileInput);
			}
			if (fclose(fp) != TRUE)
			{
				printf("** File I/O ERROR\n");
			}
		}
		else
		{
			parseUserInput(userInput); //If not a file or 'X', send for further parsing
		}
	}//end of while loop


	return 0;
}
