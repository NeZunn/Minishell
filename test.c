
// implementation of execve ls -la
# include <unistd.h>
int main(void)
{
    char *argv[3];
    // argv[0] = "/bin/ls";
    // argv[1] = "-la";
    // argv[2] = NULL;
    argv[0] = "-la";
    execve(argv[0], argv, NULL);
    return (0);
}