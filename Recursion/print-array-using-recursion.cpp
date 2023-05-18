class Solution{
public:
    //Just print the space seperated array elements
    int i=0;
	void printArray(int arr[], int n) {
	    // code here
	    if(i==n) return;
	    cout<<arr[i]<<" ";
	    i++;
	    printArray(arr,n);
	}
};