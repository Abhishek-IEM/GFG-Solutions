//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    void solve(int i, vector<int>& arr, vector<int>& temp, vector<vector<int>> &ans)
    {
        if(i >= arr.size())
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(arr[i]);
        solve(i + 1, arr, temp, ans);
        temp.pop_back();
        solve(i + 1, arr, temp, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, arr, temp, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the number of test cases
    while (t--) {
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<vector<int>> res = ob.subsets(arr);

        // Print result
        for (const auto& subset : res) {
            if (subset.size() == 0) {
                cout << "[]";
            } else
                for (int num : subset) {
                    cout << num << " ";
                }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends