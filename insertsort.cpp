/**
 * @file   insertsort.cpp
 * @brief  插入排序
 *
 * <long description>
 *
 * @author yex
 * @date   2017-03-18
 */
#include <stdio.h>

void insertsort (int *ptr , int low, int high);
int main ()
{
  int a[] = {2,-3,11,99,33,22,-23,88,66,-65};
  insertsort ( a ,0 , 9);
  printf ("排序后结果为：\n");
  for (int i = 0; i < 10; ++i)
      printf ("%d ", a[i]);
  printf ("\n");
  return 0;
}
void insertsort (int *ptr , int low ,int high) // ÉýÐòÅÅÁÐ
{
  if (low < high)
    {
      for ( int i = low +1  ; i <= high ; ++i)
        {
          int val = ptr[i];
          int j = i;
          while ( val < ptr[j - 1] && j > low)
            {
              ptr[j] =ptr[j - 1];
     //         ptr[j - 1] = val;
              j--;
            }
          ptr[j] = val;

        }
    }
}
