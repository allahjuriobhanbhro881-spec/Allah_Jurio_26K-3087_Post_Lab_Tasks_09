
#include <stdio.h>

float calculateSubtotal(float price, int quantity);
float calculateDiscount(float subtotal);
float calculateMemberDiscount(float subtotal, char membership);
float calculatePaymentFee(float amount, char payment);
void displayBill(float subtotal, float discount,float memberDiscount, float fee);

int main(){

    float price, subtotal, discount, memberDiscount;
    float paymentFee, finalAmount;
    int quantity;
    char membership, payment;

    printf("enter product price");
    scanf("%f", &price);

    printf("enter quantity: ");
    scanf("%d", &quantity);

    printf("is customer a member (Y/N): ");
    scanf(" %c", &membership);

    printf("payment method C = card H = hash: ");
    scanf(" %c", &payment);

    if(price<=0 || quantity<=0){
        printf("\ninvalid price or quantity");
        return 0;
    }

    subtotal = calculateSubtotal(price, quantity);

    discount = calculateDiscount(subtotal);

    memberDiscount = calculateMemberDiscount(subtotal, membership);

    finalAmount = subtotal - discount - memberDiscount;

    paymentFee = calculatePaymentFee(finalAmount, payment);

    finalAmount = finalAmount + paymentFee;

    displayBill(subtotal, discount, memberDiscount, paymentFee);

    printf("\nfinal payable amount: %.2f", finalAmount);

    return 0;
}

float calculateSubtotal(float price, int quantity){
    return price*quantity;
}

float calculateDiscount(float subtotal){

    if(subtotal>5000){
        return subtotal*0.10;
    }

    return 0;
}

float calculateMemberDiscount(float subtotal, char membership){
    if(membership == 'Y' || membership == 'y'){
        return subtotal*0.05;
    }
    return 0;
}

float calculatePaymentFee(float amount, char payment){
    if(payment == 'C' || payment == 'c'){
        return amount*0.02;
    }
    return 0;
}

void displayBill(float subtotal, float discount, float memberDiscount, float fee){

    printf("\n\nSHOPPING BILL\n");
    printf("\nsubtotal: %.2f", subtotal);
    printf("\n10%% discount: %.2f", discount);
    printf("\nmember discount: %.2f", memberDiscount);
    printf("\npayment fee: %.2f", fee);
}
