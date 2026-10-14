#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int check(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||(ch >= '0' && ch <= '9')){
        return 1;
    }

    return 0;
}



extern int cnt;
int k=0;

void macro_replacement(char (*ptr)[100],char *ifile)
{
	FILE *fp=NULL;

	char *q=NULL,*r=NULL;
	char (*name)[100]=NULL;
        char (*val)[100]=NULL;

	for(int x=0;x<cnt;x++)
	{
		q=ptr[x];
		int i=0,j=0;

		char str1[50]={0},str2[50]={0};

		while((q=strstr(q,"#define"))!=NULL)
		{
			r=q;
			q=q+strlen("#define");

			while( *q != '\0')
			{
				if( *q == ' ')
				{
					q++;
					while(*q != ' ' && *q!='\n' && *q!='\0')
					{
						str1[i++]=*q;
						q++;
					}
					name = realloc( name, (k+1)*sizeof(*name));
					val = realloc( val,   (k+1)*sizeof(*val));
				        strcpy( name[k] ,str1);

					q++;
					while( *q != '\n'&& *q !='\0')
					{
						str2[j++]=*q;
						q++;
					}
					strcpy( val[k] ,str2);
					k++;	

					memmove(r,q+1,strlen(q+1)+1);
				}

				q++;
			}
	        }
	}
	char *b=NULL,*d=NULL;
        int l1,l2;

	for(int j=0;j<k;j++)
        {
	for(int i=0;i<cnt;i++)
	{
		b=ptr[i];

		 while((b=strstr(b,name[j]))!=NULL)
		 {
			 l1=strlen(name[j]);
			 l2=strlen(val[j]);

			 if((!(check(*(b-1)) || *(b-1) == '_' ||  *(b-1) == '"'))  &&  !(check(*(b+l1)) || *(b+l1) == '_'))
			 {

			  d= b + l1;

                         memmove( b+l2, d, strlen(d)+1);

			 memcpy(b,val[j],l2);

			 b+=l2;
			 }
			 else
			 b++;
		 }
	}
	}

	fp=fopen(ifile,"a");

	if(fp==NULL)
	{
		puts("failed to open");
		exit(0);
	}
	for(int i=0;i<cnt;i++)
	{
		fputs(ptr[i],fp);
	}
	fclose(fp);
}
