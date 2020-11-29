#include <stdio.h>
#include "myBank.h"

#define ROWS 50
#define COLUMS 2
#define OPEN 0
#define AMOUNT 1

double accounts [ROWS] [COLUMS] = {0};

double round2Places(double number) {
	return (int)(number * 100) / 100.;
}

void openAccount(){

    double amount = 0;
    int i;
    for ( i = 0 ; i < ROWS ; i++) {
       
        if( accounts[i][OPEN] == 0){
            printf("Enter the amount for the deposit:\n");
            if(scanf("%lf" ,&amount) == 1){
            if(amount < 1){
                printf("Please insert a positive number, bigger than zero\n");
            }
            else{
                accounts[i][OPEN] = 1;
                accounts[i][AMOUNT] = round2Places(amount);
                printf("New account number is %d completed \n",901+i );
            }
        }
        else {
            printf("Failed to read the amount\n");
        }
        break;
        }
    }
    if(i==ROWS)
        printf("Sorry, there is no room for more accounts\n");

}

void balanceAccount(){

    int account_number = 0;

    printf("Enter the account number :\n");
    scanf("%d", &account_number);
    if(account_number <= 950 && account_number >= 901){
        if(accounts[account_number-901][OPEN] == 1){
            printf("The amount of the account %d is %.2f\n", account_number, accounts[account_number-901][AMOUNT]);
        }
        else{
            printf("This account is empty\n");
        }
        
    }
    else {
        printf("Please enter a valid account number\n");
    }
    
}

void depositAmount () {

int account_number = 0;

printf("Enter a account number :\n");
scanf(" %d",&account_number);

    if (account_number <= 950 && account_number >= 901) {
        if (accounts[account_number-901][OPEN] == 1 ){
            double amount = 0;
            printf ("Enter the amount that you want to deposit\n");
            if(scanf("%lf",&amount)==1){ 
            if(amount<1){
                printf("Please enter a positive number\n");
            }
            else {
                accounts[account_number-901][AMOUNT] += round2Places(amount);
                printf("The amount of the account %d is : %.2lf\n" ,account_number,accounts[account_number-901][AMOUNT]);
            }
          }
          else {
              printf("Cannot deposit a negative amount\n");
          }
        }
        else {
              printf("This account is empty\n");
        }
    }
    else {
    printf("Please enter a valid account number\n");
    }
}


void withdrawal(){

    int account_number = 0;
    double amount = 0;

    printf("Enter the account number: \n");
    scanf("%d",&account_number);
    
    printf("Enter the amount to withdrawal: \n");
    scanf("%lf",&amount);

    if(account_number <= 950 && account_number >= 901){
        if(accounts[account_number-901][OPEN] == 1 &&  accounts[account_number-901][AMOUNT] >= amount){
            
            accounts[account_number-901][AMOUNT] -= round2Places(amount);
            printf("The amount of the account %d is: %.2lf \n", account_number, accounts[account_number-901][AMOUNT]);
        }
        else{
            printf("Not a valid number\n");
        }
        
    }
    else {
        printf("Please enter a valid account number\n");
    }
    
}

void closeAccount (){

    int account_number = 0;
    printf("Enter the account number \n");
    scanf("%d", &account_number);

    if(account_number <= 950 && account_number >= 901){
        if(accounts[account_number-901][OPEN] == 1 ) {
            accounts[account_number-901][OPEN] = 0;
            printf("Closed account number %d\n", account_number);
        }
        else {
            printf("This account is already closed\n");
        }
    }
    else {  
    printf("Please enter a valid account number\n");
}


}

void increaseInterest (){

double interest_rate = 0;
printf ("Enter the interest rate for the accounts \n");
scanf("%lf",&interest_rate);

 if (interest_rate < 1 ){
    printf("Enter a positive interest rate \n");
}
 else {
    for ( int i = 0 ; i < ROWS ; i++){
        if(accounts[i][OPEN] == 1 ){
           accounts[i][AMOUNT] *=  1 + (interest_rate / 100.);
		   accounts[i][AMOUNT] = round2Places(accounts[i][AMOUNT]);
        }
    }
}
}

void printAllAccounts() { 

    for(int i = 0; i<ROWS; i++){
        if(accounts[i][OPEN] == 1){
            printf("The amount of account number %d is: %0.2f \n", i+901 , accounts[i][AMOUNT]);
        }
    }
}

void closeProgram() {

    for ( int i = 0 ; i < ROWS ; i++){
        accounts[i][OPEN] = 0;
    }
}