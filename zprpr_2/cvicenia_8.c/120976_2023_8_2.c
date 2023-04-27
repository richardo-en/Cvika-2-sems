#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **food_names = NULL;     
    float *food_prices = NULL, price;   
    int *food_counts = NULL, product_count;      
    char **company_names = NULL;  
    int records_count = 0, was_added = 0;
    char input, product_name[50] , company_name_by[50];

    while (input != 'x')
    {
        printf("Enter 'i' to insert a new product or 'x' to exit: ");
        scanf(" %c", &input);
        if (input == 'i')
        {
             scanf(" %[^\n]" , product_name);
             scanf(" %[^\n]" , company_name_by);
             scanf(" %f" , &price);
             scanf(" %d" , &product_count);
            //check for same records
            for (int i = 0; i < records_count; i++)
            {
                if (strcmp(product_name , food_names[i]) == 0)
                {
                    food_counts[i] += product_count;
                    was_added = 1;
                    break;
                }
            }

            if (was_added == 0)
            {
                if (food_counts == NULL)
                {
                    records_count++;
                    food_names = malloc(sizeof(char * ) * records_count);
                    food_names[records_count-1] = malloc(sizeof(char) * 50);

                    company_names = malloc(sizeof(char * ) * records_count);
                    company_names[records_count-1] = malloc(sizeof(char) * 50);

                    food_prices = malloc(sizeof(char) * records_count);
                    food_counts = malloc(sizeof(char));
                }else{
                    records_count++;
                    food_names = realloc(food_names , sizeof(char * ) * records_count);
                    food_names[records_count-1] = malloc(sizeof(char) * 50);

                    company_names = realloc(company_names , sizeof(char * ) * records_count);
                    company_names[records_count-1] = malloc(sizeof(char) * 50);

                    food_prices = realloc(food_prices , sizeof(char) * records_count);
                    food_counts = realloc(food_counts , sizeof(char) * records_count);
                }

                strcpy(food_names[records_count - 1] , product_name);
                strcpy(company_names[records_count - 1] , company_name_by);
                food_prices[records_count - 1] = price;
                food_counts[records_count - 1] = product_count;
            }
        }else if (input == 'v')
        {
            printf("Product Name\tCompany Name\tPrice\tCount\n");
            for (int i = 0; i < records_count; i++)
            {
                printf("%s\t%s\t%.2f\t%d\n", food_names[i], company_names[i], food_prices[i], food_counts[i]);
            }
        }
        
    }
    
}   