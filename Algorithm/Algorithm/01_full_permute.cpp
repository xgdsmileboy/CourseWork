//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string swap(string s, int first, int second)
//{
//    char ch = s.at(first);
//    s.at(first) = s.at(second);
//    s.at(second) = ch;
//    return s;
//}
//
//string msort(string s, int start)
//{
//    for(int i = start; i < s.size(); i++)
//    {
//        for(int j = start; j < s.size()-1; j++)
//        {
//            if(s.at(j) > s.at(j+1))
//            {
//                s = swap(s, j, j+1);
//            }
//        }
//    }
//    return s;
//}
//
//void permute(string s, int start)
//{
//    if(start == s.size())
//    {
//        cout<<s<<endl;
//        return;
//    }
//
//    for(int i = start; i < s.size(); i++)
//    {
//        string str = swap(s, start, i);
//        str = msort(str, start+1);
//        permute(str, start+1);
//    }
//    return;
//
//}
//
//
////int main()
////{
////    string s;
////    cin>>s;
////    permute(msort(s,0), 0);
////    return 0;
////}
//
