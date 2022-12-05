class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long>v(nums.size(),nums[0]);
        if(nums.size()==0 || nums.size()==1){
            return 0;
        }
        for(int i=1;i<nums.size();i++){
            v[i]=v[i-1]+nums[i];
        }
        long min=INT_MAX;
        int t=0;
        for(int i=0;i<nums.size()-1;i++){
            int avg=((v[i]/(i+1))-((v[nums.size()-1]-v[i])/(nums.size()-i-1)));
            avg=abs(avg);
            if(min>avg){
                min=avg;
                t=i;
            }
        }
        long long k=v[nums.size()-1]/(nums.size());
        if(min>k){
            t=nums.size()-1;
        }
        return t;
    }
};
