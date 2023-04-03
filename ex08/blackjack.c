#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[]) {
    int i, points = 0, ace_count = 0;

    for (i = 1; i < ac; i++)
    {
        if (av[i][0] == 'J' || (av[i][0] == 'Q' || av[i][0] == 'D')|| av[i][0] == 'K')
            points += 10;
        else if (av[i][0] == 'A')
        {
            ace_count++;
            points += 11;
        } else
            points += atoi(&av[i][0]);
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
