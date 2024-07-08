//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int start=0;
        int end= arr.size()-1;
        
        while(start<=end){
            int mid= start+ (end-start)/2;
            if(key== arr[mid]){
                return mid;
            }
            else if(arr[mid]==arr[start]&& arr[mid]==arr[end]){
                start++;
                end--;
            }
            else if(arr[mid]>=arr[start]){
                if(key>=arr[start]&& key < arr[mid]){
                    end= mid-1;
                    
                }
                else
                start= mid+1;
            }
            else {
            if (key>arr[mid]&& key<=arr[end]){
                start= mid+1;
            }
            else 
            end= mid-1;
            }
            
        }
        return -1;
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
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends