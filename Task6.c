#include <stdio.h>

// Function declaration
int checkLoanEligibility(int age,float salary,float existingPayments,float *remainingIncome, float *maxLoan);

int main(){
    int age;
    float salary, existingPayments, remainingIncome =0, maxLoan =0;

    printf("enter age: ");
    scanf("%d", &age);

    printf("enter monthly salary: ");
    scanf("%f", &salary);

    printf("enter existing monthly loan payments: ");
    scanf("%f", &existingPayments);

    printf("\n loan eligibility status \n");

 
    int eligible = checkLoanEligibility(age, salary, existingPayments, &remainingIncome, &maxLoan);

    if(eligible){
        printf("Congratulations! You qualify for the loan.\n");
        printf("Remaining Monthly Income: Rs. %.2f\n", remainingIncome);
        printf("Maximum Loan Amount: Rs. %.2f\n", maxLoan);
    } 
    else{
        printf("Status: Loan application rejected.\n");
    }

    return 0;
}


int checkLoanEligibility(int age, float salary, float existingPayments, float *remainingIncome, float *maxLoan){
    int eligible = 1;
    *remainingIncome = salary-existingPayments;

    if(age<21){
        printf("reason for ineligibility: age is below 21 years.\n");
        eligible =0;
    }

    if(salary <50000.0){
        printf("reason for ineligibility: monthly salary is below Rs. 50,000.\n");
        eligible=0;
    }
if(*remainingIncome<(0.40*salary)){
        printf("reason for ineligibility: remaining income is less than 40%% of the monthly salary.\n");
        eligible=0;
    }

    if(eligible){
        *maxLoan = (*remainingIncome)*10.0;
    }

    return eligible;
}