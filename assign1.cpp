#include "assessGrade.h""

int main(void)
{
	char userInput[MAX_ARRAY_LENGTH] = "";
	char myArray[] = "";

	//insert loop here later
	printf("Enter Students's Grade(s) >>> ");
	fgets(userInput, MAX_ARRAY_LENGTH, stdin);
	deleteNewLineCharacter(userInput);

	if ((strcmp(userInput, "X")) == TRUE)
	{
		printf("i found a x"); //put a break here later
	}
	else if ((strcmp(userInput, "Z")) == TRUE)
	{
		printf("it works");
	}
	else
	{
		printf("found nothing");
	}
	parseUserInput(userInput);


	return 0;
}