//
//  main.cpp
//  Practice
//
//  Created by Jiang Jiajun on 1/7/16.
//  Copyright © 2016 姜佳君. All rights reserved.
//

#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int year1,month1,date1,year2,month2,date2;
    cin>>year1>>month1>>date1>>year2>>month2>>date2;
    int i;
    int yue[13][2]={0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31};
    for(i=0;;i++)
    {
        if(year1==year2&&month1==month2&&date1==date2)
        {
            break;
        }
        
        date1++;
        bool leap=(year1 % 4 == 0 && year1% 100 != 0) || (year1 % 400 == 0);
        if(date1>yue[month1][leap])
        {
            if(month1==12)
            {
                date1=1;
                month1=1;
                year1++;	
            }	
            else
            {
                date1=1;
                month1++;	
            }
        }
    }
    cout<<i<<endl;
    cout<<i%7<<endl;
}


////http://fz.openjudge.cn/dp2/12/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int max(int a , int b){
//    return a > b ? a : b;
//}
//
//int main(){
//    
//    int m, n;
//    while (cin>>m>>n) {
//        vector<vector<int> > profit(n+1, vector<int>(m+1));
//
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                cin>>profit[i][j];
//            }
//        }
//        
//        vector<vector<int> > f(n+1, vector<int>(m+1, 0));
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                f[i][j] = f[i-1][j];
//                for (int k = 1; k <= j; k++) {
//                    if (f[i][j] <= (f[i-1][j-k]+profit[i][k])) {
//                        f[i][j] = f[i-1][j-k]+profit[i][k];
//                    }
//                }
//            }
//        }
//        
//        cout<<f[n][m]<<endl;
//        
//        int cur = m;
//        
//        vector<int> use(n+1,0);
//        for (int i = n; i >= 1; i--) {
//            for (int j = cur; j >= 0; j--) {
//                if (f[i][cur] == f[i-1][cur-j]+profit[i][j]) {
//                    use[i] = j;
//                    cur = cur-j;
//                    break;
//                }
//            }
//        }
//        
//        
//        for (int i = 1; i <= n; i++) {
//            if (use[i]) {
//                cout<<i<<" "<<use[i]<<endl;
//            }
//        }
//        
//    }
//    
//    return 0;
//}


////http://fz.openjudge.cn/dp2/4/
//#include <iostream>
//#include <cstdio>
//#define MAX_NUM 105
//using namespace std;
//
//int main()
//{
//    int high[MAX_NUM], left[MAX_NUM], right[MAX_NUM], n;
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++)
//        scanf("%d", &high[i]);
//    for(int i = 0; i < n; i++)
//    {
//        left[i] = 1;
//        for(int j = 0;j < i; j++)
//        {
//            if(high[j] <high[i] && left[j] > left[i] - 1)
//                left[i] = left[j] + 1;
//        }
//    }
//    for(int i = n-1; i >= 0; i--)
//    {
//        right[i] = 1;
//        for(int j = n-1;j > i; j--)
//        {
//            if(high[j] < high[i] && right[j] > right[i] - 1)
//                right[i] = right[j] + 1;
//        }
//    }
//    int max = 0;
//    for(int i = 0; i < n; i++)
//    {
//        if(max < left[i] + right[i] - 1)
//            max = left[i] + right[i] - 1;
//    }
//    printf("%d\n",n - max);  
//    return 0;
//}

////http://fz.openjudge.cn/dp2/9/
//#include <stdio.h>
//#include <string.h>
//
//#define min(x,y) (x < y ? x : y)
//#define MAX 101
//
//int dp[MAX][MAX];
//
//bool cmp(int n,int m)
//{
//    if((n == '('&&m == ')')||(n == '['&&m == ']'))
//        return 1;
//    else
//        return 0;
//}
//
//int main(void)
//{
//    int n,m,i,j,k;
//    char str[101];
//    scanf("%d",&n);
//    while(n--)
//    {
//        scanf("%s",str);
//        int length = strlen(str);
//        memset(dp,0,sizeof(dp));
//        for(i = 0; i < length; i++)
//        {
//            dp[i][i] = 1;
//        }
//        for(m = 1; m < length; m++)
//        {
//            for(i = 0; i < length - m; i++)
//            {
//                j = i + m;
//                dp[i][j] = MAX;
//                if(cmp(str[i],str[j]))
//                    dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
//                for(k = i; k < j; k++)
//                {
//                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
//                }
//            }
//        }
//        printf("%d\n",dp[0][length-1]);
//    }
//    return 0;
//}

////http://fz.openjudge.cn/dp2/8/
//#include <iostream>
//#include <vector>
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <algorithm>
//using namespace std;
//
//int min(int a, int b){
//    return a > b ? b : a;
//}
//
//int main(){
//    
//    int n;
//    cin>>n;
//    vector<int> data(n+1);
//    vector<vector<int> > times(n+1, vector<int>(n+1, 0));
//    
//    for (int i = 1; i <= n; i++) {
//        cin>>data[i];
//    }
//    
//    vector<int> S(n+1);
//    S[0] = 0;
//    
//    for (int i = 1; i < n; i++) {
//        S[i] = S[i-1]+data[i];
//        times[i][i+1] = data[i]+data[i+1];
//    }
//    S[n] = S[n-1]+data[n];
//    
//    for (int l = 3; l <= n; l++) {
//        for (int i = 1; i <= n -l+1; i++) {
//            int k = i + l -1;
//            times[i][k] = times[i][i]+times[i+1][k] + (S[k]-S[i-1]);
//            for (int index = i+1; index < k; index++) {
//                int temp = times[i][index]+times[index+1][k]+(S[k]-S[i-1]);
//                times[i][k] = min(times[i][k], temp);
//            }
//        }
//    }
//    
//    cout<<times[1][n]<<endl;
//    
//    return 0;
//}


////http://fz.openjudge.cn/dp2/22/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(){
//    
//    int n, total;
//    cin>>n>>total;
//    vector<int> data(n+1);
//    
//    for (int i = 1; i <= n; i++) {
//        cin>>data[i];
//    }
//    
//    vector<int> f(n+1);
//    f[0] = 1;
//    for (int i = 1; i <= n; i++) {
//        for (int j = data[i]; j <= total; j++) {
//            f[j] += f[j-data[i]];
//        }
//    }
//    
//    cout<<f[total]<<endl;
//    
//    
//    return 0;
//}



