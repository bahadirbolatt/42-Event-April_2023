#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char *av[])
{
    if(ac != 2)
        return 0;
    int i, points = 0, ace_count = 0;

    for (i = 1; i < strlen(av[1]); i++)
    {
        if (av[1][i] == 'J' || (av[1][i] == 'Q' || av[1][i] == 'D') || av[1][i] == 'K')
            points += 10;
        else if (av[1][i] == 'A')
        {
            ace_count++;
            points += 11;
        } else
            points += atoi(&av[1][i]);
    }

    while (points > 21 && ace_count > 0) {
        points -= 10;
        ace_count--;
    }

    if (points == 21 && ac == 3)
        printf("Blackjack!\n");
    else
        printf("%d\n", points);

    return 0;
}
