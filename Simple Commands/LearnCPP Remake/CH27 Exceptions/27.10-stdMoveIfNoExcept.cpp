/* C++11 ile beraber gelen bir fonksiyon şablonu diyebiliriz std::move_if_noexcept için. Bir nesnenin taşınabilirliğini bir koşula bağlı olarak 
gerçekleştirmek için kullanılır. Eğer taşınacak nesnenin move constructoru noexcept olarak işaretlenmişse, move_if_noexcept sadece taşıma işlemi yapar.
Eğer taşıma işlemi istisna atma ihtimali olan bir constructor'a sahipse, move_if_noexcept bu objeyi kopyalar.


*/