#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

#include "stack.h"
#include "circularQueue.h"
#include "linkedlist.h"
#include "dataelement.h"

void stack_testcases() {
	int len;
	cin >> len;
	stack obj(len);
	int input, value;
	do {
		cin >> input;
		switch (input) {
		case 1:
			cin >> value;
			obj.push(value);
			break;
		case 2:
			obj.pop();
			break;
		default:
			cout << "Invalid input" << endl;
		}
	}while (input != -1);
}

void circular_queue_testcase() {
	int len;
	cin >> len;
	circularQueue obj(len);
	int input, value;
	do {
		cin >> input;
		switch (input) {
		case 1:
			cin >> value;
			obj.enqueue(value);
			break;
		case 2:
			obj.dequeue();
			break;
		default:
			cout << "Invalid input" << endl;
		}
	} while (input != -1);
}

void merge_linkedlists_testcases() {
	display_linkedlist(merge_linked_lists_helper());
}

void self_adjust_linkedlist() {
	int len, value, i;
	cin >> len;
	int* arr = (int*)calloc(len, sizeof(int));
	for (i = 0; i < len; i++) {
		cin >> arr[i];
	}
	cin >> value;
	struct node* head = array_to_linkedlist(arr, len);
	display_linkedlist(head);
	head = self_adjust(head, value);
	display_linkedlist(head);
}

void sort_dataset_testcases() {
	int len, temp;
	cin >> len;
	temp = len;
	struct data_element** arr = (struct data_element**)calloc(len, sizeof(struct data_element*));
	int input, int_value, j = 0;
	char char_value;
	do {
		cin >> input;
		switch (input) {
		case 1:
			cin >> int_value;
			arr[j++] = insert_int(int_value);
			temp--;
			break;
		case 2:
			cin >> char_value;
			arr[j++] = insert_char(char_value);
			temp--;
			break;
		default:
			cout << "Invalid input" << endl;
		}
	} while (temp);
	print_data_set(arr, len);
	clock_t timestamp;
	timestamp = clock();
	quick_sort(arr, 0, len - 1);
	timestamp = clock() - timestamp;
	double time_taken = ((double)timestamp) / CLOCKS_PER_SEC;
	print_data_set(arr, len);
	cout << "Time took for sorting is " << time_taken << " seconds";
}
