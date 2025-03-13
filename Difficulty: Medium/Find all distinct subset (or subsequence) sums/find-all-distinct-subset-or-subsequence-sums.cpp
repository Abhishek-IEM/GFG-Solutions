//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void solve(vector<int> &nums, set<int> &s, int dp[101][100001], int sum, int i)
    {
        if(i == nums.size())
        {
            s.insert(sum);
            return;
        }
        
        if(dp[i][sum] != -1) return;
        dp[i][sum] = 1;
        
        solve(nums, s, dp, sum, i + 1);
        solve(nums, s, dp, sum + nums[i], i + 1);
    }
    
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    set<int> s;
	    int dp[101][100001];
	    memset(dp, -1, sizeof(dp));
	    solve(nums, s, dp, 0, 0);
	    vector<int> ans(s.begin(), s.end());
	    return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends