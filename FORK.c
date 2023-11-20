#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int n;

void sort(int arr[],int flag){
if(flag==0){
for(int i=0;i<n;i++){
for(int j=0;j<n-1;j++){
if(arr[j]>arr[j+1]){
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}

for(int i=0;i<n;i++){
printf("%d\t",arr[i]);
}
}


else{
for(int i=0;i<n;i++){
for(int j=0;j<n-1;j++){
if(arr[j]<arr[j+1]){
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}

for(int i=0;i<n;i++){
printf("%d\t",arr[i]);
}
}

}


int main(){
printf("Enter number of inputs:");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}

int c_id;
c_id=fork();  //using fork syatem call process can create another process,calling process called parent and new process called child

if(c_id==0){
sleep(5);
system("\nps");
printf("Child starting..\n");
printf("Child process id : %d\n",getpid());
printf("Child parent process id : %d\n",getppid());
sort(arr,1);
exit(0);
}

else if(c_id>0){
//sleep(5);
//system("\nps");
printf("parent starting..\n");
printf("parent process id : %d\n",getpid());
sort(arr,0);
exit(0);
}

else{
printf("Error");  //Unsuccessful
exit(-1);
}
}
