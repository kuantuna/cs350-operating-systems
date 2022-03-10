#include <stdio.h>

int main()
{
    printf("---FIRST ROUND STARTED---\n");
    int nPeople;
    printf("Number of people: ");
    scanf("%d", &nPeople);

    int threshold = nPeople / 2;
    int selectionCount[5] = {0, 0, 0, 0, 0};
    int passedThreshold[5] = {0, 0, 0, 0, 0};
    const char* foods[5];
    foods[0] = "Kebab";
    foods[1] = "Burger";
    foods[2] = "Pasta";
    foods[3] = "Lahmacun";
    foods[4] = "Salad";
    printf("1-%s\n2-%s\n3-%s\n4-%s\n5-%s\n", foods[0], foods[1], foods[2], foods[3], foods[4]);

    for(int idx = 1; idx <= nPeople; ++idx)
    {
        int selection;
        printf("Person number %d, What do you prefer to eat? (Please provide an integer bw. 1-5): ", idx);
        scanf("%d", &selection);
        selectionCount[selection-1]++;
    }

    int counter = 0;
    for(int idx = 0; idx < 5; ++idx)
    {
        if(selectionCount[idx] >= threshold)
        {
            counter++;
            passedThreshold[idx] = 1;
            printf("%s = %d\n", foods[idx], selectionCount[idx]);
        }
    }
    printf("---FIRST ROUND ENDED---\n\n");

    if(!counter){
        printf("You are eating at home/dorm today\n");
        return 0;
    }

    printf("---SECOND ROUND STARTED---\n");
    int newSelectionCount[counter];
    for(int idx=0; idx < counter; ++idx)
    {
        newSelectionCount[idx] = 0;
    }

    const char* newFoods[counter];
    int x=0;
    for(int idx=0; idx<counter; ++idx)
    {
        if(passedThreshold[idx])
        {
            newFoods[x] = foods[idx];
            x++;
        }
    }

    for(int idx = 0; idx < sizeof(newFoods) / sizeof(newFoods[0]); idx++)
    {
        printf("%d-%s\n", idx+1, newFoods[idx]);
    }

    for(int idx = 1; idx <= nPeople; ++idx)
    {
        int selection;
        printf("Person number %d, What do you prefer to eat? (Please provide an integer bw. 1-5): ", idx);
        scanf("%d", &selection);
        newSelectionCount[selection-1]++;
    }

    return 0;
}