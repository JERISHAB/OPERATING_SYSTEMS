#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
 int shmid;
 int i;
 void *shm;
 char buff[100];
 shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
 printf("Key of shared memory is %d\n",shmid);
 shm=shmat(shmid,NULL,0);
 printf("Process attached at %p\n",shm);
 printf("Enter some data to write to shared memory\n");
 read(0,buff,100);
 strcpy(shm,buff);
 printf("Value shared is %s\n",(char*)shm);
 return 0;
}
