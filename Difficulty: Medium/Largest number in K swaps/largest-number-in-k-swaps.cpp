//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the largest number after k swaps.
    void findMax(string& s, int k, int idx, string& maxNum) {
    if (k == 0) return;

    char maxDigit = s[idx];
    // Find the max digit from the remaining part
    for (int i = idx + 1; i < s.length(); i++) {
        if (s[i] > maxDigit) {
            maxDigit = s[i];
        }
    }

    // Only proceed if we find a greater digit to swap
    if (maxDigit != s[idx]) {
        k--;
    }

    for (int i = s.length() - 1; i >= idx; i--) {
        if (s[i] == maxDigit) {
            swap(s[idx], s[i]);
            if (s > maxNum) {
                maxNum = s;
            }
            findMax(s, k, idx + 1, maxNum);
            swap(s[idx], s[i]); // backtrack
        }
    }
}

    string findMaximumNum(string& s, int k) {
        // code here.
        string maxNum = s;
        findMax(s, k, 0, maxNum);
        return maxNum;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends