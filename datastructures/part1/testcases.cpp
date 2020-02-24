#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

#include "stack.h"
#include "circularQueue.h"
#include "linkedlist.h"
#include "dataelement.h"

void stack_testcases() {
	stack obj;
	obj.push(7);
	obj.push(27);
	obj.push(37);
	obj.push(57);
	obj.push(157);
	obj.push(517);
	obj.push(573);
	obj.push(257);
	obj.push(577);
	obj.push(579);
	obj.push(1579);
	obj.push(3579);
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.push(7);
	obj.push(27);
	obj.push(37);
	obj.push(57);
	obj.push(157);
	obj.push(3579);
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
}

void circular_queue_testcase() {
	circularQueue obj;
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(5);
	obj.enqueue(6);
	obj.enqueue(7);
	obj.enqueue(8);
	obj.enqueue(9);
	obj.enqueue(10);
	obj.enqueue(11);
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(9);
	obj.enqueue(10);
	obj.enqueue(11);
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
}

void merge_linkedlists_testcases() {
	display_linkedlist(merge_linked_lists_helper());
}

void self_adjust_linkedlist() {
	int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = 9, value = 10;
	struct node* head = array_to_linkedlist(arr, len);
	display_linkedlist(head);
	head = self_adjust(head, value);
	display_linkedlist(head);
}

void sort_dataset_testcases() {
	int int_arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	char char_arr[10] = { 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a' };
	int len = 20;
	struct data_element** arr = (struct data_element**)calloc(len, sizeof(struct data_element*));
	int i, j = 0;
	for (i = 0; i < 10; i++) {
		arr[j++] = insert_int(int_arr[i]);
		arr[j++] = insert_char(char_arr[i]);
	}
	print_data_set(arr, len);
	clock_t timestamp;
	timestamp = clock();
	quick_sort(arr, 0, len - 1);
	timestamp = clock() - timestamp;
	double time_taken = ((double)timestamp) / CLOCKS_PER_SEC;
	print_data_set(arr, len);
	cout << "Time took for sorting is " << time_taken << " seconds";
}
