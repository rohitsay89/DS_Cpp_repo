// this is Data structure learning code

#include <iostream>
#include "ds_main.hpp"
#include <string.h>

using namespace std;

//#define ARRAY_LINEAR_SEARCH
//#define ARRAY_BINARY_SEARCH
//#define ARRAY_INSERTION
//#define ARRAY_DELETION
//#define EXAMPLE_9_6
//#define EXCHANGE_SELECTION_SORT
//#define BUBBLE_SORT
//#define INSERTION_SORT
//#define MERGE_SORT
//#define TWO_D_ARRAY
//#define MATRIX_ARRAY
//#define LINKED_LIST
//#define COMPARE_LINKED_LIST
//#define DOUBLY_LINKED_LIST
//#define STACK_ARRAY
//#define STACK_LINKED_LIST
//#define QUEUE_ARRAY
//#define QUEUE_LINKED_LIST
#define CIRCULAR_QUEUE_ARRAY

#define ASCENDING	1

int main()
{
	cout << "C++ version = " << __cplusplus << "\nCompilation Date is " << __DATE__ << "\nCompilation Time is " << __TIME__ << endl;

#ifdef ARRAY_LINEAR_SEARCH
	vLearnLinearSearchArray();
#endif

#ifdef ARRAY_BINARY_SEARCH
	vLearnBinarySearchArray();
#endif

#ifdef ARRAY_INSERTION
	vLearnArrayInsertion();
#endif

#ifdef ARRAY_DELETION
	vLearnArrayDeletion();
#endif

#ifdef EXAMPLE_9_6
	vEx_9_4();
#endif

#ifdef EXCHANGE_SELECTION_SORT
	vLearnExchangeSelectionSort();
#endif

#ifdef BUBBLE_SORT
	vLearnBubbleSort();
#endif

#ifdef INSERTION_SORT
	vLearnInsertionSort();
#endif

#ifdef MERGE_SORT
	vLearnMergeSort();
#endif

#ifdef TWO_D_ARRAY
	vLearn2DArray();
#endif

#ifdef MATRIX_ARRAY
	vLearnMatrix();
#endif

#ifdef LINKED_LIST
	vLearnLinkedList();
#endif

#ifdef COMPARE_LINKED_LIST
	vLearnComapreLL();
#endif
#ifdef DOUBLY_LINKED_LIST
	vLearnDoublyLinkedList();
#endif

#ifdef STACK_ARRAY
	vLearnStackArray();
#endif

#ifdef STACK_LINKED_LIST
	vLearnStackLL();
#endif

#ifdef QUEUE_ARRAY
	vLearnQueueArray();
#endif

#ifdef QUEUE_LINKED_LIST
	vLearnQueueLL();
#endif

#ifdef CIRCULAR_QUEUE_ARRAY
	vLearnCircularQueue();
#endif

	cout << "\n\nProgram execution ended\n\n";
	return 0;
}

void vLearnLinearSearchArray(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int stat = Lsearch(arr, 10, 5);
	if(stat == -1){
		cout << "Item not found \n";
	}
}

void vLearnBinarySearchArray(){
	int stat = 0;
	//int arr[11] = {1,2,3,4,5,6,7,8,9,10,11};
	//stat = BsearchAscending(arr, 11, 5);

	int arr[11] = {11,10,9,8,7,6,5,4,3,2,1};
	stat = BsearchDescending(arr, 11, 5);
	if(stat == -1){
		cout << "Item not found\n";
	}
	else{
		cout << "Item found at " << stat << endl;
	}
}

void vLearnArrayInsertion()
{
	int arr[10] = {1,2,3,4,6};
	int stat = 0;
	for(int i=0; i<10; i++){
		printf("arr[%d] = %d\t", i, arr[i]);
	}
	printf("\n");
	stat = InsertionSortedAscending(arr, 10, 5, 5);
	printf("\n");
	if(stat == -1){
		printf("Unable to insert\n");
	}
	else{
		printf("Element inserted at position: %d\n", stat);
		for(int i=0; i<10; i++){
				printf("arr[%d] = %d\t", i, arr[i]);
		}
	}
}

void vLearnArrayDeletion()
{
	cout << "This is array deletion algorithm\n";
	int stat;
	int arr[10] = {1,2,3,4,5,6,7};
	for(int i=0; i<10; i++){
		printf("arr[%d] = %d\t", i, arr[i]);
	}
	printf("\n");
	stat = DeletionSortedAscending(arr, 10, 5);
	if(stat == -1){
		printf("Unable to Delete\n");
	}
	else{
		for(int i=0; i<10; i++){
			printf("arr[%d] = %d\t", i, arr[i]);
		}
		printf("\nElement Deleted at position: %d\n", stat);
	}
}

void vEx_9_4()
{
	int arr[100] = {1,2,3,20,5,6,7,20,8,9,10,22,20,65,20,20,12,13,14,15,16,4,17,18,19};
	int stat = 0, i = 0;

	for(i=0; i<50; i++){
		printf("%d ", arr[i]);
	}
	cout << endl;
	while(stat != -1){
		stat = delete_item(arr, 100, 20);
	}

	for(i=0; i<50; i++){
		printf("%d ", arr[i]);
	}
}

void vLearnExchangeSelectionSort()
{
	cout << "This is excahnge selection sort\n";
	int size = 13, i = 0;
	int arr[size] = {1000,15,6,13,22,3,52,2,-1,-15,33,53,-61};
	//int sort_index = 0;

	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	cout << endl;

	SelectionSort(arr, size);

	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	cout << endl;
}

void vLearnBubbleSort()
{
	cout << "This is Bubble sort\n";
	int size = 13, i = 0;
	int arr[size] = {1000,15,6,13,22,3,52,2,-1,-15,33,53,-61};
	int comaprison_result = 1, temp = 0;
	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	cout << endl;
	while(comaprison_result)
	{
		comaprison_result = 0;
		for(i = 0; i<size; i++)
		{
			if(arr[i] > arr[i+1])
			{
				comaprison_result = 1;
				// swapping using third variable
#if 0
				temp = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = temp;
#endif
#if 1
				// swapping WITHOUT using 3rd variable
				arr[i] = arr[i] + arr[i+1];
				arr[i+1] = arr[i] - arr[i+1];
				arr[i] = arr[i] - arr[i+1];
#endif
			}
		}
	}

	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
}

void vLearnInsertionSort()
{
	cout << "This is Insertion sort\n";
	int size = 13, i = 0;
	int arr[size] = {1,15,6,13,22,3,52,2,-1,-15,33,53,-61};
	int sort_index = 1, temp = 0;
	int small_array_index =0, k=0;
	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	cout << endl;
	cout << endl;

	for(sort_index=1; sort_index<size; sort_index++)
	{
		small_array_index = sort_index;
		printf("so_in:%d, small_array_index:%d \n", sort_index, small_array_index);
		while(small_array_index>0 && arr[small_array_index-1] > arr[small_array_index])
		{
			for(k=0; k<size; k++){
				printf("%d ", arr[k]);
			}
			cout << endl;
			temp = arr[small_array_index];
			arr[small_array_index] = arr[small_array_index-1];
			arr[small_array_index-1] = temp;
			small_array_index = small_array_index-1;
			//printf("so_in:%d, small_array_index:%d \n", sort_index, small_array_index);
			for(k=0; k<size; k++){
				printf("%d ", arr[k]);
			}
			cout << endl;
		}
		cout << endl;
		/*for(k=0; k<size; k++){
			printf("%d ", arr[k]);
		}
		cout << endl;*/
	}
	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	cout << endl;
}

