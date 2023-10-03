//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        queue<pair<vector<string>,int>> q;

        q.push({{beginWord},1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        int prevlevel=-1;
        vector<string> tobeRemoved;

        while(!q.empty()){
            auto fnode=q.front();
            q.pop();

            auto currseq=fnode.first;
            auto currstring=currseq[currseq.size()-1];
            auto currlevel=fnode.second;
            
            if(currlevel!=prevlevel){
                for(auto s:tobeRemoved)  st.erase(s);
                tobeRemoved.clear();
                prevlevel=currlevel;
            }
            
            if(currstring==endWord){
                ans.push_back(currseq);
            }

            for(int index=0;index<currstring.length();index++){
                char originalchar=currstring[index];
                for(char ch='a';ch<='z';ch++){
                    currstring[index]=ch;
                    if(st.find(currstring)!=st.end()){
                        auto temp=currseq;
                        temp.push_back(currstring);
                        q.push({temp,currlevel+1});
                        tobeRemoved.push_back(currstring);
                    }
                }
                currstring[index]=originalchar;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends