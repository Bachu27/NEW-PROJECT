#include<stdio.h>
#include<stdlib.h>

struct Node {
	int empid;
	char name[20];
	int age;
	struct Node *next;
};

struct Node *insertEmployee(struct Node *start) {
	
	struct Node *n;
	n=malloc(sizeof(struct Node));
	n->next = NULL;
	
	printf("Enter empid, name, age");
	scanf("%d %s %d", &n->empid, n->name, &n->age);
	
	if(start == NULL) {
		start = n;
		return start;
	}
	else{
		if(n->empid < start->empid)
		{
			n->next = start;
			start = n;
			return start;
		} else {
			struct Node *i,*prev=NULL;
			for(i=start;i != NULL; i=i->next)
				{
					if(n->empid < i->empid) {
						prev->next = n;
						n->next=i;
						return start;
					}
					prev=i;
				}
			prev->next=n;
			return start;
		}
	}
}

struct Node *deleteEmployee(struct Node *start) {
		int empid;
		struct Node *i, *prev = NULL;

		if(start == NULL) {
			printf("list is empty\n");
			return start;
		}
	printf("enter empid to delete\n");
	scanf("%d", &empid);

	for(i=start; i != NULL; i = i->next) {
		if(empid == i->empid) {
			
			if(i == start) {
				start = start-> next;
			}
				else { 
					prev->next = i->next;
			}
			free(i);
			return start;
		}
		prev=i;
	}
		
	printf("Empty %d is not found in the list\n",empid);
	return start;
}

display(struct Node *start) {
		if(start == NULL)
			printf("list is empty");
		else{ 	
			struct Node *i;
			printf("\n Employee list...\n");
			for(i=start; i!=NULL; i = i->next)
				printf("%d %s %d\n", i->empid, i->name, i->age);
		printf("\n");
	}
}

main() {
	struct Node *start = NULL;
	int choice;
	
	do {
		printf("1. Add Employee\n");
		printf("2. Delete Employee\n");
		printf("3. Display Employee List\n");
		printf("4. Exit\n");
		printf("Enter your Choice ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				start = insertEmployee(start);
				break;
			case 2:
				start = deleteEmployee(start);
				break;
			case 3:
				display(start);
				break;
		}
	} while(choice != 4);

}		 
