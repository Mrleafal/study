#include <stdio.h>
#include <malloc.h>

//hanshushengming
void Merge ( int *ptr, int *pval, int i, int m, int n);
int* MergeSort (int *ptr, int *pval, int low, int high);

int main ()
{
  int i;
  int a[10] = {9,2,-1,4,6,0,11,3,5,-32};
  int b[10];
  int *c = (int*) malloc (sizeof(int)*10);
  c = MergeSort (a, b, 0,9);
  printf ("After Sort:\n");
  for (i = 0; i < 10; ++i)
    printf ("%d ",c[i]);
  printf ("\n");
  // free(c);
  // c = NULL;
  return 0;
}
void Merge (int *ptr, int *pval, int i, int m, int n)
{
  int j, k;
  for (j = m + 1, k = i; i <= m && j <= n; ++k)
    {
      if (ptr[j] > ptr[i])
        {
          pval[k] = ptr[i];
          ++i;
        }
      else
        {
          pval[k] = ptr[j];
          j++;
        }
    }
  while (i <= m)
    {
      pval[k] = ptr[i];
      ++k;
      ++i;
    }
  while (j <= n)
    {
      pval[k] = ptr[j];
      ++k;
      ++j;
    }
}

int * MergeSort (int *ptr, int *pval, int low, int high)
{
  int len = 1;
  int length = high - low + 1;
  int * q = ptr;
  int *t ;
  // int *temp ;
  while (len < length)
    {
      int i = low;
      while ((i + 2 * len -1) <= high)
        {
          Merge (q, pval, i, i + len - 1, i + 2 * len - 1);
          i = i + 2 * len;
        }
      if ((i + len) <= high)
        Merge (q, pval, i, i + len - 1, high);
      len *= 2;
      t = q;
      q = pval;
      pval = t;
    }
  return q;
}
