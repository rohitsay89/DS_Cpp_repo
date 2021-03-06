/*
 * ds_helper.cpp
 *
 *  Created on: Jun 5, 2020
 *      Author: rohit
 */

#include <iostream>
//#include <stdint.h>
#include "ds_main.hpp"

using namespace std;

int Lsearch(int arr[], int size, int item){
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

int InsertionSortedAscending(int arr[], int size, int item, int N){
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

int DeletionSortedAscending(int arr[], int size, int item){
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

int delete_item(int arr[], int size, int item){
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

int SelectionSort(int arr[], int size){
	int j=0;
	int sort_index = 0;
	int small = arr[sort_index];
	int temp = 0, pos = 0;

	for(sort_index = 0; sort_index<size; sort_index++){
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

int insertArray(int arr[], int size, int key, int pos){
	int i =0;
	for(i = size-1; i>pos; i--){
		arr[i] = arr[i-1];
	}
	arr[pos] = key;

	return 0;
}

// ================== Linked List =================== //
node* InsertBeg(node *head, int value){
	//node* temp = NULL;
	//temp = (node*)malloc(sizeof(node));
	node* temp { new node };
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
	//node* endNode = NULL;
	//endNode = (node*)malloc(sizeof(node));
	node* endNode { new node };
	endNode->value = value;
	endNode->next = NULL;
	temp->next = endNode;
}

node *InsertNth(node *head, int n, int value){
	node* temp = NULL;
	if(head == NULL){
		//temp = (node*)malloc(sizeof(node));
		temp = new node;
		temp->next = NULL;
		temp->value = value;
		head = temp;
		return head;
	}
	temp = head;
	//node *newNode = (node*)malloc(sizeof(node));
	node* newNode { new node };
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

node* InsertOrd(node *head, int value)
{
	node* temp = NULL;
	temp = head;
	// check if the new value is smaller than first node
	// if yes then add that value to the begining of list
	if(temp->value > value){
		return InsertBeg(head, value);
	}

	// traverse the list till end
	// if new value is more than any node then add new value before that ndoe
	while((temp->next != NULL))
	{
		if(temp->next->value > value){
			node* endNode { new node };
			endNode->value = value;
			endNode->next = temp->next;
			temp->next = endNode;
			return head;
		}
		// if not then just keep going on till end of list
		else{
			temp = temp->next;
		}
	}
	// if no greater value is found in the existing list then add the
	// new value to end of list
	node* endNode { new node };
	endNode->value = value;
	endNode->next = temp->next;
	temp->next = endNode;
	return head;
}

node *DeleteFirst(node *head){
	if(head == NULL)
	{
		printf("List is empty, nothing to delete\n");
	}
	node *temp = head;
	head = temp->next;
	//free(temp);
	delete temp;
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
	//free(lastNode);
	delete lastNode;
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
	//free(delNode);
	delete delNode;
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

// this function looks for a value in the list if present then deletes from
// the list
node *DeleteFromList(node *head, int value)
{
	node *temp = head;
	// if the value is found at first element then just delete the first node
	// adjust the link and return new head;
	if(temp->value == value){
		return DeleteFirst(temp);
	}

	// linear search in the list for value
	while(temp->next != NULL)
	{
		// look for value at each node, if found then delete that node and
		// adjust the links and return head of the list.
		if(temp->next->value == value){
			node *valNode = temp->next;
			temp->next = valNode->next;
			delete valNode;
			return head;
		}
		temp=temp->next;
	}
	std::cout << "Desired value of "<< value << " not found in the list" << endl;
	return head;
}

/* function to compare two linked list and output 1 or 0 */
int compare_2LL(node* headA, node* headB){
	node *temp1, *temp2;

	temp1 = headA;
	temp2 = headB;
	int count_data = 0;
	int count_nodeA = 0;
	int count_nodeB = 0;
	if((headA==NULL)&&(headB==NULL)){				/* Check if both of the lists are empty */
		return 1;									/* If yes then return 1 */
    	}
	while((temp1!=NULL)&&(temp2!=NULL)){    		/* Traverse through both the lists and compare data */
		if((temp1->value)!=(temp2->value)){			/* If data is not same */
			count_data++;							/* increment count */
			if(count_data>0){						/* Check if count is more than 0 */
				return 0;							/* If yes then retrun 0 to main function i.e. list is not idnetical*/
			}
		}
		temp1=temp1->next;							/* go to next node for list 1 */
		temp2=temp2->next;							/* go to next node for list 2 */
	}
	temp1 = headA;
	temp2 = headB;
    	while((temp1!=NULL)){						/* Check for lenght of linked lists */
        	count_nodeA++;							/* count the length */
		temp1 = temp1->next;
	}
	while((temp2!=NULL)){
		count_nodeB++;								/* Check for lenght of linked lists */
		temp2 = temp2->next;						/* count the length */
    	}
    	if((count_nodeA == count_nodeB)&&(count_data==0)){	/* if length and data is equal then return 1 */
        	return 1;
    	}
    	else{										/* Else return 0 */
        	return 0;
    	}
}

void printList(node *head)
{
#if 0
	if(head == NULL){
		cout << "List is empty\n";
		return;
	}
	node *temp = head;
	while(temp!=NULL){
		cout << temp->value << " -> ";
		temp = temp->next;
	}
	cout << "NULL\n";
#endif
	// with recursion:
	if(head == NULL){
		std::cout << "NULL\n";
		return;
	}
	std::cout << head->value << " -> ";
	printList(head->next);
}

void printListReverse(node *p){
	if(p == NULL){
		//cout << "List is empty\n";
		std::cout << "NULL -> ";
		return;
	}
	printListReverse(p->next);
	std::cout << p->value << " -> ";
}

node* reverseLL(node *head){
	node *prev, *current, *next;
	current = head;
	prev = NULL;
	while(current != NULL){
		//std::cout << "Current->value = " << current->value << std::endl;
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}


/* Linked list using class */
nodeClass* InsertBegClass(nodeClass* head , int v)
{
	nodeClass *Node = new nodeClass;
	Node->value = v;
	Node->next = head;
	head = Node;
	return head;
}

void InsertEndClass(nodeClass* head , int v)
{
	if(head == NULL){
		nodeClass *Node = new nodeClass;
		Node->value = v;
		Node->next = NULL;
		head = Node;
	}
	else{
		nodeClass *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		nodeClass *Node = new nodeClass;
		temp->next = Node;
		Node->value = v;
		Node->next = NULL;
	}
}

void printLLClass(nodeClass* head){
	nodeClass* temp = head;
	while(temp != NULL){
		std::cout << temp->value << " -> ";
		temp = temp->next;
	}
	std::cout << "NULL" << endl;
}

// ===================================================//

// ================== Doubly Linked List =================== //

//doublyLL_node
doublyLL_node* InsertBegDoublyLL(doublyLL_node* head, int value){
	doublyLL_node* temp { new doublyLL_node };
	temp->value = value;
	temp->next = head;
	temp->prev = NULL;
	head = temp;
	return head;
}

void InsertEndDoublyLL(doublyLL_node* head, int value){
	doublyLL_node* temp = NULL;
	temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	doublyLL_node* endNode { new doublyLL_node };
	endNode->value = value;
	endNode->next = NULL;
	endNode->prev = temp;
	temp->next = endNode;
}

doublyLL_node *InsertNthDoublyLL(doublyLL_node* head, int n, int value){
	doublyLL_node* temp = NULL;
	if(head == NULL){
		temp = new doublyLL_node;
		temp->next = NULL;
		temp->prev = NULL;
		temp->value = value;
		head = temp;
		return head;
	}
	temp = head;
	doublyLL_node* newNode { new doublyLL_node };
	newNode->value = value;
	if(n==1){
		newNode->next = temp;
		newNode->prev = NULL;
		head = newNode;
		return head;
	}

	int i = 1;
	for(i=1;i<n-1;i++){
		if(temp->next == NULL){
			std::cout << "Enter valid position number\n";
			delete newNode;
			return head;
		}
		temp=temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
	return head;
}

doublyLL_node *DeleteFirstDoublyLL(doublyLL_node* head){
	if(head == NULL)
	{
		std::cout << "List is empty, nothing to delete\n";
	}
	doublyLL_node* temp = head;
	head = temp->next;
	delete temp;

	// rearrange link for the next node
	doublyLL_node* nextNode = head;
	nextNode->prev = NULL;

	return head;
}

void DeleteLastDoublyLL(doublyLL_node* head){
	if(head == NULL)
	{
		std::cout << "List is empty, nothing to delete\n";
		return;
	}
	doublyLL_node* temp = head;
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	doublyLL_node* lastNode = temp->next;
	temp->next = NULL;
	delete lastNode;
}

// list starts from 1 to n
doublyLL_node *DeleteNthDoublyLL(doublyLL_node *head, int n){
	if(head == NULL){
		std::cout << "List is empty, nothing to delete\n";
		return NULL;
	}
	if(n==1){
		head = DeleteFirstDoublyLL(head);
		return head;
	}
	if(n<0){
		std::cout << "Invalid node number\n";
		return head;
	}
	doublyLL_node *temp = head;
	int i;
	for(i=1;i<n-1;i++){
		if(temp->next == NULL){
			std::cout << "node number out of range, please enter a valid node number\n";
			return head;
		}
		temp = temp->next;
	}

	if(temp->next == NULL)
	{
		std::cout << "node number out of range, please enter a valid node number\n";
		return head;
	}
	doublyLL_node *delNode = temp->next;
	doublyLL_node *nextToDelNode = delNode->next;
	temp->next = delNode->next;
	nextToDelNode->prev = temp;
	delete delNode;
	return head;
}

// list starts from 1 to n
doublyLL_node *DeleteNthFromLastDoublyLL(doublyLL_node *head, int n){
	doublyLL_node *temp;
	if(head == NULL){
		std::cout << "List is empty, nothing to delete\n";
		return NULL;
	}
	if(n<0){
		std::cout << "Invalid node number\n";
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
	return DeleteNthDoublyLL(head, index);
}

void printListDoublyLL(doublyLL_node *head){
	if(head == NULL){
		//printf("List is empty\n");
		std::cout << "List is empty\n";
		return;
	}
	doublyLL_node *temp = head;
	while(temp!=NULL){
		//printf("%d -> ", temp->value);
		std::cout << temp->value << " -> ";
		temp = temp->next;
	}
	std::cout << "NULL\n";
}

void printReverseListDoublyLL(doublyLL_node *head){
	if(head == NULL){
		std::cout << "List is empty\n";
		return;
	}
	doublyLL_node *temp = head;
	while(temp->next != NULL){
		//std::cout << temp->value << " -> ";
		temp = temp->next;
	}

	while(temp != NULL){
		std::cout << temp->value << " -> ";
		temp = temp->prev;
	}

	std::cout << "NULL\n";
}

// ==========================================================//

// ================== Stack Array =================== //

void printStackArray(int arr[], int *top){
	int localTop = *top;
	if(localTop < 0){
		std::cout << "Stack is empty\n";
		return;
	}
	std::cout << "\n" << arr[localTop] << " <--- top\n";
	localTop--;
	while(localTop >= 0){
		std::cout << arr[localTop] << std::endl;
		localTop--;
	}
	std::cout << '\n';
}

void pushStackArray(int arr[], int *top, int value){
#if 0
	int localTop = *top;
	localTop++;
	arr[localTop] = value;
	*top = localTop;
#endif
	if(*top > 9){
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
	if(*top < 0){
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
	// add first element in the queue
	if(*rear == -1){
		*front = *rear = 0;
		arr[0] = value;
		return;
	}
	int localRear = *rear;
	localRear++;
	localRear = localRear % QUEUE_SIZE;
	if(localRear == *front){
		printf("Queue is full\n");
		return;
	}
	(*rear)++;
	(*rear) = (*rear) % QUEUE_SIZE;
	arr[*rear] = value;
}

int deleteCQueue(int arr[], int *front, int *rear){
	//printf("Front = %d, Rear = %d\n", *front, *rear);
	if(*front == -1){
		printf("Queue is empty, ");
		return -1;
	}
	int value = 0;
	value = arr[*front];
	if(*front == *rear){
		*rear = -1;
		*front = -1;
		return value;
	}

	(*front)++;
	(*front) = (*front) % QUEUE_SIZE;
	return value;
}

void printCQueue(int arr[], int *front, int *rear){
	if(*rear == -1||*front == -1){
		printf("PRINT: Queue is empty\n");
		return;
	}
	int i=(*front)%QUEUE_SIZE;
	int localRear = *rear;
	localRear = localRear % QUEUE_SIZE;
	//printf("Front = %d, Rear = %d\n", *front, *rear);
	printf("PRINT: \n");
	while(i != localRear){
		//printf("i = %d, localRear = %d\n", i, localRear);
		printf("%d \n", arr[i]);
		i = i % QUEUE_SIZE;
		i++;
		i = i % QUEUE_SIZE;
	}
	printf("%d \n", arr[i]);
	printf("\n");
}

// ===================================================//
// ==================== MATRIX ====================== //


// ===================================================//
