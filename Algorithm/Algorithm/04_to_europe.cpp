////
////  04_to_europe.cpp
////  Algorithm
////
////  Created by Jiang Jiajun on 11/29/15.
////  Copyright © 2015 姜佳君. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <iomanip>
//using namespace std;
//
//double min(double a, double b){
//    if (a < b) {
//        return a;
//    }
//    return b;
//}
//
//double getMinimalTime(double length, double max_load, int count, vector<double>& wi, vector<double>& si){
//    vector<double> matrix(count+1, 0);
//    double speed;
//    double curr_load;
//    for (int i = 1; i <= count; i++) {
//        speed = si[i];
//        curr_load = 0;
//        int j;
//        matrix[i] = 0xffffffff;
//        for (j = i; j > 0; j--) {
//            curr_load += wi[j];
//            if(curr_load > max_load){
//                break;
//            }
//            if(si[j] < speed)
//                speed = si[j];
//            int index = j - 1;
//            matrix[i] = min(matrix[index]+length*1.0/speed, matrix[i]);
//        }
//    }
//    matrix[count] *= 60.0;
//    return matrix[count];
//}
//
//void toEurope(){
//    double max_load;
//    double bridge_len;
//    int veh_count;
//    cin>>max_load>>bridge_len>>veh_count;
//    while(max_load != 0 || bridge_len != 0 || veh_count != 0){
//        vector<double> wi(veh_count+1);
//        vector<double> si(veh_count+1);
//        for (int i = 1; i <= veh_count; i++) {
//            cin>>wi[i]>>si[i];
//        }
//        
//        cout<<setiosflags(ios::fixed)<<setprecision(1)<<getMinimalTime(bridge_len, max_load, veh_count, wi, si)<<endl;
//        cin>>max_load>>bridge_len>>veh_count;
//    }
//}
//
//int main(){
//    toEurope();
//}