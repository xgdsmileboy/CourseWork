////
////  04_arbitrage.cpp
////  Algorithm
////
////  Created by Jiang Jiajun on 12/4/15.
////  Copyright © 2015 姜佳君. All rights reserved.
////
//
//#include <iostream>
//#include <string.h>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//bool change(int kinds, vector< vector<double> >& exchange){
//    for (int i = 0; i < kinds; i++) {
//        for (int j = 0; j < kinds; j ++) {
//            for (int k = 0; k < kinds; k ++) {
//                if (exchange[j][k] < exchange[j][i]*exchange[i][k]) {
//                    exchange[j][k] = exchange[j][i]*exchange[i][k];
//                    if (j == k && exchange[j][k] > 1.0) {
//                        return true;
//                    }
//                }
//            }
//        }
//    }
//    return false;
//}
//
//void arbitrage(){
//    int kinds;
//    int counting = 1;
//    cin>>kinds;
//    while (kinds) {
//        map<string, int> map;
//        string kind;
//        for (int i = 0; i < kinds; i ++) {
//            cin>>kind;
//            map[kind] = i;
//        }
//        
//        string source;
//        string target;
//        double rate;
//        int dataCount;
//        cin>>dataCount;
//        vector< vector<double> > exchange(kinds, vector<double>(kinds, 1.0));
//        for(int i = 0; i < dataCount; i++){
//            cin>>source>>rate>>target;
//            exchange[map[source]][map[target]] = rate;
//            
//        }
//        if(change(kinds, exchange)){
//            cout<<"Case "<<counting<<": Yes"<<endl;
//        }
//        else{
//            cout<<"Case "<<counting<<": No"<<endl;
//        }
//        counting++;
//        cin>>kinds;
//    }
//}
//
//int main(){
//    arbitrage();
//    return 0;
//}
