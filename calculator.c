#include <stdio.h>
#include <math.h>

// Pre-defining PI for manual degree-to-radian conversion
#define PI 3.14159265358979323846

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        // Simple, clean terminal interface
        printf("\n--- My Scientific Calculator ---\n");
        printf("1. Add (+)\n");
        printf("2. Subtract (-)\n");
        printf("3. Multiply (*)\n");
        printf("4. Divide (/)\n");
        printf("5. Power (x^y)\n");
        printf("6. Square Root\n");
        printf("7. Sine (Degrees)\n");
        printf("8. Natural Log (ln)\n");
        printf("9. Exit\n");
        printf("--------------------------------\n");
        printf("Choose an option (1-9): ");
        
        // Prevent infinite loops if a user types a character instead of a number
        if (scanf("%d", &choice) != 1) {
            printf("\nThat's not a number! Try again.\n");
            while (getchar() != '\n'); 
            continue;
        }

        // Direct, human-readable menu routing
        switch (choice) {
            case 1:
                printf("\nEnter two numbers to add:\n");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.4f\n", num1 + num2);
                break;

            case 2:
                printf("\nEnter two numbers to subtract:\n");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.4f\n", num1 - num2);
                break;

            case 3:
                printf("\nEnter two numbers to multiply:\n");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.4f\n", num1 * num2);
                break;

            case 4:
                printf("\nEnter numbers for division (numerator denominator):\n");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: You can't divide by zero!\n");
                } else {
                    printf("Result: %.4f\n", num1 / num2);
                }
                break;

            case 5:
                printf("\nEnter the base (x) and exponent (y):\n");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.4f\n", pow(num1, num2));
                break;

            case 6:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                if (num1 < 0) {
                    printf("Error: Cannot take the square root of a negative number.\n");
                } else {
                    printf("Result: %.4f\n", sqrt(num1));
                }
                break;

            case 7:
                printf("\nEnter angle in degrees: ");
                scanf("%lf", &num1);
                // Human-friendly explicit conversion to radians
                double radians = num1 * (PI / 180.0);
                printf("Result: sin(%.2f) = %.4f\n", num1, sin(radians));
                break;

            case 8:
                printf("\nEnter a positive number: ");
                scanf("%lf", &num1);
                if (num1 <= 0) {
                    printf("Error: Logarithm is undefined for zero or negative values.\n");
                } else {
                    printf("Result: ln(%.4f) = %.4f\n", num1, log(num1));
                }
                break;

            case 9:
                printf("\nExiting. Thanks for using the calculator!\n");
                return 0;

            default:
                printf("\nInvalid selection. Please type a number from 1 to 9.\n");
        }
    }

    return 0;
}
