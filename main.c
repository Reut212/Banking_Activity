#include <stdio.h>
#include "myBank.h"

int main () {

    char transaction = ' ';
    int exit = 0;

    while (!exit){ 
        printf("Please choose a transaction:\n");
        printf(" O-Open Account\n B-Balnce Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
        scanf(" %c",&transaction);

        switch (transaction)
        {
        case 'O':
            openAccount();
				break;
        
        case 'B':
            balanceAccount();
            break;

        case 'D':
            depositAmount();
			break;

        case 'W':
			withdrawal();
			break;

        case 'C':
			closeAccount();
			break;

		case 'I':
			increaseInterest();
			break;

		case 'P':
			printAllAccounts();
			break;

		case 'E':
			closeProgram();
			exit = 1;
			break;

            default:
            printf("Enter a valid transaction\n");
        }

    }

return 0;

}
