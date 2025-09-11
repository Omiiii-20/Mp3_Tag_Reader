#include "file.h"
#include <string.h>
#include <stdlib.h>

int change (View * datalist , char *argv[])
{
    int index = -1;
    const char * op=argv[3];

    if(strcmp(op,"-t") == 0)
    {
        for(int i = 0 ; i < 6 ; i++)
        {
            if(strcmp( "TIT2",datalist[i].tag ) == 0)
            {
                index = i;
                
                break;
            }
        }if (index != -1)
        fedit(index, datalist, argv);
    else
        printf("Error: TIT2 tag not found\n");
    }
    else if(strcmp(op,"-A") == 0)
    {
        for(int i = 0 ; i < 6 ; i++)
        {
            if(strcmp("TPE1",datalist[i].tag ) == 0)
            {
                index = i;
                
                break;
            }
        }
        fedit(index , datalist , argv);
    }
    else if(strcmp(op,"-a") == 0)
    {
        for(int i = 0 ; i < 6 ; i++)
        {
            if(strcmp("TALB",datalist[i].tag) == 0)
            {
                index = i;
               
                break;
            }
        }
         fedit(index , datalist , argv);
    }
    else if(strcmp(op,"-y") == 0)
    {
        for(int i = 0 ; i < 6 ; i++)
        {
            if(strcmp( "TYER",datalist[i].tag ) == 0)
            {
                index = i;
                
                break;
            }
        }
        fedit(index , datalist , argv);
    }
    else if(strcmp(op,"-cn") == 0)
    {
        for(int i = 0 ; i < 6 ; i++)
        {
            if(strcmp("TCON",datalist[i].tag ) == 0)
            {
                index = i;
               
                break;
            }
        }
         fedit(index , datalist , argv);
    }
    else if(strcmp(op,"-cm") == 0)
    {
        for(int i = 0 ; i < 6 ; i++)
        {
            if(strcmp("COMM",datalist[i].tag ) == 0)
            {
                index = i;
               
                break;
            }
        }
         fedit(index , datalist , argv);
    }

   
    else
    {
        printf("Tag not found!\n");
    }

    // return 0;
}
