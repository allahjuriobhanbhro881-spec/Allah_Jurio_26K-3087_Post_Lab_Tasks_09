
#include <stdio.h>

int checkBalance(int balance);
int depositMoney(int balance);
int withdrawMoney(int balance);
void displayMenu();

int main(){

    int balance =20000;
    int choice;

    while(1){
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                checkBalance(balance);
                break;

            case 2:
                balance =depositMoney(balance);
                break;

            case 3:
                balance= withdrawMoney(balance);
                break;

            case 4:
                printf("\nthank you for using the ATM");
                return 0;

            default:
                printf("\ninvalid choice");
        }
    }
    return 0;
}

void displayMenu(){
    printf("\n\n ATM MENU");
    printf("\n1.  heck balance");
    printf("\n2. deposit money");
    printf("\n3. withdraw money");
    printf("\n4. exit");
}

int checkBalance(int balance){

    printf("\ncurrent balance: %d", balance);

    return balance;
}

int depositMoney(int balance){
    int amount;

    printf("\nenter deposit amount: ");
    scanf("%d", &amount);

    if(amount>0){
        balance = balance+amount;
        printf("\ndeposit successful");
        printf("\nupdated balance: %d", balance);
    }
    else{
        printf("\ninvalid amount, deposit must be positive");
    }

    return balance;
}

int withdrawMoney(int balance){

    int amount;

    printf("\nenter withdrawal amount: ");
    scanf("%d", &amount);

    if(amount <=0){
        printf("\ninvalid amount, withdrawal must be positive");
    }
    else if(amount > 10000){
        printf("\ncannot withdraw more than Rs 10000 per transaction");
    }
    else if(amount>balance){
        printf("\ninsufficient balance");
    }
    else{
        balance = balance-amount;
        printf("\nwithdrawal successful");
        printf("\nupdated balance: %d", balance);

        if(balance<5000){
            printf("\nwarning: your balance is below Rs 5000");
        }
    }
    return balance;
}
