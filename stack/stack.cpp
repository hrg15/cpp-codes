#include <iostream>
#include <string>
using namespace std;

struct stack{
	int a[10];
	int top;
};

void create (struct stack *s){
	s->top=-1;	
};

int isFull(struct stack *s){
	if(s->top == 9)
		return 1;
	else
		return 0;
}

void push(struct stack *s){
	int x;
	cout<<"Enter number: ";
	cin>>x;
	 if(isFull(s))
	 	cout<<"Full";
	else
	{
		s->top++;
		s->a[s->top]=x;
	}
}

void pop (struct stack *s){
	
	if(isFull(s))
		cout<<"full";
	else
	{
		cout<<"Pop the: "<< s->a[s->top];
		s->top--;
	}
}

int main (){
	struct stack *x;
	
	create(x);
	
	push(x);
	push(x);
	push(x);
	
	pop(x);
	
	return 0;
}

