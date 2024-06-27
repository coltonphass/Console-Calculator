// Libraries / Pragma warning to disable 4996
#pragma warning(disable: 4996)
#include <conio.h>
#include <stdio.h> // for _getch()

//  Main function
int main() {

	// Declare Vars and initialize
	int minValue = -1000;
	int maxValue = 1000;
	int operandOne = 0, operandTwo = 0;
	char operation = 0;
	double result = 0;

	// ASCII art message
	printf("  _____                      _         _____      _            _       _             \n");
	printf(" / ____|                    | |       / ____|    | |          | |     | |            \n");
	printf("| |     ___  _ __  ___  ___ | | ___  | |     __ _| | ___ _   _| | __ _| |_ ___  _ __ \n");
	printf("| |    / _ \\| '_ \\/ __|/ _ \\| |/ _ \\ | |    / _` | |/ __| | | | |/ _` | __/ _ \\| '__|\n");
	printf("| |___| (_) | | | \\__ \\ (_) | |  __/ | |___| (_| | | (__| |_| | | (_| | || (_) | |   \n");
	printf("\\_____|\\___/|_| |_|___/\\___/|_|\\___| \\_____|\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|  \n\n");

	// First operand prompt
	printf("Please input the First Operand: ");
	scanf("%d", &operandOne);
	rewind(stdin);

	// input validation loop
	while (operandOne < minValue || operandOne > maxValue) {
		printf("Error, operand is out of bounds.\n");
		printf("Please input the first Operand within bounds : ");
		scanf("%d", &operandOne);
		rewind(stdin);
	}

	// Second operand prompt
	printf("Please input the second operand: ");
	scanf("%d", &operandTwo);
	rewind(stdin);

	// Second input validation loop
	while (operandTwo < minValue || operandTwo > maxValue) {
		printf("Error, operand is out of bounds.\n");
		printf("Please input the second Operand within bounds : ");
		scanf("%d", &operandTwo);
		rewind(stdin);
	}

	// Operation selection prompt
	printf("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+\n");
	printf("Please select one of the operations listed below +*+*+\n");
	printf("Input + for Addition                             +*+*+\n");
	printf("Input - for Subtraction                          +*+*+\n");
	printf("Input * for Multiplication                       +*+*+\n");
	printf("Input / for Division                             +*+*+\n");
	printf("Input %% for Modulus                              +*+*+\n");
	printf("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+\n");
	scanf("%c", &operation);
	rewind(stdin);

	// Operation error handling for incorrect selection
	if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '%') {
		printf("Invalid operation selected... Exiting program.\n");
		printf("Press any key to exit.");
		_getch();
		return 0;
	}

	// Check for 0's in Division and Mod, prompt for input loop if true
	if (operation == '/' || operation == '%' && operandOne == 0 || operandTwo == 0) {
		if (operandOne == 0) {
			printf("Error: Division and modulus by zero is not allowed. Please enter a non-zero value for the first operand.\n");
			printf("Enter a non-zero value for the First Operand: ");
			scanf("%d", &operandOne);
			rewind(stdin);
		}

		if (operandTwo == 0) {
			printf("Error: Division and modulus by zero is not allowed. Please enter a non-zero value for the second operand.\n");
			printf("Enter a non-zero value for the Second Operand: ");
			scanf("%d", &operandTwo);
			rewind(stdin);
		}
	}

	// Confirmation message
	printf("You've selected %c\n", operation);

	// Switch cases for operation and print result message
	switch (operation) {
	case '+':
		result = operandOne + operandTwo;
		printf("Result: %d + %d = %.2f\n", operandOne, operandTwo, result);
		break;
	case '-':
		result = operandOne - operandTwo;
		printf("Result: %d - %d = %.2f\n", operandOne, operandTwo, result);
		break;
	case '*':
		result = operandOne * operandTwo;
		printf("Result: %d x %d = %.2f\n", operandOne, operandTwo, result);
		break;
	case '/':
		result = (double)operandOne / operandTwo;
		printf("Result: %d / %d = %.2f\n", operandOne, operandTwo, result);
		break;
	case '%':
		result = operandOne % operandTwo;
		printf("Result: %d %% %d = %d\n", operandOne, operandTwo, (int)result);
		break;

	}
	// Exit to OS
	printf("Press any key to exit.");
	_getch();
	return 0;
}

