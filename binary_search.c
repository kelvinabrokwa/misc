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
