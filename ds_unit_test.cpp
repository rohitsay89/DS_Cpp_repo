/*
 * ds_unit_test.cpp
 *
 *  Created on: Jun 16, 2020
 *      Author: rohit
 */

#include <iostream>
#include "ds_main.hpp"


/**
	insertCQueue(CQueue, &front, &rear, 58);
	printCQueue(CQueue, &front, &rear);
	printf("value = %d\n", deleteCQueue(CQueue, &front, &rear));
 * */
//unit test module for Circular Queue
bool utCircularQueue(){
	printf("Unit test module for Circular Buffer\n\n");
	int CQueue[QUEUE_SIZE];
	int front, rear;
	front = rear = -1;
	int index = 0;
	bool retVal = 0;

	// create quque: 1,2,3,4,5,6,7
	// initialise counters
	for(index = 0; index<8; index++){
		CQueue[index] = index+1;
	}
	front = 0;
	rear = 6;

	// test case 1: INSERTION = insert new element = 8 at rear end
	insertCQueue(CQueue, &front, &rear, 8);
	//printCQueue(CQueue, &front, &rear);
	if(front == 0 && rear == 7 && CQueue[rear] == 8){
		printf("Insertion test case 1 PASS\n");
		retVal = 1;
	}
	else{
		printf("Insertion test case 1 FAIL\n");
		retVal = 0;
	}

	// test case 2: DELETION = delete element from the front end
	deleteCQueue(CQueue, &front, &rear);
	//printCQueue(CQueue, &front, &rear);
	if(front == 1 && rear == 7 && CQueue[front] == 2){
		printf("Deletion test case 2 PASS\n");
		retVal = 1;
	}
	else{
		printf("Deletion test case 2 FAIL\n");
		retVal = 0;
	}


	// test case 3: Insert more elements beyond the available size of queue
	for(index = 1; index < QUEUE_SIZE+10; index++){
		insertCQueue(CQueue, &front, &rear, index+7);
	}
	//printCQueue(CQueue, &front, &rear);
	if(
			front == 1 &&
			rear == 0 &&
			CQueue[front] == 2 &&
			CQueue[rear] == 20
			)
	{
		printf("Over Insertion test case 3 PASS\n");
		retVal = 1;
	}
	else{
		printf("Over Insertion test case 3 FAIL\n");
		retVal = 0;
	}

	return retVal;
}


