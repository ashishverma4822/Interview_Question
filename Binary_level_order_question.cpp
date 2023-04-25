// 107. Binary Tree Level Order Traversal II
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL){
                res.push_back(v);
                v.clear();
                if(!q.empty()) q.push(NULL);
            }
            else{
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                v.push_back(f->val);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


//637. Average of Levels in Binary Tree
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        double avg=0;
        int k=0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL){
                res.push_back(avg/k);
                avg=0;
                k=0;
                if(!q.empty()) q.push(NULL);
            }
            else{
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
                k++;
                avg+=f->val;
            }
        }
        return res;
    }
};

//515. Find Largest Value in Each Tree Row
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        int maxi=INT_MIN;
        if(root==NULL) return res;
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL){
                res.push_back(maxi);
                maxi=INT_MIN;
                if(!q.empty()) q.push(NULL);
            }
            else{
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                maxi=max(maxi,f->val);
            }
        }
        return res; 
    }
};

//1161. Maximum Level Sum of a Binary Tree
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans=INT_MIN;
        int max_sum=0;
        int index=0,idx=0;
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL){
                index++;
                if(max_sum>ans){
                    ans=max_sum;
                    idx=index;
                }
                max_sum=0;
                if(!q.empty()) q.push(NULL);
            }
            else{
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                max_sum+=f->val;
            }
        }
        return idx;
    }
};

//2583. Kth Largest Sum in a Binary Tree
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long max_sum=0;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL){
                pq.push(max_sum);
                if(pq.size()>k) pq.pop();
                max_sum=0;
                if(!q.empty()) q.push(NULL);
            }
            else{
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                max_sum+=f->val;
            }
        }
        if(pq.size()<k) return -1;
        return pq.top();
    }
};

//429. N-ary Tree Level Order Traversal
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        vector<int> v;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* f=q.front();
            q.pop();
            if(f==NULL){
                res.push_back(v);
                v.clear();
                if(!q.empty()) q.push(NULL);
            }
            else{
                v.push_back(f->val);
                for(int i=0;i<f->children.size();i++){
                    q.push(f->children[i]);
                }
            }
        }
        return res;
    }
};

//2415. Reverse Odd Levels of Binary Tree

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*>v;
        if(root==NULL) return root;
        queue<TreeNode*>q;
        int level=0;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL){
                if(level%2){
                    int i=0,j=v.size()-1;
                    while(i<j){
                        swap(v[i]->val,v[j]->val);
                        i++;
                        j--;
                    }
                }
                v.clear();
                if(!q.empty()) q.push(NULL);
                level++;
            }
            else{
                v.push_back(f);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        return root;
    }
};