class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& ans,int r,int c,int &color,int& s_color){
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        ans[r][c] = color;

        int d_row[] = {-1,1,0,0};
        int d_col[] = {0,0,-1,1};

        while(!q.empty()){
            int c_row = q.front().first;
            int c_col = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int new_row = c_row + d_row[k];
                int new_col = c_col + d_col[k];
                if(new_row >= 0 && new_row < m && new_col >=0 && new_col < n){
                    if(image[new_row][new_col] == s_color && ans[new_row][new_col] != color){
                        q.push({new_row,new_col});
                        ans[new_row][new_col] = color;
                    }
                }
            }
        }

        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();


        if(image[sr][sc] == color){
            return image;
        }

        vector<vector<int>> ans = image;

        int s_color = image[sr][sc];
        dfs(image,ans,sr,sc,color,s_color);

        return ans;
    }
};