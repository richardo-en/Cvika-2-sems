#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char c;
    struct node *next;
}NODE;


// void prehod(void **p1, void **p2, void *x, void *y){
//     *p1 = y;
//     *p2 = x;
// }

void otoc_skupinu(NODE *head, int k){
    NODE *curr = head;
    char h = 'A';
    for (int i = 0; i < 7; i++)
    {
        curr->c = (h+i);
        if (i != 6)
        {
            curr->next = (NODE*)malloc(sizeof(NODE));
            curr = curr->next;
        }else{
            curr->next = NULL;
        }
    }
    NODE *prev = NULL;
    curr = head;
    NODE *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    /*changeing order base on K argument*/


    curr = prev;
    NODE *temp = prev;
    NODE *previous = NULL;
    for (int i = 0; i < k-1; i++)
    {
        if (i == k-2)
        {
            previous = temp;
        }
        temp = temp->next;
    }
    previous->next = NULL;
    head = temp;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = curr;
    
    /*print otu*/

    curr = head;
    while (curr != NULL)
    {
        printf("%c->" , curr->c);
        curr = curr->next;
    }
}

int main(int argc, char const *argv[])
{
    NODE *head = (NODE*)malloc(sizeof(NODE));

    // float f1=1.1, f2=1.2, *uf1 = &f1, *uf2 = &f2;
    // char ch1 = 'c', ch2 = 'f', *uch1 = &ch1, *uch2 = &ch2;
    // prehod((void **)&uf1, (void **)&uf2 , (void *)&f1, (void *)&f2);
    // prehod((void **)&uch1, (void **)&uch2 , (void *)&ch1, (void *)&ch2);
    otoc_skupinu(head , 4);
    return 0;
}