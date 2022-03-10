#include <stdio.h>

int main()
{
    int nPeople;
    printf("Number of people: ");
    scanf("%d", &nPeople);
    printf("1-Kebab\n2-Burger\n3-Pasta\n4-Lahmacun\n5-Salad or others\n");
    int data[5] = {0, 0, 0, 0, 0};
    for(int idx = 1; idx <= nPeople; ++idx)
    {
        int selection;
        printf("Person number %d, What do you prefer to eat? (Please provide an integer bw. 1-5): ", idx);
        scanf("%d", &selection);
        data[selection-1] += 1;
    }
    for(int idx = 0; idx < 5; ++idx)
    {
        printf("%d. = %d\n", idx, data[idx]);
    }
    return 0;
}