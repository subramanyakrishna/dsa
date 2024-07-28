class Solution {
public:
    vector<vector<int>> makeGraph(vector<vector<int>>& edges){
        int n = edges.size();
        vector<vector<int>> ret(n+1);
        for(auto edge:edges){
            int u = edge[0],v  = edge[1];
            ret[v].push_back(u);
            ret[u].push_back(v);
        }
        return ret;
    }
    void findFarthest(vector<vector<int>>& adjs, int node, int parent, pair<int,int> &res,int dist){
        if(dist > res.first) res =  {dist,node };
        for(auto n:adjs[node]){
            if(n!=parent) findFarthest(adjs,n,node,res,dist+1);
        }
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto gr1 = makeGraph(edges1), gr2= makeGraph(edges2);

        pair<int,int> res1={INT_MIN,-1} , res2={INT_MIN,-1};
        findFarthest(gr1,0,-1,res1,0);
        findFarthest(gr1,res1.second,-1,res2,0);
        int diameter1 = res2.first;
        res1={INT_MIN,-1};
        res2={INT_MIN,-1};

        findFarthest(gr2,0,-1,res1,0);
        findFarthest(gr2,res1.second,-1,res2,0);
        int diameter2 = res2.first;

        return max(diameter1,max(diameter2,((diameter1+1)/2 +(diameter2+1)/2 +1 )));


    }
};