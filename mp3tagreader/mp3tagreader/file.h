#include<stdio.h>
#include<string.h>

typedef struct {
    char tag[5];
    char buffer[1024];
    int size ;
    long    ptrpos;
}View;

// extern View datas[6]; 

int view( View * datas  , char * argv[]);
int change(View * datas, char * argv[]);
int fedit(int , View * datas , char * argv[] );