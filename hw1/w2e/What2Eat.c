#include <stdio.h>

int main()
{
    printf("---FIRST ROUND STARTED---\n");
    int nPeople;
    printf("Number of people: ");
    scanf("%d", &nPeople);

    if(nPeople <= 1)
    {
        printf("You have to be more than 1 people to play this game.\n");
        return 0;
    }
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
        }
    }
    printf("---FIRST ROUND ENDED---\n\n");

    if(!counter){
        printf("You are eating at home/dorm today\n");
        return 0;
    }

    if(counter == 1){
        int maxSelectionCount = 0;
        int maxSelectionIndex = 0;
        for(int idx=0; idx<5; ++idx){
            if(selectionCount[idx] > maxSelectionCount)
            {
                maxSelectionCount = selectionCount[idx];
                maxSelectionIndex = idx;
            }
        }
        printf("You are eating %s today!\n", foods[maxSelectionIndex]);
        return 0;
    }

    printf("---SECOND ROUND STARTED---\n");
    int newSelectionCount[5] = {0, 0, 0, 0, 0};

    const char* newFoods[counter];
    int x=0;
    for(int idx=0; idx<5; ++idx)
    {
        if(passedThreshold[idx])
        {
            newFoods[x] = foods[idx];
            x++;
        }
    }

    for(int idx=0; idx<(sizeof(newFoods) / sizeof(newFoods[0])); ++idx)
    {
        printf("%d-%s\n", idx+1, newFoods[idx]);
    }

    for(int idx = 1; idx <= nPeople; ++idx)
    {
        int selection;
        printf("Person number %d, What do you prefer to eat? (Please provide an integer bw. 1-%d): ", idx, counter);
        scanf("%d", &selection);
        newSelectionCount[selection-1]++;
    }

    int maxVoteIndex = 0;
    int maxVote = 0;

    for(int idx=0; idx<counter; ++idx)
    {
        if(newSelectionCount[idx]>maxVote){
            maxVote = newSelectionCount[idx];
            maxVoteIndex = idx;
        }
    }
    printf("You are eating %s today!\n", newFoods[maxVoteIndex]);

    return 0;
}
