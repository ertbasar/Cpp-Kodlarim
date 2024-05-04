/* Bu bölümü tekte incelemek daha iyi olur diye düşündüm
Programı yazarken kısa ve iyi tanımlanmış bölümler halinde yazmak, sık sık derlemek ve test etmek önemlidir.
Belli bir kod bölümünü yazdıktan sonra test eden bir kod parçası yazmak ve testten geçtiğinde o parçayı silmek iyi bir alışkanlık olabilir.
Ya da bu testleri bir fonksiyon içerisinde de yapıp sonrasında fonksiyonu silebilirsin. Hatta bu fonksiyon içinde koşul sorgularıyla test etmek de iyi olur.
std::cin içine gelen invalid inputun sıfırlanması:
/n görene kadar olan ve onu da silen bir komut -> std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
Ancak en iyi yöntem yine de input var mı diye bakmaktır. Burada da std::cin.peak() fonksiyonu işe yarar, inputtaki sonraki karakteri elimine etmeden görmemizi
sağlar. std::cin.fail() fonksiyonu extraction fail olduysa 1 döner, std::cin.clear() fonksiyonu ile de normale geri dönebiliriz.
*/