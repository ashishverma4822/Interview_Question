class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char,int>mp;
        int i=0,j=0;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()==k){
                ans=max(ans,j-i+1);
            }
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        if(ans==0) return -1;
        return ans;
    }
};