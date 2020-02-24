#include <stdlib.h>
#include <iostream>

using namespace std;

#include "dataelement.h"

struct data_element * insert( void(*display_datatype)(void* data), void* data, size_t(*get_size)(void* data))
{
	struct data_element* newelement = (struct data_element*) calloc(1, sizeof(struct data_element));
	size_t size = get_size(data);
	newelement->size = size;
	newelement->data_ptr = calloc(1, size);
	memcpy(newelement->data_ptr, data, size);
	newelement->display_data = display_datatype;
	return newelement;
}

void display_int(void* data)
{
	cout<< *(int*)data << endl;
}

void display_char(void* data)
{
	cout << *(char*)data << endl;
}


size_t get_size_int(void* data)
{
	return sizeof(int);
}
size_t get_size_char(void* data)
{
	return sizeof(char);
}



struct data_element * insert_int(int val)
{
	return insert(display_int, (void*)&val, get_size_int);
}

struct data_element* insert_char(char ch)
{
	return insert(display_char, (void*)&ch, get_size_char);
}


void swap(struct data_element** arr, int i, int j) {
	struct data_element* temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int compare(struct data_element* ele1, struct data_element* ele2) {
	if (ele1->size != ele2->size) {
		if (ele1->size > ele2->size) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {
		if (ele1->size == sizeof(char)) {
			if (*(char*)(ele1->data_ptr) > * (char*)(ele2->data_ptr)) {
				return 1;
			}
			else if (*(char*)(ele1->data_ptr) < * (char*)(ele2->data_ptr)) {
				return -1;
			}
			else {
				return 0;
			}
		}
		else {
			if (*(int*)(ele1->data_ptr) > * (int*)(ele2->data_ptr)) {
				return 1;
			}
			else if (*(int*)(ele1->data_ptr) < *(int*)(ele2->data_ptr)) {
				return -1;
			}
			else {
				return 0;
			}
		}
	}
	return 0;
}

void quick_sort(struct data_element** arr, int low, int high) {
	if (low < high) {
		int i, j, pivot, temp;
		pivot = low;
		i = low;
		j = high;
		while (i < j) {
			while ((compare(arr[i], arr[pivot]) == -1 || compare(arr[i], arr[pivot]) == 0) && i < high) {
				i++;
			}
			while (compare(arr[j], arr[pivot]) == 1) {
				j--;
			}
			if (i < j) {
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[pivot], arr[j]);
		quick_sort(arr, low, j - 1);
		quick_sort(arr, j + 1, high);

	}
}

void print_data_set(struct data_element** arr, int len) {
	int i;
	cout << endl;
	for (i = 0; i < len; i++) {
		arr[i]->display_data(arr[i]->data_ptr);
	}
}