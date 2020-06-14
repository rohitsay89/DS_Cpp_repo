/*
 * ds_main.hpp
 *
 *  Created on: Jun 2, 2020
 *      Author: rohit
 */

#ifndef DS_MAIN_HPP_
#define DS_MAIN_HPP_

#define STACK_ARRAY_SIZE	10

void vLearnLinearSearchArray();
void vLearnBinarySearchArray();
void vLearnArrayInsertion();
void vLearnArrayDeletion();
void vEx_9_4();
void vLearnExchangeSelectionSort();
void vLearnBubbleSort();
void vLearnInsertionSort();
void vLearnMergeSort();
void vLearn2DArray();
void vLearnMatrix();
void vLearnLinkedList();
void vLearnStackArray();
void vLearnStackLL();

/*enum
{
	ARRAY_LINEAR_SEARCH,
	ARRAY_BINARY_SEARCH
};*/
typedef struct node
{
	int value;
	node *next;
};

// helper functions
int BsearchAscending(int arr[], int size, int item);
int BsearchDescending(int arr[], int size, int item);
int InsertionSortedAscending(int arr[], int size, int item, int);
int DeletionSortedAscending(int arr[], int size, int item);
int Lsearch(int arr[], int size, int item);
int delete_item(int arr[], int size, int item);
int SelectionSort(int arr[], int size);
int insertArray(int arr[], int size, int key, int pos);

node* InsertBeg(node *, int);
void InsertEnd(node *, int);
node *InsertNth(node *head, int n, int value);
node *DeleteFirst(node *head);
void DeleteLast(node *head);
node *DeleteNth(node *head, int n);
node *DeleteNthFromLast(node *head, int n);
void printList(node *);

void printStackArray(int arr[], int *top);
void pushStackArray(int arr[], int *top, int value);
int popStackArray(int arr[], int *top);
int ifStackArrayFull(int arr[], int *top);
int ifStackArrayEmpty(int arr[], int *top);


#endif /* DS_MAIN_HPP_ */
