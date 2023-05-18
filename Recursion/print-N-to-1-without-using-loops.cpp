class Solution
{
public:
    void printTillN(int N)
    {
        // Write Your Code here
        if(N==0) return;
        cout<<N<<" ";
        printTillN(N-1);
    }
};