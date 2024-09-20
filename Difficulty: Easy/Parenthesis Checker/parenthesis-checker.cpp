//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        if(x.length()%2!=0) return false;
        stack<char> st;
        for(int i=0;i<x.length();i++){
            if(x[i]=='('||x[i]=='{'||x[i]=='[') st.push(x[i]);
            else{
                if(st.size()==0) return false;
                char c=st.top();
                if(c=='(' && x[i]!=')') return false;
                else if(c=='{' && x[i]!='}') return false;
                else if(c=='[' && x[i]!=']') return false;
                st.pop();
            }
        }
        if(st.size()==0) return true;
        else return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends