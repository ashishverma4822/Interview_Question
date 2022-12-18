//Ashish Kumar Verma @ashishverma4822 @vashishk0602 @vashishk2003
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v;
        stack<pair<int,int>>s;
        for(int i=temperatures.size()-1;i>=0;i--){
            if(s.size()==0){
                v.push_back(0);
            }
            else if(s.size()>0 and s.top().first>temperatures[i]){
                v.push_back(s.top().second-i);
            }
            else if(s.size()>0 and s.top().first<=temperatures[i]){
                while(s.size()>0 and s.top().first<=temperatures[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(0);
                }
                else{
                    v.push_back(s.top().second-i);
                }
            }
            s.push({temperatures[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
