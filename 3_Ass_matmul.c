#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/syscall.h>

typedef struct		//structure definaton
{
   int r;
   int c;
}num;
  
void *mult(void *varg);		//function prototype

void input(int a[10][10],int m,int n) //input matrix
{
 int i,j;

  for(i=0;i<m;i++)
    {
        
     for(j=0;j<n;j++)
       {
            scanf("%d",&a[i][j]);
       }
         
      }    
}


int main()		//main function
{
  num N;			
  int a[10][10],b[10][10],c[10][10];
  int i,j,k,m,n,p,q;
  long int ans,num1,num2; 
  
  pthread_t tid; //thread variable
  printf("\n ENTER NO OF ROWS AND COLUMNS OF MATRIX 1\n");
  scanf("%d%d",&m,&n);
  printf("\n ENTER THE MATRIX 1\n");
  input(a,m,n);
  for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		
			printf("\t%d\t",a[i][j]);
		}
		printf("\n");
	}  
  printf("\n ENTER NO OF ROWS AND COLUMNS OF MATRIX 2\n");
  scanf("%d%d",&p,&q);
  printf("\n ENTER THE MATRIX 2\n");
  input(b,p,q);
  for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\t%d\t",b[i][j]);
		}
		printf("\n");
	}  
  if(n==p) //conditon for multiplication
  { 
    for(i=0;i<m;i++)
     {
        for(j=0;j<q;j++)
      {
        
        c[i][j]=0;
      	for(k=0;k<p;k++)
          {
             num1=a[i][k]; //move value to multiply
             num2=b[k][j]; //move value to multiply
               
             N.r=num1;
             N.c=num2;
             pthread_create(&tid,NULL,mult,(void *)&N);
             pthread_join(tid,(void *)&ans);
             c[i][j]+=ans;
               
           }
        }
     }
 }  	
 	printf("\nRESULTANT MATRIX IS\n");
for(i=0;i<m;i++)	//resultant matrix
	{
		for(j=0;j<q;j++)
		{
			printf("\t%d\t",c[i][j]);
		}
		printf("\n");
	}  
return 0;

}


void *mult(void *varg) // function for multiplication
{
  num *nmult=(num*)varg;
 long  int sum=0,p;
  sum=(nmult->r)*(nmult->c);
printf("Thread ID:%d\n",syscall(SYS_gettid)); //display ID for each thread
/*p=pthread_self;
printf("\n ID=%ld\n",p);*/
  return (void*)sum; //return value for multiplication
}  

/* 		OUTPUT

student@student-OptiPlex-390:~$ cd Desktop
student@student-OptiPlex-390:~/Desktop$ gcc thread.c -o ab -lpthread
student@student-OptiPlex-390:~/Desktop$ ./ab

 ENTER NO OF ROWS AND COLUMNS OF MATRIX 1
2
2

 ENTER THE MATRIX 1
1
2
3
4
	1		2	
	3		4	

 ENTER NO OF ROWS AND COLUMNS OF MATRIX 2
2
2

 ENTER THE MATRIX 2
4
5

7
8
	4		5	
	7		8	
Thread ID:8775
Thread ID:8776
Thread ID:8777
Thread ID:8778
Thread ID:8779
Thread ID:8780
Thread ID:8781
Thread ID:8782

RESULTANT MATRIX IS
	18		21	
	40		47	
student@student-OptiPlex-390:~/Desktop$ 

*/
