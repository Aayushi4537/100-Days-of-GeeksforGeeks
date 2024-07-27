//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(int i, int j, int n, string str, vector<vector<int>>& v){
        if(i>j) return 0;
        if(v[i][j]!=-1) return v[i][j];   //This (i,j) is already solved
        
        if(str[i]==str[j]) return v[i][j] = solve(i+1, j-1, n, str, v);
        return v[i][j] = 1 + min(solve(i+1, j, n, str, v), solve(i, j-1, n, str, v));
    }
    int countMin(string str){
    //complete the function here
    int n=str.size();
        vector<vector<int>> v(n, vector<int>(n, -1));  //For Memorization
        return solve(0, n-1, n, str, v);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends