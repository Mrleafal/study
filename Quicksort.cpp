#include <stdio.h>

void Quicksort (int * ptr,int low,int high);
int Findpos (int *ptr ,int low, int high,int val);

int main ()
{
  int i = 0;
  int a[]={2,-3,4,5,-12,6,7};
  Quicksort (a,0,6);
  for (i = 0 ; i < 7 ; ++i)
    {
      printf ("%d ",a[i]);
    }
  return 0;
}

void Quicksort (int * ptr,int low ,int high)
{
  if(low < high)
    {
      int pos ;
      int val = ptr[low];
      pos = Findpos (ptr,low,high,val);
      Quicksort(ptr,low,pos - 1);
      Quicksort(ptr,pos + 1,high);
    }
}
int Findpos (int* ptr ,int low ,int high,int val)
{
  while (low < high)
    {
      while (low < high && ptr[high] >= val)
        high--;
      ptr[low] = ptr[high];
      while(low < high && ptr[low] <= val)
        low++;
      ptr[high] = ptr[low];
    }
  ptr[high] = val;
  return high;
}
