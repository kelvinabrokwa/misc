#include <stdlib.h>
#include <stdio.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node node;

node *front, *rear;

void Enqueue(int x) {
  node *temp = (node*)malloc(sizeof(node));
  temp->data = x;
  temp->next = NULL;
  if (front == NULL && rear == NULL) {
    front = rear = temp;
    return;
  }
  rear->next = temp;
  rear = temp;
}

void Dequeue() {
  node *temp = front;
  if (front == NULL) {
    printf("queue is empty");
    return;
  }
  if (front == rear) {
    front = rear = NULL;
  } else {
    front = front->next;
  }
  free(temp);
}
