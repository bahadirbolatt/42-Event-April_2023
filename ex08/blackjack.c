#include <stdio.h>
#include <string.h>

int calc(char c, int res)
{
    if (c == 'A') {
        if (res >= 11)
            return (1);
        return (11);
    }
    if (strchr("TJDKQ", c) != NULL)
        return (10);
    else
        return (c - 48);
}

int main(int ac, char **av)
{
    int res = 0;

    for (int i = 0; av[1][i]; i++)
        res += calc(av[1][i], res);
    res == 21 ? printf("Blackjack!\n") : printf("%d\n", res);
}