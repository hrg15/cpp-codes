#include <iostream>
using namespace std;

const int MAXN = 1000; // حداکثر اندازه آرایه

// مرتب‌سازی حبابی برای ۵ عدد (چون تعدادش کم
// است)
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
}

// پیدا کردن kامین کوچکترین عنصر با الگوریتم Median of Medians
int selectKth(int arr[], int n, int k) {
  // اگر تعداد عناصر کم باشد، مستقیم مرتب کن و kامین را برگردان
  if (n <= 5) {
    bubbleSort(arr, n);
    return arr[k - 1];
  }

  // 1. تقسیم به گروه‌های ۵تایی
  int numGroups = (n + 4) / 5;
  int medians[MAXN / 5 + 5]; // مدیان‌های هر گروه

  for (int i = 0; i < numGroups; i++) {
    int group[5];
    int groupSize = 0;

    for (int j = 0; j < 5 && 5 * i + j < n; j++) {
      group[groupSize++] = arr[5 * i + j];
    }

    bubbleSort(group, groupSize);
    medians[i] = group[groupSize / 2];
  }

  // 2. پیدا کردن pivot با بازگشتی روی مدیان‌ها
  int pivot = selectKth(medians, numGroups, (numGroups + 1) / 2);

  // 3. تقسیم آرایه به سه قسمت: کوچکتر، مساوی، بزرگ‌تر از
  // pivot
  int L[MAXN], E[MAXN], G[MAXN];
  int l = 0, e = 0, g = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] < pivot)
      L[l++] = arr[i];
    else if (arr[i] == pivot)
      E[e++] = arr[i];
    else
      G[g++] = arr[i];
  }

  // 4. بازگشت روی بخش مناسب
  if (k <= l) {
    return selectKth(L, l, k);
  } else if (k <= l + e) {
    return pivot;
  } else {
    return selectKth(G, g, k - l - e);
  }
}

int main() {
  int arr[MAXN] = {12, 3, 5, 7, 4, 19, 26, 10, 1, 15, 8};
  int n = 11;
  int k = 4;

  int result = selectKth(arr, n, k);
  cout << k << "اُمین کوچک‌ترین عدد: " << result << endl;

  return 0;
}
