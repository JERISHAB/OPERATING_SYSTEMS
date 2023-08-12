#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{ 
 int i;
 int shmid;
 void *shm;
 char buff[100];
 shmid=shmget((key_t)2345,1024,0666);
 printf("Key of shared memory is %d\n",shmid);
 shm=shmat(shmid,NULL,0);
 printf("Process attached at %p\n",shm);
 printf("Value read from shared is %s\n",(char*)shm);
 return 0;
}