/*
	A C Program To Implement Queue Abstract Data Type with help of Linked Stack using Pointers

	Sample Input && Output:

		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 1

		Enter the Element to Enqueue: 85

		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 1

		Enter the Element to Enqueue: 23

		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 1

		Enter the Element to Enqueue: 400

		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 1

		Enter the Element to Enqueue: 89

		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 3

		Queue: 85 23 400 89


		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 3

		Queue: 85 23 400 89


		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 2

		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 3

		Queue: 23 400 89


		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 2

		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 2

		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 3

		Queue: 89


		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 2

		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 3

		Queue Empty!!


		1.Enqueue
		2.Dequeue
		3.Print
		(0 to Exit)
		Enter Your Choice: 0

*/

//Including Required Header Files
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Declaration of Queue(Node)
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node Queue;

//Function Declaration
void Enqueue();
void Dequeue();
void Print();

//Head Pointer
Queue *head = NULL;

int main(){
	int choice;
	while(1){
		printf("\n1.Enqueue\n2.Dequeue\n3.Print\n(0 to Exit)\nEnter Your Choice: ");
		scanf("%d", &choice);

		if (choice == 0){	
			return 0;
		}
		switch (choice)
		{
		case 1:
			Enqueue();
			break;
		case 2:
			Dequeue();
			break;
		case 3:
			Print();
			break;
		default:
			printf("\nWrong Choice!!!\n");
			break;
		}
	}
}

//Definition of Insert Function to insert elements into the Queue
void Enqueue(){
	Queue *newnode = malloc(sizeof(Queue));
	printf("\nEnter the Element to Enqueue: ");
	scanf("%d", &newnode->data);
	if (head == NULL){
		head = newnode;
		head->next = NULL;
		return;
	}
	Queue *ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	newnode->next = NULL;
	ptr->next = newnode;
}


//Definition of Delete Function to Remove elements from the Queue
void Dequeue(){
	if (head == NULL){
		printf("\nQueue is Empty!!\n");
		return;
	}
	head = head->next;
}

//Definition of Print Function to print the Queue
void Print(){
	if (head == NULL){
		printf("\nQueue Empty!!\n\n");
		return;
	}
	printf("\nQueue: Front End -->  ");
	Queue *ptr = head;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("  <-- Rear End\n\n");
	return;
}