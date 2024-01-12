#include "assessGrade.h"

int main(void)
{
	char userInput[MAX_ARRAY_LENGTH] = "";
	char fileInput[] = "";
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
				printf("Error opening the file '%s'.\n", userInput + 2);
			}
			while ((fgets(fileInput, MAX_ARRAY_LENGTH, fp)) != NULL)
			{
				parseUserInput(fileInput);
			}
			if (fclose(fp) != TRUE)
			{
				printf("Error: Can't close the file '%s'.\n", userInput + 2);
			}
		}
		else
		{
			parseUserInput(userInput);
		}
	}//end while loop


	return 0;
}