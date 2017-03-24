#include <stdio.h>
// 函数声明
void ShellInsert (int * ptr, int low ,int high ,int step);
void ShellSort(int * ptr, int low ,int high);
int main ()
{
  int a[] = {-99,1,66,8,0,6,9,4,5,10};
  int i;
  ShellSort (a, 0, 9);
  printf ("排序后结果为：\n");
  for (i = 0 ; i < 10 ; ++i)
    printf("%d ",a[i]);
  printf ("\n");
  return 0;
}
void ShellInsert (int * ptr , int low, int high , int step)
{
  int i = 0;
  int j = 0;
  int val = 0;
  for (i = low + step;i <= high ; i++)
    {
      j = i;
      val = ptr[i];
      while (val < ptr[j - step] && j >= low + step)
        {
          ptr[j] = ptr[j- step];
          j -= step;
        }
      ptr[j] = val;
    }
  return;
}
void ShellSort (int *ptr , int low , int high)
{
  int length = (high - low) + 1;
  int step = 0;
  for ( step = length/2 ; step >= 1 ; step = step/2)
      ShellInsert (ptr , low , high, step);
  return ;
}
