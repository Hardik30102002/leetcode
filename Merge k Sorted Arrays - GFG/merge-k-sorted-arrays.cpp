//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class info{
    public:
        int data;
        int row;
        int col;
        
        info(int val,int r,int c){
            data=val;
            row=r;
            col=c;
        }
};

class compare{
    public:
        bool operator()(info* a,info* b){
            return a->data>b->data;
        }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<info*,vector<info*>,compare>minheap;
        
        int n=arr[0].size();
        
        for(int i=0;i<k;i++){
            info* temp=new info(arr[i][0],i,0);
            minheap.push(temp);
        }
        vector<int>ans;
        
        while(!minheap.empty()){
            info* temp=minheap.top();
            int topelement=temp->data;
            int toprow=temp->row;
            int topcol=temp->col;
            minheap.pop();
            
            ans.push_back(topelement);
            if(topcol+1<n){
                info* newinfo=new info(arr[toprow][topcol+1],toprow,topcol+1);
                minheap.push(newinfo);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends