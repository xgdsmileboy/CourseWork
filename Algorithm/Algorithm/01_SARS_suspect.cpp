//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int *parent;
//int *value;
//
//int find(int n)
//{
//    if(parent[n]!=n)
//        parent[n]=find(parent[n]);
//
//    return parent[n];
//}
//
//
//void Union(int child1,int child2)
//{
//    int first=find(child1);
//    int second=find(child2);
//    if(first==second)
//        return ;
//    else if(value[first]<=value[second])
//    {
//        parent[first]=second;
//        value[second]+=value[first];
//    }
//    else
//    {
//        parent[second]=first;
//        value[first]+=value[second];
//    }
//
//}
//
//void suspect()
//{
//    int stu_num, group_num;
//
//    vector<int> vec;
//
//    while(cin>>stu_num>>group_num)
//    {
//        if(stu_num == 0 && group_num == 0)
//            break;
//
//        parent = new int[stu_num];
//        value = new int[stu_num];
//
//        for(int i = 0 ; i < stu_num; i++)
//        {
//
//            parent[i]=i;
//            value[i]=1;
//        }
//
//        for(int j=0; j < group_num; j++)
//        {
//            int group_stu_num;
//            cin>>group_stu_num;
//            int first;
//            int next;
//            for(int i = 0; i < group_stu_num; i++)
//            {
//                if(i == 0)
//                    cin>>first;
//                else
//                {
//                    cin>>next;
//                    Union(first,next);
//                }
//            }
//        }
//
//        int max = 0;
//        while(parent[max] != max)
//            max = parent[max];
//
//        vec.push_back(value[max]);
//        delete(parent);
//        delete(value);
//
//    }
//
//    for(int i = 0; i < vec.size(); i++)
//    {
//        cout<<vec[i]<<endl;
//    }
//}
//
//
//
////int main()
////{
////    suspect();
////    return 0;
////}
