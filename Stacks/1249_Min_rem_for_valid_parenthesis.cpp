#include <iostream>
#include<string>
#include<stack>
using namespace std;

// class Solution {
// public:
//     Solution(){
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
//     }
//     string minRemoveToMakeValid(string s) {
//         stack<int> st ;


//         for(int c = 0 ; c < s.length();c++){
//             if(s[c]==')' && st.empty()){
//                 s[c]=' ';
//             }
//             else if(s[c]==')'){
//                 st.pop();
//             }
//             else if(s[c]=='('){
//                 st.push(c);
//             }
//         }
        
//         while (!st.empty()) {
//             s[st.top()] = ' ';
//             st.pop();
//         }

//         s.erase(remove(s.begin(),s.end(),' '),s.end());

//         return s;
//     }
// };