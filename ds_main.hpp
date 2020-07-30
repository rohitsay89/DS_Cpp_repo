/*
 * ds_main.hpp
 *
 *  Created on: Jun 2, 2020
 *      Author: rohit
 */

#ifndef DS_MAIN_HPP_
#define DS_MAIN_HPP_

#define STACK_ARRAY_SIZE	10
#define QUEUE_SIZE			20

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
void vLearnComapreLL();
void vLearnStackArray();
void vLearnStackLL();
void vLearnQueueArray();
void vLearnQueueLL();
void vLearnCircularQueue();


// ================================== //
// unit test module func declerations:
bool utCircularQueue();

/*enum
{
	ARRAY_LINEAR_SEARCH,
	ARRAY_BINARY_SEARCH
};*/
typedef struct node
{
	int value;
	node *next;
}node;

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
int compare_2LL(node* headA, node* headB);
void printList(node *);

void printStackArray(int arr[], int *top);
void pushStackArray(int arr[], int *top, int value);
int popStackArray(int arr[], int *top);
int ifStackArrayFull(int arr[], int *top);
int ifStackArrayEmpty(int arr[], int *top);
void pushStackLL(node **TOP, int value);
int popStackLL(node **TOP);
void printStackLL(node **TOP);

void insertQueueArray(int qarr[], int *rear, int value);
int deleteQueueArray(int qarr[], int *rear);
void printQueueArray(int qarr[], int *rear);

void insertQueueLL(node **FRONT, node **REAR, int value);
void deleteQueueLL(node **FRONT, node **REAR);
void printQueueLL(node **FRONT);

void insertCQueue(int arr[], int *front, int *rear, int value);
int deleteCQueue(int arr[], int *front, int *rear);
void printCQueue(int arr[], int *front, int *rear);
#endif /* DS_MAIN_HPP_ */
