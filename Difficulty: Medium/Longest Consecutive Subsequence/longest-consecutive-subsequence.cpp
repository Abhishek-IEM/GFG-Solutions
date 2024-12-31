//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        if (arr.empty()) return 0;
        int n = arr.size(), count = 1, maxi = 1;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n - 1; i++)
        {
            if(arr[i + 1] - arr[i] == 1)
            {
                count++;
                maxi = max(maxi, count);
            }
            else if(arr[i + 1] == arr[i]) continue;
            else count = 1;
        }
        return maxi;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends