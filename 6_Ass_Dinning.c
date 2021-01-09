#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *philosopher1();
void *philosopher2();
void *philosopher3();
void *philosopher4();
void *philosopher5();
pthread_mutex_t chopstick[5];
int main()
{
	pthread_t tid[6];
	pthread_create(&tid[1],NULL,philosopher1,NULL);
	pthread_create(&tid[2],NULL,philosopher2,NULL);
	pthread_create(&tid[3],NULL,philosopher3,NULL);
	pthread_create(&tid[4],NULL,philosopher4,NULL);
	pthread_create(&tid[5],NULL,philosopher5,NULL);	
	
	pthread_join(tid[1],NULL);
	pthread_join(tid[2],NULL);
	pthread_join(tid[3],NULL);
	pthread_join(tid[4],NULL);
	pthread_join(tid[5],NULL);
}

void *philosopher1()
{
	while(1)
	{
		pthread_mutex_lock(&chopstick[4]);
		pthread_mutex_lock(&chopstick[0]);
		printf("\nPhilosopher 1 is eating");
		sleep(3);
		pthread_mutex_unlock(&chopstick[4]);
		pthread_mutex_unlock(&chopstick[0]);
		printf("\nPhilosopher 1 is releasing chopsticks");
		printf("\nPhilosopher 1 is thinking");
		sleep(3);
	}
}

void *philosopher2()
{
	while(1)
	{
		pthread_mutex_lock(&chopstick[0]);
		pthread_mutex_lock(&chopstick[1]);
		printf("\nPhilosopher 2 is eating");
		sleep(3);
		pthread_mutex_unlock(&chopstick[0]);
		pthread_mutex_unlock(&chopstick[1]);
		printf("\nPhilosopher 2 is releasing chopsticks");
		printf("\nPhilosopher 2 is thinking");
		sleep(3);
	}
}

void *philosopher3()
{
	while(1)
	{
		pthread_mutex_lock(&chopstick[1]);
		pthread_mutex_lock(&chopstick[2]);
		printf("\nPhilosopher 3 is eating");
		sleep(3);
		pthread_mutex_unlock(&chopstick[1]);
		pthread_mutex_unlock(&chopstick[2]);
		printf("\nPhilosopher 3 is releasing chopsticks");
		printf("\nPhilosopher 3 is thinking");
		sleep(3);
	}
}

void *philosopher4()
{
	while(1)
	{
		pthread_mutex_lock(&chopstick[2]);
		pthread_mutex_lock(&chopstick[3]);
		printf("\nPhilosopher 4 is eating");
		sleep(3);
		pthread_mutex_unlock(&chopstick[2]);
		pthread_mutex_unlock(&chopstick[3]);
		printf("\nPhilosopher 4 is releasing chopsticks");
		printf("\nPhilosopher 4 is thinking");
		sleep(3);
	}
}

void *philosopher5()
{
	while(1)
	{
		pthread_mutex_lock(&chopstick[3]);
		pthread_mutex_lock(&chopstick[4]);
		printf("\nPhilosopher 5 is eating");
		sleep(3);
		pthread_mutex_unlock(&chopstick[3]);
		pthread_mutex_unlock(&chopstick[4]);
		printf("\nPhilosopher 5 is releasing chopsticks");
		printf("\nPhilosopher 5 is thinking");
		sleep(3);
	}
}



