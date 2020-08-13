#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

#define ListNode struct ListNode

int ListLength(ListNode *head);

int main()
{
    printf("hello\n");
    printf("world");
    return 1;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int sizeOfFirst = ListLength(l1);
    int sizeOfSecond = ListLength(l2);
    return NULL;
}

ListNode *initList (ListNode **head) 
{
    *head = (ListNode *)malloc(sizeof(ListNode));
    (*head)->next = NULL;
}

// 求长度
int ListLength(ListNode *head)
{
    ListNode *p = head;
    int size = 0;
    while (p->next != NULL)
    {
        p = p->next;
        size ++;
    }
    
    return size;
}