#include <stdio.h>

int Findpos (int *ptr, int low, int high, int i);
void selectsort (int *ptr, int low, int high);

int main()
{
  int i = 0;
  int a[] = {3,-1,2,-10,5,77,23,16,88,39};
  selectsort (a, 0 ,9);
  printf ("排序之后：\n");
  for (i = 0 ; i < 10 ; ++i)
    printf ("%d ",a[i]);
  printf ("\n");
  return 0;
}

int Findpos (int *ptr, int low, int high, int i)
{
  int j,pos;
  pos = i + low;
  // pos = low + i;//way 1
  for (j = i + low + 1; j <= high; ++j)
    {
      if (ptr[pos] > ptr[j])
      pos = j;
    }
  return pos;
}
void selectsort ( int *ptr, int low ,int high)
{
  int i ,pos;
  int temp ;
  int j = 0;
  for (i = low; i <= high; ++i)
    {
      // j = i - low ;//acoriding to way 1
      // pos = Findpos (ptr, low, high,j);
      pos = Findpos (ptr, i, high,j);
      if (pos != i)
        {
          temp = ptr[pos];
          ptr[pos] = ptr[i];
          ptr[i] = temp;
        }
    }
  return;
}
