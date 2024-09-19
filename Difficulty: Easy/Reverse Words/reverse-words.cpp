//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
       int n = S.length();
       string ans = "";
       string d = "";
       reverse(S.begin(),S.end());
       int i = 0;
       while(i < n)
       {
           if(S[i] != '.')
           {
               d += S[i];
           }
           else
           {
               reverse(d.begin(),d.end());
               d += ".";
               ans += d;
               d = "";
           }
           i++;
       }
      reverse(d.begin(), d.end());
      ans += d;
        
       return ans;
    } 
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends