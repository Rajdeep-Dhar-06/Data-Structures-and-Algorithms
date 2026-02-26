using ll = long long;
class Solution {
public:
    vector<vector<pair<int, int>>> g;
    vector<ll> dist;
    vector<bool> o;
    int n;
    ll k;

    void dijkstra(int u, int mid){
        priority_queue<pair<ll, int>> pq;
        dist.assign(n, 1e18);
        dist[u] = 0;
        pq.push({-0, u});

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            d = -d;

            if(d > dist[u] || !o[u]) continue;

            for(auto [v, c] : g[u]){
                if(!o[v] || c < mid) continue;
                if(dist[v] > d + c && d + c <= k){
                    dist[v] = d + c;
                    pq.push({-dist[v], v});
                }
            }
        }
    }

    bool check(int mid){
        dijkstra(0, mid);
        if(dist[n-1] != 1e18) return true;
        else return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long x) {
        o = online;
        n = online.size();
        k = x;
        g.assign(n, {});
        int lo = 1e9, hi = 0;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int c = e[2];
            g[u].push_back({v, c});
            lo = min(lo, c);
            hi = max(hi, c);
        }

        // for(auto x : minEdge){
        //     cout << x << " ";
        // }
        // cout << endl;
        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(check(mid)){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return ans;
    }
};