//#include <iostream>
//#include <vector>
//using namespace std;
//
//int *parent;
//int *length;
//int * value;
//
//
//void make_set(int n)
//{
//   delete(parent);
//   delete(length);
//   delete(value);
//
//   parent = new int[n];
//   length = new int[n];
//   value = new int[n];
//
//   
//   for(int i = 0; i < n; i ++)
//   {
//       parent[i] = i;
//       length[i] = 0;
//       value[i] = 1;
//   }
//}
//
//int mfind(int n)
//{
//   if(parent[n] != n)
//   {
//       int t = mfind(parent[n]);
//       length[n] = length[n] ^ length[parent[n]];
//       parent[n] = t;
//   }
//
//   return parent[n];
//}
//
//bool munion(int i, int j, int rel)
//{
//   int pi = mfind(i);
//   int pj = mfind(j);
//
//   if(pi == pj)
//   {
//       if((length[i]+length[j]+rel)%2)
//           return true;
//   }
//   else
//   {
//       if(value[pi] < value[pj])
//       {
//           parent[pi] = pj;
//           value[pj] += value[pi];
//           length[pi] = length[i] ^ length[j] ^ rel;
//       }
//       else
//       {
//           parent[pj] = pi;
//           value[pi] += value[pj];
//           length[pj] = length[i] ^ length[j] ^ rel;
//       }
//   }
//
//   return false;
//}
//
//
//void butterfly()
//{
//   vector<bool> vec;
//   int butterfly_num, rel_num;
//   while(cin>>butterfly_num>>rel_num)
//   {
//       make_set(butterfly_num);
//       int first, second, relate;
//       bool have_collision = false;
//       for(int i = 0; i < rel_num; i++)
//       {
//           cin>>first>>second>>relate;
//           if(munion(first, second, relate))
//             {
//                   have_collision = true;
//                   for(i++; i < rel_num; i++)
//                   {
//                       cin>>first>>second>>relate;
//                   }
//             }
//       }
//       vec.push_back(have_collision);
//   }
//
//   for(int i = 0; i < vec.size(); i++)
//   {
//       if(vec[i])
//           cout<<"NO"<<endl;
//       else
//           cout<<"YES"<<endl;
//   }
//}
//
//int main()
//{
//   butterfly();
//   return 0;
//}
