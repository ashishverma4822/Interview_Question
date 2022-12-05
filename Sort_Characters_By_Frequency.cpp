class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }                     
        priority_queue<pair<int,int>>maxHeap;
        for(auto i=mp.begin();i!=mp.end();i++){
            maxHeap.push({i->second,i->first});
        }
        string t;
        while(maxHeap.size()>0){
            int n=maxHeap.top().first;
            char c=maxHeap.top().second;
            for(int i=0;i<n;i++){
                t.push_back(c);
            }
            maxHeap.pop();
        }
        return t;
    }
};
