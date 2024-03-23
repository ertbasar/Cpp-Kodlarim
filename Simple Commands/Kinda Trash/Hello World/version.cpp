#include <iostream>

int main() {
  int x{4};
  int y{x};
  std::cout << "C++ derleyici versiyonu: " << __cplusplus << std::endl;
  std::cout << y << std::endl;
  return 0;
}
