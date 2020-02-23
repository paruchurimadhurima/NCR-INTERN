#include <stdlib.h>
#include <iostream>
#include "linkedlist.h"

using namespace std; 

struct node* create_node(int data) {
	struct node* newnode = (struct node*)calloc(1, sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

struct node* insert_at_end(struct node* head, int data) {
	struct node* newnode = create_node(data);
	struct node* temp = head;
	if (head == NULL) {
		head = newnode;
	}
	else {
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
	return newnode;
}

struct node* delete_at_end(struct node* head, int * deleted_val) {
	if (head == NULL)
		return NULL;

	else if (head->next == NULL) {
		(*deleted_val) = head->data;
		return NULL;
	}

	else {
		struct node* prev = NULL;
		struct node* temp = head;
		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		(*deleted_val) = temp->data;
		free(temp);
		temp = NULL;
		return head;
	}
}

struct node* get_last_node(struct node* head) {
	if (head == NULL) {
		return NULL;
	}
	struct node* lastnode = head;
	while (lastnode->next) {
		lastnode = lastnode->next;
	}
	return lastnode;
}

void display_linkedlist(struct node * head) {
	cout << endl;
	while (head) {
		cout << head->data << endl;
		head = head->next;
	}
}

struct node* self_adjust(struct node * head, int value) {
	if (head == NULL) {
		return NULL;
	}
	struct node* prev = NULL;
	struct node* temp = head;
	while (temp && temp->data != value) {
		prev = temp;
		temp = temp->next;
	}
	if (prev && temp) {
		prev->next = temp->next;
		temp->next = head;
		head = temp;
	}
	return head;
}

void merge_linked_lists(struct node** list1, struct node* list2, int list1_len, int position) {
	if (*list1 == NULL) {
		*list1 = list2;
	}
	else if (position <= 0) {
		struct node* lastnode = get_last_node(list2);
		lastnode->next = *list1;
		*list1 = list2;
	}
	else {
		struct node* temp = *list1;
		position--;
		while (position && temp->next) {
			temp = temp->next;
			position--;
		}
		struct node* list2_lastnode = get_last_node(list2);
		list2_lastnode->next = temp->next;
		temp->next = list2;
	}
}


struct node* array_to_linkedlist(int* arr, int len) {
	struct node* head = NULL;
	if (len > 0) {
		int i = 0;
		head = insert_at_end(head, arr[i++]);
		for (; i < len; i++) {
			insert_at_end(head, arr[i]);
		}
	}
	return head;
}


struct node * merge_linked_lists_helper() {
	int len1, len2, position, i;
	struct node* list1 = NULL,  * list2 = NULL;
	cin >> len1;
	if (len1 > 0) {
		int * arr1 = (int *)calloc(len1, sizeof(int));
		for (i = 0; i < len1; i++) {
			cin >> arr1[i];
		}
		list1 = array_to_linkedlist(arr1, len1);
		free(arr1);
		arr1 = NULL;
	}
	cin >> len2;
	if (len2 > 0) {
		int* arr2 = (int*)calloc(len2, sizeof(int));
		for (i = 0; i < len2; i++) {
			cin >> arr2[i];
		}
		list2 = array_to_linkedlist(arr2, len2);
		free(arr2);
		arr2 = NULL;
	}
	cin >> position;
	merge_linked_lists(&list1, list2, len1, position);
	return list1;
}













/*node * node::insert_at_end(node * head, int data) {
	if (head == NULL) {
		this->data = data;
		this->next = NULL;
	}
	else {
		this->next = insert_at_end(head->next, data);
	}
	return this;
}

node * node::delete_at_end() {
	if (this->next == NULL) {
		return NULL;
	}
	node * prev = this;
	node * temp = this->next;
	while (temp->next) {
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	delete(temp);
	return this;
}*/