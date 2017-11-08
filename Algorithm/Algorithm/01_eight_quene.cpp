//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <math.h>
//
//using namespace std;
//
//int no = 1;
//
//void mquene(vector<int> vec, int col)
//{
//    if(col == 8)
//    {
//        cout<<"No. "<<no<<endl;
//        no ++;
//        for(int i = 0; i < 8; i++)
//        {
//            for(int j = 0; j < 8; j++)
//            {
//                if(vec[j] == i)
//                {
//                    cout<<1<<" ";
//                }
//                else
//                {
//                    cout<<0<<" ";
//                }
//            }
//            cout<<endl;
//        }
//        return;
//    }
//    for(int i = 0; i < 8; i++)
//    {
//        int j = 0;
//        for(j = 0; j < col; j++)
//        {
//            if(vec[j] == i || abs(vec[j]-i) == abs(j-col))
//            {
//                break;
//            }
//        }
//        if(j == col)
//        {
//            vec[col] = i;
//            mquene(vec, col+1);
//        }
//    }
//    return ;
//}
//
//
////int main()
////{
////    vector<int> vec(8,-1);
////    for(int i = 0; i < 8; i++)
////    {
////        vec[0] = i;
////        mquene(vec, 1);
////    }
////
////    return 0;
////}
//
