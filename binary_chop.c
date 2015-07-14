#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

/**
 * find the index of an item in an array using binary chop
 */

bool is_odd(int i) { return i % 2 != 0; }

int find(int i, int arr[], int len) {
  int arr_cp[len], half_idx, new_len, k;
  bool len_is_odd;
  int range[2] = {0, len - 1};

  while (len > 2) {

    k = 0;
    for (int j=range[0]; j<=range[1]; j++,k++) { // update the array
      arr_cp[k] = arr[j];
    }

    len_is_odd = is_odd(len);
    half_idx = (int)( (range[1] - range[0]) / 2); // index of the last item of the first half
    len = (int)(len/2);

    if (arr_cp[half_idx] > i) { // in the first half
      // decrease upper bound
      range[1] -= (int)( (range[1] - range[0]) / 2 ) + 1;

    } else if (arr_cp[half_idx] < i) { // in the second half
      // increase lower bound
      range[0] += (int)( (range[1] - range[0]) / 2 ) + 1;

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
