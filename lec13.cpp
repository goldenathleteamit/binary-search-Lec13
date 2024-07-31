class Solution{
public:
	bool possible(vector<int> &arr,int day,int m,int k){
		int count=0;
		int nofbu=0;
		int n=arr.size();
		for(int i=0;i<n;i++){
			if(arr[i]<=day){
				count++;
			}
			else{
				nofbu+=(count/k);
				count=0;
			}
		}
		nofbu+=(count/k);
		return nofbu>=m;
	}
	int mindays(vector<int> &arr,int m,int k){
		long long val=m*1ll*k*1ll;
		int n=arr.size();
		if(val>n){
			return -1;
		}
		int low =*min_element(arr.begin(),arr.end());
		int high =*max_element(arr.begin(),arr.end());
		while(low<=high){
			int mid=(low+high)/2;
			if(possible(arr,mid,m,k)){
				high=mid-1;
			}
			else {
				low=mid+1;
			}
		}return low;
	}
