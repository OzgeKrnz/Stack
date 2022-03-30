#include <stdio.h>
#include <stdlib.h>

//baglı listeler ile stack yapısı

struct node {
	int data;
	struct node* sonrakiDugum;
};
/**/

struct node* temp=NULL;
struct node* top = NULL;

void push(int n) {
	struct node* eleman=(struct node*)malloc(sizeof(struct node));

	eleman->data = n;

	if (top == NULL) {
		top = eleman;
		top->sonrakiDugum = NULL;

	}
	else {
		eleman->sonrakiDugum = top;
		top = eleman;//son eklenen eleman en üstte olmalı
	}
}

void pop() {

	if (top == NULL) {
		printf("Stack boş(silinecek eleman yok)");
	}

	else {
		printf("%d elemani stackten cikarildi\n", top->data);
		temp = top->sonrakiDugum;
		free(top); //silme
		top = temp; // top=top->sonrakiDugum; 
	}
}

void print() {

	if (top == NULL) {
		printf("stack bos");
	}
	else {
		temp = top;
		/*degistirildi*/
		while (temp!=NULL)
		{
			printf("%d \n", temp->data);
			temp = temp->sonrakiDugum;
		}
		/*degistirildi*/
		
	}
}

void pick() { //top elemanı gösterir fakat stackten silmez.

	if(top==NULL)
	printf("stack bos\n");
	else {
		printf("stack top elemani: %d\n", top->data);
	}
}

int main()
{
	/*degistirildi*/
	push(3);
	//print();
	push(8);
	//print();
	push(9);
	push(20);
	push(14);
	push(22);
	print();
	/*degistirildi*/
	printf("\n-------\n");
	pop();

	printf("\nYeni stack\n");
	print();
	printf("\n------\n");
	pick();

}


