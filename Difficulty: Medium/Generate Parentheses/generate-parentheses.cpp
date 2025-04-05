//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends

//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int n, string &temp, vector<string> &ans, int open, int close)
    {
        if(open == n && close == n)
        {
            ans.push_back(temp);
            return;
        }
        
        if(open < n)
        {
            temp.push_back('(');
            solve(n, temp, ans, open + 1, close);
            temp.pop_back();
        }
        
        if(close < open)
        {
            temp.push_back(')');
            solve(n, temp, ans, open, close + 1);
            temp.pop_back();
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        string temp;
        vector<string> ans;
        solve(n, temp, ans, 0, 0);
        return ans;
    }
};


//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	
cout << "~" << "\n";
}
	return 0; 
} 

// } Driver Code Ends