class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long i=0,j=0,sum=0,maxsum=INT_MIN;
        while(j<N){
            sum+=Arr[j];
            if(j-i+1<K){
                j++;
            }
            else if((j-i+1)==K){
                maxsum=max(sum,maxsum);
                sum-=Arr[i];
                i++;
                j++;
            }
        }
        return maxsum;
    }
};