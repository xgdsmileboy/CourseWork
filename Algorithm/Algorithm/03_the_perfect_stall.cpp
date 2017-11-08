//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<bool> visited;
//vector<int> lefts;
//vector<int> rights;
//vector< vector<int> > lnkList;
//int n, m;
//
//bool dfs(int u){
//    for(int i = 0; i < lnkList[u].size(); i++){
//        int v = lnkList[u][i];
//        if(visited[v])
//            continue;
//        if(rights[v] == 0){
//            rights[v] = u;
//            lefts[u] = v;
//            return true;
//        }
//        visited[v] = true;
//        if(dfs(rights[v])){
//            rights[v] = u;
//            lefts[u] = v;
//            visited[v] = false;
//            return true;
//        }
//    }
//    return false;
//}
//
//int hungrian(){
//    int match = 0;
//    for(int u = 1; u < lnkList.size(); u++){
//        if(!lefts[u]){
//            if(dfs(u))
//                match ++;
//        }
//    }
//    return match;
//}
//
//void initDataSet(int n, int m){
//    visited.clear();
//    lefts.clear();
//    rights.clear();
//    lnkList.clear();
//    lefts.resize(n+1, 0);
//    rights.resize(m+1, 0);
//    visited.resize(n+1, false);
//    lnkList.resize(n+1, vector<int>());
//}
//
//void perfectStall(){
//    while(cin>>n>>m){
//        initDataSet(n, m);
//        int num, stall;
//        for(int id = 1; id <= n; id++){
//            cin>>num;
//            for(int i = 0; i < num; i++){
//                cin>>stall;
//                lnkList[id].push_back(stall);
//            }
//        }
//        cout<<hungrian()<<endl;
//    }
//}
//
//int main(){
//    perfectStall();
//}
