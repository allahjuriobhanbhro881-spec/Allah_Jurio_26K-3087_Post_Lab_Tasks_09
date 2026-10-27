#include <stdio.h>

void evenOdd(int num);
void palidrome(int num);
void prime(int num);
// int primeCheck(int num);

int main(){

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    evenOdd(num);
    palidrome(num);
    prime(num);

    return 0;
}

void prime(int num){
    int counter = 0;
    for(int i=1;i<=(num/2);i++){
        if(num%i == 0){
            counter++;
        }
    }

    if(counter <= 2){
        printf("\n Prime Number");
    }
    else{
        printf("\nNot Prime Number");
    }
}

void evenOdd(int num){
      if(num%2 == 0){
        printf("\nEven");
      }
      else{
        printf("\nOdd");
      }
}

void palidrome(int num){
    int sum = 0,counter=0, num2 = num, num3 = num;
    
    while(num>0){
        num = num/10;
        counter++;
    }

    int mult = 1;

    for(int i=1;i<=counter-1;i++){
         mult = mult*10;
    }

    
    while(num2>0){
        int d = num2%10;
        num2 = num2/10;

        sum = sum + d*mult;
        mult = mult/10;
       
    }

    if(sum == num3){
        printf("\nPalindrome");
    }
    else{
        printf("\nNot Palindrome");
    }
}