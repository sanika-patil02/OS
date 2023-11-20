#include<iostream>
using namespace std;

int p,r,i,j,k;
int main(){
cout<<"Enter number of processes:";
cin>>p;

cout<<"Enter number of resources:";
cin>>r;

int allocation[p][r],max[p][r],need[p][r];
int available[r],finish[p],safe_sequence[p];
cout<<"Enter Allocation Matrix:\n";
for(i=0;i<p;i++){
    cout<<"For Process P"<<i<<":\n";
    for(j=0;j<r;j++){
        cin>>allocation[i][j];
    }
}

cout<<"Enter Max Matrix:\n";
for(i=0;i<p;i++){
    cout<<"For Process P"<<i<<":\n";
    for(j=0;j<r;j++){
        cin>>max[i][j];
    }
}

cout<<"Enter Available Resources:\n";
for(j=0;j<r;j++){
    cin>>available[j];
}

for(i=0;i<p;i++){
    for(j=0;j<r;j++){
        need[i][j]=max[i][j]-allocation[i][j];
    }
}

for(i=0;i<p;i++){    //finish array is initialised to 0,if execution of process is done then                  
    finish[i]=0;    //we assign va;ue 1 in it
}

int ind=0;
for(k=0;k<p;k++){   //for some processes if need > available then it will not execute and afterwards 
    for(i=0;i<p;i++){           //there are sufficient resources to fulfill that need ,so to execute 
        if(finish[i]==0){       //that process we used k loop
            int flag=0;
            for(j=0;j<r;j++){
                if(need[i][j]>available[j]){
                    flag=1;
                    break;
                }
            }

            if(flag==0){
                safe_sequence[ind++]=i;
                for(int y=0;y<r;y++){
                    available[y]=available[y]+allocation[i][y];
                }
                finish[i]=1;
            }

        }
    }
}

int flag=1;
for(i=0;i<p;i++){
    if(finish[i]==0){
        flag=0;
        cout<<"The given sequence is not safe";
        break;
    }
}

if(flag==1){
    cout<<"Following is the safe sequence:";
    for(i=0;i<p-1;i++){
        cout<<"P"<<safe_sequence[i]<<" -> ";
    }
    cout<<"P"<<safe_sequence[p-1];
}
}

/*************OUTPUT********************
Enter number of processes:5
Enter number of resources:3
Enter Allocation Matrix:
For Process P0:
1
1
2
For Process P1:
2
1
2
For Process P2:
3
0
1
For Process P3:
0
2
0
For Process P4:
1
1
2
Enter Max Matrix:
For Process P0:
5
4
4
For Process P1:
4
3
3
For Process P2:
9
1
3
For Process P3:
8
6
4
For Process P4:
2
2
3
Enter Available Resources:
3
2
1
Following is the safe sequence:P1 -> P4 -> P0 -> P2 -> P3
*/