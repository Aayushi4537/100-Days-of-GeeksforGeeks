//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        int a, b, c, d;
        char slash1, slash2, comma;
        std::stringstream ss(str);

        // Parsing the input string
        ss >> a >> slash1 >> b >> comma >> c >> slash2 >> d;

        // Cross-multiplying to compare fractions
        int leftSide = a * d;
        int rightSide = b * c;

        if (leftSide > rightSide) {
            return to_string(a) + "/" + to_string(b);
        } else if (leftSide < rightSide) {
            return to_string(c) + "/" + to_string(d);
        } else {
            return "equal";
        }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends