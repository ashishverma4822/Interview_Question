class Solution{
  //@ashishverma4822 @vashishk0602 @vashishk2003
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char,int>mp;
        int i=0,j=0,ans=-1;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            else if(mp.size()==k){
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};
