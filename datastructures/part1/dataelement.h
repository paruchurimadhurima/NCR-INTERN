#pragma once
struct data_element {
	void* data_ptr;
	size_t size;
	void(*display_data)(void* data);
};

struct data_element* insert_int(int val);
struct data_element* insert_char(char val);
void quick_sort(struct data_element** arr, int low, int high);
void print_data_set(struct data_element** arr, int len);

