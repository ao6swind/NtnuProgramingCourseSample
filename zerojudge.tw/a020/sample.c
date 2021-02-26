#include <stdio.h>

int main()
{
    char id[10];
    int zone[26] = {
        10, 11, 12, 13, 14, 15, 16, 17, 34,
        18, 19, 20, 21, 22, 35, 23, 24, 25,
        26, 27, 28, 29, 32, 30, 31, 33};

    scanf("%s", id);

    int zone_index = id[0] - 'A';
    int city_number = zone[zone_index];
    int n1 = city_number / 10;
    int n2 = city_number % 10;

    int total = n1 + n2 * 9 + (id[9] - '0');
    for (int i = 1; i < 9; i++)
    {
        total += (id[i] - '0') * (9 - i);
    }
    if ((id[1] == '1' || id[1] == '2') && total % 10 == 0)
    {
        printf("real");
    }
    else
    {
        printf("fake");
    }

    return 0;
}
