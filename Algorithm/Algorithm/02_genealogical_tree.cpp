//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void genealogical_tree()
//{
//    int generation;
//    cin >> generation;
//
//    vector< vector<int> > child_list(generation);
//    for(int i = 0; i <= generation; i++)
//    {
//        vector<int> a(0);
//        child_list.push_back(a);
//    }
//
//    vector<int> degree(generation, 0);
//    int child;
//
//    for(int i = 1; i <= generation; i++)
//    {
//        cin>>child;
//        while(child)
//        {
//            degree[child]++;
//            child_list[i].push_back(child);
//            cin>>child;
//        }
//    }
//
//    for(int i = 1; i <= generation; i++)
//    {
//        for(int j = 1; j <= generation; j++)
//        {
//            if(degree[j] == 0)
//            {
//                cout<<j<<" ";
//                degree[j]--;
//                for(int k = 0; k < child_list[j].size(); k++)
//                {
//                    degree[child_list[j][k]] --;
//                }
//            }
//        }
//    }
//    cout<<endl;
//
//}
//
//int main()
//{
//    genealogical_tree();
//    return 0;
//}
