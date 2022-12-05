class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        int sr=0,sc=0,er=r-1,ec=c-1;
        int total=r*c;
        int cnt=0;
        vector<int>ans;
        while(cnt<total){
            for(int i=sc;cnt<total && i<=ec;i++){
                ans.push_back(matrix[sr][i]);
                cnt++;
            }
            sr++;
            for(int i=sr;cnt<total && i<=er;i++){
                ans.push_back(matrix[i][ec]);
                cnt++;
            }
            ec--;
            for(int i=ec;cnt<total && i>=sc;i--){
                ans.push_back(matrix[er][i]);
                cnt++;
            }
            er--;
            for(int i=er;cnt<total && i>=sr;i--){
                ans.push_back(matrix[i][sc]);
                cnt++;
            }
            sc++;
        }
        return ans;
    }
};
