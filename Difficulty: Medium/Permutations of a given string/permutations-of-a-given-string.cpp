//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void permut(string &s, vector<string> &ans, string &temp, vector<bool> &visited)
    {
        if(s.size() == temp.size())
        {
            ans.push_back(temp);
            return;
        }
        unordered_set<char> seen;
        for(int i = 0; i < s.size(); i++)
        {
            if (visited[i] || seen.find(s[i]) != seen.end()) continue;
            seen.insert(s[i]);
            if(visited[i] == 0)
            {
                visited[i] = 1;
                temp.push_back(s[i]);
                permut(s, ans, temp, visited);
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<string> find_permutation(string s) {
        // Code here there
        vector<string> ans;
        sort(s.begin(), s.end());
        string temp;
        vector<bool> visited(s.size(), 0);
        permut(s, ans, temp, visited);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends