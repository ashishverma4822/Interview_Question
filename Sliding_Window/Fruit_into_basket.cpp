class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0,ans=-1;
        unordered_map<int,int>mp;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0){
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
            }
            else if(mp.size()==2){
                ans=max(ans,j-i+1);
            }
                j++;
        }
        if(mp.size()==1){
            ans=fruits.size();
        }
        return ans;
    }
};