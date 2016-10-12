from math import *

def InsertionSort(A, n): #A is an array of size n
    for j in xrange(1,n): #starts at 1, ends at n-1 ( BECAUSE ARRAYS ARE 0 INDEX IN PYTHON )
        key = A[j] 
        #Insert A[j] into sorted sequence A[:j] ( A[:j] is every item up to but not including j )
        i = j
        while i>0 and A[i-1]>key:
            A[i] = A[i-1]
            i = i-1         
        A[i] = key
    return A

def binRep(n):
    if n == 1:
        return 1

    return 1 + binRep(floor(n/2))

#very psudo-y. Should be in-place sort, return nothing. Doesn't actually work that way in python, but whatever.
def MergeSort(A, l, r): #array, left, right
    if (l<r):
        mid = floor((l+r)/2)
        MergeSort(A, l, mid)
        MergeSort(A, mid+1, r)
        Merge(A,l,mid,r)