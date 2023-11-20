#include<iostream>
#include<queue>
using namespace std;

struct process{
    int pid;
    int AT;
    int BT;
    int WT;
    int TAT;
};

void RoundRobin(process p[],int n,int tq){
    int count=0;
    int i=0;

    queue<process> q;  //Declares a queue of type process to manage the processes.
    q.push(p[i]);

    while(!q.empty()){
        process temp=q.front();   //Initially front and rare are at index 0,as we pushes the element in queue
 	    if(temp.BT>tq){         //rare gets increment,and when front element pop then front increments
            temp.BT=temp.BT-tq;
            count=count+tq;
        }

        else{
            count=count+temp.BT;
            temp.BT=0;
            for(int j=0;j<n;j++){
                if(p[j].pid==temp.pid){
                    p[j].TAT=count-p[j].AT;
                    p[j].WT=p[j].TAT-p[j].BT;
                }
            }
            cout<<"P"<<temp.pid<<" completed at time "<<count<<endl;
        }

        if(p[i+1].AT<=count){
            for(int x=i+1;x<n;x++){
                if(p[x].AT<=count){
                    q.push(p[x]);
                    i++;
                }
            }
        }

        if(temp.BT>0){
            q.push(temp);
            q.pop();
        }
        else{
            q.pop();
        }
    }

    float avgTAT=0;
    float avgWT=0;
    cout<<"Process\tAT\tBT\tTAT\tWT\n";
    for(int j=0;j<n;j++){
        cout<<"P"<<j<<"\t"<<p[j].AT<<"\t"<<p[j].BT<<"\t"<<p[j].TAT<<"\t"<<p[j].WT<<endl;
        avgTAT=avgTAT+p[j].TAT;
        avgWT=avgWT+p[j].WT;
    }
        avgTAT=avgTAT/n;
        avgWT=avgWT/n;
        cout<<"Average Waiting Time="<<avgWT<<endl;
        cout<<"Average Turn Around Time="<<avgTAT;
}

void sort(process p[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(p[j].AT>p[j+1].AT){
                process temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

}

int main(){
    int n,tq;

    cout<<"Enter number of process:";
    cin>>n;

    cout<<"Enter time quantum:";
    cin>>tq;
    
    process p[n];
    cout<<"Enter arrival time and burst time of process:";
    for(int i=0;i<n;i++){
        cout<<"P"<<i<<": ";
        p[i].pid=i;
        cin>>p[i].AT;
        cin>>p[i].BT;
    }

    sort(p,n);
    cout<<"Process\tAT\tBT\n";
    for(int i=0;i<n;i++){
        cout<<"P"<<i<<"\t"<<p[i].AT<<"\t"<<p[i].BT<<endl;
    }
    RoundRobin(p,n,tq);
}


/************OUTPUT***********
Enter number of process:4
Enter time quantum:2
Enter arrival time and burst time of process:P0: 0
5
P1: 1
4
P2: 2
2
P3: 4
1
Process AT      BT
P0      0       5
P1      1       4
P2      2       2
P3      4       1
P2 completed at time 6
P3 completed at time 9
P1 completed at time 11
P0 completed at time 12
Process AT      BT      TAT     WT
P0      0       5       12      7
P1      1       4       10      6
P2      2       2       4       2
P3      4       1       5       4
Average Waiting Time=4.75
Average Turn Around Time=7.75
*/
