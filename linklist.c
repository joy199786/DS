# include <stdio.h>
# include <stdlib.h> 


typedef struct{
	int age; 
	int height;
	double weight;
}Student; //student type 

typedef struct node{
	Student stu;
	struct node *next;
}Node;

void copyValue(Student *stu1, Student *std2){
	s1->age = s2->age;
	s1->height = s2->height;
	s1->weight = s2->weight;
}

//Create Node
//Return Node
Node *createNode(Student *stu){
	// applying a ram space
	Node *node = (Node*) malloc(sizeof(Node));
	// determine if the appiing of space successed
	if (!node){
		printf("Create Error!\n");
		return NULL;
	}
	// initize the content of Node
	copyValue()
	// return created Node
	
	
	
}

