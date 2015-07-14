/**
 * a clean implementation of binary search for searching ordered arrays
 */

int search(int i, int arr[], int len) {
  int min=0, max=len-1, mid;
  while (len) {
    mid = (int)((max + min) / 2);
    len = (int)(len/2);
    if (arr[mid] > i) max = --mid; // if in first half, decrement upper bound
    else if (arr[mid] < i) min = ++mid; // if in second half, increment lower bound
    else if (arr[mid] == i) return mid;
  }
  return -1;
}


//test
#include <stdio.h>
#include <assert.h>

int main() {
  int arr[10] = {0,1,2,3,4,5,6,7,8,9};
  int len = sizeof(arr) / sizeof(int), idx, i;
  for (i=0; i<10; i++) {
    idx = search(i, arr, len);
    printf("query: %d\nresponse: %d\n\n", i, idx);
    assert(idx == i);
  }
}
