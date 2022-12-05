class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int s=0;
        int e=r*c-1;
        int mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(matrix[mid/c][mid%c]==target){
                return true;
            }
            else if(matrix[mid/c][mid%c]>target){
                e=mid-1;
            }
            else if(matrix[mid/c][mid%c]<target){
                s=mid+1;
            }
        }
        return false;
    }
};
