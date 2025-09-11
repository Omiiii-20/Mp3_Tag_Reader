#include <string.h>
#include <stdlib.h>
#include "file.h"

// extern View datas[6];

int fedit(int index, View *datalist, char *argv[])
{
    FILE *fptr;
    FILE *fptr2;
    fptr = fopen(argv[2], "rb");
    if (fptr == NULL)
    {
        printf("Error in opening the file\n");
        return 1;
    }

    int len = strlen(argv[4]);
    long len2 = datalist[index].ptrpos; // ✅ fixed indexing
    fptr2 = fopen("temp.mp3", "wb");
    rewind(fptr);
    char buffer[1024];
    // char head[10] = {'0'};
    size_t bytes;
    
    while ((bytes = fread(buffer, 1, sizeof(char), fptr)) > 0)
    {
        if (ftell(fptr) > len2)
        {
            break;
        }
        fwrite(buffer, 1, bytes, fptr2);
    }

    
    int n = len;
    len = len + 1;
    unsigned char *cptr = (unsigned char *)&len;

    char temp = cptr[3];
    cptr[3] = cptr[0];
    cptr[0] = temp;

    temp = cptr[2];
    cptr[2] = cptr[1];
    cptr[1] = temp;

    fwrite(&len, sizeof(int), 1, fptr2);
    
    // Skip 3 bytes in old file (flags/encoding etc.)
    fseek(fptr, 3, SEEK_CUR);
    for (int i = 0; i < 3; i++)
    {

        bytes = fread(buffer, 1, 1, fptr); // read exactly 1 byte
        fwrite(buffer, sizeof(char), bytes, fptr2);
    }

    // Write new tag data
    fwrite(argv[4], sizeof(char), n, fptr2);
    // printf("hello\n");

    // Skip old tag data
    fseek(fptr, datalist[index].size-1, SEEK_CUR);
    // // Copy rest of file
    while ((bytes = fread(buffer, sizeof(char), 1, fptr)) > 0)
    {
        fwrite(buffer, sizeof(char), bytes, fptr2);
    }

    fclose(fptr);
    fclose(fptr2);

    remove(argv[2]);
    rename("temp.mp3", argv[2]);

    return 0;
}
