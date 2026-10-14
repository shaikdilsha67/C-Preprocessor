#include<stdio.h>
#include<string.h>
#include<stdlib.h>


extern int cnt;


void* readfile(char *file)
{
        FILE *fptr=NULL;
	char (*ptr)[100]=NULL,str[100];

	cnt=0;
        fptr=fopen(file,"r");
        if(fptr==NULL)
        {
                puts("failed to open");
                exit(0);
        }
	
        while((fgets(str,sizeof(str),fptr))!=NULL)
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
                                                                memmove(q,temp+1,strlen(temp+1)+1);
                                                                q=ptr[++i];
                                                                temp=q;
                                                        }
                                                        else
                                                        {
                                                                if( (*temp=='*') && (*(temp+1)=='/'))
                                                                {
                                                                 
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


