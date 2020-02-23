#include <stdlib.h>
#include "iostream"
#include "stack.h"

using namespace std;

stack::stack() {
	this->head = NULL;
	this->length = 0;
	this->capacity = 10;
}

stack::stack(int capacity) {
	this->head = NULL;
	this->length = 0;
	this->capacity = capacity;
}

void stack::push(int data) {
	if (this->length == 0) {
		this->head = insert_at_end(this->head, data);
		++(this->length);
	}
	else if (this->length == this->capacity) {
		cout << "-----Stack Overflow-----" << endl;
	}
	else {
		insert_at_end(this->head, data);
		++(this->length);
	}
}

int stack::pop() {
	if (this->length == 0) {
		cout << "-----Stack Underflow-----" << endl;
		return -1;
	}
	else {
		int deleted_val;
		this->head = delete_at_end(this->head, &deleted_val);
		cout << "Popped val : " << deleted_val << endl;
		--(this->length);
		return deleted_val;
	}
}