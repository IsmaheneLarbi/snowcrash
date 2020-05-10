#include <fcntl.h>
#include <strings.h>

int main(int argc, char **argv)
{
        int i;
        int it;
        int c;

        i = 0;
        c = i;
        it = strlen(const char *(&argv[1]));
        while(i < it)
        {
                c = argv[1][i] + i;
                write(1, c, 1);
                i++;
        }
}
