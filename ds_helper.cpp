/*
 * ds_helper.cpp
 *
 *  Created on: Jun 5, 2020
 *      Author: rohit
 */

#include <iostream>
#include "ds_main.hpp"
using namespace std;

int Lsearch(int arr[], int size, int item)
{
	int pos = -1;
	int i = 0;

	// using for loop
#if 1
	for(i = 0; i<size; i++){
		if(item == arr[i]){
			printf("Item found at %d\n", i);
			pos = i;
			break;
		}
	}
#endif

	// using while loop
#if 0
	while(i <= (size-1)){
		if(item == arr[i]){
			printf("Item found at %d\n", i);
			return_value = 1;
			break;
		}
		i++;
	}

#endif

	return pos;
}

int BsearchDescending(int arr[], int size, int item){
	//init all local counters
	int pos = -1;
	int beg = 0, last = size-1, mid = 0;
	// traverse through the array and search
	while(beg <= last){
		mid = (beg + last)/2;
		if(item == arr[mid]){		// look for the element in the mid of the array
			pos = mid;
			break;
		}
		if(item < arr[mid]){
			beg = mid + 1;			// change the window edges
		}
		if(item > arr[mid]){
			last = mid - 1;			// change the window edges
		}
	}
	return pos;
}

int BsearchAscending(int arr[], int size, int item){
	int pos = -1;
	int beg = 0, last = size-1, mid = 0;
	while(beg <= last){
		mid = (beg + last)/2;
		if(item == arr[mid]){
			pos = mid;
			break;
		}
		if(item < arr[mid]){
			last = mid - 1;
		}
		if(item > arr[mid]){
			beg = mid + 1;
		}
	}
	return pos;
}

int InsertionSortedAscending(int arr[], int size, int item, int N)
{
	int pos = -1;
	int i = 0;
	if(N >= size){
		return pos;
	}
	// 1. first find out the place to insert the element in the sorted array
	for(i = 0; i<size; i++){
		if(arr[i] <= item && arr[i+1] > item){
			pos = i+1;
			break;
		}
	}
	// 2. now as we know the position, we can shift the elements to make space to new item at pos
	for(i = N; i>pos; i--){
		arr[i] = arr[i-1];
	}
	// 3. store the new item at pos
	arr[pos] = item;
	return pos;
}

int DeletionSortedAscending(int arr[], int size, int item)
{
	//1. find the element and its position it the array
	// using binary search
	int pos = -1, i = 0;
	pos = BsearchAscending(arr, size, item);
	if(pos == -1){
		cout << "Element not found\n";
		return pos;
	}
	// 2. now as we have the position we can shift up the elements of the array
	for(i = pos; i<size-1; i++){
		arr[i] = arr[i+1];
	}
	return pos;
}

int delete_item(int arr[], int size, int item)
{
	// linear search the item in the array
	int pos = -1;
	int i = 0;
	for(i = 0; i<size; i++){
		if(item == arr[i]){
			pos = i;
			break;
		}
	}

	if(pos == -1){	//element not found
		return -1;
	}

	// now delete that element and shift up the array
	if(pos != -1){
		for(i=pos; i<size-1; i++){
			arr[i] = arr[i+1];
		}
	}
	return pos;
}

int SelectionSort(int arr[], int size)
{
	int j=0;
	int sort_index = 0;
	int small = arr[sort_index];
	int temp = 0, pos = 0;

	for(sort_index = 0; sort_index<size; sort_index++)
	{
		small = arr[sort_index];
		pos = sort_index;
		for(j=sort_index+1; j < size; j++){
		//printf("compare: %d < %d\n", arr[i], small);
			if(arr[j] < small){
				small = arr[j];
				pos = j;
			}
			//printf("so_in:%d, i:%d, small:%d, swap_index:%d\n", so_in, i, small, swap_index);
		}
		temp = arr[pos];
		arr[pos] = arr[sort_index];
		arr[sort_index] = temp;
	}

	return 0;
}

int insertArray(int arr[], int size, int key, int pos)
{
	int i =0;

	for(i = size-1; i>pos; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[pos] = key;

	return 0;
}

// ================== Linked List =================== //
node* InsertBeg(node *head, int value){
	node *temp = NULL;
	temp = (node*)malloc(sizeof(node));
	temp->value = value;
	temp->next = head;
	head = temp;
	return head;
}

void InsertEnd(node *head, int value){
	node* temp = NULL;
	temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	node *endNode = NULL;
	endNode = (node*)malloc(sizeof(node));
	endNode->value = value;
	endNode->next = NULL;
	temp->next = endNode;
}

node *InsertNth(node *head, int n, int value){
	node *temp = NULL;
	if(head == NULL){
		temp = (node*)malloc(sizeof(node));
		temp->next = NULL;
		temp->value = value;
		head = temp;
		return head;
	}
	temp = head;
	node *newNode = (node*)malloc(sizeof(node));
	newNode->value = value;
	if(n==1){
		newNode->next = temp;
		head = newNode;
		return head;
	}

	int i = 1;
	for(i=1;i<n-1;i++){
		if(temp->next == NULL){
			printf("Enter valid position number\n");
			free(newNode);
			return head;
		}
		temp=temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	return head;
}

node *DeleteFirst(node *head){
	if(head == NULL)
	{
		printf("List is empty, nothing to delete\n");
	}
	node *temp = head;
	head = temp->next;
	free(temp);
	return head;
}

void DeleteLast(node *head){
	if(head == NULL)
	{
		printf("List is empty, nothing to delete\n");
		return;
	}
	node *temp = head;
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	node *lastNode = temp->next;
	temp->next = NULL;
	free(lastNode);
}

// list starts from 1 to n
node *DeleteNth(node *head, int n){
	if(head == NULL){
		printf("List is empty, nothing to delete\n");
		return NULL;
	}
	if(n==1){
		head = DeleteFirst(head);
		return head;
	}
	if(n<0){
		printf("Invalid node number\n");
		return head;
	}
	node *temp = head;
	int i;
	for(i=1;i<n-1;i++){
		if(temp->next == NULL){
			printf("node number out of range, please enter a valid node number\n");
			return head;
		}
		temp = temp->next;
	}

	if(temp->next == NULL)
	{
		printf("node number out of range, please enter a valid node number\n");
		return head;
	}
	node *delNode = temp->next;
	temp->next = delNode->next;
	free(delNode);
	return head;
}

// list starts from 1 to n
node *DeleteNthFromLast(node *head, int n){
	node *temp;
	if(head == NULL){
		printf("List is empty, nothing to delete\n");
		return NULL;
	}
	if(n<0){
		printf("Invalid node number\n");
		return head;
	}
	// 1st pass to count the items in the list
	temp = head;
	int count = 1;
	while(temp->next != NULL){
		temp = temp->next;
		count++;
	}
	int index = (count-n)+1;
	//printf("Count = %d, index = %d\n", count, index);
	return DeleteNth(head, index);
}

void printList(node *head)
{
	if(head == NULL){
		printf("List is empty\n");
		return;
	}
	node *temp = head;
	//printf("Head -> ");
	while(temp!=NULL){
		printf("%d -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
}

// ===================================================//

// ================== Stack Array =================== //

void printStackArray(int arr[], int *top){
	int localTop = *top;
	if(localTop < 0){
		printf("Stack is empty\n");
		return;
	}
	printf("\n");
	printf("%d <--- top\n", arr[localTop]);
	localTop--;
	while(localTop >= 0){
		printf("%d\n", arr[localTop]);
		localTop--;
	}
	printf("\n");
}

void pushStackArray(int arr[], int *top, int value){
#if 0
	int localTop = *top;
	localTop++;
	arr[localTop] = value;
	*top = localTop;
#endif
	if(*top > 9)
	{
		printf("STACK OVERFLOW\n");
		return;
	}
	//printf("top before push = %d\n", *top);
	(*top)++;
	arr[*top] = value;
	//printf("top after push = %d\n", *top);
}

int popStackArray(int arr[], int *top){
#if 0
	int value = 0;
	int localTop = *top;
	value = arr[localTop];
	localTop--;
	*top = localTop;
	return value;
#endif
	if(*top < 0)
	{
		printf("Stack Underflow\n");
		return 0;
	}
	//printf("top before pop = %d\n", *top);
	int value = arr[*top];
	(*top)--;
	//printf("top after pop = %d\n", *top);
	return value;
}

int ifStackArrayEmpty(int arr[], int *top){
	if(*top < 0)
		return 1;
	else
		return 0;
}

int ifStackArrayFull(int arr[], int *top){
	if(*top > 9)
		return 1;
	else
		return 0;
}

// ===================================================//

// ================ Stack Linked List =============== //

void pushStackLL(node **TOP, int value){
	node *temp = NULL;
	if(*TOP == NULL){
		temp = (node*)malloc(sizeof(node));
		temp->value = value;
		temp->next = NULL;
		*TOP = temp;
		return;
	}
	temp = *TOP;
	node *newNode = (node*)malloc(sizeof(node));
	newNode->value = value;
	newNode->next = temp;
	*TOP = newNode;
}

int popStackLL(node **TOP){
	if(*TOP == NULL){
		printf("Stack is empty: UNDERFLOW!\n");
		return -1;
	}
	int value = 0;
	node *temp = *TOP;
	value = temp->value;
	*TOP = temp->next;
	free(temp);
	return value;
}

void printStackLL(node **TOP){
	if(*TOP == NULL){
		printf("Stack is empty\n");
		return;
	}
	node *temp = *TOP;
	printf("%d <-- TOP\n", temp->value);
	temp = temp->next;
	while(temp != NULL){
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

// ===================================================//
// ================ Queue Array ===================== //

void insertQueueArray(int qarr[], int *rear, int value){
	if(*rear > QUEUE_SIZE-2){
		printf("Queue Overflow: Queue full not able to add\n");
		return;
	}
	(*rear)++;
	qarr[*rear] = value;
}

int deleteQueueArray(int qarr[], int *rear){
	if(*rear < 0){
		printf("Queue Underflow: queue is empty");
		return -1;
	}
	int value = qarr[0];
	//shift remaing elements till end of array
	int i = 0;
	for(i=0; i<*rear; i++){
		qarr[i] = qarr[i+1];
	}
	(*rear)--;
	return value;
}

void printQueueArray(int qarr[], int *rear){
	if(*rear < 0){
		printf("Queue is empty\n");
		return;
	}
	int i = 0;
	printf("\n");
	for(i=0;i<=*rear;i++){
		printf("%d ", qarr[i]);
	}
	printf("\n");
}

// ===================================================//
// ================ Queue Linked List =============== //

void insertQueueLL(node **FRONT, node **REAR, int value){
	node *newNode = new node;
	newNode->value = value;
	newNode->next = NULL;
	if(*REAR == NULL){
		*REAR = newNode;
		*FRONT = newNode;
		return;
	}
	node *temp = *FRONT;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	*REAR = newNode;
}

void deleteQueueLL(node **FRONT, node **REAR){
	if(*FRONT == NULL){
		printf("Queue is empty, nothing to delete\n");
		return;
	}
	node *temp = *FRONT;
	*FRONT = temp->next;
	if(temp->next == NULL){
		*REAR = NULL;
	}
	delete temp;
}

void printQueueLL(node **FRONT){
	node *temp = *FRONT;
	printf("\n");
	while(temp!=NULL){
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

// ===================================================//
// ================ Ring buuffer FIFO =============== //

void insertCQueue(int arr[], int *front, int *rear, int value){
	//printf("Front = %d, Rear = %d, Inserting %d,", *front, *rear, value);
	if(*rear == -1)// first element in the queue
	{
		*front = *rear = 0;
		arr[0] = value;
		return;
	}
	int localRear = *rear;
	localRear++;
	localRear = localRear % QUEUE_SIZE;

	//printf(" localRear = %d\n", localRear);
	if(localRear == *front){
		printf("Queue is full\n");
		return;
	}
	(*rear)++;
	(*rear) = (*rear) % QUEUE_SIZE;
	arr[*rear] = value;

	/*if((*front == 0 && *rear == QUEUE_SIZE-1)||
				(*rear == (*front-1)%(QUEUE_SIZE-1)))
	{
		printf("Queue is full\n");
		*rear = (*front) - 1;
		return;
	}
	if(*front == -1){
		*front = *rear = 0;
		arr[*rear] = value;
		return;
	}

	if(*rear == QUEUE_SIZE-1 && *front != 0)
	{
		*rear = 0;
		arr[*rear] = value;
		return;
	}
	(*rear)++;
	arr[*rear] = value;*/
}

int deleteCQueue(int arr[], int *front, int *rear){
	//printf("Front = %d, Rear = %d\n", *front, *rear);
	int value = 0;
	if(*front == -1)
	{
		printf("Queue is empty, ");
		return -1;
	}
	if(*front == *rear)
	{
		value = arr[*front];
		*rear = -1;
		*front = -1;
		return value;
	}
	int localFront = *front;
	value = arr[localFront];
	localFront++;
	localFront = localFront % QUEUE_SIZE;
	*front = localFront;
	return value;
}

void printCQueue(int arr[], int *front, int *rear){
	printf("PRINT:\n");
	if(*rear == -1||*front == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	int i=*front;
	*rear = *rear % QUEUE_SIZE;
	//printf("Front = %d, Rear = %d\n", *front, *rear);
	//for(i=*front;i<=*rear;i++){
	while(i != *rear){
		i = i % QUEUE_SIZE;
		printf("%d \n", arr[i]);
		i++;
	}
	printf("%d \n", arr[i]);
	printf("\n");
}

// ===================================================//
