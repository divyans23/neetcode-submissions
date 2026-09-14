class Solution {
public:
    int rows;
    int column;
    bool dfs(vector<vector<char>>&board,string word,int r,int c,int idx){
        if(idx==word.size()){
            return true;
        }
        if(r<0 ||r>=rows || c<0 || c>=column) return false;
        if(board[r][c]!=word[idx]) return false;
        char temp=board[r][c];
        // mark the visted one 
        board[r][c]='#';
        bool found = dfs(board,word,r+1,c,idx+1) ||dfs(board,word,r-1,c,idx+1) ||dfs(board,word,r,c+1,idx+1) ||dfs(board,word,r,c-1,idx+1);
        // undoing when the dead end is acheived
        board[r][c]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        column=board[0].size();
        for(int r=0;r<rows;r++){
            for(int c=0;c<column;c++){
                if(dfs(board,word,r,c,0)){
                    return true;
                }
                
            }
        }
        return false;
    }
};