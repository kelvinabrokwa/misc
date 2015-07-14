#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

/**
 * find the index of an item in an array using binary chop
 */

int find(int i, int arr[], int len) {
  int arr_cp[len], half_idx, k, range[2] = {0, len - 1};
  bool len_is_odd;

  while (len > 2) {

    for (int j=range[0], k=0; j<=range[1]; j++,k++) { // update the array
      arr_cp[k] = arr[j];
    }

    len_is_odd = len % 2 != 0;
    half_idx = (int)( (range[1] - range[0]) / 2 ); // index of the last item of the first half
    len = (int)(len/2);

    if (arr_cp[half_idx] > i) { // in the first half
      range[1] -= (int)( (range[1] - range[0]) / 2 ) + 1; // decrease upper bound

    } else if (arr_cp[half_idx] < i) { // in the second half
      range[0] += (int)( (range[1] - range[0]) / 2 ) + 1; // increase lower bound

    } else if (arr_cp[half_idx] == i) {
      int loc = range[1] - (int)( (range[1] - range[0]) / 2 );
      if (!len_is_odd) loc -= 1;
      return loc;

    }
  }

  if (arr[range[0]] == i) return range[0];
  else if (arr[range[1]] == i) return range[1];
  else return -1;
}

// test
int main() {
  int arr[10] = {0,1,2,3,4,5,6,7,8,9};
  int len = sizeof(arr) / sizeof(int);
  int idx, i;
  for (i=0; i<10; i++) {
    idx = find(i, arr, len);
    printf("query: %d\nresponse: %d\n\n", i, idx);
    assert(idx == i);
  }
}
