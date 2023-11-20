#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define buffer_size 5
sem_t s,e,f;      //s is binary semaphore;and f,e are counting semaphore
int in=0;
int out=0;

int buff[buffer_size];

void *producer(void *arg){
int data;
sem_wait(&e);        //sem_wait used for decrement(it converts 1 to 0),sem_post used for increment (it converts 0 to 1 )
sem_wait(&s);
data=rand()%100+1;
buff[in]=data;
printf("Producer produced data %d at index %d\n",data,in);
printf("Thread id of producer is %ld\n",pthread_self());
in=(in+1)%buffer_size;
sem_post(&s);
sem_post(&f);
}

void *consumer(void *arg){
int data,var;
do{
sem_wait(&f);
sem_wait(&s);
data=buff[out];
printf("Consumer consumed data %d at index %d\n",data,out);
printf("Thread id of consumer is %ld\n",pthread_self());
out=(out+1)%buffer_size;
sem_post(&s);
sem_post(&e);
sem_getvalue(&e,&var);
}while(var!=buffer_size);
}


int main(){
sem_init(&e,0,buffer_size);
sem_init(&f,0,0);
sem_init(&s,0,1);

pthread_t tid[buffer_size],ctid;         //we created tid array of producer b/z at a time 1 producer produces 1 data
	                                   //consumer consumes entire data so we created 1 consumer thread
for(int i=0;i<buffer_size;i++){
pthread_create(&tid[i],NULL,producer,NULL);
}
pthread_create(&ctid,NULL,consumer,NULL);

for(int i=0;i<buffer_size;i++){ 
pthread_join(tid[i],NULL);   //join-throw
}
pthread_join(ctid,NULL);

}


/*************OUTPUT*************
sanika@sanika-VirtualBox:~$ gcc PRODUCER_CONSUMER.c -lpthread
sanika@sanika-VirtualBox:~$ ./a.out
Producer produced data 84 at index 0
Thread id of producer is 139911306925632
Producer produced data 87 at index 1
Thread id of producer is 139911315318336
Consumer consumed data 84 at index 0
Thread id of consumer is 139911281747520
Consumer consumed data 87 at index 1
Thread id of consumer is 139911281747520
Producer produced data 78 at index 2
Thread id of producer is 139911290140224
Consumer consumed data 78 at index 2
Thread id of consumer is 139911281747520
Producer produced data 16 at index 3
Thread id of producer is 139911298532928
Producer produced data 94 at index 4
Thread id of producer is 139911323711040
Consumer consumed data 16 at index 3
Thread id of consumer is 139911281747520
Consumer consumed data 94 at index 4
Thread id of consumer is 139911281747520

*/

