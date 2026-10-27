#include <stdio.h>

void inputData(int *parcelWeight, int *del_distance, char *customer_memb);
int baseCharges(int Parcel_weight);
int distanceCharges(int dist);
int discount(int totalCharges, char memebership);
int finalAmount(int total_charges,int disc);

int main(){

    int p_w, d_d;
    char c_m;

    inputData( &p_w, &d_d, &c_m);

    int base_charges = baseCharges(p_w);
    int distance_charges = distanceCharges(d_d);
    int total_charges = base_charges + distance_charges;
    int disc = discount(total_charges, c_m);
    int fin_am = finalAmount(total_charges, disc);


    printf("\nBase Charges: %d", base_charges);
    printf("\ndistance charges: %d", distance_charges);
    printf("\nTotal Charges: %d", total_charges);
    printf("\ndiscount amount: %d", disc);
    printf("\nFinal amount: %d", fin_am);

    

    return 0;
}

void inputData(int *parcelWeight, int *del_distance, char *customer_memb){
    printf("\n Enter parcel weight: ");
    scanf("%d", parcelWeight);

    printf("\n Enter delivery distance weight: ");
    scanf("%d", del_distance);

    printf("\n Enter customer membership: ");
    scanf(" %c", customer_memb);
}

int baseCharges(int Parcel_weight){
    int cost = 0;
     if(Parcel_weight <= 2){
        cost = 200;
     }
     else if(Parcel_weight > 2 && Parcel_weight <= 5){
        cost = 400;
     }
     else if(Parcel_weight > 5){
        cost = 700;
     }

     return cost;
}

int distanceCharges(int dist){
    int total = 0;
    if(dist > 10){
       total = dist*20;
    }

    return total;
}

int discount(int totalCharges, char membership){ 
    int disc = 0;
  if(membership == 'Y' || membership == 'y'){
    if(totalCharges > 1000){
       disc = (10*totalCharges)/100;
    }
   }

   return disc;
}

int finalAmount(int total_charges,int disc){
    return total_charges-disc;
}