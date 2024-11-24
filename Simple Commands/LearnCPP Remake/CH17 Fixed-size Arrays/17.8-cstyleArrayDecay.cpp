/* Çoğu c-style kullanımında, arrayle derleyici tarafından pointer gibi bir forma döndürülür ve de bu pointerın adresi array'in 0. indexiyle init
edilmiş olur. Buna array decay denir. Yani biz bu arrayleri bir yere gönderirken pass by value gibi gözükse bile aslında pass by address olur.
Burada fonksiyon parametresi olarak c-style array bekleyeniyorsa array syntaxi kullanılmalı -> int arr[] rather than int *arr
sizeof ile decayed c-style array kullanımı biraz problemli olabilir, std::size ve ssize da pointerlarla çalışmaz. Burada belki fonksiyonlara ayrı bir
parametre gönderebiliriz bu array ile beraber. 
Burada best practice için:
read only string -> string_view
modıfıable string -> std::string
non-global constexpr array -> std::array
non-constexpr array -> vector

*/
