//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        for(auto x : mp)
        {
            int a = x.first;
            int b = x.second;
            if(b % 2 != 0) return a;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends