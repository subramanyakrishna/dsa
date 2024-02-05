class Solution {
public:
   bool isBipartiteHelper(int node,vector<vector<int>>& graph,vector<int> &colorOnV,int parentColor){
        if(parentColor==-1) colorOnV[node] = 1;
        if(colorOnV[node]==parentColor){
            return false;
        }
        else{
            if(parentColor!=-1) colorOnV[node] = parentColor ==1 ?0:1;
            for(auto it:graph[node]){
            if(colorOnV[it]==-1){
                if(!isBipartiteHelper(it,graph,colorOnV,colorOnV[node])) return false;
            }
            else if(colorOnV[node]==colorOnV[it]) return false;
        }
        }
        return true;        
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colorOnV(n,-1);
        for(int i=0;i<n;i++){
            if(colorOnV[i]==-1){
                if(!isBipartiteHelper(i,graph,colorOnV,-1)) return false;
            }
            
        }
        return true   ;     
    }
};