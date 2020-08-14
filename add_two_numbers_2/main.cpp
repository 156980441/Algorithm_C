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
int ListInsert(ListNode *head, int index, int data);
void reverseList(ListNode *head, ListNode **outputHead);

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
    ListNode *firstLast = l1 + sizeOfFirst;
    ListNode *secondLast = l2 + sizeOfSecond;
    int max = sizeOfFirst > sizeOfSecond ? sizeOfFirst : sizeOfSecond;
    ListNode **newHead;
    initList(newHead);
    bool carry = 0;
    for (int i = 0; i < max; i++)
    {
        int val = firstLast->val + secondLast->val;
        if (carry == 1) // 上一个存在进位
        {
            val = val + 1;
            carry = 0;
        }

        if (val > 10)
        {
            carry = 1;
            ListInsert(*newHead, i, val - 10);
        }
        else
        {
            ListInsert(*newHead, i, val);
        }
    }

    ListNode **outputHead;
    reverseList(*newHead, outputHead);
    return *outputHead;
}


void reverseList(ListNode *head, ListNode **outputHead)
{
    initList(outputHead);
    int size = ListLength(head);
    ListNode *p = head + size - 1;
    int index = 0;
    while (p >= head)
    {
        ListInsert(*outputHead, 0, p->val);
        index++;
    }
}

// 初始化
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
int ListInsert(ListNode *head, int index, int data)
{
    ListNode *p, *q;
    p = head;
    int j = -1;
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
    p = head;
    while (p->next != NULL)
    {
        if (p == head + index)
        {
            *data = p->val;
            return 1;
        }
        p++;
    }
    return 0;
}