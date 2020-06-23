#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>

class LinkedList
{
    struct Node{
        Node* prev;
        Node* next;
        T item;
    };

    public:
        class Iterator{
            public:
                void setIterator(Node* ptr) {
                    iterator1 = ptr;
                }
                Node* getIterator() {
                    return this->iterator1;
                }
                friend void operator++ (Iterator& it, int x) {
                    try {
                        if(it.iterator1->next == NULL) {
                            throw "range error";
                        }
                        it.iterator1 = it.iterator1->next;
                    }
                    catch(...) {
                        cout<<"Iterator already at the end of the linked list"<<endl;
                        exit(0);
                    }
                }
                friend void operator-- (Iterator& it, int x) {
                    try {
                        if(it.iterator1->prev == NULL) {
                            throw "range error";
                        }
                        it.iterator1 = it.iterator1->prev;
                    }
                    catch(...) {
                        cout<<"Iterator already at the beginning of the list"<<endl;
                        exit(0);
                    }
                }
                bool operator== (const Iterator& it) {
                    return it.iterator1 == this->iterator1;
                }
                bool operator!= (const Iterator& it) {
                    return it.iterator1 != this->iterator1;
                }
                friend T& operator* (const Iterator& it) {
                    return it.iterator1->item;
                }
            private:
                Node* iterator1;
    };

    public:
        LinkedList() {
            Node* dummyNode = new Node;
            head = tail = dummyNode;
            dummyNode->next = NULL;
            length = 0;
        }

        LinkedList(T element, int initialSize) {
            Node* dummyNode = new Node;
            head = tail = dummyNode;
            dummyNode->next = NULL;
            length = 0;
            for(int i = 0; i < initialSize; i++) {
                push_back1(element);
            }
        }

        void push_back1(T element) {
            Node* newNode = new Node;
            newNode->item = element;
            if(length == 0) {
                newNode->next = head;
                newNode->prev = NULL;
                newNode->next->prev = newNode;
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->next = tail->next;
                newNode->prev = tail;
                newNode->next->prev = newNode;
                newNode->prev->next = newNode;
                tail = newNode;
            }
            length++;
        }

        Iterator beforeEnd() {
            Iterator it;
            it.setIterator(tail);
            return it;
        }

        void insert1(T element, Iterator position) {
            Node* newNode = new Node;
            newNode->item = element;
            if(length == 0) {
                newNode->next = head;
                newNode->prev = NULL;
                newNode->next->prev = newNode;
                head = newNode;
                tail = newNode;
            }
            else if(position == begin1()) {
                newNode->next = head;
                newNode->prev = NULL;
                newNode->next->prev = newNode;
                head = newNode;
            }
            else if(position == end1()) {
                newNode->next = tail->next;
                newNode->prev = tail;
                newNode->next->prev = newNode;
                newNode->prev->next = newNode;
                tail = newNode;
            }
            else {
                Iterator it = begin1();
                while (it != position) {
                    it++;
                }
                newNode->next = it.getIterator();
                it--;
                newNode->prev = it.getIterator();
                newNode->next->prev = newNode;
                newNode->prev->next = newNode;
            }
            length++;
        }
        Iterator erase1(Iterator position) {
            if(position == end1()) {
                cout<<"Range error"<<endl;
                length++;
            }
            else if(length == 1) {
                Node* current = position.getIterator();
                current = tail;
                head = tail = current->next;
                position.setIterator(tail);
                delete current;
                current = NULL;
            }
            else if(position == begin1()) {
                Node* current = position.getIterator();
                current = head;
                current->next->prev = NULL;
                head = current->next;
                position++;
                delete current;
                current = NULL;
            }
            else if(position == beforeEnd()) {
                Node* current = position.getIterator();
                current = tail;
                current->next->prev = current->prev;
                current->prev->next = current->next;
                tail = current->prev;
                position++;
                delete current;
                current = NULL;
            }
            else {
                Iterator it = begin1();
                while (it != position) {
                    it++;
                }
                Node* current = it.getIterator();
                Node* after = current->next;
                Node* before = current->prev;
                after->prev = before;
                before->next = after;
                position++;
                delete current;
                current = NULL;
            }
            length--;
            return position;
        }
        Iterator begin1() {
            Iterator it;
            it.setIterator(head);
            return it;
        }
        Iterator end1() {
            Iterator it;
            it.setIterator(tail->next);
            return it;
        }

        void printList(){
            if(length == 0) {
                cout<<"list is empty"<<endl;
            }
            Node* current = head;
            int siz = 0;
            while(siz < length) {
                cout << current->item << endl;
                current = current->next;
                siz++;
            }
        }

        int listSize() {
            return length;
        }

        LinkedList <T>& operator = (LinkedList <T>& list2) {
            Iterator it = list2.begin1();
            for(int i = 0; i < list2.listSize(); i++) {
                push_back1(*it);
                it++;
            }
            return list2;
        }

        ~LinkedList() {
            Node* current = head;
            int siz = 0;
            while(siz < length) {
                delete current;
                current = current->next;
                siz++;
            }
            current = NULL;
        }

    protected:
    private:
        Node* head;
        Node* tail;
        int length;
};

#endif // LINKEDLIST_H
