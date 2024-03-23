// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
  int low = 0;
  int high = size - 1;
  int n = 0;
  while (low <= high) {
    int mid = low + ((high - low) / 2);
    if (arr[mid] == value) {
      n = 1;
      int net = mid + 1;
      while ((net < size) && (arr[net] == value)) {
        net++;
        n++;
      }
      net = mid - 1;
      while ((net >= 0) && (arr[net] == value)) {
        net--;
        n++;
      }
      return n;
    } else if (arr[mid] < value) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return 0;
}

int countPairs1(int *arr, int len, int value) {
  int n = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        n++;
      }
    }
  }
  return n;
}

int countPairs2(int *arr, int len, int value) {
  int n = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if ((arr[i] + arr[j]) == value) {
        n++;
        if ((arr[i] + arr[j - 1]) != value) break;
      }
    }
  }
  return n;
}

int countPairs3(int *arr, int len, int value) {
  int n = 0;
  for (int i = 0; i < len - 1; i++) {
    if (arr[i] <= value) {
      n += cbinsearch(arr + i + 1, len - i, value - arr[i]);
    }
  }
  return n;
}
