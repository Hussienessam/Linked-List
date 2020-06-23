#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list1;
    list1.push_back1(1);
    list1.push_back1(2);
    list1.push_back1(3);
    list1.push_back1(4);
    cout<<"-----pushing_back----"<<endl;
    list1.printList();
    LinkedList<int>::Iterator it2 = list1.begin1();
    it2++;
    it2++;
    cout<<"-----printing_value----"<<endl;
    cout<<*it2<<endl;
    list1.insert1(5, it2);
    cout<<"-----inserting----"<<endl;
    list1.printList();
    LinkedList<int>::Iterator it = list1.begin1();
    it++;
    it = list1.erase1(it);
    cout<<"-----erasing----"<<endl;
    list1.printList();
    LinkedList<int> list2;
    list2 = list1;
    cout<<"-----copying----"<<endl;
    list2.printList();
    return 0;
}
