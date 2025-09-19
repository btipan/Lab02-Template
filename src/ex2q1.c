#include <stdio.h>

#define APPLES_PRICE 5.99f
#define CARROTS_PRICE 3.99f
#define CHIPS_PRICE 2.99f
#define CANDY_PRICE 1.50f
#define TAX 1.05f



int input_check (int a, int c, int ch, int ca, float apples, float carrots, int chips, int candy)
{
    int scanf_total = a + c + ch + ca;

    if (apples == 0 && carrots == 0 && chips == 0 && candy == 0)
    {
        return 0;
    }
    else if (apples > 7.2f || carrots > 4.1f || chips > 9 || candy > 3 ) 
    {
        printf("invalid input\n");
        return 1;
    }
    else if (scanf_total < 4)
    {
        printf("Invalid input\n");
        return 1;
    }
    else if (apples < 0.0f || carrots < 0.0f || chips < 0 || candy < 0)
    {
        return 1;
    }
    return 0;
}

float discount(int chips, int candy)
{
    float disc;
    int chip = chips/2;

    if (chip >= candy)
    {
        disc = candy * CANDY_PRICE * 0.5f;
    }
    
    else if (chip < candy)
    {
        int new_quant = candy - chip;
        disc = (new_quant * CANDY_PRICE) + (chip * CANDY_PRICE * 0.5f);
    }
    return disc;
}

float overalldiscount (float apples, float carrots, float chips, float candy)
{
    float discount = (apples + carrots + chips + candy) * 0.10f;
    return discount;
}

int main(void)
{
    float apples, carrots, total, disc_candy;
    int chips, candy;
    float apple_cost, carrot_cost, chips_cost, candy_cost;
    float candy_total, subtotal, tax, discounted, cost_total;

    total = 0;

    printf("Apples:     ");
    printf("(7.20  kg) : ");
    int a = scanf("%f", &apples);

    printf("Carrots:    ");
    printf("(4.10  kg) : ");
    int c = scanf("%f", &carrots);

    printf("Chips:      ");
    printf("(9  units) : ");
    int ch = scanf("%d", &chips);

    printf("Candy:      ");
    printf("(3  units) : ");
    int ca = scanf("%d", &candy);
    
    int check = input_check(a, c, ch, ca, apples, carrots, chips, candy);
    if (check != 0)
    {
        return 1;
    }

    apple_cost = apples * APPLES_PRICE;
    carrot_cost = carrots * CARROTS_PRICE;
    chips_cost = chips * CHIPS_PRICE;
    candy_cost = candy * CANDY_PRICE;


    if(chips >= 2)
    {
        float candfifty = 0;
        disc_candy = 0;
        if (chips % 2 == 0)
        {
            candfifty = discount(chips, candy);
            disc_candy += candfifty;
        }
        else if (chips % 2 != 0)
        {
            int chip = chips - 1;
            candfifty = discount(chip, candy);
            disc_candy += candfifty;

        }
    }

    candy_total = candy_cost - disc_candy;

    if (apples >= 1.0f && carrots >= 1.0f && chips >= 1 && candy >= 1)
    {
        discounted = overalldiscount(apple_cost, carrot_cost, chips_cost, candy_total);
    }

    cost_total = (apple_cost + carrot_cost + chips_cost + candy_total);
    subtotal = cost_total - discounted;
    tax = subtotal * 0.05f;
    total = subtotal + tax;
    
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    printf("| Item     | Quantity       | Cost        | Discount    | Total   |\n");
    if (apples > 0.00f)
    printf("| Apples   |%-7.2f      kg | $    %6.2f | -$     0.00 | $%6.2f |\n", apples, apple_cost, apple_cost);
    if (carrots > 0.00f)
    printf("| Carrots  |%-7.2f      kg | $    %6.2f | -$     0.00 | $%6.2f |\n", carrots, carrot_cost, carrot_cost);
    if (chips > 0)
    printf("| Chips    |%-16d| $    %6.2f | -$     0.00 | $%6.2f |\n", chips, chips_cost, chips_cost);
    if (candy > 0)
    printf("| Candy    |%-16d| $    %6.2f | -$%9.2f | $%6.2f |\n", candy, candy_cost, disc_candy, candy_total);
    printf("-------------------------------------------------------------------\n");
    printf("\n");
    if (discounted > 0)
    printf("Subtotal        : $%2.2f - $%2.2f = $%2.2f\n", subtotal, discounted, total);
    else
    printf("Subtotal        : $%2.2f\n", subtotal);
    printf("Tax (5%%)        : $%2.2f\n", tax);
    printf("----------------------------------------------------\n");
    printf("Total           : $%2.2f\n", total);

    

    return 0;
}