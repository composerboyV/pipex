#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    int    i;

    (void)argv;
    i = 0;
    while (envp[i])
    {
        printf("envp[%d] : %s\n", i, envp[i]);
        i++;
    }
}
