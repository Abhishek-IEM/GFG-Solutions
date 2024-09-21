//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int n = s.length();
    vector<bool> count(256, 0);
    int first = 0, second = 0, len = 0;
    while(second < n)
    {
        //repeating character
        while(count[s[second]])
        {
            count[s[first]] = 0;
            first++;
        }
        count[s[second]] = 1;
        len = max(len, second - first + 1);
        second++;
    }
    return len;
}