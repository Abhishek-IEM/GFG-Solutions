//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });
        int maxLen = 1;
        unordered_map<string, int> mp;
        for(const string &word: words)
        {
            int len = 1;
            for(int i = 0; i < word.size(); i++)
            {
                string pred = word.substr(0, i) + word.substr(i + 1);
                if(mp.find(pred) != mp.end())
                {
                    len = max(len, mp[pred] + 1);
                }
            }
            mp[word] = len;
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends