//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m > n) return -1;
        int sta = 0;
        long long end, mid, ans;
        for(int i = 0; i < n; i++)
        {
            sta = max(sta, arr[i]);
            end += arr[i];
        }
        long long start = sta;
        while(start <= end)
        {
            mid = start + (end - start)/2;
            long long pages = 0, count = 1;
            for(int i = 0; i < n; i++)
            {
                pages += arr[i];
                if(pages > mid)
                {
                    count++;
                    pages = arr[i];
                }
            }
            if(count <= m)
            {
                ans = mid;
                end = mid - 1;
            }
            else
             start = mid + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends