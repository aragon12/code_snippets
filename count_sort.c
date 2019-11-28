/*
* count_sort.c by aragon12
* C code implementation of the counting sort algorithm

* Counting sort is a sorting technique based on
* keys between a specific range. It works by
* counting the number of objects having distinct
* key values, Then doing some arithmetic to
* calculate the position of each object in the
* output sequence

* Usage:
        -the counting_sort(arr, l, c_l) takes 3 args:
             * array (arr) of integers to be sort
             * length (l) of the array
             * largest element (c_l) of the array
             * it returns pointer to the new sorted array
         -largest element of the array can be
         found by another utility max_arr(arr, l)
         which takes:
             * array (arr) of integers
             * length (l) of array
             * and returns largest element of array

*/

#include<stdio.h>
#include<malloc.h>

int max_arr(int *arr, int l)
{
	int i, max = 0;
	for (i = 0; i < l; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

void print_arr(int *arr, int l)
{
	int i;
	for (i = 0; i < l; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int *counting_sort(int *arr, int l, int c_l)
{
	int i;

	// creating arr C of length of max element + 1
	c_l++;
	int *c = (int *)malloc(c_l * sizeof(int));

	// count occurence of each element
	// and store in arr C 
	for (i = 0; i < l; i++)
		c[arr[i]]++;

	// recursive add elements of arr C
	// and store in same arr C
	int sum = 0;
	for (i = 0; i < c_l; i++)
	{
		sum += c[i];
		c[i] = sum;
	}

	// create one more arr B of same length A
	int *b = (int *)malloc(l * sizeof(int));

	// sort the array and save on new array B
	for (i = (l - 1); i >= 0; i--)
	{
		b[c[arr[i]] - 1] = arr[i];
		c[arr[i]]--;
	}

	return b;
}

void main()
{
	 int arr[] = { 6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2 };
	//int arr[] = { 5, 8, 3, 9, 2, 10, 1, 35, 32 };
	
	int arr_s = 11;
	int max_el = max_arr(arr, arr_s);
	
	print_arr(arr, arr_s);
	
	int *sorted = counting_sort(arr, arr_s, max_el);

	print_arr(sorted, arr_s);
}