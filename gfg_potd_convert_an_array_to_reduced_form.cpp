class Solution{
public:	
  //Ashish Kumar Verma @ashishverma4822 @vashishk2003 @vashishk0602
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	    vector<int>v;
	    for(int i=0;i<n;i++){
	        v.push_back(arr[i]);
	    }
	    sort(v.begin(),v.end());
	    unordered_map<int,int>mp;
	    for(int i=0;i<v.size();i++){
	        mp[v[i]]=i;
	    }
	    for(int i=0;i<n;i++){
	        arr[i]=mp[arr[i]];
	    }
	}

};
