//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool checkcycle(vector<int> adj[],int src,
                    unordered_map<int,bool>&visited,
                    unordered_map<int,bool> &dfsvisited,int safenodes[]){
        visited[src]=true;
        dfsvisited[src]=true;
        safenodes[src]=0;
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                bool nextans=checkcycle(adj,nbr,visited,dfsvisited,safenodes);
                if(nextans==true)   return true;
            }
            if(visited[nbr]==true && dfsvisited[nbr]==true){
                return true;
            }
        }
        dfsvisited[src]=false;
        safenodes[src]=1;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans;
        unordered_map<int,bool> visited,dfsvisited;
        int safenodes[V]={0};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool x=checkcycle(adj,i,visited,dfsvisited,safenodes);
            }
        }
        for(int i=0;i<V;i++){
            if(safenodes[i])    ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends