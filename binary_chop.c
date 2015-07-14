/**
 * a terse implementation of binary chop for searching ordered arrays
 */
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>


int find(int i, int arr[], int len) {
  int arr_cp[len], half_idx, j, k, range[2] = {0, len - 1};
  bool len_is_odd;

  while (len) {
    for (j=range[0], k=0; j<=range[1]; j++,k++) arr_cp[k] = arr[j];

    len_is_odd = len % 2 != 0;
    half_idx = (int)( (range[1] - range[0]) / 2 );
    len = (int)(len/2);

    if (arr_cp[half_idx] > i)
      range[1] -= ++half_idx; // if in first half, decrement upper bound
    else if (arr_cp[half_idx] < i)
      range[0] += ++half_idx; // if in second half, increment lower bound
    else if (arr_cp[half_idx] == i)
      return len_is_odd ? range[1] - half_idx : range[1] - half_idx - 1;
  }
  return -1;
}

// test
int main() {
  int arr[10] = {0,1,2,3,4,5,6,7,8,9};
  int len = sizeof(arr) / sizeof(int), idx, i;
  for (i=0; i<10; i++) {
    idx = find(i, arr, len);
    printf("query: %d\nresponse: %d\n\n", i, idx);
    assert(idx == i);
  }
}
