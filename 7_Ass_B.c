#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>


#define MAX_BUF 1024

int main()
{
    int fd,c=0;
    char * myfifo1="myfifo1";
    int fd1;
    char * myfifo2="myfifo2";
    
    char buf1[MAX_BUF];
    
    
    
    mkfifo(myfifo1,0777);
     printf("\nEnter the Sentence : \n");
    fd=open(myfifo1,O_WRONLY);
    
    char str;
   
    while((str=getchar())!='#')
   
        buf1[c++]=str;
	buf1[c]='\0';
	
	write(fd,buf1,sizeof(buf1)); 
	close(fd);
	
	fd1=open(myfifo2,O_RDONLY);
	read(fd1,&buf1,sizeof(buf1));
       
        printf("\nThe contents of the file are as follows : %s\n ",buf1);
	
	  close(fd1);
	    
	       unlink(myfifo2);
	       return (0);

    
}


