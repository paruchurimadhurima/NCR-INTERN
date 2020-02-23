#pragma once
struct node {
	int data;
	struct node* next;
};

struct node* insert_at_end(struct node* head, int data);
struct node* delete_at_end(struct node* head, int * deleted_val);
void display_linkedlist(struct node* head);
struct node* array_to_linkedlist(int* arr, int len);
struct node* self_adjust(struct node * head, int value);
struct node* merge_linked_lists_helper();

/*class node {
	public:
		int data;
		node * next;

		node * insert_at_end(node * head, int data);

		node * delete_at_end();
};*/