#include <stdio.h>

int main(){

    int marks[2][3][4]=
    {
        {
          {60,70,75,45},
          {90,35,50,60},
          {45,60,65,70} 
        },
        {
          {85,90,75,80},
          {70,65,55,40},
          {95,90,70,75}
        }
    };

    int avg_counter = 0;

    for(int i=0;i<2;i++){
        int highest_scoring = marks[0][0][0], highest_scoring_section=0, highest_avg=0, highest_avg_sec = 0;

        for(int j=0;j<3;j++){
            int total=0, avg=0;
            for(int k=0;k<4;k++){
                total = total + marks[i][j][k];
            }

            if(highest_scoring < total){
               highest_scoring = total;
               highest_scoring_section = i+1;
            }
            avg = total/4;
            printf("\ntotal marks of student: %d: %d",j+1,total);
            printf("\naverage marks of student: %d", avg);

            if(avg >= 50){
                avg_counter++;
            }
            if(avg > highest_avg){
                highest_avg = avg;
                highest_avg_sec = i+1;
            }
        }
        printf("\n\nHighest Scoring student in section: %d",highest_scoring_section);
        printf("\nHighest Average section: %d\n ",highest_avg_sec);
    }

    printf("\n\nAverage at Least 50 students are: %d", avg_counter);


    return 0;
}