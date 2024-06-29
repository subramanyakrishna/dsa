class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return vector<int>{0};
        vector<vector<int>> adjs(n);
        vector<int> edgeCount(n,0);
        for(int i = 0;i<edges.size();i++){
            int a=edges[i][0], b=edges[i][1];
            adjs[a].push_back(b);
            adjs[b].push_back(a);
            edgeCount[a]++;
            edgeCount[b]++;
        }
        queue<int> leaves;
        
        for(int i = 0 ; i < n ; i++){
            if(edgeCount[i]==1) leaves.push(i);
        }
        vector<int> ans;
        
        while(!leaves.empty()){
            int n = leaves.size();
            ans.clear(); 
            while(n--){
                int node = leaves.front();
                leaves.pop();
                ans.push_back(node);
                for(int i=0;i<adjs[node].size();i++){
                    edgeCount[adjs[node][i]]--;
                    if(edgeCount[adjs[node][i]]==1) leaves.push(adjs[node][i]);
                }
            }
        }
        return ans;
    }
};