#include<stdio.h>
#include<unistd.h>

#define size 100

int main()
{
  char fname[size],inbuf[size];
  pid_t pid;
  int p1[2],p2[2];
  FILE *fp;
  
  pipe(p1);
  pipe(p2);
  
  printf("\nEnter File Name -");
  scanf("%s",fname);
  
  write(p1[1],fname,sizeof(fname));
  close(p1[1]);

  pid=fork();
  
  if(pid==0)
  {
      read(p1[0],inbuf,size);
      fp=fopen(inbuf,"r");
      while(fgets(inbuf,150,fp))
      {
	write(p2[1],inbuf,sizeof(inbuf));
	close(p2[1]);
      }
      close(p1[0]);
  }
  else
  {
      read(p2[0],inbuf,size);
      printf("\n %s",inbuf);
      close(p2[0]);
  }
  return 0;
}









