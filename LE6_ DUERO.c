#include <stdio.h>


float add(float a, float b) {
	return a + b;
}

float subtract(float a, float b) {
	return a - b;
}

float multiply(float a, float b) {
	return a * b;
}

float divide(float a, float b) {
	return a / b;
}

int main() {
	float first, second, result;
	int choice;

	do {
		printf("\nMultiple function to perform to Arithmetic Operation\n");

		printf("Enter first number: ");
		scanf_s("%f", &first);

		printf("Enter second number: ");
		scanf_s("%f", &second);


		printf("\nChoose Operation:\n");
		printf("[1] Addition\n");
		printf("[2] Subraction\n");
		printf("[3] Multiplication\n");
		printf("[4] Divsion\n");
		printf("[5] Exit Program\n");

		printf("\nEnter choice [1-5]: ");
		scanf_s("%d", &choice);


		switch (choice) {
  		    case 1:
				result = add(first, second);
				printf("%.0f + %.0f = %.0f\n", first, second, result);
				break;

			case 2:
				result = subtract(first, second);
				printf("%.0f - %.0f = %.0f\n", first, second, result);
				break;

			case 3:
				result = multiply(first, second);
				printf("%.0f * %.0f = %.0f\n", first, second, result);
				break;

			case 4:
				if (second != 0) {
					result = divide(first, second);
					printf("%.0f / %.0f = %.2f\n", first, second, result);
				} else {
					printf("Error: Cannot divide by zero.\n");
			}
			break;

		case 5:
			printf("Exiting program\n");
			break;

		default:
			printf("Invalid choice. Please choose 1-5.\n");
		}

	} while (choice != 5);

	return 0;
}