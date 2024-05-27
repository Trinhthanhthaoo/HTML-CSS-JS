#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
int a[N], n = 10000;

void Inp()
{
    for (int i = 1; i <= n; i++) a[i] = rand() % 10000 + 1;
}

void Out()
{
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
}

void insertionSort()
{
    for (int i = 2; i <= n; i++) {
        int j = i;
        while (j > 0 && a[i] < a[j - 1]) 
            --j;
        int tmp = a[i];
        for (int k = i; k > j; k--)
            a[k] = a[k-1];
        a[j] = tmp;
    }
}

void selectionSort(){
    int i, j, min, temp;
    for (i = 1; i <= n - 1; i++) {
        min = i; 
        for (j = i + 1; j < n; j++){
            if (a[j] < a[min]) min = j;
        }
        swap(a[i], a[min]);
    }
}

void bubbleSort() {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++){
            if (a[j-1] > a[j])
                swap(a[j-1],a[j]);
        }
    }
} 

void quickSort(int left, int right) {
	int i = left, j = right;
	int pivot = a[left + rand() % (right - left)];
	while (i <= j) {
		while (a[i] < pivot) ++i;
		while (a[j] > pivot) --j;

		if (i <= j) {
			swap(a[i], a[j]);
			++i;
			--j;
		}
	}
	// G?i d? quy d? s?p x?p các n?a
	if (left < j) quickSort(left, j);
	if (i < right) quickSort(i, right);
}

void merge(int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++)
    L[i] = a[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = a[q + 1 + j];
  int i, j, k;
  i = 0; j = 0; k = p;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      a[k] = L[i]; i++;
    } else {
      a[k] = M[j]; j++;
    }
    k++;
  }
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    a[k] = M[j];
    j++;
    k++;
  }
}


void mergeSort(int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(l, m);
    mergeSort(m + 1, r);
    merge(l, m, r);
  }
}

int LinearSearch(int num)
{
    cout << "Position: ";
    for (int i = 1; i <= n; i++) {
        if (num == a[i]) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int target) {
    sort(a + 1, a + n + 1);
    Out();
    cout << "Position: ";
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (a[mid] == target)
            return mid;       	
        else if (a[mid] < target)
            lo = mid+1;
        else
            hi = mid-1;
    }
    return -1;
}  

int main()
{
    Inp();
    Out();
    int x = 3;
    cout << BinarySearch(x);
    return 0;
}
