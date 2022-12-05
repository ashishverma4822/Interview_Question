class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1 || n==1 ){
            return 0;
        }
        int num=pow(2,n-2);
        if(k<=num){
            return kthGrammar(n-1,k);
        }
        else{
            return 1-kthGrammar(n-1,k-num);
        }
    }
};
