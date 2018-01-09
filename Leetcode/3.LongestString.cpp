/**
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //check input
        if (s.size() <= 1) return s.size();
        
        map<char, int> mTmp;
        int left = 0, right = 0, len = s.size(), final = 0;
        
        //right processing
        while (right<len){
            if (mTmp.find(s[right]) != mTmp.end()){
                final = final>mTmp.size() ? final : mTmp.size();
                //left processing
                while (left <= right){
                    if (s[left] != s[right]){
                        mTmp.erase(s[left]);
                        left++;
                    }
                    else{
                        left++;
                        right++;
                        break;
                    }
                }
            }
            else {
                mTmp[s[right]] = right;
                right++;
            }
       }

    final = final>mTmp.size() ? final : mTmp.size();
    return final;
    }
};