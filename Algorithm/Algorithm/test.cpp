////
////  test.cpp
////  Algorithm
////
////  Created by Jiang Jiajun on 12/10/15.
////  Copyright © 2015 姜佳君. All rights reserved.
////
////#include <iostream>
////#include <vector>
////#include <queue>
////using namespace std;
////
////int main(){
////    int n, m;
////    cin>>n>>m;
////    vector<vector<int> > list(n+1, vector<int>());
////    vector<int> degree(n+1,0);
////    int s,t;
////    for(int i = 0; i < m; i++){
////        cin>>s>>t;
////        list[s].push_back(t);
////        degree[t]++;
////    }
////    priority_queue<int, vector<int>, greater<int> > p_q;
////    for(int i = 1; i <= n; i++){
////        if(degree[i] == 0){
////            p_q.push(i);
////        }
////    }
////    
////    while(!p_q.empty()){
////        int a = p_q.top();
////        cout<<"v"<<a<<" ";
////        p_q.pop();
////        for(int i = 0; i < list[a].size(); i++){
////            degree[list[a][i]]--;
////            if(degree[list[a][i]] == 0){
////                p_q.push(list[a][i]);
////            }
////        }
////    }
////    cout<<endl;
////    
////    return 0;
////}
//
//#include<cstdio>
//#include<set>
//#include<cstdlib>
//#include<cstring>
//using namespace std;
//const int maxn = 300010;
//#define L ch[rt][0]
//#define R ch[rt][1]
//int ch[maxn][2], aux[maxn] , num[maxn] , size[maxn] , cnt[maxn];
//int val[maxn];
//int tot,rt;
//inline void init(){
//    size[0]=0;
//    rt = tot = 0;
//    ch[0][0] = ch[0][1] = 0;
//    aux[0] = 0;
//}
//inline void pushup(int rt){
//    size[rt]=cnt[rt]+size[L]+size[R];
//}
//inline void Rotate(int &rt,int f){//f=1:右旋  f=0：左旋
//    int t = ch[rt][!f];
//    ch[rt][!f] = ch[t][f];
//    ch[t][f] = rt;
//    pushup(rt);pushup(t);
//    rt = t;
//}
//void insert(int &rt,int key){
//    if(!rt) {
//        rt = ++tot;
//        val[rt] = key; L = R = 0; size[rt]=cnt[rt]=1;
//        aux[rt] = ( rand() << 14 ) + rand();
//        return ;
//    }
//    if(key==val[rt]) {
//        ++cnt[rt];
//    }else if(key < val[rt]){
//        insert(L , key);
//        if( aux[L] < aux[rt] ) Rotate(rt,1);
//    }else {
//        insert(R , key);
//        if( aux[R] < aux[rt] ) Rotate(rt,0);
//    }
//    pushup(rt);
//}
//void treap_delete(int &rt){//real deletion
//    if(!L || !R){
//        rt=L?L:R;
//    }else {
//        if(aux[L] < aux[R]){
//            Rotate(rt,1);
//            treap_delete(R);
//        }else {
//            Rotate(rt,0);
//            treap_delete(L);
//        }
//    }
//}
//void del(int &rt , int key){//lazy deletion
//    if(key == val[rt]) {
//        cnt[rt]--;
//        size[rt]--;
//        if(cnt[rt]==0)
//            treap_delete(rt);
//    }
//    else {
//        if(key < val[rt])
//            del(L,key);
//        else
//            del(R,key);
//        size[rt]--;
//    }
//}
//int find(int rt,int key){
//    if(!rt) return 0;
//    else if(key < val[rt])  return find(L,key);
//    else if(key > val[rt])  return find(R,key);
//    else return cnt[rt];
//}
////找后继结点
//void succ(int rt,int key,int &ans){//找>=key的第一个结点，即后继结点
//    if(!rt)  return ;
//    if(val[rt] >= key){
//        ans=val[rt];
//        succ(L,key,ans);
//    }else
//        succ(R,key,ans);
//}
////找前驱结点
//void pre(int rt,int key,int &ans){
//    if(!rt) return ;
//    if(val[rt]<=key) {
//        ans=val[rt];
//        succ(R,key,ans);
//    }else
//        succ(L,key,ans);
//}
//int getmin(int rt){
//    while(L) rt=L;    return val[rt];
//}
//int getmax(int rt){
//    while(R) rt=R;   return val[rt];
//}
////找第k小的数
//int find_kth(int rt,int k){
//    if(k<size[L]+1)
//        return find_kth(L,k);
//    else if(k>size[L]+cnt[rt])
//        return find_kth(R,k-size[L]-cnt[rt]);
//    else return val[rt];
//}
////确定key的排名
//int treap_rank(int rt,int key,int cur){//cur:当前已知比要求元素（key）小的数的个数
//    int a;
//    if(key == val[rt])
//        return size[L] + cur + 1;
//    else if(key < val[rt])
//        a = treap_rank(L,key,cur);
//    else
//        a = treap_rank(R,key,cur+size[L]+cnt[rt]);
//    return a;
//}
//int a[maxn],c[maxn],p[maxn];//值为i的数有i个
//int find(int x){return x==p[x] ? x : p[x]=find(p[x]);}
//int main()
//{
//    init();
//    int i,n,m,q,x,y,k,l,r;
//    scanf("%d%d",&n,&m);
//    for(i=1;i<=n;i++) p[i]=i;
//    for(i=1;i<=n;i++) a[i]=1;
//    for(int i=1;i<=n;i++) insert(rt,1);
//    int num=n;
//    for(i=1;i<=m;i++)
//    {
//        scanf("%d",&q);
//        if(q==0)
//        {
//            scanf("%d%d",&x,&y);
//            x=find(x);
//            y=find(y);
//            if(x==y) continue;
//            del(rt,a[x]);
//            del(rt,a[y]);
//            insert(rt,a[x]+a[y]);
//            p[y]=x;
//            a[x]+=a[y];
//            num--;//合并集合
//        }
//        else
//        {
//            scanf("%d",&k);
//            k=num-k+1;//转换为找第k小的数
//            printf("%d\n",find_kth(rt,k));
//        }
//    }
//    return 0;
//}
//
//
//
