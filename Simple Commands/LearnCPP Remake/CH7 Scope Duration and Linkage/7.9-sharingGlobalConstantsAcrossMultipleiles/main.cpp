/* Önceden global değişken, sabitler vsler aşağıdaki süreçte yapılırdı
1. Header dosyasının oluşturulması   2. Header dosyası içinde namespace oluşturulması    3. Tüm sabitlerin bu namespace içinde constexpr şekilde tanımlanması
4. Bu header dosyasının her yerde kullanılması
Çok büyük projelerde her include işlemi her dosyaya kopyalama gerektirir ve bazı değişiklikler yapıldığında her dosyanın yeniden compile edilmesi gerekir.
Bu tür sıkıntıların önüne geçmek için bu değişkenleri external hale getirip ve bir yerde tanımını yaptıktan sonra headerlarda sadece forward declaration
işlemini gerçekleştirmek mantıklı olabilir. Bu durumda tabii constexpr yerine const kullanılmalı.
Bu işlemin bir basit örneğini bu klasör içindeki constant cpp ve h dosyalarıyla örneklendirdim.

*/