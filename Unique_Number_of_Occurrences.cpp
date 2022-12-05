class Solution{
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int i=0,cnt;
        sort(arr.begin(),arr.end());
        vector<int>v;
        while(i<arr.size()){
            cnt=1;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]==arr[j]){
                  cnt++;  
                }
            }
            v.push_back(cnt);
            i=i+cnt;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            if(v[i]==v[i+1]){
                return false;
            }
        }
        return true;
    }
};
