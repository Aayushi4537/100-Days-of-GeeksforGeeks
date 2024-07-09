//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int n= arr.size();
        sort(arr.begin(), arr.end());
        int closestsum= INT_MAX/2;
        for(int i=0; i<n-2; i++){
            int j= i+1;
            int k= n-1;
            while(j<k){
                int currentsum= arr[i]+ arr[j]+ arr[k];
                if (abs(currentsum - target) < abs(closestsum - target) || 
                (abs(currentsum - target) == abs(closestsum - target) && currentsum > closestsum)) {
                closestsum = currentsum;
            }
            
            if(currentsum< target){
                j++;
            }
            else{
                k--;
            }
                
                
            }
            
        }
        return closestsum;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends