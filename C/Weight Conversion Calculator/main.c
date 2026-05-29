#include<stdio.h>

int main(){
    printf("Weight Conversion Calculator\n");

    printf("1. Kilograms to pounds Convesion\n");
    printf("2. Pounds to kilograms Conversion\n");

    int choice;
    printf("Enter Your Choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1){
        float _Kilograms;
        printf("Enter Your Weight in kilograms: ");
        scanf("%f", &_Kilograms);

        float results_in_pounds = _Kilograms * 2.204623;
        printf("%.2f kilograms is equal to %.2f in pounds\n", _Kilograms, results_in_pounds);
    } else if (choice == 2){
        float _pounds;
        printf("Enter Your Weight in Pounds: ");
        scanf("%f", &_pounds);

        float results_in_kilograms = _pounds * 0.4535924;
        printf("%.2f pounds is equal to %.2f in kilograms\n", _pounds, results_in_kilograms);
    } else {
        printf("Invalid Choice! Please Enter (1 or 2).\n");
    }
    return 0;
}