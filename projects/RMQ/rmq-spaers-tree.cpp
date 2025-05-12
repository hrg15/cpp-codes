#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // آرایه ورودی
  int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  // محاسبه بیشترین توان ۲ مورد نیاز (log n)
  int log_n = log2(n) + 1;

  // ایجاد جدول پراکنده با ابعاد n × log n
  // ST[i][j] = کمترین مقدار در بازه [i, i+2^j-1]
  vector<vector<int>> ST(n, vector<int>(log_n));

  // مقداردهی اولیه برای زیربازه‌های با طول ۱
  for (int i = 0; i < n; i++) {
    ST[i][0] = arr[i];
  }

  // ساخت جدول پراکنده
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      // هر بازه به دو زیربازه با طول ۲^(j-1) تقسیم
      // می‌شود
      ST[i][j] = min(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
    }
  }

  // تابع پرسش RMQ برای بازه [L, R]
  auto query = [&](int L, int R) {
    // محاسبه بزرگترین توان ۲ که در بازه جا
    // می‌شود
    int k = log2(R - L + 1);

    // مقایسه دو زیربازه و برگرداندن کمترین مقدار
    return min(ST[L][k], ST[R - (1 << k) + 1][k]);
  };

  // تست پرسش‌ها
  cout << "Min in range [0, 4]: " << query(0, 4) << endl; // 1
  cout << "Min in range [2, 5]: " << query(2, 5) << endl; // 1
  cout << "Min in range [5, 7]: " << query(5, 7) << endl; // 2

  return 0;
}