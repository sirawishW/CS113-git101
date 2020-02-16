// 6210406700 Sirawish Wongsuthipakorn
#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
	int data; 
	struct Node* next; 
};
struct Node *newNode(int new_data) 
{ 

	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

	new_node->data = new_data; 
	new_node->next = NULL; 

	return new_node; 
}
void sortedInp(struct Node** headModify, struct Node* new_node) 
{ 
	struct Node* now; 

	if (*headModify == NULL || (*headModify)->data >= new_node->data) 
	{ 
		new_node->next = *headModify; 
		*headModify = new_node; 
	} 
	else
	{ 
		
		now = *headModify; 
		while (now->next!=NULL && now->next->data < new_node->data) 
		{ 
			now = now->next; 
		} 
		new_node->next = now->next; 
		now->next = new_node; 
	} 
} 
int main() 
{ 
    int inp;
    struct Node* head = NULL;  
    while(scanf("%d",&inp)==1){
        if(inp<=-1){
            break;
        }
        struct Node *new_node = newNode(inp);
        sortedInp(&head, new_node);
    }
	struct Node *tmp = head; 
	for(tmp=head;tmp;tmp=tmp->next)
	{ 
		printf("%d\n", tmp->data); 
	}
	return 0; 
}