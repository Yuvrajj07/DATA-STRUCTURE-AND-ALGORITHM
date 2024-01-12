#include <stdio.h>

#define MAX_SIZE 100

struct PriorityQueue {
    int arr[MAX_SIZE];
    int size;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(struct PriorityQueue *pq, int index) {
    int left = 2 * index;
    int right = 2 * index + 1;
    int largest = index;

    if (left <= pq->size && pq->arr[left] > pq->arr[largest]) {
        largest = left;
    }

    if (right <= pq->size && pq->arr[right] > pq->arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(&pq->arr[index], &pq->arr[largest]);
        maxHeapify(pq, largest);
    }
}

void buildMaxHeap(struct PriorityQueue *pq) {
    for (int i = pq->size / 2; i >= 1; i--) {
        maxHeapify(pq, i);
    }
}

void insert(struct PriorityQueue *pq, int val) {
    if (pq->size == MAX_SIZE - 1) {
        printf("Priority Queue is full. Cannot insert %d\n", val);
        return;
    }

    pq->size++;
    int index = pq->size;
    pq->arr[index] = val;

    while (index > 1 && pq->arr[index / 2] < pq->arr[index]) {
        swap(&pq->arr[index / 2], &pq->arr[index]);
        index = index / 2;
    }
}

int extractMax(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return -1; // Assuming -1 is not a valid value in the priority queue
    }

    int maxVal = pq->arr[1];
    pq->arr[1] = pq->arr[pq->size];
    pq->size--;

    maxHeapify(pq, 1);

    return maxVal;
}

void print(struct PriorityQueue *pq) {
    printf("Priority Queue: ");
    for (int i = 1; i <= pq->size; i++) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    pq.size = 0;

    insert(&pq, 45);
    insert(&pq, 50);
    insert(&pq, 30);
    insert(&pq, 20);

    print(&pq);

    int maxVal = extractMax(&pq);
    printf("Extracted Max Value: %d\n", maxVal);

    print(&pq);

    return 0;
}
