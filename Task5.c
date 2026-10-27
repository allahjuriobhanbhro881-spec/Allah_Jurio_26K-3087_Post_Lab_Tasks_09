#include <stdio.h>


float calculateBonus(float basicSalary,int years);
float calculateTax(float salaryWithBonus);

int main(){
    float basicSalary, bonus =0, tax =0, salaryWithBonus, finalSalary;
    int years;

    printf("enter basic salary:");
    scanf("%f", &basicSalary);

    printf("enter years of service: ");
    scanf("%d", &years);

    
    bonus = calculateBonus(basicSalary, years);
    salaryWithBonus = basicSalary+bonus;
    tax = calculateTax(salaryWithBonus);
    finalSalary = salaryWithBonus -tax;

    printf("\n--- rmployee salary summary ---\n");
    printf("basic salary: Rs. %.2f\n", basicSalary);
    printf("bonus: Rs. %.2f\n", bonus);
    printf("tax deducted: Rs. %.2f\n", tax);
    printf("final salary: Rs. %.2f\n", finalSalary);

    return 0;
}


float calculateBonus(float basicSalary,int years){
    if(years>5){
        return basicSalary*0.15;
    }else if(years>=3 && years<=5){
        return basicSalary*0.10;
    } 
    else{
        return basicSalary*0.05;
    }
}


float calculateTax(float salaryWithBonus){
    if(salaryWithBonus >100000.0){
        return salaryWithBonus*0.05;
    }
    return 0.0;
}