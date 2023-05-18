#include<bits/stdc++.h>
using namespace std;
 
int main(){
    vector<char>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        v.push_back(c);
    }
    int i=0,j=0;
    int max_len=0;
    unordered_map<char,int>mp;
    while(j<n){
        mp[v[j]]++;
        while(mp.size()>2){
            mp[v[i]]--;
            if(mp[v[i]]==0) mp.erase(v[i]);
            i++;
        }
        if(mp.size()==2){
            max_len=max(max_len,j-i+1);
        }
        j++;
    }
    cout<<max_len<<endl;
    return 0;
}