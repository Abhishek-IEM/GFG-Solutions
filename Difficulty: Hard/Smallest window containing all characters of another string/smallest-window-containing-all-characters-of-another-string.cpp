//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s, string &t) {
        // Your code here
        int total = t.size();
        int n = s.size();
        unordered_map<char, int> m;
        
        for(int i = 0; i < t.size(); i++)
        {
            m[t[i]]++;
        }
        
        int start = 0, end = 0, ans = INT_MAX, index = -1;
        
        while(end < s.size())
        {
            m[s[end]]--;
            
            if(m[s[end]] >= 0) total--;
            while(!total && start <= end)
            {
                if(ans > end - start + 1)
                {
                    ans = end - start + 1;
                    index = start;
                }
                
                m[s[start]]++;
                
                if(m[s[start]] > 0) total++;
                
                start++;
            }
            end++;
        }
        
        if(index == -1) return "";
        
        string str = "";
        
        for(int i = index; i < index + ans; i++)
        {
            str += s[i];
        }
        
        return str;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        string str = obj.smallestWindow(s1, s2);
        if (str.size() == 0) {
            cout << "\"\"" << endl;
        } else {
            cout << str << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends