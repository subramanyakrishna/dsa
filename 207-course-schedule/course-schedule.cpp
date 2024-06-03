class Solution {
public:
    bool dfsCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
		vis[node] = 1;
		pathVis[node] = 1;
		for (int it : adj[node]) {
			if (!vis[it]) {
				if (dfsCheck(it, adj, vis, pathVis) == false)
					return false;
			}
			else if (pathVis[it]) {
				return false;
			}
		}
		pathVis[node] = 0;
        
		return true;
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses);
        vector<int> pathVis(numCourses);  
        vector<int> adj[numCourses];
        for(auto x:prerequisites){
            adj[x[0]].push_back(x[1]);
        }
		for (int i = 0; i < numCourses; i++) {
			if (!vis[i]) {
				if (dfsCheck(i, adj, vis, pathVis) == false) return false;
			}
		}
		return true;
    }
};