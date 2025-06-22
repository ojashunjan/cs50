#include <stdio.h>
#include <stdint.h>


const int LOCK = 512;

uint8_t BUFF[512];

FILE *a;

FILE *b;

int c = 0;

char name[8];

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Wrong\n");

        return 1;
    }


    char *input = argv[1];

    a= fopen(input, "r");


    if (a== NULL)
    {
        printf("Error");
        return 2;
    }


    while (fread(BUFF, LOCK, 1, a))
    {
        if (BUFF[0] == 0xff && BUFF[1] == 0xd8 && BUFF[2] == 0xff && (BUFF[3] == 0xe0 || BUFF[3] == 0xe1))
        {

            if (b!= NULL)
            {
                fclose(b);
            }


            sprintf(name, "%03d.jpg", c);

            b= fopen(name, "w");

            c++;
        }

        if (b!= NULL)
        {
            fwrite(BUFF, LOCK, 1, b);
        }

    }

    if (b!= NULL)
    {
        fclose(b);
    }

    fclose(a);
    return 0;
}
