// memoization
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<char>memo(s.size() + 2 , -1);
        return solve(0 , s,wordDict  , memo);
    }
    bool solve(int i , string &s, vector<string>& wordDict , vector<char>&memo){
        if (i >= s.size())return true;
        char &ret = memo[i];
        if(~ret)return ret;
        bool res = false;

        for(auto word:wordDict){
            int wordLen = (int)word.size();
            if(i+wordLen <= s.size()){
                string subWord = s.substr(i , wordLen);
                if(subWord == word){
                    res |= solve(i+wordLen , s , wordDict , memo);
                }
            }
        }
        return ret = res;
    }
};

// dp iterative

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = (int)s.size();
        vector<bool>dp(n + 1 , false);
        dp[n]=true;
        for(int i = n-1 ; i >= 0 ; i--){
            for(auto word:wordDict){
                if(i+word.size() <= s.size()){
                    string subWord = s.substr(i , word.size());
                    if(word == subWord){
                        dp[i] = dp[i] || dp[i+word.size()];
                    }
                }
            }
        }
        return dp[0];
    }
};
