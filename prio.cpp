#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<vector<int>>v;
    //priority 
    cout<<"arrival "<<" burst"<<" "<<" priority "<<endl;
    for(int i=0;i<n;i++){
        int x,y,z;cin>>x>>y>>z;
        vector<int>v3;
        v3.push_back(x);
        v3.push_back(y);
        v3.push_back(z);
        v3.push_back(i);
        v.push_back(v3);
    }
    vector<vector<int>>v2=v;
    sort(v.begin(),v.end());
    int x=v[0][0];
    int a[n]={0};
    vector<vector<int>>v1;
    while(1){
        for(int i=0;i<v.size();i++){
            if(v[i][0]<=x && v[i][2]!=-1){
                v1.push_back({v[i][2],v[i][0],v[i][1],v[i][3]});
                v[i][2]=-1;
            }
        }
        sort(v1.begin(),v1.end());
        bool flag=true;
        if(v1.size()!=0){
            for(int i=0;i<v1.size();i++){
                if(v1[i][0]!=-1){
                    a[v1[i][3]]=v1[i][1]+v1[i][2]+(x-v1[i][1]);
                    v1[i][0]=-1;
                    flag=false;
                    x=a[v1[i][3]];
                    break;
                }
            }
        }
        if(flag) x++;
        int k=0,k1=0;
        for(int i=0;i<v.size();i++){
            if(v[i][2]==-1) k++;
        }
        for(int i=0;i<v1.size();i++){
            if(v1[i][0]==-1) k1++;
        }
        if(v.size()==k && v1.size()==k1) break;
    }
    cout<<"processno "<< " arrival "<< " brust "<< "priority "<<" compliton "<<" waiting time "<<" tat"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<v2[i][0]<<" "<<v2[i][1]<<" "<<v2[i][2]<<" "<<a[i]<<" "<<a[i]-((v2[i][0] + v2[i][1]))<<" "<<a[i]-(v[i][0])<<endl;
    }
}