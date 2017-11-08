//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <queue>
//#include <climits>
//
//#define INF INT_MAX
//using namespace std;
//
//int augment(vector<vector<int> > &cap, int s, int t, const vector<int> &p) {
//  int bt = -1, v = t;
//  while (v != s) {
//    int u = p[v];
//    int c = cap[u][v];
//    if (bt < 0 || c < bt) bt = c;
//    v = u;
//  }
//  v = t;
//  while (v != s) {
//    int u = p[v];
//    cap[u][v] -= bt;
//    cap[v][u] += bt;
//    v = u;
//  }
//  return bt;
//}
//
//int bfs(vector<vector<int> > &cap, int s, int t) {
//  int n = (int)cap.size();
//  vector<bool> visited(n);
//  vector<int> p(n);
//  queue<int> q;
//  visited[s] = true;
//  q.push(s);
//  while (!q.empty()) {
//    int u = q.front();
//    q.pop();
//    for (int v=0; v<n; v++) {
//      if (!visited[v] && cap[u][v] > 0) {
//        visited[v] = true;
//        p[v] = u;
//        if (v == t) return augment(cap, s, t, p);
//        q.push(v);
//      }
//    }
//  }
//  return 0;
//}
//
//int ek(vector<vector<int> > &cap, int s, int t) {
//  int flow, max_flow = 0;
//  while ((flow = bfs(cap, s, t)) > 0) {
//    max_flow += flow;
//  }
//  return max_flow;
//}
//
//int main() {
//    int n, m;
//    cin >> m >> n;
//    vector<int> initNum(m+1);
//    vector<int> openPersonNum(m+1, -1);
//    vector<vector<int> > cap(n+2, vector<int>(n+2));
//    for(int i = 1; i <= m; i++) {
//        cin>>initNum[i];
//    }
//    for (int personid=1; personid<=n; personid++) {
//        int canOpenNumber;
//        cin>>canOpenNumber;
//        for(int i = 0; i < canOpenNumber; i++) {
//            int openNumber;
//            cin>>openNumber;
//            if(openPersonNum[openNumber] == -1) {
//                openPersonNum[openNumber] = personid;
//                cap[0][personid] += initNum[openNumber];
//            }else{
//                int parent = openPersonNum[openNumber];
//                cap[parent][personid] = INF;
//            }
//        }
//        cin>>cap[personid][n+1];
//    }
//    cout << ek(cap, 0, n+1) << endl;
//    return 0;
//}
