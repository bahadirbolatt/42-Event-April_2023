#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 2)
        return 0;
    char *str_copy = strdup(av[1]);
    char *tk_str_copy = strtok(str_copy, " ");

    int max_len = 0;
    while (tk_str_copy) // finding longest word
    {
        int len = strlen(tk_str_copy);
        if (len > max_len)
            max_len = len;
        tk_str_copy = strtok(NULL, " ");
    }

    for (int i = 0; i < max_len + 4; i++) // write '*' to up
        write(1, "*", 1);
    write(1, "\n", 1);

    free(str_copy);
    str_copy = strdup(av[1]);
    tk_str_copy = strtok(str_copy, " ");

    while(tk_str_copy)
    {
        int c = max_len - strlen(tk_str_copy);
        printf("* %s", tk_str_copy);
        for (int i = 0; i < c; i++) //put space as difference of longest line
            putchar(' ');
        printf(" *\n");
        tk_str_copy = strtok(NULL, " ");
    }

    for (int i = 0; i < max_len + 4; i++) // write '*' to down
        write(1, "*", 1);
    write(1, "\n", 1);

    free(str_copy);
    return 0;
}
