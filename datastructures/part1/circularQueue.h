#include "linkedlist.h"
#pragma once
class circularQueue {
	public:
		struct node* frontnode;
		struct node* rearnode;
		int capacity;
		int length;

		circularQueue();
		circularQueue(int capacity);
		void enqueue(int data);
		int dequeue();
};
