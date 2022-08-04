#include <stdio.h>
#include <stdlib.h>

 struct list {
    int *arr;
    int size;
    struct list *next;
}node;


void print(node *head) {
    node *ptr = head->next;

    if (!ptr) {
        printf("-> Empty");
    }
    while (ptr) {
        printf("->|");
        for (int i = 0; i < ptr->size; ++i) {
            printf("%d", ptr->arr[i]);
            if (i != ptr->size - 1) {
                printf(" ");
            }
        }
        printf("| ");
        ptr = ptr->next;
    }
    printf("\n");
}

void insert(node *head, int *arr, int m) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->size = m;
    new_node->arr = (int *) malloc(sizeof(int) * m);
    new_node->next = NULL;
    for (int i = 0; i < m; ++i) {
        new_node->arr[i] = arr[i];
    }
    new_node->next = head->next;
    head->next = new_node;
}

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int start, int end) {
    int pivot = arr[end];
    int i = start;
    for (int j = start; j < end; ++j) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, end);
    return i;
}

void quick_sort(int *arr, int start, int end) {
    if (start < end) {
        int loc = partition(arr, start, end);
        quick_sort(arr, start, loc - 1);
        quick_sort(arr, loc + 1, end);
    }
}

void sort_item_in_nodes(node *head) {
    node *ptr = head->next;
    while (ptr) {
        quick_sort(ptr->arr, 0, ptr->size - 1);
        ptr = ptr->next;
    }
}

void sort_sll(node *head, int n) {
    node *qtr = head;
    int i = 0;
    while (i < n) {
        while (qtr->next->next) {

            if (qtr->next->arr[0] > qtr->next->next->arr[0]) {
                node *wtr = qtr->next;
                qtr->next = qtr->next->next;
                wtr->next = qtr->next->next;
                qtr->next->next = wtr;
            }
            qtr = qtr->next;
        }
        qtr = head;
        i++;
    }
}

int main() {
    int m, n, k, j, i;
    int *arr;
    node head;
    head.size = 0;
    head.next = NULL;
    head.arr = NULL;
    printf("Enter values for m and n: ");
    scanf("%d%d", &m, &n);
    arr = (int *) calloc(m, sizeof(int));
    i = 0;
    printf("Enter the elements: ");
    while (i < n) {
        k = n - i;
        if (m < k) {
            for (j = 0; j < m; ++j) {
                scanf("%d", arr + j);
                i++;
            }
              insert(&head, arr, m);
        } else {
            for (j = 0; j < k; ++j) {
                scanf("%d", arr + j);
                i++;
            }
              insert(&head, arr, k);
        }
    }
    sort_item_in_nodes(&head);
    sort_sll(&head, (n / m) + 1);
    return 0;
}