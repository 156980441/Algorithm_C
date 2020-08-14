#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

#define ListNode struct ListNode

int ListLength(ListNode *head);
void initList(ListNode **head);
int insertList(ListNode *head, int index, int data);
void reverseList(ListNode *head, ListNode **outputHead);
int ListGet(ListNode *head, int index, int *data);
void printList(ListNode *l);

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

int main()
{
    ListNode *l1, *l2;
    int data, size;
    initList(&l1);
    insertList(l1, 0, 7);
    insertList(l1, 1, 2);
    insertList(l1, 2, 4);
    insertList(l1, 3, 3);
    printf("list 1:");
    size = ListLength(l1);
    printList(l1);

    printf("list 2:");
    initList(&l2);
    insertList(l2, 0, 5);
    insertList(l2, 1, 6);
    insertList(l2, 2, 4);
    printList(l2);

    ListNode *result = addTwoNumbers(l1, l2);
    return 1;
}

void printList(ListNode *l)
{
    int data;
    for (int i = 0; i < ListLength(l); i++)
    {
        ListGet(l, i, &data);
        printf("%d->", data);
    }
    printf("\n");
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int sizeOfFirst = ListLength(l1);
    int sizeOfSecond = ListLength(l2);
    ListNode *firstLast = l1 + sizeOfFirst;
    ListNode *secondLast = l2 + sizeOfSecond;
    int max = sizeOfFirst > sizeOfSecond ? sizeOfFirst : sizeOfSecond;
    ListNode *newHead;
    initList(&newHead);
    bool carry = 0; // 进位标记，0没有进位
    for (int i = 0; i < max; i++)
    {
        int val = -1;
        if (firstLast != NULL)
        {
            if (val == -1)
            {
                val = 0;
            }
            val = firstLast->val + val;
        }
        if (secondLast != NULL) {
            if (val == -1)
            {
                val = 0;
            }
            val = secondLast->val + val;
        }
        if (carry == 1) // 上一个存在进位
        {
            val = val + 1;
            carry = 0;
        }

        if (val >= 10)
        {
            carry = 1;
            insertList(newHead, i, val - 10);
        }
        else
        {
            insertList(newHead, i, val);
        }

        if (firstLast != l1)
        {
            firstLast--;
        }
        else 
        {
            firstLast = NULL;
        }
        if (secondLast != l2)
        {
            secondLast--;
        }
        else 
        {
            secondLast = NULL;
        }
    }

    printList(newHead);

    ListNode *outputHead;
    reverseList(newHead, &outputHead);
    printList(outputHead);
    return outputHead;
}

void reverseList(ListNode *head, ListNode **outputHead)
{
    initList(outputHead);
    int size = ListLength(head);
    ListNode *p = head + size - 1;
    int index = 0;
    while (p >= head)
    {
        insertList(*outputHead, 0, p->val);
        index++;
    }
}

// 初始化，头结点不存储数据
void initList(ListNode **head)
{
    *head = (ListNode *)malloc(sizeof(ListNode));
    (*head)->next = NULL;
}

// 销毁
void destroy(ListNode **head)
{
    ListNode *p, *p1;
    p = *head;
    while (p != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
    *head = NULL;
}

// 求长度
int ListLength(ListNode *head)
{
    ListNode *p = head;
    int size = 0;
    while (p->next != NULL)
    {
        p = p->next;
        size++;
    }

    return size;
}

// 插入
int insertList(ListNode *head, int index, int data)
{
    ListNode *p, *q;
    int j;
    p = head;
    j = -1;
    while (p->next != NULL && j < index - 1)
    {
        p = p->next;
        j++;
    }
    if (j != index - 1)
        return 0;

    q = (ListNode *)malloc(sizeof(ListNode));
    q->val = data;
    q->next = p->next;
    p->next = q;
    return 1;
}

// 取数据元素
int ListGet(ListNode *head, int index, int *data)
{
    ListNode *p;
    int j;
    p = head->next;
    while (p != NULL)
    {
        if (p == head->next + index)
        {
            *data = p->val;
            return 1;
        }
        p++;
    }
    return 0;
}