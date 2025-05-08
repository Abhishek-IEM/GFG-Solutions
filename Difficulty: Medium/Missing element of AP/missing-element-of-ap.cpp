//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int>& arr) {
        int n = arr.size();
        if (n == 2) {
            int diff = arr[1] - arr[0];
            return arr[1] + diff;
        }
    
        int diff1 = arr[1] - arr[0];
        int diff2 = arr[2] - arr[1];
        int common_diff = (diff1 == diff2) ? diff1 :
                          (diff1 == arr[3] - arr[2] ? diff1 : diff2);
    
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] != common_diff) {
                return arr[i - 1] + common_diff;
            }
        }
    
        return arr[n - 1] + common_diff;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends