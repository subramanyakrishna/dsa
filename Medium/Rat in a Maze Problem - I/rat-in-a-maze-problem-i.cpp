//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void backTrack(
        vector<vector<int>> &m,
            int n,
            int i ,
            int j,
            string &path,
            vector<string> &paths,
            vector<vector<bool>> &visited ){
                
        if(i == n-1 && j == n-1) {
            paths.push_back(path);
            return;
        }
        
        visited[i][j] = true;
    
        
        if(i+1 < n  && !visited[i+1][j] && m[i+1][j] ){
            path.push_back('D');
            backTrack(m,n,i+1,j,path,paths,visited);
            path.pop_back();
        }
        
        if(j-1 >= 0 && !visited[i][j-1] && m[i][j-1] ){
            path.push_back('L');
            backTrack(m,n,i,j-1,path,paths,visited);
            path.pop_back();
        }
       
        if(j+1 < n && !visited[i][j+1] && m[i][j+1] ){
            path.push_back('R');
            backTrack(m,n,i,j+1,path,paths,visited);
            path.pop_back();
        }
        
        if( i-1 >= 0  && !visited[i-1][j] && m[i-1][j] ){
            path.push_back('U');
            backTrack(m,n,i-1,j,path,paths,visited);
            path.pop_back();
        }
        
        visited[i][j] = false;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string > paths;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        if(m[n-1][n-1] != 1 or m[0][0] != 1 ) return paths;
        string path;
        backTrack(m,n,0,0,path,paths,visited);
        return paths;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends