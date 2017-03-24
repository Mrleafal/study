#include <stdio.h>

void HeapAdjust (int *ptr, int pos, int low, int high);
void CreateHeap (int *ptr, int low, int high);
void HeapSort (int *ptr, int low, int high);

int main ()
{
  int i;
  int a[] = {10,26,11,-9,3,78,43,12,0,8};
  HeapSort (a , 0 ,9);
  printf ("排序后结果为：\n");
  for (i = 0; i < 10; ++i)
    printf ("%d ",a[i]);
  printf ("\n");
  return 0;
}
void HeapAdjust (int *ptr, int pos, int low, int high)
{
  int temp;
  int child = 2*pos + 1 + low;
  while (child <= high)
    {
      if ( child < high && ptr[child] < ptr[child + 1])
        {
          ++child;
        }
      if (ptr[child] > ptr[pos + low])
        {
          temp = ptr[pos + low];
          ptr[pos + low] = ptr[child];
          pos = child - low;
          child = 2 * pos + 1 + low;
        }
      else
        break;
      ptr[pos + low] = temp;
    }
}
void CreateHeap( int *ptr, int low, int high)
{
  int i;
  int length = high - low ;
  for (i = length/2; i >= 0; --i)
    {
      HeapAdjust (ptr, i ,low,high);
    }
}

void HeapSort( int *ptr, int low, int high)
{
  CreateHeap (ptr, low, high);
  for (int i = high; i > low; --i)
    {
      int temp = ptr[i];
      ptr[i] = ptr[low];
      ptr[low] = temp;
      HeapAdjust (ptr,0,low,i-1);
    }
}
