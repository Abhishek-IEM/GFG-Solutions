//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int ans = 0, start = 1, end = stalls.back() - stalls.front();
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int cowCount = 1, prevPos = stalls[0];
            for(int i = 1; i < stalls.size(); i++)
            {
                if(stalls[i] - prevPos >= mid)
                {
                    cowCount++;
                    prevPos = stalls[i];
                }
            }
            if(cowCount >= k) ans = mid, start = mid + 1;
            else end = mid - 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends