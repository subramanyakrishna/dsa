class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int  m = grid.size() , n = grid[0].size(), mins = 0 ,tot = 0 , rotCnt = 0;
        queue<pair<int,int>> rot; 
        for(int i = 0 ;i< m; i++){
            for(int j=0; j<n; j++){
                if( grid[i][j] != 0) tot++;
                if( grid[i][j] == 2)  rot.push({i,j});
            }
        }
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        while(!rot.empty()){
            int k = rot.size();
            rotCnt += k;
            while(k--){
                int x = rot.front().first, y = rot.front().second ;
                rot.pop();
                for(int i = 0 ; i < 4; i++){
                    int nx = x +  dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rot.push({nx,ny});
                }        
            }
            if(!rot.empty()) mins++;
        }
        return tot == rotCnt ? mins:-1;
    }
};