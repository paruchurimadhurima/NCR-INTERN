#include <stdlib.h>
#include <iostream>
#include "circularQueue.h"

using namespace std;

circularQueue::circularQueue() {
	this->frontnode = NULL;
	this->rearnode = NULL;
	this->capacity = 10;
	this->length = 0;
}

circularQueue::circularQueue(int capacity) {
	this->frontnode = NULL;
	this->capacity = capacity;
	this->length = 0;
}

void circularQueue::enqueue(int data) {
	if (this->length == this->capacity) {
		cout << "-----Circular Queue Overflow-----" << endl;
	}
	else if (this->length == 0) {
		this->frontnode = insert_at_end(frontnode, data);
		++(this->length);
	}
	else{
		insert_at_end(frontnode, data);
		++(this->length);
	}
}

int circularQueue::dequeue() {
	if (this->length == 0) {
		cout << "-----Circular Queue Underflow-----" << endl;
		return -1;
	}
	else {
		int deleted_val = this->frontnode->data;
		struct node* temp = this->frontnode;
		this->frontnode = this->frontnode->next;
		cout << "Dequeued val : " << deleted_val << endl;
		--(this->length);
		free(temp);
		temp = NULL;
		return deleted_val;
	}
}