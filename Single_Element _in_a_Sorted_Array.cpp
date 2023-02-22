---------> @ashishverma4822 @vashishk2003 @vashishk0602 <---------
class Solution {
private:
    int binary_search(vector<int>&nums,int s,int e){
        int mid=(s+e)/2;
        int t=-1;
        if(s>e) return -1;
        if(mid==0 and nums[mid]!=nums[mid+1]) return nums[mid];
        if(mid==nums.size()-1 and nums[mid]!=nums[mid-1]) return nums[mid];
        if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1]){
            return nums[mid];
        }
        else{
            t=binary_search(nums,mid+1,e);
            if(t!=-1) return t;
            else return binary_search(nums,s,mid-1);
        }
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int i=0,j=nums.size()-1;
        return binary_search(nums,i,j);
    }
};
