import heapq

class Solution:
    def networkDelayTime(self, times, n, k):

        adj = [[] for _ in range(n)]

        for u, v, w in times:
            adj[u - 1].append((v - 1, w))

        inf = 10**9
        dist = [inf] * n

        pq = []

        dist[k - 1] = 0
        heapq.heappush(pq, (0, k - 1))

        while pq:
            dis, node = heapq.heappop(pq)

            if dis > dist[node]:
                continue

            for nxt, wt in adj[node]:
                if dis + wt < dist[nxt]:
                    dist[nxt] = dis + wt
                    heapq.heappush(pq, (dist[nxt], nxt))

        ans = max(dist)

        return -1 if ans == inf else ans