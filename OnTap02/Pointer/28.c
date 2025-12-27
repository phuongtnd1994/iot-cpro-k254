#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *fn_create_node(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Thêm nút vào cuối danh sách liên kết
void fn_append(Node **head, int value)
{
    Node *newNode = fn_create_node(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// In danh sách liên kết
void fn_print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Giải phóng bộ nhớ danh sách liên kết
void fn_free_list(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    // 28 Triển khai linked list cơ bản bằng con trỏ.	Tạo struct Node, dùng con trỏ next.
    Node *head = NULL;

    fn_append(&head, 10);
    fn_append(&head, 20);
    fn_append(&head, 30);
    fn_append(&head, 40);

    printf("Danh sach lien ket don:\n");
    fn_print_list(head);

    fn_free_list(head);

    return 0;
}