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

float discount(int chips)
{
    float extra;
    extra = (CANDY_PRICE/2) * (chips/2);
    printf("%.2f extra\n", extra);
    return extra ;
}

float overalldiscount (float total)
{
    float new_total = total * 0.9;
    float discount = total * 0.1;
    printf("Discount: %.2f\n", discount);
    return new_total;
}

// print 67 lines

float cost_lesschips(float apples, float carrots, int chips, int candy)
{
    float total;
    total = (apples * APPLES_PRICE) + (carrots * CARROTS_PRICE) + (chips * CHIPS_PRICE) + (candy * CANDY_PRICE);
    return total;
}
float cost_morechips(float apples, float carrots, int chips)
{
    float a, b, c;
    a = apples * APPLES_PRICE;
    b = carrots * CARROTS_PRICE;
    c = chips * CHIPS_PRICE;
    printf("%d * %.2f = %.2f\n", chips, CHIPS_PRICE, c);
    printf("%.2f %.2f %.2f\n", a, b, c);
    float total = (apples * APPLES_PRICE) + (carrots * CARROTS_PRICE) + (chips * CHIPS_PRICE);
    printf("total: %.2f\n", total);
    return total;
}


int main(void)
{
    float apples, carrots, total;
    int chips, candy;

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
            int chip = chips - 1;
            candfifty = discount(chip);
            total += candfifty;

        }
        printf("balls %.2f\n", total);
        total += cost_morechips(apples, carrots, chips);
        printf("%.2f\n", total);
    }
    else
    {
        total += cost_lesschips(apples, carrots, chips, candy);
    }

    if (apples >= 1.0f && carrots >= 1.0f && chips >= 1 && candy >= 1)
    {
        total = overalldiscount(total);
    }

    float after_tax = total * TAX;

    printf("Total: $%.2f\n", total);
    printf("Tax (5%%): $%.2f\n", after_tax);
    return 0;
}