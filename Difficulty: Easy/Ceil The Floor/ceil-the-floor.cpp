//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        vector<int> v;
            
             for(int i=0;i<arr.size();i++){
                    if(arr[i]==x) {
                        v.push_back(x);
                        v.push_back(x);
                        return v;
                    }
             }
             
             
            int lowerbound=-1;
            
            int temp=INT_MIN;
            
            for(int i=0;i<arr.size();i++){
                 if(arr[i]<x){
                     if(arr[i]>temp){
                         temp=arr[i];
                         lowerbound=arr[i];
                     }
                 }
            }
            
            int higherbound=-1;
            
            int temp1=INT_MAX;
          
           for(int i=0;i<arr.size();i++){
                 if(arr[i]>x){
                     if(arr[i]<temp1){
                         temp1=arr[i];
                         higherbound=arr[i];
                     }
                 }
           }
            
            
            v.push_back(lowerbound);
            v.push_back(higherbound);
            return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends