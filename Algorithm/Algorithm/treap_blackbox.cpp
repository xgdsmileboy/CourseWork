////
////  treap_blackbox.cpp
////  Algorithm
////
////  Created by Jiang Jiajun on 12/8/15.
////  Copyright © 2015 姜佳君. All rights reserved.
////
//
//#include <stdio.h>
//#include <queue>
//using namespace std;
//int main()
//{
//    int a[30005],i,j,n,m;
//    while(scanf("%d%d",&n,&m)!=EOF)
//    {
//        int cut=0,x,c=0,t;
//        for(i=0; i<n; i++)
//        {
//            scanf("%d",&a[i]);
//        }
//        priority_queue <int , vector <int> , less<int> > p; //大顶堆
//        priority_queue <int , vector <int> , greater<int> >q;
//        for(i=0; i<m; i++)
//        {
//            scanf("%d",&x);
//            while(c<x)
//            {
//                q.push(a[c]);
//                c++;
//            }
//            while(!p.empty()&&p.top()>q.top())  //保证P的元素一定比Q小
//            {
//                t=p.top();
//                p.pop();
//                p.push(q.top());
//                q.pop();
//                q.push(t);
//            }
//            printf("%d\n",q.top());
//            p.push(q.top());
//            q.pop();
//        }
//    }
//    return 0;
//}
//