void vLearnMergeSort()
{
	cout << "This is merge Sort\n";

#if ASCENDING
	int sizeA = 5, sizeB = 5, sizeC = 10;
	int A[5] = {1,5,55,87,96};
	int B[5] = {33,54,55,81,95};
	int C[10];
	memset(&C[0], 0x00, 10*sizeof(int));
	int i = 0, Actr = 0, Bctr = 0, Cctr = 0;

	for(i=0; i<sizeA; i++){
		printf("%d ", A[i]);
	}
	cout << endl;
	for(i=0; i<sizeB; i++){
		printf("%d ", B[i]);
	}
	cout << endl;

	// iterate till either array counter are expired
	for(Actr = 0, Bctr = 0, Cctr = 0; Actr < sizeA && Bctr < sizeB;){
		if(A[Actr] < B[Bctr]){
			C[Cctr] = A[Actr];
			Cctr++;
			Actr++;
		}
		if(B[Bctr] <= A[Actr]){
			C[Cctr] = B[Bctr];
			Cctr++;
			Bctr++;
		}
		for(i=0; i<sizeC; i++){
			printf("%d ", C[i]);
		}
		cout << endl;
	}
	// now put the remaing elements if any from both the array
	while(Actr < sizeA){
		C[Cctr] = A[Actr];
		Cctr++;
		Actr++;
	}
	while(Bctr < sizeB){
		C[Cctr] = B[Bctr];
		Cctr++;
		Bctr++;
	}
	for(i=0; i<sizeC; i++){
		printf("%d ", C[i]);
	}
	cout << endl;

#endif
}

void vLearn2DArray()
{
	cout << "This is 2-D array sample\n";
	int row = 2, col = 3;
	int arr[row][col] = {{1,2,3},{4,5,6}};
	int i = 0, j = 0;

	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("val = %d add = %X\t", arr[i][j], &arr[i][j]);
		}
		printf("\n");
	}
	cout << endl;

}

void vLearnMatrix()
{
	cout << "This is Matrix implementation of 2d array\n";
#if 0
	// addition of mtrices
	{
		int row = 3, col = 3;
		int i, j;
		int m1[row][col] = {{1,2,3}, {4,5,6}, {7,8,9}};
		int m2[row][col] = {{7,8,9}, {10,11,12}, {1,2,3}};
		int m3[row][col] = {0};

		// print m1
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				printf("%02d ", m1[i][j]);
			}
			printf("\n");
		}
		cout << endl;
		// print m2
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				printf("%02d ", m2[i][j]);
			}
			printf("\n");
		}
		cout << endl;
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				m3[i][j] = m1[i][j] + m2[i][j];
				printf("%02d ", m3[i][j]);
			}
			printf("\n");
		}
		cout << endl;
	}
#endif

#if 0
	// multiplication of matrices
	std::cout << "Multiplication of matrices" << endl;
	int i = 0, j = 0, ip = 0;
	int row = 2, col = 2;
	int m1[2][3] = {1,2,3, 4,5,6};
	int m2[3][2] = {6,5, 4,3, 2,1};
	int m3[2][2];

	for(i = 0; i<2; i++)
	{
		for(j=0;j<2; j++)
		{
			m3[i][j] = 0;
			for(ip = 0;ip<3;ip++)
			{
				m3[i][j] += m1[i][ip] * m2[ip][j];
			}
		}
	}
	// print m3
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%02d ", m3[i][j]);
		}
		printf("\n");
	}

#endif

#if 0
	// transposition of matrices
	std::cout << "transposition of a matrix" << endl;
	int m1[2][3] = {1,2,3, 4,5,6};
	int m2[2][2];
	int i = 0, j = 0, ip = 0;
	int row = 2, col = 3;

	// print m1
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%02d ", m1[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			m2[j][i] = m1[i][j];
			//printf("%02d ", m2[i][j]);
		}
		printf("\n");
	}

	// print m2
	for(i=0; i<col; i++){
		for(j=0; j<row; j++){
			printf("%02d ", m2[i][j]);
		}
		printf("\n");
	}

#endif

#if 0
	// determinant of a 2x2 square matrix
	std::cout << "Determinant of 2x2 matrix" << endl;
	int m1[2][2] = {1,2, 4,5};
	int i = 0, j = 0;
	int row = 2, col = 2;
	// print m1
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%02d ", m1[i][j]);
		}
		printf("\n");
	}

	int determinant = 0;
	determinant = (m1[0][0] * m1[1][1]) - (m1[0][1] * m1[1][0]);
	std::cout << determinant << endl;
#endif

