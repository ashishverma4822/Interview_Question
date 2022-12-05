class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                for(int j=i;j>=0;j--){
                    if(s[j]==' '){
                        return cnt;
                    }
                    cnt++;
                }
                return cnt;
            }
        }
        return cnt;
    }
};
