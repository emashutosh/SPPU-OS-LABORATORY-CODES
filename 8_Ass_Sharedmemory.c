#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/types.h>

void do_client(int*); 

int main(int argc,char *argv[])
{
   int shm_id;
   int *shm_ptr;
   pid_t pid;
   int status;
   int size_segment;
   
   if(argc!=5)    //To accept only 4 integer from comment line argument
   {
        printf("\nusage: %s #1 #2 #3 #4\n",argv[0]); // for user acknowledgment 
        exit(1);   // out from running state similarly return 1
   }
   
   size_segment=4*sizeof(int); 
   shm_id=shmget(IPC_PRIVATE,size_segment,IPC_CREAT|0666); // creating a shared memory
    
   if(shm_id<0)
   {
        printf("\nError In Shmget : Server\n");
        exit(shm_id);
   }
    printf("\nParent Process=%d\n",getpid());
   printf("\n server: There is a Share Memory segment of 4 integers\n");
   shm_ptr=(int*)shmat(shm_id,NULL,0);   // memory attached
      
   if((long int)shm_ptr==-1)
   {
        printf("\nServer: shmat error\n");
        exit(-1);  
   }
   
   printf("\nShared memory segment is attached to the server\n");
   
      shm_ptr[0]=atoi(argv[1]);          
      shm_ptr[1]=atoi(argv[2]);
      shm_ptr[2]=atoi(argv[3]);
      shm_ptr[3]=atoi(argv[4]);
   
   printf("\nServer has Produced %d %d %d %d items in the shared memory\n",shm_ptr[0],shm_ptr[1]
   ,shm_ptr[2],shm_ptr[3]);
   
   printf("\nServer : Now fork child process\n");
   
      pid=fork();
      
      if(pid<0)
      {
          printf("\n Fork Error\n");
          exit(pid);
      }
      
      else if(pid==0)
      {
           do_client(shm_ptr);
           exit(0);
      }
      
      
      wait(NULL);
      printf("\n Child Process has Finished\n");
      
      
      shmdt((void*)shm_ptr);
      printf("\nServer:shm Removed\n");
      printf("\n Server:exits\n");
   
   return(0);    
 }  
   
   
  void do_client(int *shm_ptr) 
  {
   printf("\nChild started as Client With ID=%d and having server of ID=%d\n",getpid(),getppid());
   printf("\nClient Consumed %d %d %d %d data items in shared memory\n",shm_ptr[0],shm_ptr[1],shm_ptr[2],shm_ptr[3]);
   printf("\n Client Terminated\n");
  } 
   
   
   /* OUTPUT
 student@student-OptiPlex-390:~$ cd Desktop
student@student-OptiPlex-390:~/Desktop$ gcc 08.c 
student@student-OptiPlex-390:~/Desktop$ ./a.out

usage: ./a.out #1 #2 #3 #4
student@student-OptiPlex-390:~/Desktop$ ./a.out 70 71 72 74

Parent Process=2686

 server: There is a Share Memory segment of 4 integers

Shared memory segment is attached to the server

Server has Produced 70 71 72 74 items in the shared memory

Server : Now fork child process

Child started as Client With ID=2687 and having server of ID=2686

Client Consumed 70 71 72 74 data items in shared memory

 Client Terminated

 Child Process has Finished

Server:shm Removed

 Server:exits
student@student-OptiPlex-390:~/Desktop$ 

   */
   
   
   
