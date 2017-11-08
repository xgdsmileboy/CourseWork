//#include <iostream>
//#include <vector>
//using namespace std;
//
//void district_connect()
//{
//    vector<int> range(10000,0);
//    int pair_count;
//    cin>>pair_count;
//    int left, right;
//    int max_num = 0;
//    int min_num = 100000;
//    for(int i = 0; i < pair_count; i++)
//    {
//        cin>>left>>right;
//        if(right > max_num)
//            max_num = right;
//        if(left < min_num)
//            min_num = left;
//
//        for(int j = left; j < right; j++)
//        {
//            range[j] = 1;
//        }
//
//    }
//
//    bool flag = true;
//    for(int i = min_num ;i < max_num; i ++)
//    {
//        if (!range[i])
//        {
//            flag = false;
//            break;
//        }
//    }
//
//    if(flag)
//        cout<<min_num<<" "<<max_num<<endl;
//    else
//        cout<<"no"<<endl;
//}
//
//
////int main()
////{
////    district_connect();
////    return 0;
////}
