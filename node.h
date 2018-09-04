#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

	void killSelf() {
		if (next != start)
			next->killSelf();
		delete this;
	};
	void print_next() {
		Node <T>* temp = start;
		if (start == NULL) throw "Lista Vacía";
		else {
			cout << temp->data;
			temp = temp->next;
			while (temp != start) {
				cout << temp->data;
				temp = temp->next;
			}
		}
	};
};

#endif
