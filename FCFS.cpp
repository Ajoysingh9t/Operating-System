#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>at(n),bt(n),ct(n),tat(n),wt(n),process(n);
    for(int i = 0;i<n;i++){
        cin>>at[i]>>bt[i];
        process[i] = i;
    }
    sort(process.begin(),process.end(),[&](int a,int b){
        return at[a]<at[b];
    });
    int time = 0;
    for(int i = 0;i<n;i++){
        int j= process[i];
        if(time < at[j]){
            time = at[j];
        }
        time += bt[j];
        ct[j] = time;
        tat[j] = ct[j] - at[j];
        wt[j] = tat[j] - bt[j];
    }
    for(auto i:process){
        cout<<"p"<<i+1<<" ";
    }
    cout<<endl;
    double tatsum = 0,wtsum = 0;
    for(int i = 0;i<n;i++){
        tatsum += tat[i];
        wtsum += wt[i];
    }
    cout<<endl;
    cout<<"AVG TAT TIME = "<<tatsum/n<<endl;
    cout<<"AVG WT TIME = "<<wtsum/n<<endl;
}