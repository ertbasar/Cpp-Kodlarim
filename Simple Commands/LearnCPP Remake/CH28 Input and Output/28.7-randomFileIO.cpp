/* Her akış sınıfının sahip olduğu bir dosya pointerı vardır. Bu pointer o anki dosyada bulunan okuma/yazma noktasını takip eder. Default olarak bu pointer dosyanın başından başlar. (Append
modunda ise sondan başlar) Bununla beraber random olarak da dosyaların içine erişebilriz. Bu da seekg() veya seekp() ile pointerı manipüle ederek yapılır. ('g' get, 'p' put)
Bu fonksiyonlar iki adet parametre alır:
1. Byte türünden offset
2. offset'in geçerli olacağı durum. Bunlar da:
beg -> dosyanın başı, cur -> o anki yer, end -> dosyanın sonu 
Bu arada bir dosyayı silmek için de remove() kullanılır
*/