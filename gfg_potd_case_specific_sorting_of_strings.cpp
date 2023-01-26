class Solution
{
    //Ashish Kumar Verma @ashishverma4822 @vashishk0602 @vashishk2003 
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string s;
        string t;
        for(int i=0;i<str.size();i++){
            if(str[i]>='A' and str[i]<='Z'){
                s.push_back(str[i]);
            }
            else{
                t.push_back(str[i]);
            }
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        string ans;
        int j=0,k=0;
        for(int i=0;i<str.size();i++){
            if(str[i]>='A' and str[i]<='Z'){
                ans.push_back(s[j]);
                j++;
            }
            else{
                ans.push_back(t[k]);
                k++;
            }
        }
        return ans;
    }
};
