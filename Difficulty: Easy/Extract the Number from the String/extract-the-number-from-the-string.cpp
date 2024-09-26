//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
         vector<string>ans;
        vector<long long>res;
        string a;
        for(int i=0;i<sentence.length();i++){
            if(isdigit(sentence[i])){
                a+=sentence[i];
            }
            if(sentence[i]==' '){
                if(a.length()!=0){
                    ans.push_back(a);
                    a="";
                }
            }
        }
        if(a.length()!=0){
            ans.push_back(a);
        }
        for(int i=0;i<ans.size();i++){
            string b=ans[i];
            bool x=true;
            for(int i=0;i<b.length();i++){
                if(b[i]=='9'){
                    x=false;
                }
            }
            if(x==true){
                long long val=stoll(ans[i]);
                res.push_back(val);
            }
        }
        long long maxi=-1;
        for(long long i=0;i<res.size();i++){
            maxi=max(maxi,res[i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends