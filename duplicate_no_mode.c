#include <stdio.h>

int main() {
  int arr[25], freq[25], i, j, count, max_freq, mode;

  printf("Enter 25 integers: ");
  for(i = 0; i < 25; i++) {
    scanf("%d", &arr[i]);
    freq[i] = -1;
  }

  for(i = 0; i < 25; i++) {
    count = 1;
    for(j = i+1; j < 25; j++) {
      if(arr[i] == arr[j]) {
        count++;
        freq[j] = 0;
      }
    }
    if(freq[i] != 0) {
      freq[i] = count;
    }
  }

  int num_duplicates = 0;
  for(i = 0; i < 25; i++) {
    if(freq[i] > 1) {
      num_duplicates++;
    }
  }
  printf("Number of duplicate elements: %d\n", num_duplicates);

  max_freq = 0;
  for(i = 0; i < 25; i++) {
    if(freq[i] > max_freq) {
      max_freq = freq[i];
      mode = arr[i];
    }
  }
  printf("Mode of the array: %d\n", mode);

  return 0;
}
