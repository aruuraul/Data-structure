 #include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100
void enque();
void deque();
void display();
int queue[max],front=-1,rear=-1;
int main(){
int value,choice;
do{
printf("\n\t *****MAIN MENU*****");
printf("\n 1.Insertion\n 2.Deletion\n 3.Dislay \n 4.Exit\n");
printf("Enter choice:");
scanf("%d",&choice);
switch(choice){
case 1: enque();
	break;
case 2: deque();
	break;
case 3: display();
	break;
case 4: break;
default: printf("\n INVALID CHOICE!!!");
	break;
}
}
while(choice!=5);
return 0;
}
void enque() {
int num;
if(front==0 && rear==max-1){
printf("\n Queue is full!");
}
else{
printf("\n Enter the data to be inserted:");
scanf("%d",&num);
if (front==-1 && rear==-1){
front=rear=0;
queue[rear]=num;
}
else if(front!=0 && rear==max-1){
rear=0;
queue[rear]=num;}
else{
rear++;
queue[rear]=num;
}
}}
void deque(){
if(front==-1 && rear==-1){
printf("Queue is empty!!!");
}
else{
printf("\n the deleted element is %d",queue[front]);
if(front==rear){
front=rear=-1;
}
else if(front==max-1){
front=0;
}
else{
front++;
}}}
void display(){
int i;
if(front==-1 && rear==-1){
printf("\n Queue is empty!!!");
}
else
{
printf("\n the elements in the queue are:");
if(front<rear)
{
for(i=front;i<rear;i++){
printf("%d\t",queue[i]);
}}
else if(front>rear){
for(i=front;i<max;i++){
printf("%d\t",queue[i]);
}
for(i=0;i<=rear;i++){
printf("%d\t",queue[i]);
}}
else{
printf("%d\t",queue[front]);
}}}

