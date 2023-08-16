# include <stdio.h>

int main(int argc, char **argv)
{
    int i = -1;

    while (argv[++i])
        printf("%s\n", argv[i]);
    return (0);
}