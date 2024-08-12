//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
         int n = arr2.size();
         int low = n-1;
         int high =0;
         while(low >= 0 && high < n)
         {
             if(arr1[low] > arr2[high])
             {
                 swap(arr1[low],arr2[high]);
                 low--;
                 high++;
             }
             else
             {
                 break;
             }
         }
         sort(arr1.begin(),arr1.end());
         sort(arr2.begin(),arr2.end());
         low = arr1[n-1];
         high = arr2[0];
         int mid = low +high;
         return mid;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends