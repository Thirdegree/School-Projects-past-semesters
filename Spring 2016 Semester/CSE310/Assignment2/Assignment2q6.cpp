#include <iostream>
#include <stdlib.h>
#include <stdio.h>

bool isHeap(int *h, int n, int compIndex) {
    int lLeaf = compIndex*2;
    int rLeaf = lLeaf + 2;
    if (lLeaf>n) {
        return true; // a leaf is a heap.
    }
    if (rLeaf>n) { // if there is only one leaf
        if (h[rLeaf-1] <= h[compIndex-1]) { // and that leaf is smaller than the current node
            return isHeap(h, n, lLeaf); // then check if that leaf is a heap.
        } else {
            return false; // Otherwise, false.
        }
    }
    if(h[lLeaf-1] <= h[compIndex-1] && h[rLeaf-1] <= h[compIndex-1]) { // if both leafs are smaller than the current node
        return isHeap(h, n, lLeaf) && isHeap(h, n, rLeaf); // check if both leafs are heaps
    } else {
        return false; // otherwise, false.
    }
}

int main() {
    int testArrayTrue[] = {16,14,10,8,7,9,3,2,4,1};
    int testArrayFalse[] = {16,10,15,14,7,9,3,2,8,1};

    if (isHeap(testArrayTrue, 10, 1)) {
        printf("First array is a heap!\n");
    } else {
        printf("First array is not a heap!\n");
    }

    if (isHeap(testArrayFalse, 10, 1)) {
        printf("Second array is a heap!\n");
    } else {
        printf("Second array is not a heap!\n");
    }

    //Can't believe this worked on the first compile perfectly. 
}