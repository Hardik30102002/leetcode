//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        map<int,int>presum;
        int sum=0;
        int maxlen=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(sum==k){
                maxlen=max(maxlen,i+1);
            }
            int res=sum-k;
            if(presum.find(res)!=presum.end()){
                int len=i-presum[res];
                maxlen=max(maxlen,len);
            }
            if(presum.find(sum)==presum.end()){
                presum[sum]=i;
            }
        }
        return maxlen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends