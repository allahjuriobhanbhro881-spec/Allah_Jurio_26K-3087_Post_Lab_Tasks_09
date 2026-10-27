
#include <stdio.h>

int main(){

    double temp[2][3][4] = 
    {
      {
        {36.5, 35.5, 37.9, 38.0},
        {34.0, 34.6, 30.0, 30.7},
        {37.8, 37.9, 37.3, 37.4}
      },
      {
        {34.5, 33.3, 33.4, 37.8},
        {32.2, 34.5, 36.7, 37.9},
        {37.6, 38.5, 29.4, 37.8}
      }
    };

   int counter = 0;
   int patients[6], num = 0;

    for(int i=0;i<2;i++){
        double highest_temp=0;
        for(int j=0;j<3;j++){
          double total_temp = 0, avg=0;
            for(int k=0;k<4;k++){
                total_temp = total_temp + temp[i][j][k];

                if(temp[i][j][k] > highest_temp){
                    highest_temp = temp[i][j][k];
                }
            }
            avg = total_temp/4;
            printf("\ntotal temp: patient %d: %0.2f",j+1,total_temp);
            printf("\naverage temp: patient %d: %0.2f",j+1,avg);
            if(avg > 37.5){
                counter++;
            }
            if(avg > 38){
                patients[num] = j+1;
                num++;
            }
            printf("\n\nReadings above 37.5: %d", counter);
        }
        printf("\n\nhighest temp: %d: %0.2f",i+1,highest_temp);
    }

    printf("\n");
    for(int i=0;i<num;i++){
        printf("\npatient %d", patients[i]);
    }

    return 0;
}
