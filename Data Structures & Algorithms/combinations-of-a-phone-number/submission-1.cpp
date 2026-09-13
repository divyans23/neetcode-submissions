class Solution {
public:
    vector<string>ans;
    vector<string>mapping={
        ",",",","abc","def",
        "ghi","jkl","mno",
        "pqrs","tuv","wxyz"
    };
    void backtrack(string digits,string current,int idx){
        if(current.size()==digits.size()){
            ans.push_back(current);
            return;
        }
        string letters=mapping[digits[idx]-'0'];
        for(char c:letters){
            current.push_back(c);
            backtrack(digits,current,idx+1);
            // undoing when the dead end is achieved 
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string current;
        backtrack(digits,current,0);
        return ans;
    }
};
