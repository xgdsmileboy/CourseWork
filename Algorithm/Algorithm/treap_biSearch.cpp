////
////  treap_biSearch.cpp
////  Algorithm
////
////  Created by Jiang Jiajun on 12/8/15.
////  Copyright © 2015 姜佳君. All rights reserved.
////
//
//#include <iostream>
//#include <cstdio>
//#include <string.h>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//    char str[100];
//    int value,ls,rs,pa;
//    Node()
//    {
//        value=pa=ls=rs=0;
//        memset(str,0,sizeof(str));
//    }
//}treap[50005];
//bool operator < (const Node a,const Node b)
//{
//    return strcmp(a.str,b.str)<0;
//}
//void insert(int i)
//{
//    int j=i-1;
//    while(treap[j].value<treap[i].value)
//        j=treap[j].pa;
//    treap[i].ls=treap[j].rs;
//    treap[j].rs=i;
//    treap[i].pa=j;
//}
//void dfs(int i)   //中序遍历
//{
//    if(i)
//    {
//        printf("(");
//        dfs(treap[i].ls);
//        printf("%s/%d",treap[i].str,treap[i].value);
//        dfs(treap[i].rs);
//        printf(")");
//    }
//}
//int main()
//{
//    int n;
//    while(scanf("%d",&n),n)
//    {
//        memset(treap,0,sizeof(treap));
//        for(int i=1;i<=n;i++)
//        {
//            scanf("%*[ ]%[^/]/%d",treap[i].str,&treap[i].value);
//        }
//        sort(treap+1,treap+n+1);
//        treap[0].value=10000000;
//        for(int i=1;i<=n;i++)
//        {
//            insert(i);
//        }
//        dfs(treap[0].rs);
//        printf("\n");
//    }
//}
