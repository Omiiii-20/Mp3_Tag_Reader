#include <stdio.h>
#include <string.h>
#include "file.h"

View datas[6];

int main(int argc, char *argv[])
{

    if (argc <= 2)
    {
        printf("Invalid Arguments\n");
        printf("should be -->: %s -v <filename>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-v") == 0)
    {
        if (!strstr(argv[2], ".mp3"))
        {
            printf("Please provide an .mp3 file\n");
            return 1;
        }
        view(datas, argv);

        printf("-------------------------------------------\n");
        for (int i = 0; i < 6; i++)
        {

            printf("\t\t%s --\t%s\n", datas[i].tag, datas[i].buffer);
        }
        printf("-------------------------------------------\n");

    }
    else if (strcmp(argv[1], "-e") == 0)
    {
       
        if (argc < 5)
        {
            printf("Usage: %s -e <file.mp3> <tag-flag> <newdata>\n", argv[0]);
            return 1;
        }
        else if (!strstr(argv[2], ".mp3"))
        {
            printf("Please provide an .mp3 file\n");
            return 1;
        }
        else
        {
            view(datas, argv);

            change(datas, argv);
             
        }
    }
    else
    {
        printf("Invalid argument\n");
        return 1;
    }

    return 0;
}
