#include <stdio.h>

#define APPLES_PRICE 5.99f
#define CARROTS_PRICE 3.99f
#define CHIPS_PRICE 2.99f
#define CANDY_PRICE 1.50f

float discount(int chips)
{
    float extra;
    extra = (CANDY_PRICE/2) * (chips/2);
    return extra ;
}
/** 
int overalldiscount ()
{

}


int cost()
{

}
*/
int main()
{
    float apples, carrots, total;
    int chips, candy;

    total = 0;

    printf("Apples:     ");
    printf("(7.20  kg) : ");
    scanf("%f", &apples);

    printf("Carrots:    ");
    printf("(4.10  kg) : ");
    scanf("%f", &carrots);

    printf("Chips:      ");
    printf("(9  units) : ");
    scanf("%d", &chips);

    printf("Candy:      ");
    printf("(3  units) : ");
    scanf("%d", &candy);
    
    if(chips >= 2)
    {
        float candfifty;
        if (chips % 2 == 0)
        {
            candfifty = discount(chips);
            total += candfifty;
        }
        else if (chips % 2 != 0)
        {
            chips -= 1;
            candfifty = discount(chips);
            total += candfifty;

        }
    }

    printf("Total: $%.2f\n", total);
    return 0;
}