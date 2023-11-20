#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t r,w;     //Binary semaphore
int rcount=0;
int rc=0;
int wc=0;

void *reader(void *arg){
sem_wait(&r);
rcount++;
if(rcount==1){  
sem_wait(&w);        //For 1st reader,we check whether writer is is writing or not,if it is writting then we wait till it write
}                    //Initially it is 1 then if it will writting then it will 0,after performing writting operation it is 1
sem_post(&r);            //then sem_wait will make it 0,

rc++;
printf("%d:Reader is reading\n",rc);

sem_wait(&r);
rcount--;
if(rcount==0){
sem_post(&w);
}
sem_post(&r);
}

void *writer(void *arg){
sem_wait(&w);
wc++;
printf("%d:Writer is writting\n",wc);
sem_post(&w);
}

int main(){
sem_init(&r,0,1);
sem_init(&w,0,1);

pthread_t read[3],write[3];
for(int i=0;i<3;i++){
pthread_create(&read[i],NULL,reader,NULL);
pthread_create(&write[i],NULL,writer,NULL);
}

for(int i=0;i<3;i++){
pthread_join(read[i],NULL);
pthread_join(write[i],NULL);
}
}

/***************OUTPUT***********
sanika@sanika-VirtualBox:~$ gcc READERWRITER_SEMAPHORE.c -lpthread
sanika@sanika-VirtualBox:~$ ./a.out
1:Writer is writting
2:Writer is writting
1:Reader is reading
3:Writer is writting
2:Reader is reading
3:Reader is reading
/*

