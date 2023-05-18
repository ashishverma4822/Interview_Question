class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        unordered_map<char,int>mp;
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;
        }
        int count=mp.size();
        int i=0,j=0;
        int res=s.size();
        pair<int,int>pa={0,0};
        string g="";
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
	                count--;
	            }
            }
	        if(count==0){
	            while(count==0){
	                if(mp.find(s[i])!=mp.end()){
	                    mp[s[i]]++;
	                    if(mp[s[i]]==1){
	                        count++;
	                    }
	                }
	                i++;
	            }
	            if(j-i+2<res){
	                res=j-i+2;
	                pa.first=i-1;
	                pa.second=j;
	            }
	        }
	        j++;
        }
        for(int l=pa.first;l<=pa.second;l++){
            g.push_back(s[l]);
        }
        if(res==s.size()){
            return "-1";
        }
        return g;
    }
};