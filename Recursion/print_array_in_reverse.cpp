class Solution{
public:
    //Just print the space seperated array elements
    void reverse_print(int arr[],int n,int i){
        if(i==n) return ;
        reverse_print(arr,n,i+1);
        cout<<arr[i]<<" ";
    }
	void printArray(int arr[], int n) {
	    // code here
	    reverse_print(arr,n,0);
	}
};