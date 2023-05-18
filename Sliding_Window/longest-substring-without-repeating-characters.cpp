class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        unordered_map<char,int>mp;
        int count=0,ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            count++;
            if(count>mp.size()){
                while(count>mp.size()){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                    count--;
                }
            }
            else if(count==mp.size()){
                ans=max(ans,count);
            }
            j++;
        }
        return ans;
    }
};