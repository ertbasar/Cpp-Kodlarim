/* 

İlk üç terim aslında temel olarak bazı objeler (sınıflar) arasındaki ilişkileri açıklamak amacıyla kullanılır.
- Eğer bir sınıf, başka bir sınıfın parçasıysa ve onun varlığı olmadan olamıyorsa, bu composition olur. (İç içe nesne kullanımı gibi)
- Aggregation, nesneler arasındaki zayıf sahiplik ilişkisidir. Üst nesne yok edildiğinde alt nesne yok edilmez. Alt nesne bağımsız da var
olabilir. (Genellikle pointer veya referans kullanımı)
- Association, 2 sınıf arasındaki genel bir ilişkiyi ifade eder. Bu, her 2 nesnenin de birbirlerini kullanabilmesi anlamına gelir. Ancak 
birbirlerine sahip değillerdir. 
- Bir nesne, belirli bir görevi yerine getirmek için başka bir nesnenin işlevini çağırdığında bir bağımlılık (dependency) oluşur.
Bu, association (ilişkilendirme) ilişkisine göre daha zayıf bir ilişkidir. Ama yine de, bağımlı olunan nesnede yapılan herhangi bir değişiklik, 
(bağımlı olan) çağırıcı nesnenin işlevini bozabilir. Bir bağımlılık her zaman tek yönlü bir ilişkidir.

*/