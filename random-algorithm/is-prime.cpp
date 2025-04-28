#include <iostream>
using namespace std;

bool isPrime(int n) {
  int i = 3;
  if (n == 2) {
    return true;
  }
  if (n % 2 == 0) {
    return false;
  }
  while (i * i <= n) {
    if (n % i == 0) {
      return false;
    } else {
      i += 2;
    }
  }
  return true;
}

int main() {
  int n = 10;
  bool result = isPrime(n);
  if (result) {
    cout << n << " is prime" << endl;
  } else {
    cout << n << " is not prime" << endl;
  }
  return 0;
}
