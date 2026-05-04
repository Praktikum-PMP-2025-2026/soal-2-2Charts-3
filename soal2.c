/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2026/2027
 *  Modul               : 04 - Dynamic Structures
 *  Hari dan Tanggal    : Senin, 4 May 2026
 *  Nama (NIM)          : Arvin Fauzan Badri (13224072)
 *  Nama File           : soal2.c
 *  Deskripsi           : Soal 2. Input 2 linked list terurut menaik, 
 *                        gabungkan & output terurut menaik juga
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct PQ_Node {
    int num;
    struct PQ_Node *next;
} PQ_Node;

/** 
 * PRIORITY QUEUE
 * 
 * head -> pop (belakang)
 * tail -> push  (depan)
 * 
 * terjamin terurut menaik dari head (belakang) ke tail (depan)
 */
typedef struct Priority_Queue {
    PQ_Node *head;
    PQ_Node *tail;
} Priority_Queue;

void pq_push(Priority_Queue* pq, int num) {
    PQ_Node *new_node = malloc(sizeof *new_node);
    new_node->num = num;
    new_node->next = NULL;

    if(pq->head == NULL && pq->tail == NULL) {
        pq->head = new_node;
        pq->tail = new_node;
        return;
    }

    if(pq->head != NULL && pq->tail != NULL) {
        for(PQ_Node *curr = pq->head, *prev = NULL; 
            curr != NULL;
            prev = curr, curr = curr->next) {
            
            if(num < curr->num) {
                if(prev == NULL) { // didepan
                    new_node->next = curr;
                    pq->head = new_node;
                    return;
                }
                else { // ditengah
                    prev->next = new_node;
                    new_node->next = curr;
                    return;
                }
            }
        }
        // disini belum return, artinya harus diinsert pada tail (depan)
        pq->tail->next = new_node;
        pq->tail = new_node;
    }
}

void pq_pop(Priority_Queue *pq, int *out, int *success) {
    if(pq->head == NULL) {
        *success = 0;
    }
    else {
        *success = 1;
        *out = pq->head->num;
        PQ_Node *old = pq->head;
        pq->head = old->next;
        if(pq->head == NULL) {
            pq->tail = NULL;
        }
        free(old);
    }
}

int main(void) {
    Priority_Queue pq = {0};
    int count = 0;

    for(int i = 0; i < 2; ++ i) {
        scanf("%d", &count);
        int num;
        for(int i = 0; i < count; ++i) {
            scanf("%d", &num);
            pq_push(&pq, num);
        }
    }

   if(pq.head == NULL && pq.tail == NULL) {
        printf("MERGED EMPTY\n");
        return 0;
    }
    
    printf("MERGED");

    int success = 0;
    int out = 0;
    while(1) {
        pq_pop(&pq, &out, &success);
        if(success == 0) {
            break;
        }
        printf(" %d", out);
    }
    printf("\n");
    
    return 0;
}

// debug tahap 2
// int main(void) {
//     Priority_Queue pq = {0};
//     int count = 0;

//     for(int i = 0; i < 2; ++ i) {
//         scanf("%d", &count);
//         int num;
//         for(int i = 0; i < count; ++i) {
//             scanf("%d", &num);
//             pq_push(&pq, num);
//         }
//     }

//     int success = 0;
//     int out = 0;
//     while(1) {
//         pq_pop(&pq, &out, &success);
//         if(success == 0) {
//             break;
//         }
//         printf("%d\n", out);
//     }
    
//     return 0;
// }

// debug tahap 1
// int main(void) {
//     Priority_Queue pq = {0};

//     pq_push(&pq, 2);
//     pq_push(&pq, 1);
//     pq_push(&pq, 3);
//     pq_push(&pq, 4);
//     pq_push(&pq, 6);
//     pq_push(&pq, 5);

//     // for(PQ_Node *tmp =  pq.head; tmp != NULL; tmp = tmp->next) {
//     //     printf("%d\n", tmp->num);
//     // }

//     int success = 0;
//     int out = 0;
//     while(1) {
//         pq_pop(&pq, &out, &success);
//         if(success == 0) {
//             break;
//         }
//         printf("%d\n", out);
//     }
    
//     return 0;
// }

