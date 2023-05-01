# include <stdio.h>
# include <stdlib.h> 

# define LIST_MAXSIZE 3

typedef struct{
    int age;
    int height;
    double weight;
} Student;

typedef struct{
    Student *stu;
    int length;
    int listsize;
} SqList;

// initialize list
int initList(SqList *L){
    // 1. apply a space
    // 2. if get the space
    // 3. If we get the space, initialize the list
    L->stu = (Student *)malloc(LIST_MAXSIZE * sizeof(Student));
    if(L->stu == NULL) exit(-1);

    L->length = 0;
    L->listsize = LIST_MAXSIZE;

    return 1;
}

// Since we use malloc, when we finish the list, we destory the list
int deledteList(SqList *L){
    // 1. Determine whether the sequence table exists
    if(L->stu == NULL){
        return 0;
    }
    // 2. If it exists, release the corresponding memory //using free
    free(L->stu);
    // 3. After releasing the memory, restore the initial value of the table
    L->length =0;
    L->listsize = 0;
    return 1;
} 

//traversa lList
void AllList(SqList *L){
    int i=0;
    for(i=0; i<L->length; i++){
        printf("age: %d, height: %d, weight: %lf\n", L->stu[i].age, L->stu[i].height, L->stu[i].weight);
    }
    printf("%d\n", L->length);
}

int find(SqList *L, Student *s){
    int index = 0;
    while(index < L->length){
        //printf("%d %d %lf\n", L->stu[index].age, L->stu[index].height, L->stu[index].weight);
        if(L->stu[index].age == s->age && L->stu[index].height == s->height && L->stu[index].weight == s->weight){
            return index;
        }
        index++;
        //printf("%d\n", index);
    }

    return -1;
}


int main(){
	// 1. Initialize a usual use case
	SqList L;
	// Student stu[LIST_INIT_SIZE] = {{10,160,45},{20,170,50},{30,180,55}};
	Student find_stu;
	
  	initList(&L);
  	
  	int i=0;
	for(i = 0; i < LIST_MAXSIZE; i++){
		printf("input age, height, weight\n");
		scanf("%d%d%lf", &L.stu[i].age, &L.stu[i].height, &L.stu[i].weight);
		L.length ++;
	}
	AllList(&L);
	printf("input search student info:\n");
	scanf("%d %d %lf", &find_stu.age, &find_stu.height, &find_stu.weight);
	printf("index: %d", find(&L, &find_stu));
	deledteList(&L);
     
     
	return 0;
} 
