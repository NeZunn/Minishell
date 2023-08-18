
// implementation of execve ls -la
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
int main(int argc, char **argv)
{
    // char *argv[3];
    // // argv[0] = "/bin/ls";
    // // argv[1] = "-la";
    // // argv[2] = NULL;
    // argv[0] = "-la";
    // execve(argv[0], argv, NULL);
    printf("%d", isspace('a'));
    return (0);
}