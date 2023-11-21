#include<bits/stdc++.h>
using namespace std;
int main()
{

    
	
    int n;cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;  //ba
        vector<int>v3;
        v3.push_back(x);
        v3.push_back(y);
        v3.push_back(i);
        v.push_back(v3);
    }

    vector<vector<int>>v2=v;
    int a[n]={0};// array of completion time
    set<vector<int>>s;  
    int x=1;  //current time
    while(1)  
    {
        for(int i=0;i<n;i++){
            if(v[i][0]!=-1 && v[i][1]<=x){
                s.insert(v[i]);
                v[i][0]=-1;
            }
        }
        for(auto x1:s){
            vector<int>v1=x1;
          v1[0]--; //dec burst time by 1
            s.erase(x1); 
            if(v1[0]<=0){
                a[v1[2]]=x;
            }
            else{
                s.insert(v1);
            }
            break;
        }
        int k=0;
        for(int i=0;i<n;i++){
            if(v[i][0]==-1){
                k++;
            }
        }
        x++;
        if(k==v.size() && s.size()==0) break;
    }
    cout<<"process_no "<< " arrival "<< " brust "<<" compliton "<<" waiting time "<<" tot"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<"    "<<v2[i][1]<<"    "<<v2[i][0]<<"    "<<a[i]+1<<"    "<<a[i]-((v2[i][0] + v2[i][1]))<<"    "<<a[i]-(v2[i][1])<<endl;
    }
}