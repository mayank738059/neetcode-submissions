from collections import deque
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj=[[] for _ in range(n)]
        for it in flights:
            u=it[0]
            v=it[1]
            w=it[2]
            adj[u].append((v,w))
        inf=1000000009
        dist=[inf]*n
        q=deque()
        q.append((0,src,0)) #stops,node,dist
        dist[src]=0
        while q:
            stops,node,dis=q.popleft()
            if stops>k:continue
            for it in adj[node]:
                m=it[0]
                wt=it[1]
                if dist[m]>dis+wt and stops<=k:
                    dist[m]=dis+wt
                    q.append((stops+1,m,dis+wt))
        if dist[dst]==inf:return -1
        return dist[dst]




