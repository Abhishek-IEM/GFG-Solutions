//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x) {
        // Your Code Here
        sort(arr, arr + n);
        for(int i = 0; i < n - 2; i++)
        {
            int ans = x - arr[i];
            int start = i + 1, end = n - 1;
            while(start < end)
            {
                if(arr[start] + arr[end] == ans) return 1;
                else if(arr[start] + arr[end] > ans) end--;
                else start++;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends