//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        if(s>9*d){
            return "-1";
        }
        
        int digits[d];
        for(int i=0; i<d;i++){
            digits[i]=0;
        }
        digits[0]=1;
        s-=1;
        for(int i=d-1; i>=0;i--){
            if(s>9){
                digits[i]+=9;
                s-=9;
            }
            else{
                digits[i]+=s;
                s=0;
            }
        }
        string result= "";
        for(int i=0; i<d;i++){
            result+= to_string(digits[i]);
        }
        return result;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends