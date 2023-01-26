class Solution {
  public:
  //Ashish Kumar Verma @ashishverma4822 @vashishk0602 @vashishk2003
    string removePair(string s) {
        // code here
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string t;
        while(!st.empty()){
            t.push_back(st.top());
            st.pop();
        }
        reverse(t.begin(),t.end());
        if(t==""){
            t.push_back('-');
            t.push_back('1');
        }
        return t;
    }
};
