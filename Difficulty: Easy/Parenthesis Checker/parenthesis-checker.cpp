//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        map<char,int>m ={{'{',-1},{'(',-2},{'[',-3},{'}',1},{')',2},{']',3}};
    stack<char>st;
    for(int i=0;i<x.length();i++){
      if(st.empty()){
        st.push(x[i]);
      }else{
          if(m[x[i]]>0){
              if(m[x[i]]+m[st.top()]==0){
                  st.pop();
              }else{
                  return false;
                  
              }
          }else{
              st.push(x[i]);
          }
      }
    }
    if(st.empty())return true;
    return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends