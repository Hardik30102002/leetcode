//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int> q;
        const int mod=100000;
        vector<int> ans(100000,-1);
        ans[start]=0;
        q.push(start);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if(front==end)  return ans[end];
            for(auto it:arr){
                int newNode=(front*it)%mod;
                if(ans[newNode]==-1){
                    ans[newNode]=ans[front]+1;
                    q.push(newNode);
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends