class DisJointSet{
public:
    vector<int> size,parent;
    DisJointSet(int n){
        size.resize(n+1);
        parent.resize(n+1,0);

        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findUPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findUPar(parent[u]);
    }
    void joinBySize(int u,int v){
        int ulp=findUPar(u);
        int vlp=findUPar(v);
        if(ulp==vlp) return;
        if(size[ulp]<size[vlp]){
            parent[ulp]=vlp;
            size[vlp]+=size[ulp];
        }
        else if(size[ulp]>size[vlp]){
            parent[vlp]=ulp;
            size[ulp]+=size[vlp];
        }
        else{
            parent[vlp]=ulp;
            size[ulp]+=size[vlp];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> ans;
        DisJointSet ds(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.findUPar(u)==ds.findUPar(v)) ans.push_back(it);
            else ds.joinBySize(u,v);
        }
        return ans.back();
    }
};
