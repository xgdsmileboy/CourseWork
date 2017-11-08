////
////  Paid roads.cpp
////  Algorithm
////
////  Created by Jiang Jiajun on 12/18/15.
////  Copyright © 2015 姜佳君. All rights reserved.
////
//
////Memory Time
////248K  16MS
//
///*---- C风格 ----*/
//
//#include<iostream>
//#include <string.h>
//using namespace std;
//
//int n;  //城市数
//int m;  //道路数
//int vist[11];  //记录城市的访问次数,每个城市最多经过3次
//int MinCost;  //最小总花费
//struct
//{
//    int a,b,c,p,r;
//}road[11];  //每条道路的付费规则
//
//void DFS(int a,int fee)   //a:当前所在城市,fee:当前方案的费用
//{
//    if(a==n && MinCost>fee)
//    {
//        MinCost=fee;
//        return;
//    }
//    
//    for(int i=1;i<=m;i++)  //枚举道路
//    {
//        if(a==road[i].a && vist[ road[i].b ]<=3)
//        {
//            int b=road[i].b;
//            vist[b]++;
//            
//            if(vist[ road[i].c ])
//                DFS(b,fee+road[i].p);
//            else
//                DFS(b,fee+road[i].r);
//            
//            vist[b]--;       //回溯
//        }
//    }
//    return;
//}
//
//int main(void)
//{
////    while(cin>>n>>m)
////    {
//    cin>>n>>m;
//        memset(vist,0,sizeof(vist));
//        vist[1]=1;    //从城市1出发，因此预记录到达1次
//        MinCost=2000;
//        
//        for(int i=1;i<=m;i++)
//            cin>>road[i].a>>road[i].b>>road[i].c>>road[i].p>>road[i].r;
//        
//        DFS(1,0);
//        if(MinCost==2000)
//            cout<<"impossible"<<endl;
//        else
//            cout<<MinCost<<endl;
////    }
//    return 0;
//}
