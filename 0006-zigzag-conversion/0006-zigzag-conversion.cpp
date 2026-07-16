class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows >= n || numRows == 1) return s;
        vector<vector<char>> grid(numRows,vector<char>(1000,'0'));
        int i = 0;
        int r = 0;
        int c = 0;
        while(i<n){
            while(r<numRows && i<n){
                grid[r++][c] = s[i++];
            }
            r--;
            while(r!=1 && i<n){
                grid[--r][++c] = s[i++];
            }
            r--;
            c++;
        }
        string ans;
        int count = 0;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<1000;j++){
                if(grid[i][j] !='0'){
                    ans.push_back(grid[i][j]);
                    count++;
                }
                if(count == n) break;
            }
            if(count == n) break;
        }
        return ans;
    }
};