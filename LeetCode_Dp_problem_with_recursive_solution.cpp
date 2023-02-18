// @ashishverma4822 @vashishk0602 @vashishk2003
///////////////////////////////////////////////////////////////////// LeetCode -- 343
----> Recursive Solution(Not Accepted)
class Solution {
private:
    int helpme(int n){
        if(n<=2) return 1;
        int maxP=INT_MIN;
        for(int i=1;i<n;i++){
            int pro=max(i*helpme(n-i),i*(n-i));
            maxP=max(maxP,pro);
        }
        return maxP;
    }
public:
    int integerBreak(int n) {
        return helpme(n);
    }
};

----> DP Solution
class Solution {
private:
    int helpme(int n,vector<int>&dp){
        if(n<=2) return 1;
        if(dp[n]!=-1) return dp[n];
        int maxP=INT_MIN;
        for(int i=1;i<n;i++){
            int pro=max(i*helpme(n-i,dp),i*(n-i));
            maxP=max(maxP,pro);
        }
        return dp[n]=maxP;
    }
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return helpme(n,dp);
    }
};

/////////////////////////////////////////////////////////////////// LeetCode -- 279
----> Recursive Solution(Not Accepted)
class Solution {
private:
    int helpme(int n){
        if(n==0) return 0;
        int ans=INT_MAX;
        for(int i=1;i<=sqrt(n);i++){
            ans=min(ans,helpme(n-i*i)+1);
        }
        return ans;
    }
public:
    int numSquares(int n) {
        return helpme(n);
    }
};

------> DP Solution
class Solution {
private:
    int helpme(int n,vector<int>&dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(int i=1;i<=sqrt(n);i++){
            ans=min(ans,helpme(n-i*i,dp)+1);
        }
        return dp[n]=ans;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helpme(n,dp);
    }
}; 

/////////////////////////////////////////////////////////////////// LeetCode -- 120
----> Recursive Solution(Not Accepted)
class Solution {
private:
    int helpme(vector<vector<int>>& tri,int i,int j){
        if(i>=tri.size()) return 0;
        int left=tri[i][j]+helpme(tri,i+1,j);
        int right=tri[i][j]+helpme(tri,i+1,j+1); 
        return min(left,right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return helpme(triangle,0,0);
    }
};

------> DP Solution
class Solution{
private:
    int helpme(vector<vector<int>>& tri,int i,int j,vector<vector<int>>&dp){
        if(i>=tri.size() or j>=tri[i].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=tri[i][j]+helpme(tri,i+1,j,dp);
        int right=tri[i][j]+helpme(tri,i+1,j+1,dp); 
        return dp[i][j]=min(left,right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp;
        for(int i=0;i<triangle.size();i++){
            vector<int> temp(triangle[i].size(),-1);
            dp.push_back(temp);
        }
        return helpme(triangle,0,0,dp);
    }
};

//////////////////////////////////////////////////////////////////// LeetCode -- 931
----> Recursive Solution(Not Accepted)
class Solution {
private:
    int helpme(int i,int j,vector<vector<int>>&v){
        if(j<0 or j>=v[0].size()) return 10001;
        if(i == v.size()-1) return v[i][j];
        int ans1 = v[i][j]+helpme(i+1,j-1,v);
        int ans2 = v[i][j]+helpme(i+1,j,v);
        int ans3 = v[i][j]+helpme(i+1,j+1,v);
        return min(ans1,min(ans2,ans3));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mpath=INT_MAX;
        for(int i=0;i<n;i++){
            int psum=helpme(0,i,matrix);
            mpath=min(psum,mpath);
        }
        return mpath;
    }
};

------> DP Solution
class Solution {
private:
    int helpme(int i,int j,vector<vector<int>>&v,vector<vector<int>>&dp){
        if(j<0 or j>=v[0].size()) return 10001;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i == v.size()-1) return v[i][j];
        int ans1 = v[i][j]+helpme(i+1,j-1,v,dp);
        int ans2 = v[i][j]+helpme(i+1,j,v,dp);
        int ans3 = v[i][j]+helpme(i+1,j+1,v,dp);
        return dp[i][j]=min(ans1,min(ans2,ans3));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mpath=INT_MAX;
        for(int i=0;i<n;i++){
            int psum=helpme(0,i,matrix,dp);
            mpath=min(psum,mpath);
        }
        return mpath;
    }
};

//////////////////////////////////////////////////////////////////////// LeetCode -- 1289
----> Recursive Solution(Not Accepted)
class Solution {
private:
    int helpme(int i,int j,vector<vector<int>>& v){
        if(i == v.size()-1) return v[i][j];
        int ans=INT_MAX;
        for(int c=0;c<v.size();c++){
            if(c!=j){
                ans=min(ans,v[i][j]+helpme(i+1,c,v));
            }
        }
        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int mpath=INT_MAX;
        for(int i=0;i<n;i++){
            int psum = helpme(0,i,grid);
            mpath=min(psum,mpath);
        }
        return mpath;
    }
};
------> DP Solution
class Solution {
private:
    int helpme(int i,int j,vector<vector<int>>& v,vector<vector<int>>& dp){
        if(i == v.size()-1) return v[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int c=0;c<v.size();c++){
            if(c!=j){
                ans=min(ans,v[i][j]+helpme(i+1,c,v,dp));
            }
        }
        return dp[i][j]=ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int mpath=INT_MAX;
        for(int i=0;i<n;i++){
            int psum = helpme(0,i,grid,dp);
            mpath=min(psum,mpath);
        }
        return mpath;
    }
};
