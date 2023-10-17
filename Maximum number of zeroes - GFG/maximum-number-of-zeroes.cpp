//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    	string MaxZero(string a[],int n)
    	{
    	    
    	        string str = ""; 
        int maxi = 0;
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            string s = a[i];

            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '0') {
                    cnt++;
                }
            }
            if (cnt > maxi) {
                maxi = cnt;
                str = s;
                flag = 1;
            }
            if(cnt == maxi){
            if(a[i].size()>=str.size() && a[i]>str) 
                str = a[i];
           }
          
        }
        if(flag == 0)return "-1";

        return str;
    	}
};
	 

//{ Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    string a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    

      

        Solution ob;
        cout << ob.MaxZero(a,n) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends