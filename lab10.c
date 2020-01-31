#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
	char *name;
	int age;
	struct person *next;
} Person;

void print(Person *ptr);			// prints the entire list
Person *add(Person *ptr, char *n, int a);	// adds a new node to the list
int getAge(Person *myList, char *z);		// returns the age of the person or -1 if not found

int main(void) {
	char input1[100];
	int input2;
	Person *myList = NULL;
	printf("Enter a person's name (one word) and age : ");
	scanf("%s %d", input1, &input2);
	while (input2 != 0) {
	       myList = add (myList, input1, input2);
              printf("\n\nThe list is now : ");  print(myList);
		printf("Enter a name (one word) and age, enter 'xxx' and 0 to exit : ");
		scanf("%s %d", input1, &input2);
	}
	printf("\n\nThe final list is ");  print(myList);
	printf("\n\nEnter the name of a person to look up their age : ");
	scanf("%s", input1);
	while ( strcmp(input1, "xxx") != 0 ) {
		printf("\t%s is %d years old\n", input1, getAge(myList, input1) );
		printf("Enter a name to look up their age or 'xxx' to exit : ");
		scanf("%s", input1);
	}
	return 0;
}
void print(Person *ptr) {
	while (ptr) { printf("[%s-%d] ", ptr->name, ptr->age); ptr = ptr->next; }
	printf("\n");
	return;
}

Person *add(Person *ptr, char *n, int a) {

    /*if(n = ptr->name){
      printf("That person already exists");
      return ptr;
    }*/


	Person *newNode = malloc( sizeof(Person) );
	newNode->name = malloc( strlen(n) + 1 );
	strcpy(newNode->name, n);
  newNode->age = a;

//empty list
  if(ptr == NULL){          //if ptr is empty
    newNode->next = NULL;    //new pointer points to null (end of list)
    return newNode;         //return the only item in the list
  }
//adding to the front
  if(strcmp(newNode->name, ptr->name) < 0){     // if first letter of new < old
    newNode->next = ptr;                   // point to the old first item in the list
    return newNode;                        // return where the list now starts (new)
  }
//adding to the middle or end
  Person *prev = ptr;
  Person *curr = ptr->next;
  while(curr != NULL){
    if(strcmp(n, prev->name) == 0 || strcmp(n, curr->name) == 0){
			printf("error\n");
			return ptr;
		}
		if(strcmp(n, prev->name) > 0 && strcmp(n, curr->name) < 0){
			newNode->next = curr;
			prev->next = newNode;
			return ptr;
		}
		prev = prev->next;
		curr = curr->next;
}
	prev->next = newNode;
	newNode->next = curr;
	return ptr;
}

int getAge(Person *myList, char *z){

	Person *ptr = myList;
	while(ptr != NULL){
		if(strcmp(z, ptr->name) == 0){
			return ptr->age;
		}
		ptr = ptr->next;
	}
return -1;
}
