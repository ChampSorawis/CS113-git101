//6210451551 Sorawis Chitranon
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct Node {
    int i;
    struct Node *n;
};

void homework(struct Node **m, struct Node *nn) {
    struct Node *x;
    if (*m == NULL || (*m)->i >= nn->i) {
        nn->n = *m;
        *m = nn;
    } else {
        x = *m;
        while (x->n != NULL && x->n->i < nn->i) {
            x = x->n;
        }
        nn->n = x->n;
        x->n = nn;
    }
}

int main() {
    struct Node *y = NULL;
    struct Node *new = NULL;
    int z;

    while (1) {
        scanf("%d", &z);
        if (z==-1){
          break;
        }
        else{
          struct Node *new = (struct Node *)malloc(sizeof(struct Node));

          new->i = z;
          new->n = NULL;

          homework(&y, new);
        }
    }
    for(;y; y = y->n){
        printf("%d\n", y->i);
    }
}