#include <stdio.h>

void bselectsort (int *ptr, int low, int high);

int main ()
{
  int i;
  int a[] = {-99,1,66,8,0,6,9,4,5,10};
  bselectsort (a, 5, 9);
  printf("排序好的结果为：\n");
  for (i = 0; i < 10; ++i)
    printf ("%d ",a[i]);
  printf ("\n");
  return 0;
}
void bselectsort ( int *ptr, int low, int high)
{
  int i, j, min, max, temp;
  int length = high - low + 1;
  for ( i = low; i < low + length/2; ++i)
    {
      min = i;
      max = i;
      for (j = i + 1; j <= low + high - i; ++j)
        {
          if (ptr[j] > ptr[max])
            max = j;
          else
            {
              if (ptr[j] < ptr[min])
                min = j;
            }
        }
      if ( max == i)
        {
          if (min == low + high - i)
            {
              temp = ptr[i];
              ptr[i] = ptr[min];
              ptr[low + high - i] = temp;
            }
          else
            {
              temp = ptr[low + high - i];
              ptr[low + high - i] = ptr[max];
              ptr[max] = temp;

              temp = ptr[i];
              ptr[i] = ptr[min];
              ptr[min] = temp;
            }
        }
      else
        {
          temp = ptr[i];
          ptr[i] = ptr[min];
          ptr[min] = temp;
          temp = ptr[low + high - i];
          ptr[low + high - i] = ptr[max];
          ptr[max] = temp;
        }
    }
  return;
}
