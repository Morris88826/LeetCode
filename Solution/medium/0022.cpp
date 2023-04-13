/*
22. Generate Parentheses (https://leetcode.com/problems/generate-parentheses/description/)
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

ex:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Input: n = 1
Output: ["()"]

Hint: using recursion
*/

#include <iostream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    void generate(int num_open, int num_close, vector<string>& result, string s){ 
        // num_open: number of open brackets left
        // num_close: number of close brackets left
        if(num_open==0 && num_close==0){
            result.push_back(s);
            return;
        }

        if(num_open>0){
            generate(num_open-1, num_close, result, s+"(");
        }

        if(num_close>0 && num_close>num_open){
            generate(num_open, num_close-1, result, s+")");
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, n, result, "");
        return result;
    }


    vector<string> generateParenthesis_v1(int n) { // use too much memories, no need to use set
        if(n==1){
            return {"()"};
        }

        set<string> mySet;
        vector<string> s = generateParenthesis(n-1);
        for(int i=0; i<s.size(); i++){
            string _s = "(";
            _s += s[i] + ")";
            mySet.insert(_s);

            _s = "()";
            _s += s[i];
            mySet.insert(_s);

            _s = s[i];
            _s += "()";
            mySet.insert(_s);
        }
        
        for(int i=2; i<=n/2; i++){
            vector<string> l = generateParenthesis(i);
            vector<string> r = generateParenthesis(n-i);
            for(int j=0; j<l.size(); j++){
                for(int k=0; k<r.size(); k++){
                    mySet.insert(l[j]+r[k]);
                    mySet.insert(r[k]+l[j]);
                }
            }
        }

        vector<string> result;
        for(auto iter=mySet.begin(); iter!=mySet.end(); iter++){
            result.push_back(*iter);
        }
    
        return result;
    }
};