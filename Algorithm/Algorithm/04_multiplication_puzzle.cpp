////
////  04_multiplication_puzzle.cpp
////  Algorithm
////
////  Created by Jiang Jiajun on 11/29/15.
////  Copyright © 2015 姜佳君. All rights reserved.
////
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream>
//
//using namespace std;
//
//unsigned int s[100][100];
//
//int c[100];
//
//void GetScores(int card_count)
//{
//    int i, j, k, t;
//    unsigned int tmp;
//    /* init */
//    memset(s, 0, sizeof(s));
//    
//    for(k = 3; k <= card_count; k++)
//    {
//        for(i = 0; i < card_count - 2; i++)
//        {
//            j = i + k - 1;
//            s[i][j] = 0xffffffff;
//            for(t = i + 1; t < j; t++)
//            {
//                tmp = s[i][t] + s[t][j] + c[i]*c[t]*c[j];
//                if(tmp < s[i][j])
//                {
//                    s[i][j] = tmp;
//                }
//            }
//        }
//    }
//}
//
//int main(int argc, char* argv[])
//{
//    int card_count = 0;
//    
//    cin>>card_count;
//    for(int i = 0; i < card_count; i++)
//        cin>>c[i];
//        
//    GetScores(card_count);
//    cout<<s[0][card_count-1]<<endl;
//    return 0;
//}