#if 0
	// determinant of a 3x3 matrix=
	std::cout << "Determinant of 3x3 matrix" << endl;
	int m1[3][3] = {1,2,17, 4,5,18, 7,8,19};
	int i = 0, j = 0;
	int row = 3, col = 3;
	// print m1
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%02d ", m1[i][j]);
		}
		printf("\n");
	}

	int determinant = 0;
	i = 0; j = 0;
	for(j=0; j<3 ; j++){
		determinant = determinant + (m1[0][j]*( (m1[1][(j+1)%3]*m1[2][(j+2)%3]) - (m1[2][(j+1)%3]*m1[1][(j+2)%3]) ));
	}
	std::cout << determinant << endl;

#endif
	std::cout << " 0%3 = " << 0%3
			<< " 1%3 = " << 1%3
			<< " 2%3 = " << 2%3
			<< " 3%3 = " << 3%3
			<< endl;

#if 1
	// Sparse matrix
	int count = 0;
	int sparseMatrix[4][5] =
	{
			{0,0,3,0,4},
			{0,0,5,7,0},
			{0,0,0,0,0},
			{0,2,6,0,0}
	};

	// now calculate count of non zero elements in the sparse matrix:
	int i=0, j=0;
	for(i=0;i<4;++i){
		for(j=0;j<5;++j){
			//printf("sparseMatrix[%d][%d] = %d", i,j, sparseMatrix[i][j]);
			std::cout <<"  " <<sparseMatrix[i][j];
			if(sparseMatrix[i][j] != 0){
				count++;
			}
		}
		//printf("\n");
		std::cout << endl;
	}
	//printf("\n");
	std::cout << endl;
	int compactMatrix[3][count];
	int k =0;

	for(i=0;i<4;++i){
		for(j=0;j<5;++j){
			if(sparseMatrix[i][j] != 0){
				compactMatrix[0][k] = i;
				compactMatrix[1][k] = j;
				compactMatrix[2][k] = sparseMatrix[i][j];
				k++;
			}
		}
	}

	for(i=0;i<3;++i){
		for(j=0;j<count;++j){
			//printf("compactMatrix[%d][%d] = %d", i, j, compactMatrix[i][j]);
			//printf("%d  ", compactMatrix[i][j]);
			std::cout << "  " << compactMatrix[i][j];
		}
		std::cout << endl;
	}


#endif

}

void vLearnLinkedList(){

#if 1
	std::cout << "Operations on ordered list" << endl;
	// ordered list operations:
	// 1. adding new element to ordered list
	// 2. deleting an existing element from ordered list
	node *HEAD = NULL;
	HEAD = InsertBeg(HEAD, 55);
	InsertEnd(HEAD, 56);
	InsertEnd(HEAD, 57);
	//InsertEnd(HEAD, 58);
	InsertEnd(HEAD, 59);
	InsertEnd(HEAD, 60);
	printList(HEAD);
	HEAD = InsertOrd(HEAD, 4);
	printList(HEAD);
	HEAD = InsertOrd(HEAD, 600);
	printList(HEAD);
	HEAD = DeleteFromList(HEAD, 570);
	printList(HEAD);

#endif

#if 0
	printf("This is linked list code here\n");
	node *HEAD = NULL;
	//int n = -1;
	//int val = -1;
	//HEAD = InsertNth(HEAD, 5, 5);
	HEAD = InsertBeg(HEAD, 5);
	InsertEnd(HEAD, 56);
	InsertEnd(HEAD, 57);
	InsertEnd(HEAD, 58);
	InsertEnd(HEAD, 59);
	printList(HEAD);
	std::cout << '\n';
	HEAD = reverseLL(HEAD);
	printList(HEAD);
	std::cout << '\n';
	//printListReverse(HEAD);
	//std::cout << '\n';
	/*printf("Enter nth node to insert:");
	scanf("%d", &n);
	printf("Enter nth node value:");
	scanf("%d", &val);
	HEAD = InsertNth(HEAD, n, val);*/
	//printf("Enter nth node to delete:");
	//printf("Enter nth node from last to delete:");
	//scanf("%d", &n);
	//HEAD = DeleteNth(HEAD, n);
	//HEAD = DeleteNthFromLast(HEAD, n);
	//printList(HEAD);
#endif

#if 0
	/* Linked list implementation using classes and objects */
	std::cout << "This is Linked list implementation using classes\n";
	nodeClass* Head = NULL;
	Head = InsertBegClass(Head, 64);
	InsertEndClass(Head, 65);
	InsertEndClass(Head, 66);
	InsertEndClass(Head, 67);
	InsertEndClass(Head, 68);
	InsertEndClass(Head, 69);
	InsertEndClass(Head, 70);
	printLLClass(Head);
#endif

}

void vLearnComapreLL(){
	std::cout << "Compare 2 linked lists\n";
	node *HEADA = NULL;
	node *HEADB = NULL;

	//HEAD = InsertNth(HEAD, 5, 5);
	HEADA = InsertBeg(HEADA, 5);
	InsertEnd(HEADA, 56);
	InsertEnd(HEADA, 57);
	InsertEnd(HEADA, 58);
	InsertEnd(HEADA, 59);
	cout << "List A = ";
	printList(HEADA);

	HEADB = InsertBeg(HEADB, 5);
	InsertEnd(HEADB, 56);
	InsertEnd(HEADB, 57);
	InsertEnd(HEADB, 58);
	InsertEnd(HEADB, 59);
	cout << "List A = ";
	printList(HEADB);

	cout << "Compare = " << compare_2LL(HEADA, HEADB) << endl;

}

void vLearnDoublyLinkedList(){
	std::cout << "Doubly linked lists demo\n";

	doublyLL_node *HEAD = NULL;
	int n = -1;
	int val = -1;
	//HEAD = InsertNthDoublyLL(HEAD, 5, 5);
	HEAD = InsertBegDoublyLL(HEAD, 5);
	InsertEndDoublyLL(HEAD, 56);
	InsertEndDoublyLL(HEAD, 57);
	InsertEndDoublyLL(HEAD, 58);
	InsertEndDoublyLL(HEAD, 59);
	printListDoublyLL(HEAD);
	printReverseListDoublyLL(HEAD);
	/*std::cout << "Enter nth node to insert:";
	std::cin >> n;
	std::cout << "Enter nth node value:";
	std::cin >> val;
	HEAD = InsertNthDoublyLL(HEAD, n, val);
	printListDoublyLL(HEAD);*/

}

//STACK(LIFO) last in first out implementation using array
void vLearnStackArray(){
	printf("This is stack implementation using array\n");
	int Stack[STACK_ARRAY_SIZE];
	memset(Stack, 0x00, STACK_ARRAY_SIZE*sizeof(int));
	int top = -1;
	printStackArray(Stack, &top);
	pushStackArray(Stack, &top, 1000);
	pushStackArray(Stack, &top, 55);
	pushStackArray(Stack, &top, 2);
	pushStackArray(Stack, &top, 74);
	pushStackArray(Stack, &top, 73);
	pushStackArray(Stack, &top, 54);
	pushStackArray(Stack, &top, 35);
	pushStackArray(Stack, &top, 72);
	printStackArray(Stack, &top);
	pushStackArray(Stack, &top, 66);
	pushStackArray(Stack, &top, 658);
	pushStackArray(Stack, &top, 37);
	pushStackArray(Stack, &top, 65);
	printStackArray(Stack, &top);
	popStackArray(Stack, &top);
	pushStackArray(Stack, &top, 5);
	pushStackArray(Stack, &top, 12);
	popStackArray(Stack, &top);
	popStackArray(Stack, &top);
	popStackArray(Stack, &top);
	printStackArray(Stack, &top);
	popStackArray(Stack, &top);
	pushStackArray(Stack, &top, 87);
	pushStackArray(Stack, &top, 658);
	printStackArray(Stack, &top);
	popStackArray(Stack, &top);
	printStackArray(Stack, &top);
	popStackArray(Stack, &top);
	printStackArray(Stack, &top);
}

// This is the linked List implementation of the Stack DS
void vLearnStackLL(){
	printf("This is stack implementation using Linked List\n");
	node *TOP = NULL;
	int i = 0;
	printStackLL(&TOP);
	for(i = 1; i<7; i++){
		pushStackLL(&TOP, i+5);
	}
	printStackLL(&TOP);
	popStackLL(&TOP);
	printStackLL(&TOP);
	popStackLL(&TOP);
	popStackLL(&TOP);
	popStackLL(&TOP);
	popStackLL(&TOP);
	popStackLL(&TOP);
	popStackLL(&TOP);
	popStackLL(&TOP);
	popStackLL(&TOP);
	popStackLL(&TOP);
	printStackLL(&TOP);
}

// In this implementation I am treating front of queue at 0 index.
void vLearnQueueArray(){
	printf("This is a queue implementation using array\n");
	int qarr[QUEUE_SIZE];
	memset(qarr, 0x00, QUEUE_SIZE*sizeof(int));
	int rear = -1;
	deleteQueueArray(qarr, &rear);
	insertQueueArray(qarr, &rear, 55);
	insertQueueArray(qarr, &rear, 56);
	insertQueueArray(qarr, &rear, 57);
	insertQueueArray(qarr, &rear, 58);
	printQueueArray(qarr, &rear);
	for(int i = 0; i<25; i++){
		insertQueueArray(qarr, &rear, i+5);
		printQueueArray(qarr, &rear);
	}
	printQueueArray(qarr, &rear);
	for(int i = 0; i<20; i++){
		deleteQueueArray(qarr, &rear);
		printQueueArray(qarr, &rear);
	}
	printQueueArray(qarr, &rear);

}

void vLearnQueueLL(){
	printf("This is queue implementation using linked list\n");
	node *FRONT, *REAR;
	FRONT = REAR = NULL;

	deleteQueueLL(&FRONT, &REAR);
	insertQueueLL(&FRONT, &REAR, 55);
	insertQueueLL(&FRONT, &REAR, 56);
	insertQueueLL(&FRONT, &REAR, 57);
	insertQueueLL(&FRONT, &REAR, 58);
	insertQueueLL(&FRONT, &REAR, 59);
	printQueueLL(&FRONT);
	deleteQueueLL(&FRONT, &REAR);
	printQueueLL(&FRONT);
}

void vLearnCircularQueue(){
	printf("This is circular queue implementation using array\n");
	utCircularQueue();

#if 0
	printCQueue(CQueue, &front, &rear);
	for(int i = 1;i<20;i++){
		insertCQueue(CQueue, &front, &rear, i);
	}
	//printCQueue(CQueue, &front, &rear);
	printCQueue(CQueue, &front, &rear);
	printf("value = %d\n", deleteCQueue(CQueue, &front, &rear));
	insertCQueue(CQueue, &front, &rear, 55);
	insertCQueue(CQueue, &front, &rear, 56);
	insertCQueue(CQueue, &front, &rear, 57);
	insertCQueue(CQueue, &front, &rear, 58);
	printCQueue(CQueue, &front, &rear);
	printf("value = %d\n", deleteCQueue(CQueue, &front, &rear));
	printCQueue(CQueue, &front, &rear);
	printf("value = %d\n", deleteCQueue(CQueue, &front, &rear));
	printf("value = %d\n", deleteCQueue(CQueue, &front, &rear));
	printf("value = %d\n", deleteCQueue(CQueue, &front, &rear));
	printf("value = %d\n", deleteCQueue(CQueue, &front, &rear));
	printf("value = %d\n", deleteCQueue(CQueue, &front, &rear));
	printf("value = %d\n", deleteCQueue(CQueue, &front, &rear));
	printCQueue(CQueue, &front, &rear);
	insertCQueue(CQueue, &front, &rear, 1);
	insertCQueue(CQueue, &front, &rear, 2);
	insertCQueue(CQueue, &front, &rear, 3);
	insertCQueue(CQueue, &front, &rear, 4);
	printCQueue(CQueue, &front, &rear);
	for(int i = 1;i<20;i++){
		printf("value = %d\n", deleteCQueue(CQueue, &front, &rear));
	}
	printCQueue(CQueue, &front, &rear);
#endif
}
