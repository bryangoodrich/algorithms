#include "Quicksort.h"

static unsigned part (void*, size_t, size_t, int (*) (const void*, const void*));
static void     swap (char*, char*, size_t);
static void     swap (unsigned&, unsigned&);



void Quicksort (void* base, size_t nelem, size_t width,
                int (*fcmp) (const void*, const void*))
{
    if (nelem <= 1) return;

    unsigned pivot = part(base, nelem, width, fcmp);
    Quicksort (base, pivot, width, fcmp);
    Quicksort (static_cast<char*>(base)+(pivot+1)*width,
               nelem-(pivot+1), width, fcmp);
}



static unsigned part (void* base, size_t nelem, size_t width,
                      int (*fcmp) (const void*, const void*)) {
    unsigned pivot = 0;
    unsigned    oe = nelem - 1;	
    
    while (pivot != oe) {
        if (pivot < oe) {
            if (fcmp (static_cast<char*>(base)+(pivot*width),
                      static_cast<char*>(base)+(oe*width)) >  0)
            {
                swap (static_cast<char*>(base)+(pivot*width),
                      static_cast<char*>(base)+(oe*width), width);
                swap (pivot, oe);
                oe++;
            } else oe--;
        } else {
            if (fcmp (static_cast<char*>(base)+(pivot*width),
                      static_cast<char*>(base)+(oe*width)) < 0)
            {
                swap (static_cast<char*>(base)+(pivot*width),
                      static_cast<char*>(base)+(oe*width), width);
                swap (pivot, oe);
                oe--;
            } else oe++;
        }
    }
    return pivot;
}


static void swap (char* A, char* B, size_t blocksize) {
    for (unsigned j=0; j < blocksize; j++) {
        char temp = A[j];
        A[j] = B[j];
        B[j] = temp;
    }
}

static void swap (unsigned& A, unsigned& B) {
    unsigned temp = A;
    A = B;
    B = temp;
}




