//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // code here
        unordered_map<int, int> freq;
        
        for(int i = 0;i < arr.size();i++){
            if(freq.find(arr[i]) != freq.end())
                freq[arr[i]]++;
            else
                freq[arr[i]] = 1;
        }
        
        for(auto x : freq)
            if(x.second % 2)
                return x.first;
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends