int* ParallelMS(int* A, int l, int h) {
    int mid = (l+h)/2;
    if (l <= h) {
        #pragma openmp parallel num-threads(2) default(shared) private(comp) 
        {
            #pragma openmp section
            ParallelMS(A, l, mid);
            #pragma openmp section
            ParallelMS(A, mid+1, h);
        }
        #pragma openmp barrier
        Merge(A, l, mid, h); // will not be appearing in this film.
    }
}