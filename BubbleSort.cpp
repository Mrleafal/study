#include <stdio.h>

void BubbleSort ( int *ptr, int low, int high);

int main ()
{
  int i;
  int a[] = {9,1,3,-9,11,17,8,-88,10,100};
  BubbleSort (a, 3, 7);
  printf ("排序后结果为：\n");
  for (i = 0; i < 10; i++)
    printf ("%d ", a[i]);
  printf ("\n");
  return 0;
}

void BubbleSort ( int *ptr, int low, int high)
{
  int i, j, temp;
  for (i = 0; i < high - low ; ++i)
    {
      for (j = low; j < high - i ; ++j)
        {
          if (ptr[j] > ptr[j + 1])
            {
              temp = ptr[j];
              ptr[j] = ptr[j + 1];
              ptr[j + 1] = temp;
            }
        }
    }
  return ;
}