////http://poj.org/problem?id=2455
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (400+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//    
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//    
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//    
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//struct Node{
//    int a,b,cap;
//}data[M];
//
//
//int main() {
//    
//    int  s, t;
//    
//    int n, p, times;
//    
//    while (cin>>n>>p>>times) {
//        s = 1;
//        t = n;
//        
//        LL lflow = INT_MAX;
//        LL hflow = 0;
//        
//        int a, b, l;
//        for (int i = 0; i < p; i++) {
//            scanf("%d %d %d", &a, &b, &l);
//            data[i].a = a;
//            data[i].b = b;
//            data[i].cap = l;
//            if(l > hflow){
//                hflow = l;
//            }
//            if (l < lflow) {
//                lflow = l;
//            }
//        }
//        
//        
//        LL mflow;
//        LL ans = 0;
//        while (lflow <= hflow) {
//            mflow = (lflow+hflow) >> 1;
//            
//            dinic_init();
//            
//            for (int i = 0; i <p; i++) {
//                if (data[i].cap <= mflow) {
//                    add_edge(data[i].a, data[i].b, 1, 1);
//                }
//            }
//            
//            LL tempFlow = dinic(s, t);
//            
//            
//            if (tempFlow >= times) {
//                ans = mflow;
//                hflow = mflow - 1;
//            }
//            else{
//                lflow = mflow + 1;
//            }
//            
//        }
//        
//        printf("%lld\n", ans);
//        
//    }
//    
//    return 0;
//}


////http://poj.org/problem?id=2112
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (500+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//    
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//    
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//    
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//
//int main() {
//    
//    int  s, t;
//    
//    int k, c, m;
//    
//    while (cin>>k>>c>>m) {
//        int n = k+c;
//        
//        s = 0;
//        t = n+1;
//        
//        int temp;
//        vector<vector<int> > mat(n+1, vector<int>(n+1));
//
//        LL lflow = 0;
//        LL hflow = 0;
//
//        
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                cin>>temp;
//                if (temp) {
//                    mat[i][j] = temp;
//                    hflow += temp;
//                }
//                else{
//                    mat[i][j] = INT_MAX/2;
//                }
//            }
//        }
//        
//        
//        for (int i = 1; i <= n; i++) {
//            for (int j = 0; j<= n; j++) {
//                for (int k = 0; k <= n; k++) {
//                    if (mat[j][i]+mat[i][k] < mat[j][k]) {
//                        mat[j][k] = mat[j][i]+mat[i][k];
//                    }
//                }
//            }
//        }
//        
//        LL mflow;
//        while (lflow < hflow) {
//            mflow = (lflow+hflow) >> 1;
//            dinic_init();
//            
//            for (int i = 1; i <= k; i++) {
//                add_edge(s, i, m, 0);
//            }
//            
//            for (int i = k+1; i <= n; i++) {
//                add_edge(i, t, 1, 0);
//            }
//            
//            for (int i = 1; i <= k; i++) {
//                for (int j = 1+k; j <= n; j++) {
//                    if (mat[i][j] <= mflow) {
//                        add_edge(i, j, 1, 0);
//                    }
//                }
//            }
//            
//            
//            LL tempFlow = dinic(s, t);
//            
//            
//            if (tempFlow == c) {
//                hflow = mflow;
//            }
//            else{
//                lflow = mflow + 1;
//            }
//            
//        }
//        
//        cout<<hflow<<endl;
//        
//    }
//    
//    return 0;
//}


////http://poj.org/problem?id=1966
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (50+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//struct Pair{
//    int a, b;
//}p[M];
//
//int main() {
//
//    int  s;
//
//    int n, m;
//
//    while (cin>>n>>m) {
//        
//        if (m == 0) {
//            if (n == 1) {
//                printf("1\n");
//                continue;
//            }
//            printf("0\n");
//            continue;
//        }
//        
//        int a, b;
//        for (int i = 0; i < m; i ++) {
//            scanf(" (%d,%d)", &a, &b);
//            p[i].a = a;
//            p[i].b = b;
//        }
//        
//        s = 0;
//        
//        LL MAX_FLOW = INT_MAX;
//        
//        for (int t = 1; t < n; t++) {
//            dinic_init();
//            for (int i = 0; i < m; i++) {
//                add_edge(p[i].a+n, p[i].b, INT_MAX, 0);
//                add_edge(p[i].b+n, p[i].a, INT_MAX, 0);
//            }
//            
//            for (int i = 0; i < n; i++) {
//                add_edge(i, i+n, 1, 0);
//            }
//            
//            LL temp = dinic(s+n, t);
//            
//            
//            if (temp < MAX_FLOW) {
//                MAX_FLOW = temp;
//            }
//        }
//        
//        if (MAX_FLOW < INT_MAX) {
//            printf("%lld\n",MAX_FLOW);
//        }
//        else{
//            printf("%d\n",n);
//        }
//
//    }
//
//    return 0;
//}




////http://poj.org/problem?id=2125
////部分完成，没有输出结果
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (100+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//    
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//    
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)  ", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//    
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//vector<int> result;
//
//
//
//int main() {
//    
//    int  s, t;
//    int n, m;
//    
//    
//    while (cin>>n>>m) {
//        dinic_init();
//        
//        s= 0;
//        t = 2*n+1;
//        
//        int temp;
//        for (int i = 1; i <= n; i++) {
//            cin>>temp;
//            add_edge(s, i, temp, 0);
//        }
//        
//        for (int i = 1; i <= n; i++) {
//            cin>>temp;
//            add_edge(i+n, t, temp, 0);
//        }
//        
//        int a, b;
//        vector<vector<bool> >flag(n+1, vector<bool>(n+1, false));
//        for (int i = 1; i <= m; i++) {
//            cin>>a>>b;
//            if (flag[a][b] || a == b) {
//                continue;
//            }
//            flag[a][b] = true;
//            add_edge(i, i+n, INT_MAX, 0);
//            add_edge(a, b+n, INT_MAX, 0);
//            
//        }
//        
//        
//        LL flow = dinic(s, t);
//        
//        cout<<flow<<endl;
//        
//    }
//    
//    return 0;
//}



////http://poj.org/problem?id=3084
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (500+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//    
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//    
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//    
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//
//int main() {
//    
//    int test;
//    int  s, t;
//    
//    int n, m;
//    char ch[3];
//    
//    cin>>test;
//    
//    while (test--) {
//        dinic_init();
//        cin>>m>>n;
//        int room;
//        s = 0;
//        t = n+1;
//        for (int i = 1; i <= m; i++) {
//            cin>>ch>>room;
//            int open;
//            for (int j = 1; j <= room; j++) {
//                cin>>open;
//                add_edge(i, open+1, INT_MAX, 0);
//                add_edge(open+1, i, 1, 0);
//            }
//            
//            if (ch[0] == 'I') {
//                add_edge(s, i, INT_MAX, 0);
//            }
//        }
//        
//        LL flow = dinic(s, t);
//        
//        if (flow < INT_MAX) {
//            cout<<flow<<endl;
//        }
//        else{
//            cout<<"PANIC ROOM BREACH"<<endl;
//        }
//        
//    }
//    
//    return 0;
//}



////http://poj.org/problem?id=3041
//#include <cstdio>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int> > lnklst;
//vector<int> l, r;
//vector<bool> visited;
//
///* make all vectors one element bigger in case the index starts from 1 instead of 0 */
//void init(int n1, int n2) {
//    lnklst.clear(); lnklst.resize(n1+1);
//    l.clear(); l.resize(n1+1,-1);
//    r.clear(); r.resize(n2+1,-1);
//    return;
//}
//
//void add_edge(int u, int v) {
//    lnklst[u].push_back(v);
//    return;
//}
//
//bool dfs(int u) {
//    for (int i=0; i<lnklst[u].size(); i++) {
//        int v = lnklst[u][i];
//        if (visited[v]) continue;
//        visited[v] = true;
//        if (r[v] < 0 || dfs(r[v])) {
//            l[u] = v;
//            r[v] = u;
//            return true;
//        }
//    }
//    return false;
//}
//
//int greedy_match(int n1) {
//    int match = 0;
//    for (int u=0; u<n1; u++) {
//        if (l[u] < 0) {
//            for (int i=0; i<lnklst[u].size(); i++) {
//                int v = lnklst[u][i];
//                if (r[v] < 0) {
//                    l[u] = v;
//                    r[v] = u;
//                    match++;
//                    break;
//                }
//            }
//        }
//    }
//    return match;
//}
//
//int hungarian(void) {
//    int n1 = l.size();
//    int n2 = r.size();
//    int match = greedy_match(n1);
//    for (int u=0; u<n1; u++) {
//        if (l[u] < 0) {
//            visited.clear();
//            visited.resize(n2);
//            if (dfs(u)) {
//                match++;
//            }
//        }
//    }
//    return match;
//}
//
//int main() {
//    
//    int n, m;
//    while (cin >> n >> m) {
//        init(n, n);
//        int x, y;
//        for (int i = 1; i <= m; i++) {
//            cin>>x>>y;
//            add_edge(x, y);
//        }
//        cout<<hungarian()<<endl;
//    }
//    return 0;
//}



////http://poj.org/problem?id=3204
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (500+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//
//int main() {
//    int  s, t;
//
//    int n, m;
//
//    cin>>n>>m;
//    dinic_init();
//    s = 0;
//    t = n-1;
//
//    int a,b,v;
//    for (int i = 1; i <= m; i++) {
//        scanf("%d %d %d", &a, &b, &v);
//        add_edge(a, b, v, 0);
//    }
//
//    dinic(s, t);
//    
//    int ans = 0;
//    
//    for (int i = 0; i < num_of_edges; i+=2) {
//        if (e[i].cap == 0) {
//            e[i].cap++;
//            if (bfs(s, t)) {
//                ans++;
//            }
//            e[i].cap--;
//        }
//    }
//    
//    cout<<ans<<endl;
//    return 0;
//}


////http://poj.org/problem?id=3469
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (20000+2)
//#define M (200000*4+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//
//int main() {
//    int  s, t;
//
//    int n, m;
//
////    while(cin>>n>>m){
//    cin>>n>>m;
//        dinic_init();
//        s = 0;
//        t = n+1;
//        
//        int a,b;
//        for (int i = 1; i <= n; i++) {
//            scanf("%d %d", &a, &b);
//            add_edge(s, i, a, 0);
//            add_edge(i, t, b, 0);
//        }
//        int v;
//        for (int i = 0; i < m; i++) {
//            scanf("%d %d %d", &a, &b, &v);
//            add_edge(a, b, v, v);
//        }
//   
//
////    print_graph(n+2);
//        LL flow = dinic(s, t);
//
//        cout<<flow<<endl;
////    }
//
//    return 0;
//}


////http://poj.org/problem?id=1815
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (5000+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//    
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//    
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//    
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//int n,s,t;
//int origin[5001][5001];
//int temp[5001][5001];
//
//void build(){
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            if(origin[i][j]){
//                add_edge(i+n, j, INT_MAX, 0);
//            }
//        }
//    }
//    
//    for (int i = 1; i <= n; i++) {
//        if (i == s || i == t) {
//            add_edge(i, i+n, INT_MAX, 0);
//        }else{
//            add_edge(i, i+n, 1, 0);
//        }
//    }
//}
//
//
//
//int main() {
//    
//    while(cin>>n>>s>>t){
//        dinic_init();
//        int  r;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                cin>>r;
//                origin[i][j] = r;
//            }
//        }
//        
//        if (origin[s][t]) {
//            cout<<"NO ANSWER!"<<endl;
//            continue;
//        }
//        
//        build();
//        
//        //    print_graph(n+2);
//        LL flow = dinic(s, t+n);
//        
//        cout<<flow<<endl;
//        
//        if(!flow){
//            continue;
//        }
//        
//        vector<int> result;
//        for (int k = 1; k <= n; k++) {
//            if (k == s || k == t) {
//                continue;
//            }
//            
//            dinic_init();
//            
//            for (int i = 1; i <= n; i++) {
//                for (int j = 1; j <= n; j++) {
//                    temp[i][j] = origin[i][j];
//                    if(i == k || j == k){
//                        origin[i][j] = 0;
//                    }
//                }
//            }
//        
//            build();
//            
//            LL tempflow = dinic(s, t+n);
//            if (tempflow < flow ) {
//                result.push_back(k);
//                flow --;
//            }else{
//                for (int i = 1; i <= n; i++) {
//                    for (int j = 1; j <= n; j++) {
//                        origin[i][j] = temp[i][j];
//                    }
//                }
//            }
//            if (!tempflow) {
//                break;
//            }
//            
//        }
//        
//        for (int i = 0; i < result.size(); i++) {
//            cout<<result[i]<<" ";
//        }
//        cout<<endl;
//        
//    }
//    
//    return 0;
//}


////http://poj.org/problem?id=3281
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (410+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//
//int main() {
//    int  s, t;
//
//    int f, d, n;
//
//    while(cin>>n>>f>>d){
//        dinic_init();
//        s = 0;
//        t = 2*n+d+f+1;
//        int fi, di;
//        int a, b;
//        for (int i = 1; i <= f; i++) {
//            add_edge(s, i, 1, 0);
//        }
//        for (int i = f+2*n+1; i<= f+2*n+d; i++) {
//            add_edge(i, t, 1, 0);
//        }
//        for (int i = 1+f; i <= n+f; i++) {
//            cin>>fi>>di;
//            for (int j = 0; j < fi; j++) {
//                cin>>a;
//                add_edge(a, i, 1, 0);
//            }
//            for (int j = 0; j < di; j++) {
//                cin>>b;
//                b = b+2*n+f;
//                add_edge(i+n, b, 1, 0);
//            }
//            add_edge(i, i+n, 1, 0);
//        }
//
////    print_graph(n+2);
//        LL flow = dinic(s, t);
//
//        cout<<flow<<endl;
//    }
//
//    return 0;
//}


////http://poj.org/problem?id=1274
//#include <cstdio>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int> > lnklst;
//vector<int> l, r;
//vector<bool> visited;
//
///* make all vectors one element bigger in case the index starts from 1 instead of 0 */
//void init(int n1, int n2) {
//    lnklst.clear(); lnklst.resize(n1+1);
//    l.clear(); l.resize(n1+1,-1);
//    r.clear(); r.resize(n2+1,-1);
//    return;
//}
//
//void add_edge(int u, int v) {
//    lnklst[u].push_back(v);
//    return;
//}
//
//bool dfs(int u) {
//    for (int i=0; i<lnklst[u].size(); i++) {
//        int v = lnklst[u][i];
//        if (visited[v]) continue;
//        visited[v] = true;
//        if (r[v] < 0 || dfs(r[v])) {
//            l[u] = v;
//            r[v] = u;
//            return true;
//        }
//    }
//    return false;
//}
//
//int greedy_match(int n1) {
//    int match = 0;
//    for (int u=0; u<n1; u++) {
//        if (l[u] < 0) {
//            for (int i=0; i<lnklst[u].size(); i++) {
//                int v = lnklst[u][i];
//                if (r[v] < 0) {
//                    l[u] = v;
//                    r[v] = u;
//                    match++;
//                    break;
//                }
//            }
//        }
//    }
//    return match;
//}
//
//int hungarian(void) {
//    int n1 = l.size();
//    int n2 = r.size();
//    int match = greedy_match(n1);
//    for (int u=0; u<n1; u++) {
//        if (l[u] < 0) {
//            visited.clear();
//            visited.resize(n2);
//            if (dfs(u)) {
//                match++;
//            }
//        }
//    }
//    return match;
//}
//
//int main() {
//    //freopen("stall.dat", "r", stdin);
//    int n, m;
//    while (cin >> n >> m) {
//        init(n, m);
//        int num, a;
//        for (int i = 1; i <= n; i++) {
//            cin>>num;
//            for (int j = 0; j < num; j++) {
//                cin>>a;
//                add_edge(i, a);
//            }
//        }
//        cout<<hungarian()<<endl;
//    }
//    return 0;
//}


////http://poj.org/problem?id=1149
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (100+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//
//int main() {
//    int  s, t;
//
//    int n,m;
//
//    while(cin>>m>>n){
//        vector<int> first(m+2, 0);
//        vector<int> pigs(m+2, 0);
//        s = 0;
//        t = n+1;
//        int a, b, tobuy;
//        dinic_init();
//        for (int i = 1; i <= m; i++) {
//            scanf("%d", &a);
//            pigs[i] = a;
//        }
//        
//        for(int i = 1; i <=n; i++){
//            scanf("%d",&a);
//            int temp = 0;
//            for (int j = 0; j < a; j++) {
//                scanf("%d", &b);
//                if (first[b]) {
//                    add_edge(first[b], i, INT_MAX, 0);
//                }else{
//                    first[b] = i;
//                    temp += pigs[b];
//                }
//            }
//            if (temp) {
//                add_edge(s, i, temp, 0);
//            }
//            scanf("%d", &tobuy);
//            add_edge(i, t, tobuy, 0);
//        }
//
////    print_graph(n+2);
//        LL flow = dinic(s, t);
//
//        cout<<flow<<endl;
//    }
//
//    return 0;
//}

////http://poj.org/problem?id=1273
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (200+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//
//int main() {
//    int  s, t;
//
//    int n,m;
//
//    while(cin>>n>>m){
//    s = 1; t = m;
//    int a, b, v;
//    dinic_init();
//    for(int i = 0; i < n; i++){
//        scanf("%d %d %d",&a,&b,&v);
//        add_edge(a, b, v, 0);
//    }
//
////    print_graph(n+2);
//    LL flow = dinic(s, t);
//
//    cout<<flow<<endl;
//    }
//
//    return 0;
//}


////http://poj.org/problem?id=2367
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int main(){
//    
//    int n;
//    while(cin>>n){
//        vector<vector<int> > list(n+1, vector<int>(1));
//        vector<int> parent(n+1, 0);
//        int child;
//        for (int i = 1; i <= n; i++) {
//            cin>>child;
//            while (child) {
//                list[i].push_back(child);
//                parent[child]++;
//                cin>>child;
//            }
//        }
//        queue<int> qu;
//        for (int i = 1; i <= n; i++) {
//            if(parent[i] == 0){
//                qu.push(i);
//            }
//        }
//        
//        while (!qu.empty()) {
//            int frnt = qu.front();
//            qu.pop();
//            cout<<frnt<<" ";
//            for (int i = 1; i < list[frnt].size(); i++) {
//                parent[list[frnt][i]]--;
//                if(parent[list[frnt][i]]==0){
//                    qu.push(list[frnt][i]);
//                }
//            }
//        }
//        cout<<endl;
//        
//    }
//    
//    return 0;
//}


////http://algorithm.openjudge.cn/hw1/D/
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//using namespace std;
//
//int parent[1001];
//int d[10001];
//
//void make_set(int n){
//    for (int i = 0; i <= n; i++) {
//        parent[i] = i;
//    }
//    memset(d, 0, sizeof(d));
//}
//
//int find_parent(int n){
//    if (parent[n] != n) {
//        int temp = find_parent(parent[n]);
//        d[n] = d[n]^d[parent[n]];
//        parent[n] = temp;
//    }
//    return parent[n];
//}
//
//bool munion(int a, int b, int r){
//    int pa = find_parent(a);
//    int pb = find_parent(b);
//    if(pa == pb){
//        if (d[a]^d[b]^r) {
//            return true;
//        }
//    }
//    else{
//        parent[pa] = pb;
//        d[pa] = d[a]^d[b]^r;
//    }
//    return false;
//}
//
//int main(){
//    
//    int h_n, r_n;
//    while (cin>>h_n>>r_n) {
//        make_set(h_n);
//        int a, b, r;
//        int flag = false;
//        for (int i = 1; i <= r_n; i++) {
//            cin>>a>>b>>r;
//            if(!flag && munion(a, b, r)){
//                flag = true;
//            }
//        }
//        if (flag) {
//            cout<<"NO"<<endl;
//        }
//        else{
//            cout<<"YES"<<endl;
//        }
//    }
//    
//    return 0;
//}

////http://poj.org/problem?id=1459
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (6000+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//    
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//    
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//    
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//
//int main() {
//    int  s, t;
//    
//    int n, np, nc, m;
//    
//    while(cin>>n>>np>>nc>>m){
//    s = 0; t = n+1;
//    int a, b, v;
//    dinic_init();
//    for(int i = 0; i < m; i++){
//        scanf(" (%d,%d)%d",&a,&b,&v);
//        add_edge(a+1, b+1, v, 0);
//    }
//    
//    for(int i = 0; i < np; i++){
//        scanf(" (%d)%d", &a, &v);
//        add_edge(s, a+1, v, 0);
//    }
//    
//    for(int i = 0; i < nc; i++){
//        scanf(" (%d)%d",&a, &v);
//        add_edge(a+1, t, v, 0);
//    }
//    
////    print_graph(n+2);
//    LL flow = dinic(s, t);
//    
//    cout<<flow<<endl;
//    }
//    
//    return 0;
//}

//
////http://poj.org/problem?id=2987
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <string.h>
//#include <assert.h>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//#define N (6000+2)
//#define M (N*N+4*N)
//
//typedef long long LL;
//
//using namespace std;
//
//struct edge {
//    int v, cap, next;
//};
//edge e[M];
//
//int head[N], level[N], cur[N];
//int num_of_edges;
//
///*
// * When there are multiple test sets, you need to re-initialize before each
// */
//void dinic_init(void) {
//    num_of_edges = 0;
//    memset(head, -1, sizeof(head));
//    return;
//}
//
//int add_edge(int u, int v, int c1, int c2) {
//    int& i=num_of_edges;
//    
//    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
//    e[i].v = v;
//    e[i].cap = c1;
//    e[i].next = head[u];
//    head[u] = i++;
//    
//    e[i].v = u;
//    e[i].cap = c2;
//    e[i].next = head[v];
//    head[v] = i++;
//    return i;
//}
//
//void print_graph(int n) {
//    for (int u=0; u<n; u++) {
//        printf("%d: ", u);
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            printf("%d(%d)", e[i].v, e[i].cap);
//        }
//        printf("\n");
//    }
//    return;
//}
//
///*
// * Find all augmentation paths in the current level graph
// * This is the recursive version
// */
//int dfs(int u, int t, int bn) {
//    if (u == t) return bn;
//    int left = bn;
//    for (int i=head[u]; i>=0; i=e[i].next) {
//        int v = e[i].v;
//        int c = e[i].cap;
//        if (c > 0 && level[u]+1 == level[v]) {
//            int flow = dfs(v, t, min(left, c));
//            if (flow > 0) {
//                e[i].cap -= flow;
//                e[i^1].cap += flow;
//                cur[u] = v;
//                left -= flow;
//                if (!left) break;
//            }
//        }
//    }
//    if (left > 0) level[u] = 0;
//    return bn - left;
//}
//
//bool bfs(int s, int t) {
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    queue<int> q;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        if (u == t) return true;
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (!level[v] && e[i].cap > 0) {
//                level[v] = level[u]+1;
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//LL dinic(int s, int t) {
//    LL max_flow = 0;
//    
//    while (bfs(s, t)) {
//        memcpy(cur, head, sizeof(head));
//        max_flow += dfs(s, t, INT_MAX);
//    }
//    return max_flow;
//}
//
//int upstream(int s, int n) {
//    int cnt = 0;
//    vector<bool> visited(n);
//    queue<int> q;
//    visited[s] = true;
//    q.push(s);
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        for (int i=head[u]; i>=0; i=e[i].next) {
//            int v = e[i].v;
//            if (e[i].cap > 0 && !visited[v]) {
//                visited[v] = true;
//                q.push(v);
//                cnt++;
//            }
//        }
//    }
//    return cnt; // excluding s
//}
//
//int main() {
//    int m, n, s, t;
//    int profit;
//    
//    while(cin>>m>>n){
//        dinic_init();
//        s = 0, t = m+1;
//        LL total = 0;
//        for (int i=1; i<=m; i++) {
//            cin>>profit;
//            if(profit > 0){
//                total += profit;
//                add_edge(s, i, profit, 0);
//            }else{
//                add_edge(i, t, -profit, 0);
//            }
//        }
//    
//        int a , b;
//    
//        for (int i = 0; i < n; i++) {
//            cin>>a>>b;
//            add_edge(a, b, INT_MAX, 0);
//        }
//    
//    print_graph(n+2);
//        LL flow = dinic(s, t);
//    
//        int number = upstream(s, t);
//    
//        cout<<number<<" "<<total - flow<<endl;
//    }
//    return 0;
//}
//


//
////http://poj.org/problem?id=1050
//#include <stdio.h>
//#include <string.h>
//#define N 103
//
//int fun(int b[N], int n)
//{
//    int i, max, c;
//    
//    c = 0;
//    max = 0;
//    for(i=1; i<=n; i++)
//    {
//        if(c > 0)
//            c = c+b[i];
//        else c = b[i];
//        if(max < c)
//            max = c;
//    }
//    return max;
//}
//
//int main()
//{
//    int i, j, n, max, sum, k;
//    int a[N][N], b[N];
//    
//    scanf("%d", &n);
//    for(i=1; i<=n; i++)
//        for(j=1; j<=n; j++)
//            scanf("%d", &a[i][j]);
//    max = 0;
//    for(i=1; i<=n; i++)
//    {
//        for(j=1; j<=n; j++)
//            b[j] = 0;
//        for(j=i;j <=n; j++)
//        {
//            for(k=1; k<=n; k++)
//                b[k]+=a[j][k];
//            sum = fun(b, n);
//            if(max < sum)
//                max = sum;
//        }
//        
//    }
//    printf("%d\n", max);
//    return 0;
//}


//
////http://poj.org/problem?id=3903
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//int main(){
//    
//    int len;
//    while (scanf("%d", &len)) {
//        vector<long> a(len);
//        for (int i = 0; i < len; i++) {
//            scanf("%ld ", &a[i]);
//        }
//        vector<int> f(len, 1);
//        int max = 0;
//   
//        for (int i = 1; i < len; i++) {
//            for (int j = i-1; j > 0; j--) {
//                if (a[i] > a[j] && f[j]+1>f[i]) {
//                    f[i]=f[j]+1;
//                    break;
//                }
//            }
//            if (f[i] > max) {
//                max = f[i];
//            }
//        }
//        printf("%d\n",max);
//        
//    }
//    
//    return 0;
//}


//
////http://poj.org/problem?id=2677
//#include <algorithm>
//#include <iostream>
//#include <cmath>
//#include <stdio.h>
//#include <string.h>
//using namespace std;
//struct Point
//{
//    int x,y;
//    void input()
//    {
//        scanf("%d %d",&x,&y);
//    }
//}p[101];
//double Dis(Point p1,Point p2)
//{
//    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(double)(p2.y-p1.y)*(p2.y-p1.y));
//}
//bool cmp(Point m,Point n)
//{
//    return m.x<n.x;
//}
//int main()
//{
//    int n;
//    double a[101][101],dp[101][101];
//    while(cin>>n)
//    {
//        p[0].input();
//        if(n==1) {printf("0.00\n");continue;}
//        for(int i=1;i<n;i++)
//        {
//            p[i].input();
//            if(p[0].x>p[i].x) swap(p[0],p[i]);
//        }
//        sort(p,p+n,cmp);
//        for(int i=0;i<n;i++)
//        {
//            a[i][i]=0;
//            for(int j=i+1;j<n;j++)
//            {
//                a[i][j]=a[j][i]=Dis(p[i],p[j]);
//            }
//        }
//        dp[0][0]=0;
//        for(int i=1;i<n;i++)
//            dp[i][0]=a[i][0];
//        for(int i=1;i<n-1;i++)
//        {
//            dp[i+1][i]=1000000000;
//            for(int j=0;j<=i-1;j++)
//            {
//                dp[i+1][j]=dp[i][j]+a[i][i+1];
//                dp[i+1][i]=min(dp[i+1][i],dp[i][j]+a[j][i+1]);
//            }
//        }
//        printf("%.2lf\n",dp[n-1][n-2]+a[n-1][n-2]);
//    }
//    return 0;
//}

////本题是有bug代码 题目同上
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//int main(){
//    vector<float> starts(51);
//    vector<float> ends(51);
//    int points;
//    while (cin>>points) {
//        for(int i = 0; i < points; i++){
//            cin>>starts[i]>>ends[i];
//        }
//        
//        for(int i = 0; i < points; i++){
//            for(int j = i+1; j < points; j++){
//                if(starts[i] > starts[j]){
//                    int temp = starts[i];
//                    starts[i] = starts[j];
//                    starts[j] = temp;
//                    
//                    temp = ends[i];
//                    ends[i] = ends[j];
//                    ends[j] = temp;
//                }
//            }
//        }
//        
//        float length = 0;
//        for (int i = 0; i < points-1; i++) {
//            length += sqrt(pow(starts[i]-starts[i+1], 2)+pow(ends[i]-ends[i+1], 2));
//        }
//        length +=sqrt(pow(starts[0]-starts[points-1], 2)+pow(ends[0]-ends[points-1], 2));
//        
//        printf("%.2f", length);
//        
//    }
//    return 0;
//}


////http://poj.org/problem?id=3264
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//int main(){
//    int number;
//    int query;
//    cin>>number>>query;
//    vector<int> data(number+1);
//    vector< vector<int> > minNum(number+1, vector<int>(number+1));
//    vector< vector<int> > maxNum(number+1, vector<int>(number+1));
//    for(int i = 1; i <= number; i++){
//        cin>>data[i];
//    }
//    
//    for(int i = 1; i <= number; i++){
//        minNum[i][i] = maxNum[i][i] = data[i];
//    }
//    
//    for(int j = 1; j <= number; j++){
//        for (int i = 1; i<j; i++) {
//            minNum[i][j] = min(data[j], minNum[i][j-1]);
//            maxNum[i][j] = max(data[j], maxNum[i][j-1]);
//        }
//    }
//    
//    
//    for (int i = 0; i < query; i++) {
//        int a,b;
//        cin>>a>>b;
//        cout<<maxNum[a][b]-minNum[a][b]<<endl;
//    }
//    
//    return 0;
//}
//

////http://poj.org/problem?id=2576
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//int main(int argc, const char * argv[]) {
//    
//    int person;
//    cin>>person;
//    vector<int> w(person+1);
//    
//    int sum = 0;
//    
//    for (int i= 1; i <= person; i++) {
//        cin>>w[i];
//        sum += w[i];
//    }
//    
//    vector<vector<bool> > selection(101, vector<bool>(sum, false));
//    selection[0][0]=true;
//    
//    for (int i = 1; i <= person; i++) {
//        int j = (person+1)/2 > i ? i : (person+1)/2;
//        for (; j > 0; j--) {
//            for(int k = sum/2; k >= w[i]; k--){
//                if (!selection[j][k] && selection[j-1][k-w[i]]) {
//                    selection[j][k] = true;
//                }
//            }
//        }
//    }
//    int w1 = 0;
//    for (int i = sum/2; i>0; i--) {
//        if(selection[person/2][i] || selection[(person+1)/2][i]){
//            w1 = i;
//            break;
//        }
//    }
//    
//    cout<<w1<<" "<<sum-w1<<endl;
//
//    
//    return 0;
//}
