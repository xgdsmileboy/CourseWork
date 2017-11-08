//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> heap(100000, 0);
//int heap_size = 0;
//
//void shift_up(int index, int element)
//{
//    while(index > 1)
//    {
//        int parent = index / 2;
//        if(heap[parent] <= element)
//            break;
//        heap[index] = heap[parent];
//        index = parent;
//    }
//    heap[index] = element;
//}
//
//void shift_down(int index, int element)
//{
//    int half = heap_size / 2;
//    int mini,left_child,right_child;
//    while( index <= half)
//    {
//        mini = left_child = index * 2;
//        right_child = left_child + 1;
//        if(right_child <= heap_size && heap[left_child] > heap[right_child])
//            mini = right_child;
//        if(element <= heap[mini])
//            break;
//        heap[index] = heap[mini];
//        index = mini;
//    }
//    heap[index] = element;
//}
//
//int pop()
//{
//    if(heap_size <= 0)
//        return -1;
//    int ret = heap[1];
//    heap[1] = heap[heap_size];
//    heap_size -= 1;
//    if(heap_size > 0)
//        shift_down(1, heap[1]);
//
//    return ret;
//}
//
//void add(int element)
//{
//    heap_size += 1;
//    heap[heap_size] = element;
//    shift_up(heap_size, element);
//}
//
//void minimal_heap()
//{
//    vector<int> vec;
//    int test_number;
//    int operating_number;
//    int type, data;
//    cin>>test_number;
//    for(int i = 0; i < test_number; i++)
//    {
//        heap_size = 0;
//        cin>>operating_number;
//        for(int j = 0; j < operating_number; j++)
//        {
//            cin>>type;
//            if(type == 1)
//            {
//                cin>>data;
//                add(data);
//            }
//            else
//            {
//                int a = pop();
//                if(a != -1)
//                    vec.push_back(a);
//            }
//        }
//    }
//    for(int i = 0; i < vec.size(); i++)
//        cout<<vec[i]<<endl;
//}
//
//
//int main()
//{
//    cout<<"begin"<<endl;
//    minimal_heap();
//    return 0;
//}
