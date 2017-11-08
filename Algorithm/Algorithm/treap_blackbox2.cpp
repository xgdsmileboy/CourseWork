////
////  treap_blackbox2.cpp
////  Algorithm
////
////  Created by Jiang Jiajun on 12/12/15.
////  Copyright © 2015 姜佳君. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <algorithm>
//#include <math.h>
//#include <vector>
//#include <set>
//#include <map>
//#include <queue>
//using namespace std;
//#define L(id) tree[id].ch[0]
//#define R(id) tree[id].ch[1]
//#define Size(id) tree[id].size
//#define Father(id) tree[id].fa
//#define Val(id) tree[id].val
//#define ll int
//ll Mid(ll x,ll y){return (x+y)>>1;}
//#define N 30100
//
//ll a[N], n;
//int ch[N][2],val[N],counts[N],r[N],size[N],tot,root;
//int Newnode(int &rt,int v)
//{
//    rt=++tot;
//    val[rt]=v;
//    ch[rt][0]=ch[rt][1]=0;
//    counts[rt]=size[rt]=1;
//    r[rt]=rand();
//    return rt;
//}
//inline void PushUp(int rt)
//{
//    size[rt]=size[ch[rt][0]]+size[ch[rt][1]]+counts[rt];
//}
//void Rotate(int &x,int kind)
//{
//    int y=ch[x][kind^1];
//    ch[x][kind^1]=ch[y][kind];
//    ch[y][kind]=x;
//    PushUp(x);PushUp(y);
//    x=y;
//}
//int Insert(int &rt,int v)
//{
//    if(rt==0)
//        return Newnode(rt,v);
//    int ans;
////    if(v==val[rt]) counts[rt]++, ans = rt;
////    else
////    {
//        int kind=(v>val[rt]);
//        ans = Insert(ch[rt][kind],v);
//        if(r[ch[rt][kind]]<r[rt])
//            Rotate(rt,kind^1);
////    }
//    PushUp(rt);
//    return ans;
//}
//int select(int rt,int k)
//{
//    if(size[ch[rt][0]]>=k) return select(ch[rt][0],k);
//    if(size[ch[rt][0]]+counts[rt]>=k) return val[rt];
//    return select(ch[rt][1],k-size[ch[rt][0]]-counts[rt]);
//}
//
//void Init()
//{
//    ch[0][0]=ch[0][1]=0;
//    size[0]=counts[0]=val[0]=0;
//    tot=root=0;
//    r[0]=(1LL<<31)-1;
//    Newnode(root,2000000001);
//}
//int q[N];
//int main(){
//    int que, i, l, r;
//    scanf("%d %d",&n,&que);
//        Init();
//        for(i=1;i<=n;i++)scanf("%d",&a[i]);
//        for(i=1;i<=que;i++)scanf("%d",&q[i]);
//        int s = 1, cnt = 0;
//        for(i=1;i<=n;i++)
//        {
//            Insert(root, a[i]);
//            if(s>n)break;
//            while(size[root]-1 == q[s])
//            {
//                printf("%d\n",select(root,++cnt));
//                s++;
//            }
//        }
//    
//    return 0;
//}
///*
// 7 3
// 1 5 2 6 3 7 4
// 2 5 3
// 4 4 1
// 1 7 3
// 
// */
