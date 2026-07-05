class Solution {
public:
    int n;
    int mod = 1e9 + 7;
    vector<vector<pair<int,int>>> score_table;
    int getval(char ch){
        if(ch!='S'){
            return ch-'0';
        }else{
            return 0;
        }
    }
    bool isValid(int i,int j,vector<string>& board){
        if(i>=0 && i<n && j>=0 && j<n && board[i][j]!='X'){
            return true;
        }
        else {
            return false;
        }
    }
    pair<int,int> solve(int i,int j,vector<string>& board){
        if(board[i][j] == 'E'){
            return {0,1};
        }
        if(board[i][j] == 'X'){
            return {0,0};
        }

        if(score_table[i][j] != make_pair(-1,-1)){
            return score_table[i][j];
        }
        int leftscore = 0, leftpath = 0;
        int upscore = 0, uppath = 0;
        int diagscore = 0, diagpath = 0;

        char ch = board[i][j];

        if(isValid(i,j-1,board)){ //up
            pair<int,int> temp = solve(i,j-1,board);
            upscore = temp.first;
            uppath = temp.second;

            if(uppath > 0){
                upscore += getval(ch);
            }
        }
        if(isValid(i-1,j,board)){ //left
            pair<int,int> temp = solve(i-1,j,board);
            leftscore = temp.first;
            leftpath = temp.second;

            if(leftpath > 0){
                leftscore += getval(ch);
            }
        }
        if(isValid(i-1,j-1,board)){ //upleft(diagonal)
            pair<int,int> temp = solve(i-1,j-1,board);
            diagscore = temp.first;
            diagpath = temp.second;

            if(diagpath > 0){
                diagscore += getval(ch);
            }
        }

        // finding bestscore and bestpath among all of them
        int bestscore,bestpath;
    
        if(upscore == leftscore && leftscore == diagscore){
            bestscore = upscore;
            bestpath = uppath + leftpath + diagpath;
        }
        else if(upscore == leftscore){
            bestscore = upscore;
            bestpath = uppath + leftpath;
            
            if(diagscore > bestscore || (diagscore == bestscore && diagpath > bestpath)){
                bestscore = diagscore;
                bestpath = diagpath;
            }
        }
        else if(leftscore == diagscore){
            bestscore = leftscore;
            bestpath = leftpath + diagpath;
            
            if(upscore > bestscore || (upscore == bestscore && uppath > bestpath)){
                bestscore = upscore;
                bestpath = uppath;
            }
        }else{
            bestscore = upscore;
            bestpath = uppath;
            
            if(leftscore > bestscore || (leftscore == bestscore && leftpath > bestpath)){
                bestscore = leftscore;
                bestpath = leftpath;
            }
            if(diagscore > bestscore || (diagscore == bestscore && diagpath > bestpath)){
                bestscore = diagscore;
                bestpath = diagpath;
            }
        }

        score_table[i][j] = {bestscore,bestpath % mod};
        return score_table[i][j];
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        score_table.assign(n,vector<pair<int,int>>(n,{-1,-1}));
        pair<int,int> result = solve(n-1,n-1,board);

        return {result.first, result.second};
    }
};