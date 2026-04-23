#include "file.h"
#include <string.h>

int view(View *datas , char *argv[])
{
    int size;
    char data[1020];
    char tag[5];
    FILE *fptr;
   
    fptr = fopen(argv[2], "r");
    if (fptr == NULL)
    {
        printf("Error in opening the file\n");
        return 1;
    }
    fseek(fptr, 10, SEEK_SET);

    for (int i = 0; i < 6; i++)
    {
        fread(datas[i].tag, sizeof(char), 4, fptr) ;
      
        datas[i].tag[4] = '\0';
        datas[i].ptrpos = ftell(fptr);
       
 unsigned char *cptr = (unsigned char *)&(datas[i].size);
        fread(&(datas[i].size), sizeof(char), 4, fptr);
       

        unsigned char temp;
        temp = cptr[3];
        cptr[3] = cptr[0];
        cptr[0] = temp;

        temp = cptr[2];
        cptr[2] = cptr[1];
        cptr[1] = temp;

        fseek(fptr, 3, SEEK_CUR);

        fread(datas[i].buffer, sizeof(char), datas[i].size-1, fptr);
        datas[i].buffer[datas[i].size-1] = '\0';

       
    }
    
    fclose(fptr);
}
