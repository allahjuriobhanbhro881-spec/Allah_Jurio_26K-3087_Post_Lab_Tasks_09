#include <stdio.h>


float calculateBillAmount(int units,char category);
float calculateSurcharge(float bill);

int main() {
    int units;
    char category;
    float bill =0, surcharge =0, final_amount;

    printf("enter customer category D for domestic, C for commercial: ");
    scanf(" %c", &category);

    if(category != 'D' && category != 'd' && category != 'C' && category != 'c'){
        printf("invalid customer category entered.\n");
        return 1;
    }

    printf("enter units consumed: ");
    scanf("%d", &units);

 
    bill = calculateBillAmount(units,category);
    surcharge = calculateSurcharge(bill);
    final_amount = bill+ surcharge;

    printf("\n--- electricity bill Summary ---\n");
    printf("units consumed: %d\n", units);
    printf("bill amount: Rs. %.2f\n", bill);
    printf("surcharge: Rs. %.2f\n", surcharge);
    printf("final payable amount: Rs. %.2f\n", final_amount);

    return 0;
}

float calculateBillAmount(int units,char category) {
    float bill =0;
    if(category == 'D' || category == 'd'){
        if(units <=100) {
            bill = units*15.0;
        }else{
            bill = (100*15.0) + ((units-100)*20.0);
        }
    } 
    else if(category == 'C' || category == 'c'){
        bill = units*25.0;
    }
    return bill;
}

float calculateSurcharge(float bill){
    if (bill>5000.0) {
        return bill*0.05;
    }
    return 0.0;
}