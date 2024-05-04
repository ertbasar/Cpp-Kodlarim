/* Bu bölümü tekte incelemek daha iyi olur diye düşündüm
Programı yazarken kısa ve iyi tanımlanmış bölümler halinde yazmak, sık sık derlemek ve test etmek önemlidir.
Belli bir kod bölümünü yazdıktan sonra test eden bir kod parçası yazmak ve testten geçtiğinde o parçayı silmek iyi bir alışkanlık olabilir.
Ya da bu testleri bir fonksiyon içerisinde de yapıp sonrasında fonksiyonu silebilirsin. Hatta bu fonksiyon içinde koşul sorgularıyla test etmek de iyi olur.
std::cin içine gelen invalid inputun sıfırlanması:
/n görene kadar olan ve onu da silen bir komut -> std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
Ancak en iyi yöntem yine de input var mı diye bakmaktır. Burada da std::cin.peak() fonksiyonu işe yarar, inputtaki sonraki karakteri elimine etmeden görmemizi
sağlar. std::cin.fail() fonksiyonu extraction fail olduysa 1 döner, std::cin.clear() fonksiyonu ile de normale geri dönebiliriz.
std::cerr outputa hata mesajı yazdırmak için kullanılabilecek bir fonksiyon

assert bir ifadenin bug olmadığı durumda true olması halidir. Eğer false olursa da std::abort eder.
static_assert olarak kullanılırsa compile-time'da değerlendirilir ancak değerlendirilecek bu durumda koşul da constant expression olmalı

Aşağıda komple olarak LearnCPP'den ve Gemini'dan kopyaladığım bir fonksiyon olacak
*/
#include <iostream>
#include <cassert>
int getGuess(int count) {
  while (true) {
    std::cout << "Guess #" << count << ": ";

    int guess;
    std::cin >> guess;

    // Check for failed extraction and handle it
    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Error: Invalid input. Please enter a number." << std::endl;
      continue;
    }

    // Assert that the guess is within valid range (1-100)
    assert(guess >= 1 && guess <= 100);

    // Clear any remaining input and return the guess
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return guess;
  }
}

int main() {
  int guess;
  for (int count = 1; count <= 3; count++) {
    guess = getGuess(count);
    // You can now process the valid guess here
    std::cout << "Your guess: " << guess << std::endl;
  }
  return 0;
}
