#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<pair<pair<int,int>,int>>v;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        v.push_back({{x,y},i});
    }
    sort(v.begin(),v.end());
    int a[n]={0};
    int x=v[0].first.first;
    for(int i=0;i<n;i++){
        if(x<=v[i].first.first){
            a[v[i].second]=(v[i].first.first + v[i].first.second);
            x=a[v[i].second];
        }
        else{
            a[v[i].second]=(v[i].first.first + v[i].first.second + (abs(x-(v[i].first.first))));
            x=a[v[i].second];
        }
    }
    cout<<"processno "<< " arrival "<< " brust "<<" compliton "<<" waiting time "<<" tot"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<v[i].first.first<<" "<<v[i].first.second<<" "<<a[i]<<" "<<a[i]-((v[i].first.first + v[i].first.second))<<" "<<a[i]-(v[i].first.first)<<endl;
    } 
}
