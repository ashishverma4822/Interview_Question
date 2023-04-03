class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int sum=0;
        int count=0;
        int s=0;
        int e=people.size()-1;
        while(s<=e){
            sum=people[s]+people[e];
            if(sum<=limit){
                count++;
                s++;
                e--;
            }
            else{
            count++;
            e--;
            }
        }
        return count;
    }
};
