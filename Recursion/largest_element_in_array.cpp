class Solution
{
private:
    int max_bata(vector<int>&arr , int i){
        if(arr.size()-1==i) return arr[i];
        return max(arr[i],max_bata(arr,i+1));
    }
public:
    int largest(vector<int> &arr, int n)
    {
        return max_bata(arr,0);
    }
};