class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& visited,int r,int c,int &color,int& s_color){
        int m = image.size();
        int n = image[0].size();
        visited[r][c] = 1;
        image[r][c] = color;

        int d_row[] = {-1,1,0,0};
        int d_col[] = {0,0,-1,1};

        for(int k=0;k<4;k++){
            int new_row = r + d_row[k];
            int new_col = c + d_col[k];
            if(new_row >= 0 && new_row < m && new_col >=0 && new_col < n){
                if(visited[new_row][new_col] == 0 && image[new_row][new_col] == s_color){
                    dfs(image,visited,new_row,new_col,color,s_color);
                }
            }
        }

        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));

        if(image[sr][sc] == color){
            return image;
        }

        int s_color = image[sr][sc];
        dfs(image,visited,sr,sc,color,s_color);

        return image;
    }
};