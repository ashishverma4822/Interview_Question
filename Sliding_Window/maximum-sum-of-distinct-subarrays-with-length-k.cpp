class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long i=0,j=0,sum=0;
        long long ans=0;
        while(j<nums.size()){
            sum+=nums[j];
            mp[nums[j]]++;
            while(j-i+1>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k and mp.size()==k){
                ans=max(ans,sum);
            }
            j++;
        }
        return ans;
    }
};