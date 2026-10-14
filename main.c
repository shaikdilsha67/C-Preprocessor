#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#include"header_inclusion.h"
#include"comment_removal.h"
#include"macro_replacement.h"

int cnt=0;


int main(int argc,char *argv[])
{
        char (*buf)[100]=NULL;
        char str[100],*p;
        int l1;
	char headerfile[10][100] = {0};
        int header_count = 0;

        if(argc!=2)
        {
                printf("incorrrect input\n");
                puts("enter: exe input_file");
                exit(0);
        }

	// .i file creats
        strcpy(str,argv[1]);
        l1=strlen(argv[1]);
        p=str;
        *(p+l1-1)='i';

	//function calls

        buf=readfile(argv[1]);
        buf=comment(buf);
        buf=header_inclusion(buf,str);
        macro_replacement(buf,str);
}
