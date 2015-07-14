#include <stdio.h>
#include <assert.h>
#include "../binary_search.c"

int main() {
  int arr[10] = {0,1,2,3,4,5,6,7,8,9};
  int len = sizeof(arr) / sizeof(int), idx, i;
  for (i=0; i<10; i++) {
    idx = search(i, arr, len);
    printf("query: %d\nresponse: %d\n\n", i, idx);
    assert(idx == i);
  }
}
