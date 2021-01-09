#include<stdio.h>
#include<unistd.h>
main()
{
int pid;
pid=fork();
if(pid<0)
 {
  printf ("invalid process");
 }
  else if(pid==0)
   {
     printf("\nchild process");
printf("\nchild pid=%d",getpid());
     execlp("p.out","a3.c",asc(),(char*)0);
   }
  else if(pid>0)
   {
     printf("\nparent process");
printf("\nparent pid=%d",getppid());
     wait();
     dsc();
   }
} 

asc()
{

int i,a[10],k,temp,n;
printf("\nplease enter the number of array elements you want to enter::");
scanf("%d",&n);  
printf("\nplease enter the array elements::");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
  for(k=0;k<n-1;k++)
    {
      if(a[i]<a[k])
        {
           temp=a[k];
           a[k]=a[i];
           a[i]=temp;
        }
    }
}
printf("\nthe sorted elements in ascending order is: ");
for(i=0;i<n;i++)
printf("%3d",a[i]);
}

dsc()
{

int i,a[10],k,temp,n;
printf("\nplease enter the number of array elements you want to enter::");
scanf("%d",&n);
printf("\nplease enter the array elements::");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
  for(k=0;k<n-1;k++)
    {
      if(a[i]>a[k])
        {
           temp=a[k];
           a[k]=a[i];
           a[i]=temp;
        }
    }
}
printf("\nthe sorted elements in descending order is: ");
for(i=0;i<n;i++)
printf("%3d",a[i]);
}



