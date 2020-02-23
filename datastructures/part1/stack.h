#include "linkedlist.h"

#pragma once
class stack{
	public:
		struct node* head;
		int length;
		int capacity;

		stack();
		stack(int capacity);
		void push(int data);
		int pop();
};