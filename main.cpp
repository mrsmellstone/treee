#include <iostream>
#include <tree.h>

using namespace std;

// Реализация интерфейса
template<typename T>
Container<T>* SimpleTree(){
    Container<T>* buf = new Tree<T>(0);
    return buf;
}
// TODO

int main()
{
    Container<int>* c = SimpleTree<int>();

//    for(int i = 1; i < 10; i++)
//        c->insert(i*i);
    c->insert(-1);

    printf("List after creation:\n");
    c->print();

    if(c->exists(25))
        cout << "Search for value 25: found" << endl;

    if(!c->exists(111))
        cout << "Search for value 111: not found" << endl;

    c->remove(0);
//    c->remove(1);
    c->remove(25);
    cout << "List after deletion of the element:" << endl;
    c->print();

    delete c;
    return 0;
}

