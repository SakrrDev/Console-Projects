#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main(){

    float _price = 0.0f;
    char choice[10] = "";
    bool _isStudent = false;
    bool _isSenior = false;

    /*
    if he's a student 10% Discount
    if he's a senior 20% Discount
    if he's a student and senior 30% Discount
    */

    printf("if you are a Student Enter (ST), if a Senior Enter (SE), if both Enter (BOTH)\n");
    fgets(choice, sizeof(choice), stdin);
    choice[strlen(choice) - 1] = '\0';

    printf("Please Enter a Price: ");
    scanf("%f", &_price);

    if (strcmp(choice, "ST") == 0){
        _isStudent = true;
    } 
    else if (strcmp(choice, "SE") == 0){
        _isSenior = true;
    } 
    else if (strcmp(choice, "BOTH") == 0){
        _isStudent = true;
        _isSenior = true;
    }

    if(_isStudent){
        if(_isSenior){    // student and senior
            _price *= (1 - 30 / 100.0);
            printf("You get a student discount 10%%\n");
            printf("You get a senior discount 20%%\n");
            printf("The Total price now is: %.2f\n", _price);
        } 
        else {            // student only
            _price *= (1 - 10 / 100.0);
            printf("You get a student discount 10%%\n");
            printf("The Total price now is: %.2f\n", _price);
        }
    } 
    else if(_isSenior){   // senior only
        _price *= (1 - 20 / 100.0);
        printf("You get a senior discount 20%%\n");
        printf("The Total price now is: %.2f\n", _price);
    } 
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}