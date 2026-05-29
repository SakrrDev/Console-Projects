#include<stdio.h>

int main(){

    printf("Temperature Conversion Calculator\n");
    printf("C. Celsius to Fahrenheit Conversion\n");
    printf("F. Fahrenheit to Celsius\n");

    char choice = "";
    printf("Enter Your Temp in Celsius (C) or Celsius (F): ");
    scanf("%c", &choice);

    if (choice == 'C'){
        float Temp_in_Celsius;
        float result_in_Fahrenheit;

        printf("Enter a temp: ");
        scanf("%f", &Temp_in_Celsius);

        result_in_Fahrenheit = (Temp_in_Celsius * 9 / 5) + 32;

        printf("%.1f in Celsius is equal %.1f in Fahrenheit", Temp_in_Celsius, result_in_Fahrenheit);

    } else if (choice == 'F'){
        float Temp_in_Fahrenheit;
        float result_in_Celsius;

        printf("Enter a Temp: ");
        scanf("%f", &Temp_in_Fahrenheit);

        result_in_Celsius = (Temp_in_Fahrenheit - 32) * 5/9;
        printf("%.1f in Fahrenheit is equal %.1f in Celsius", Temp_in_Fahrenheit, result_in_Celsius);
        
    } else {
        printf("Invalid choice! Please Enter (C or F).\n");
    }

    return 0;
}