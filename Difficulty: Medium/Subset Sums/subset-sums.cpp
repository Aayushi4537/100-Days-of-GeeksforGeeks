//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void f(int i, int sum, vector<int> &arr,int n, vector<int> &sumsubset){
      if(i==n){
          sumsubset.push_back(sum);
          return;
      }
      f(i+1,sum+arr[i],arr,n,sumsubset);
      f(i+1, sum,arr,n,sumsubset);
  }
  
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int>sumsubset;
        f(0,0,arr,n,sumsubset);
        return sumsubset;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends