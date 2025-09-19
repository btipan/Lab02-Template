#include <stdio.h>>
#include <math.h>>

float hypotenuse_calc(float x, float y)
{
    float x_square, y_square, hypotenuse;
    x_square = x * x;
    y_square = y * y;
    hypotenuse = sqrtf(x_square + y_square);
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
        smallest = length_two;
    else
    smallest = length_one;
    
    if (length_one > length_three)
        smallest = length_three;
    else
        smallest = length_one;
    
    if (length_two > length_three)
        smallest = length_two;
    else
        smallest = length_three;
    
    return smallest;
}


main(void)
{
    float x_1, y_1, x_2, y_2, x_3, y_3, distance_1, distance_2, distance_3, shortest;

    printf("Point 1: ");
    scanf("(%f, %f)", &x_1, y_1);
    printf("Point 1: ");
    scanf("(%f, %f)", &x_2, y_2);
    printf("Point 1: ");
    scanf("(%f, %f)", &x_3, y_3);

    distance_1 = vector(x_1, y_1, x_2, y_2);
    distance_2 = vector(x_1, y_1, x_3, y_3);
    distance_3 = vector(x_2, y_2, x_3, y_3);

    if (distance_1 == distance_2 && distance_3 == distance_2)
    {
        printf("All points are equal distance: %.2f\n", distance_1);
        return 0;
    }

    else
    {
        shortest = comparison()
    }

    return 0;
}