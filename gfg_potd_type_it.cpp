class Solution {
  // Ashish Kumar Verma @ashishverma4822 @vashishk0602 @vashishk2003
  private:
    bool help(string t,string s){
        bool flag=true;
        for(int i=0;i<t.size();i++){
            if(s[i+t.size()]!=t[i]){
                flag=false;
            }
        }
        return flag;
    }
  public:
    int minOperation(string s) {
        // code here
        string t=s;
        for(int i=0;i<s.size()/2;i++){
            t.pop_back();
        }
        for(int i=0;i<s.size()/2;i++){
            bool k=help(t,s);
            if(k==true){
                return s.size()-t.size()+1;
            }
            t.pop_back();
        }
        return s.size();
    }
};
