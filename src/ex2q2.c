#include <stdio.h>
#include <math.h>

float hypotenuse_calc(float x, float y)
{
    float x_square, y_square, hypotenuse;
    x_square = x * x;
    y_square = y * y;
    float length = x_square + y_square;
    hypotenuse = sqrtf(length);
    return hypotenuse;
}

float vector(float x_start, float y_start, float x_end, float y_end)
{
    float x_diff, y_diff, length;
    x_diff = x_end - x_start;
    y_diff = y_end - y_start;
    length = hypotenuse_calc(x_diff, y_diff);
    return length;
}

float comparison(float length_one, float length_two, float length_three)
{
    float smallest;
    if (length_one > length_two)
        if (length_two > length_three)
        {
            smallest = 3;
        }
        else
        {
            smallest = 2;
        }
    else if (length_two > length_one)
    {
        if (length_one > length_three)
        {
            smallest = 3;
        }
        else
        {
            smallest = 1;
        }
    }

    return smallest;
}


int main(void)
{
    float x_1, y_1, x_2, y_2, x_3, y_3, distance_1, distance_2, distance_3, shortest;
    int c_one, c_two, c_three;

    printf("Point 1: ");
    c_one = scanf(" (%f, %f)", &x_1, &y_1);

    printf("Point 2: ");
    c_two = scanf(" (%f, %f)", &x_2, &y_2);

    printf("Point 3: ");
    c_three = scanf(" (%f, %f)", &x_3, &y_3);
    printf("\n");

    if (c_one != 2 || c_two != 2 || c_three != 2)
    {
        return -1;
    }

    distance_1 = vector(x_1, y_1, x_2, y_2);
    distance_2 = vector(x_1, y_1, x_3, y_3);
    distance_3 = vector(x_2, y_2, x_3, y_3);

    int check_dist1, check_dist2, check_dist3;
    
    check_dist1 = distance_1;
    check_dist2 = distance_2;
    check_dist3 = distance_3;

    if (distance > 1000)
    {
        
    }

    if (check_dist1 == check_dist2 && check_dist3 == check_dist2)
    {
        printf("All points are equal distance: %.2f\n", distance_1);
        return 0;
    }

    else if (check_dist1 == check_dist2)
    {
        printf("P1<->P2: %1.2f\nP1<->P3: %1.2f\n", distance_1, distance_2);
    }

    else if (check_dist3 == check_dist2)
    {
        printf("P1<->P3: %1.2f\nP2<->P3: %1.2f\n", distance_2, distance_3);
    }

    else if (check_dist3 == check_dist1)
    {
        printf("P1<->P2: %1.2f\nP2<->P3: %1.2f\n", distance_1, distance_3);
    }

    else
    {
        shortest = comparison(distance_1, distance_2, distance_3);
        if (shortest == 1)
        printf("P1<->P2: %1.2f\n", distance_1);

        else if (shortest == 2)
        printf("P1<->P3: %1.2f\n", distance_2);

        else
        printf("P2<->P3: %1.2f\n", distance_3);
    }
    return 0;
}