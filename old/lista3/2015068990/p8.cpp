#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct Edge
{
    int v, rev;
    ll cap;
    Edge(int v_, ll cap_, int rev_) : v(v_), rev(rev_), cap(cap_) {}
};

struct Dinic
{
    vector<vector<Edge> > g;
    vector<int> level;
    queue<int> q;
    ll flow;
    int n;

    Dinic(int n_) : g(n_), level(n_), n(n_) {}

    void addEdge(int u, int v, ll cap)
    {
        if(u == v) return;
        Edge e(v, cap, int(g[v].size()));
        Edge r(u, 0, int(g[u].size()));
        g[u].push_back(e);
        g[v].push_back(r);
    }

    bool buildLevelGraph(int src, int sink)
    {
        fill(level.begin(), level.end(), -1);
        cout << "src = " << src << endl;
        cout << "sink = " << sink << endl;
        while(not q.empty()) q.pop();
        level[src] = 0;
        q.push(src);
        while(not q.empty())
        {
            int u = q.front();
            cout << "u = " << u << endl;
            q.pop();
            for(vector<Edge>::iterator e=g[u].begin();e!=g[u].end();e++)
            {
                cout << "eita = " << e->v << endl;
                if(not e->cap or level[e->v] != -1) continue;
                level[e->v] = level[u] + 1;
                if(e->v == sink) return true;
                q.push(e->v);
            }
        }
        cout << "returned false\n";
        return false;
    }

    ll blockingFlow(int u, int sink, ll f)
    {
        if(u == sink or not f) return f;
        cout << "u = " << u << endl;
        ll fu = f;
        for(vector<Edge>::iterator e=g[u].begin();e!=g[u].end();e++)
        {

            if(not e->cap or level[e->v] != level[u] + 1) continue;
            ll mincap = blockingFlow(e->v, sink, min(fu, e->cap));
            if(mincap)
            {
                g[e->v][e->rev].cap += mincap;
                e->cap -= mincap;
                fu -= mincap;
            }
        }
        if(f == fu) level[u] = -1;
        return f - fu;
    }

    ll maxFlow(int src, int sink)
    {
        flow = 0;
        while(buildLevelGraph(src, sink))
            flow+= blockingFlow(src, sink, numeric_limits<ll>::max());
        return flow;
    }
};

int main()
{
   int n,m;
   
    while(cin>>n>>m){
        cout << n << " " << m << endl;
        
        int sink = 2*n+1;
        Dinic my_dinic = Dinic(sink); // vertices 0 a n-1
        
        for(int i=1;i<=n;i++)my_dinic.addEdge(0,i,1);
        for(int i=n+1;i<=2*n;i++)my_dinic.addEdge(i,sink,1);

        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            cout << u << " " << v << endl;
            my_dinic.addEdge(u+1,v+1+n,1);
            // my_dinic.addEdge(v,u,1);
        }

        cout<< my_dinic.maxFlow(0,n+1)<<endl; 
    }
   
   return 0;
}

