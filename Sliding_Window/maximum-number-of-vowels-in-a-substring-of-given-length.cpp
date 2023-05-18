class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int ans=0,cnt=0;
        unordered_map<char,bool>mp;
        mp['a']=true; mp['e']=true; mp['i']=true; mp['o']=true; mp['u']=true;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()) cnt++;
            if(j-i+1==k){
                ans=max(ans,cnt);
                if(mp.find(s[i])!=mp.end()) cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};