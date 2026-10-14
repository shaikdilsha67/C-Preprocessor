#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//#include "macro_replacement.h"

int c=0;
extern int cnt;
int size;

void* header_inclusion(char (*ptr)[100],char *filename)
{
	FILE *fp=NULL,*fptr=NULL;

	char *p=NULL,*q=NULL,*m=NULL,s[200],(*g)[200]=NULL,(*buf)[100]=NULL;
	int k;
	

	//.i file open in write mode for predefined header file content write in this file. 

           fptr=fopen(filename,"w");
           if(fptr==NULL)
           {
           puts("failed to open headerfile");
           exit(0);
           }

	for(int i=0;i<cnt;i++)
	{
		q=ptr[i];
		int flag=0;
		k=0;
		char str[100]={0};
	        char path[100]="/usr/include/";

		//searching #include using ststr predefined function
             while((q=strstr(q,"#include"))!=NULL)
             {
               p=q;
               q=q+strlen("#include");

              while(*q==' ' || *q=='\t')
                    q++;

    		if(*q=='<')
        	flag=1;
    		else if(*q=='"')
        	flag=2;
    		else
        	break;

    		q++;
    		k=0;

    		while(*q!='>' && *q!='"' && *q!='\n' && *q!='\0')
    		{
        	str[k++]=*q;//header name is  store in array
        	q++;
    		}
    		str[k]='\0';

    		if(*q=='>' || *q=='"')
        	q++;

    		memmove(p,q,strlen(q)+1);//remove the the #include line.
              }
	     //This for predefined header file 
		if(flag==1)
		{
		  strcat(path,str);

		  fp=fopen(path,"r");
		  if(fp==NULL)
		  {
			 puts("failed to open");
			 exit(0);
		  }
             //reading and writing content using fread and fwrite.
		  fseek(fp,0,2);
		  size=ftell(fp);
		  rewind(fp);
		 
		  p=calloc(1,size+1);

		  fread(p,1,size,fp);
		  p[size]='\0';
		  fwrite(p,1,size,fptr);
		  fclose(fp);
		}
		//This for user defined header file
		if(flag==2)
		{
	          fp=fopen(str,"r");
                  if(fp==NULL)
                  {
                          puts("failed to open headerfile");
                          exit(0);
                  }
		   //This for user defined file have Macro copy to heap memory perform macro
                  //replacement.
		  int c=0;
		  while((fgets(s,100,fp))!=NULL)
		  {
			  g=realloc(g,(c+1)*sizeof(*g));
			  strcpy(g[c],s);
			  c++;
		  }
		  for(int i=0;i<c;i++)
		  {
			  m=g[i];
			  while((m=strstr(m,"#define"))!=NULL)
			  {
				  flag=3;
				  m=m+strlen("#define");
				  break;
			  }
		  }
		  if(flag==3)
		  {
			  fclose(fp);
			  fp=fopen(str,"w");
			  
			 
			  for(int i=0;i<c;i++)
			  {
				  fputs(g[i],fp);
			  }
			  for(int i=0;i<cnt;i++)
			  {
				  fputs(ptr[i],fp);
			  }
			  fclose(fp);

			  fp=fopen(str,"r");

			  int line_cnt=0;
			  while((fgets(s,100,fp))!=NULL)
                          {
                          buf=realloc(buf,(line_cnt+1)*sizeof(*buf));
                          strcpy(buf[line_cnt],s);
                          line_cnt++;
                          }
			  cnt=line_cnt;
			  fclose(fp);
			  flag=4;

			  fp=fopen(str,"w");
			  for(int i=0;i<c;i++)
                          {
                                  fputs(g[i],fp);
                          }
			  fclose(fp);
		  }
		  else
		  {
		  buf=ptr;
                  fseek(fp,0,2);
                  size=ftell(fp);
                  rewind(fp);
                  p=calloc(1,size+1);

                  fread(p,1,size,fp);
                  p[size]='\0';

                  fwrite(p,1,size,fptr);
		 }
		}
		
		
	}
	fclose(fptr);
	return buf;//return the Address of heap memory.
}
