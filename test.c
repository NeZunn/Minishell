
// implementation of execve ls -la
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
int main(int argc, char **argv, char **envp)
{
    char *args[2];
    args[0] = "/bin/env";
    // argv[1] = "echo";
    args[1] = NULL;
    // argv[2] = NULL;

    // execve(argv[0], argv, NULL);
    // printf("%d", isspace('a'));

    // int i = 0;
    // while (envp[i])
    //     i++;
    // envp[i] = "NUMBER=42";
    execve(args[0], args, NULL);
    return (0);
}