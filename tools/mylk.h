#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
typedef struct Node* pn;

struct Node{
    int data;
    pn next;
};

pn createNode(int data);
pn addNode(int data,pn p);
pn findNode(int data,pn p);
int isEmpty(pn p){return p->next == NULL;}
