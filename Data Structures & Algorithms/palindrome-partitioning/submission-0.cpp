class Solution {
public:
    vector<vector<string>>ans;
    vector<string>current;
    bool isPalindrome(string s,int l,int r){
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void backtrack(string s,int start){
        if(start==s.size()){
            ans.push_back(current);
            return;
        }
        for(int end=start;end<s.size();end++){
            if(!isPalindrome(s,start,end)){
               continue;
            }
            current.push_back(s.substr(start,end-start+1));
            backtrack(s,end+1);
            // undoing when dead end is achieved
            current.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return ans;
    }
};
