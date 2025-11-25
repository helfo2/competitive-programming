void bfs(){
  visited.reset(); visited[s] = 1;
  queue<int> q; q.push(s);
  memset(p, -1, sizeof p);
  while(!q.empty()){
    int u = q.front(); q.pop();
    if (u==t) break;
    for (int i = 0; i < graph[u].size(); i++){
      int v = graph[u][i];
      if (!visited[v] && res[u][v]){
        p[v] = u;
        visited[u] = 1;
        q.push(v);
      }  
    }
  }
} 

bool dfs(int v){
  visited[v] = 1;
  if (v == t) return 1;
  for (int i = 0; i < graph[v].size(); i++){
    int new_vertex = graph[v][i];
    if (res[v][new_vertex] && !visited[new_vertex]){
      p[new_vertex] = v;
      if (dfs(new_vertex)) return 1;
    }
  }
  return 0;
}