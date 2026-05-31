#include<bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        for(auto it:s){
            if (isalnum(it)) {
                s1 += tolower(it);
            }
        }
        int l=0,r=s1.size()-1;
        while(l<=r){
            if(s1[l]==s1[r]){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
};
