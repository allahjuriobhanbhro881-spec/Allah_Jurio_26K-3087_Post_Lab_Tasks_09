
#include <stdio.h>

int main()
{
    int sales_data[2][3][4] =
    {
        {
            {500, 700, 400, 1000},
            {300, 500, 1500, 400},
            {200, 150, 2000, 2500}
        },
        {
            {3000, 1600, 1000, 1500},
            {200, 500, 1000, 700},
            {800, 500, 1500, 300}
        }
    };

    int highest_sale_branch = 0, branch = 0;
    int week_array[4] = {0, 0, 0, 0};

    for(int i=0; i<2; i++){
        int total_quantity_branch=0;
        int highest_sale_product=0;
        int highest_product_quantity =0;

        for(int j=0; j<3; j++){
            int total_quantity_product=0;

            for (int k=0; k<4; k++){
                total_quantity_product += sales_data[i][j][k];
                week_array[k] += sales_data[i][j][k];
            }

            printf("\ntotal quantity of product %d: %d",
                   j+1, total_quantity_product);

            total_quantity_branch += total_quantity_product;

            if(total_quantity_product > highest_product_quantity){
                highest_product_quantity = total_quantity_product;
                highest_sale_product = j+1;
            }
        }

        printf("\ntotal quantity of branch %d: %d",
               i+1, total_quantity_branch);

        printf("\nhighest selling product in branch %d: product %d",
               i+1, highest_sale_product);

        if (total_quantity_branch > highest_sale_branch)
        {
            highest_sale_branch = total_quantity_branch;
            branch = i+1;
        }

        printf("\n");
    }

    int highest_week =0;

    printf("\nweekly total sales:\n");

    for (int k=0; k<4; k++)
    {
        printf("week %d: %d\n", k+1, week_array[k]);

        if (week_array[k] > week_array[highest_week])
        {
            highest_week =k;
        }
    }

    printf("\nhighest sales week: week %d", highest_week+1);

    printf("\ngreatest quantity sold by branch: %d", branch);

    printf("\ngreatest branch quantity: %d\n", highest_sale_branch);

    return 0;
}
