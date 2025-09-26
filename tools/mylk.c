/*
 * =====================================================================================
 *
 *       Filename:  mylk.c
 *
 *    Description: i 
 *
 *        Version:  1.0
 *        Created:  08/28/25 11:27:33
 *
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "mylk.h"

pn creatNode(const int data){
    pn newNode = (pn)malloc(sizeof(node));
    if (newNode == NULL){
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

pn addNode(int data,pn p){
    pn newNode = (pn)malloc(sizeof(node));
    if (newNode == NULL){
    }
    newNode->data =data;
    p->next = newNode ;
    newNode->next = NULL;
    return newNode;
}

pn findNode(int data,pn p){
    pn tp = p;
    while(p->data != data){
        tp = tp->next;
    }
    return tp;
}














