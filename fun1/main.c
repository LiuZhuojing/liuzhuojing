#include"uhead.h"
int main()
{
  int a[UNUMBER] = {};
  urand(a,UNUMBER);
  bubbleSort(a,UNUMBER);
  show(a,UNUMBER);
  return 0;
}   
