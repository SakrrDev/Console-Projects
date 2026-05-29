#include<stdio.h>

int main(){

    printf("Simple Calculator");

    float firstNumber = 0.0f;
    float secondNumber = 0.0f;
    char operator = '\0';
    double result = 0.0f;
    
    printf("Enter a first number: ");
    scanf("%f", &firstNumber);

    printf("Enter a operator (+ - / *): ");
    scanf(" %c", &operator);

    printf("Enter a second number: ");
    scanf("%f", &secondNumber);

    switch(operator){
        case '+':
            result = firstNumber + secondNumber;
            break;
        case '-':
            result = firstNumber - secondNumber;
            break;
        case '/':
            if (secondNumber == 0){
                printf("You can't divide by zero!\n");
                return 0;
            } else {
                result = firstNumber / secondNumber;
                break;
            }
        case '*':
            result = firstNumber * secondNumber;
            break;
        default:
        printf("Invalid operator!\n");
    }   

    printf("Result: %.4lf \n", result);
}