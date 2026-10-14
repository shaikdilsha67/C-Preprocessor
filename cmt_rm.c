#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
void writefile(char (*buf)[100],char *filename);
void* comment(char (*ptr)[100]);
void* readfile(char *file);
*/
extern int cnt;
/*
int main(int argc,char *argv[])
{
        char (*buf)[100]=NULL;
	char str[1000],*p;
	int l1;

        if(argc!=2)
        {
                printf("incorrrect input\n");
		puts("enter: exe input_file");
                exit(0);
        }
	strcpy(str,argv[1]);
	l1=strlen(argv[1]);
	p=str;
	*(p+l1-1)='i';

        buf=readfile(argv[1]);
        buf=comment(buf);
	header_inclusion(buf);

        //writefile(buf,str);
}
*/

void* readfile(char *file)
{
        FILE *fptr=NULL;
        char (*ptr)[100]=NULL,str[200];

        fptr=fopen(file,"r");
        if(fptr==NULL)
        {
                puts("failed to open");
                exit(0);
        }
        while((fgets(str,200,fptr))!=NULL)
        {
                ptr=realloc(ptr,(cnt+1)*sizeof(*ptr));
                strcpy(ptr[cnt],str);
                cnt++;
        }
        return ptr;
}


void* comment(char (*ptr)[100])
{
        char *q=NULL,*temp=NULL,*p=NULL;
        int t,c;

        for(int i=0;i<cnt;i++)
        {
                q=ptr[i];
      
                while(*q!='\0')
                {
                          if(*q=='/')
			  {
				  if(*(q+1)=='/')
				  {
                          
				  t=0;

				   while( q[t]!='\n' && q[t]!='\0')
				   {
					t++;
				   }
                            
                                   memmove(q,q+t,strlen(q+t)+1);
			           }
                                  else
			          {
                                  if(*(q+1)=='*')
                                  {
                                                temp=q;
                                

                                                while(*temp!='\0')
                                                {
                                                        if(*temp =='\n')
                                                        {
                                                                memmove(q,temp,strlen(temp)+1);
                                                                q=ptr[++i];
                                                                temp=q;
                                                        }
                                                        else
                                                        {
                                                                if( (*temp=='*') && (*(temp+1)=='/'))
                                                                {
                                                                        //memmove(q,temp+2,strlen(temp+2)+1);
									memset(q,' ',(temp+2)-q);
									q=temp+2;
                                                                        break;
                                                                }
                                                        }

                                                        temp++;
                                                }
                                      }
				  }
			  }
			  else if(*q =='"' || *q=='\'')
			  {
			   p=q;
		           c=0;
		           while(*p != '\0')
			   {
			   if(*q == *p)
			   {
			   c++;
			   }
	                   if(c==2)
		           break;
	                   p++;		    
			   }
	                   q=p;
			}

                        q++;
                }
        }

        return ptr;
}

/*
void writefile(char (*buf)[100],char *filename)
{
        FILE *fp=NULL;
        fp=fopen(filename,"w");
        for(int i=0;i<cnt;i++)
        {
                fputs(buf[i],fp);
        }
}


*/
