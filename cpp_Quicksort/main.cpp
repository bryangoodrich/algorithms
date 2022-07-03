#include <iostream>
#include <iomanip>
using namespace std;

#include "Quicksort.h"



bool REV      = 0;
bool TESTMAIN = 0;

int fcmp1(const void*, const void* );
int fcmp2(const void*, const void* );
int fcmp3(const void*, const void* );
int fcmp4(const void*, const void* );

const unsigned MAX = 10;

unsigned u[MAX];
int      s[MAX];
double   d[MAX];
char     c[MAX];



int main() {
  for (unsigned i=0; i<MAX; i++) {
    u[i] = unsigned(rand()) * rand() %MAX*2;
    d[i] = u[i];
    d[i] += 1.0 / (rand() % 1000 + 1);
    s[i] = u[i];
    c[i] = u[i] % 256;
    if (rand() % 2) {
      d[i] *= -1;
      s[i] *= -1;
      c[i] *= -1;
    }
  }

  if (TESTMAIN) qsort(u,MAX,sizeof(unsigned),fcmp1);
  else Quicksort(u,MAX,sizeof(unsigned),fcmp1);


  {
    unsigned firstu = u[0];
    for ( unsigned i=1; i<MAX; i++ ) {
      unsigned second = u[i];
      if ((!REV && firstu > second) || (REV && firstu < second))
        cout << "error #1 "<< firstu << "  " << second << endl;
      firstu = second;
    }
  }
  cout << endl << "done 1" << endl << endl;

  if ( TESTMAIN ) qsort(d,MAX,sizeof(double),fcmp2);
  else Quicksort(d,MAX,sizeof(double),fcmp2);

  {
    double firstd = d[0];
    for (unsigned i=1; i<MAX; i++) {
      double second = d[i];
      if ((!REV && firstd > second) || (REV && firstd < second))
        cout << setprecision(15) << "error #2 " << firstd << "  " << second << endl;
      firstd = second;
    }
  }
  cout << endl << "done 2" << endl << endl;

  if ( TESTMAIN ) qsort(s,MAX,sizeof(int),fcmp3);
  else Quicksort(s,MAX,sizeof(int),fcmp3);

  {
    int firsts = s[0];
    for (unsigned i=1; i<MAX; i++) {
      int second = s[i];
       if ((!REV && firsts > second) || (REV && firsts < second))
        cout << "error #3 "<<firsts << "  " << second <<endl;
      firsts = second;
    }
  }
  cout <<endl<< "done 3"<<endl<<endl;

  if (TESTMAIN) qsort(c,MAX,sizeof(char),fcmp4);
  else Quicksort(c,MAX,sizeof(char),fcmp4);

  {
    char firstc = c[0];
    for (unsigned i=1; i<MAX; i++) {
      char second = c[i];
       if ((!REV && firstc > second) || (REV && firstc < second))
        cout << "error #4 "<< int(firstc) << "  " << int(second) <<endl;
      firstc = second;
    }
  }
  cout <<endl<< "done 4"<<endl;

  return 0;
}



int fcmp1(const void* v1, const void* v2 ) {
  return int(*reinterpret_cast<const unsigned*>(v1)) -
         int(*reinterpret_cast<const unsigned*>(v2));
}

int fcmp2(const void* v1, const void* v2 ) {
  if (*reinterpret_cast<const double*>(v1) >
         *reinterpret_cast<const double*>(v2))
    return 1;

  if (*reinterpret_cast<const double*>(v1) <
         *reinterpret_cast<const double*>(v2))
    return -1;

  return 0;
}

int fcmp3(const void* v1, const void* v2 ) {
  return int(*reinterpret_cast<const int*>(v1)) -
         int(*reinterpret_cast<const int*>(v2));
}

int fcmp4(const void* v1, const void* v2 ) {
 return int(*reinterpret_cast<const char*>(v1)) -
         int(*reinterpret_cast<const char*>(v2));
}

