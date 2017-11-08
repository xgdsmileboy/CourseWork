////
////  Apple tree.cpp
////  Algorithm
////
////  Created by Jiang Jiajun on 12/18/15.
////  Copyright © 2015 姜佳君. All rights reserved.
////
//
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//const int N=105;
//struct Edge
//{
//    int v;
//    Edge* nxt;
//}memo[N*N],*cur,*adj[N];
//
//int dp[N][N*2][2],n,K;
//
//void dfs(int u,int fa)
//{
//    for(Edge* it=adj[u];it;it=it->nxt)
//    {
//        int v=it->v;
//        if(v==fa) continue;
//        dfs(v,u);
//        for(int i=K;i>=0;i--)
//        {
//            for(int j=0;j<=i;j++)
//            {
//                dp[u][i+2][0]=max(dp[u][i+2][0],dp[u][i-j][0]+dp[v][j][0]);
//                dp[u][i+2][1]=max(dp[u][i+2][1],dp[u][i-j][1]+dp[v][j][0]);
//                dp[u][i+1][1]=max(dp[u][i+1][1],dp[u][i-j][0]+dp[v][j][1]);
//            }
//        }
//    }
//}
//void addEdge(int u,int v)
//{
//    cur->v=v;
//    cur->nxt=adj[u];
//    adj[u]=cur++;
//}
//void init()
//{
//    cur=memo;
//    memset(adj,0,sizeof(adj));
//    memset(dp,0,sizeof(dp));
//}
//int main()
//{
//    while(scanf("%d%d",&n,&K)!=EOF)
//    {
//        init();
//        
//        for(int i=1;i<=n;i++)
//        {
//            scanf("%d",&dp[i][0][1]);
//            dp[i][0][0]=dp[i][0][1];
//        }
//        for(int i=1;i<n;i++)
//        {
//            int u,v;
//            scanf("%d%d",&u,&v);
//            addEdge(u,v);
//            addEdge(v,u);
//        }
//        
//        dfs(1,-1);
//        
//        int res=0;
//        for(int i=0;i<=K;i++) res=max(res,dp[1][i][1]);
//        printf("%d\n",res);
//    }
//    return 0;
//}
