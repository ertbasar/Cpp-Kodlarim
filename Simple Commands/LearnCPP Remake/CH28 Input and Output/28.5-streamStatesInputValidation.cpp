/* ios_base sınıfı, akışları kullanırken bazı koşulların ne halde olup olmadığıyla alakalı sinyalleri inceler diyebiliriz. En temel olanı ise failbit
adındaki flagdir. Bu flag olmaması gereken bir giriş yapıldığında aktive olur ve bu akıştaki sonradan gelen veriler gözardı edilir. clear() fonksiyonunu
kullanana kadar akıştan veri işlenmez. 
Burada string, numeric ve numeric validation as a string olmak üzere 3 farklı temel doğrulama bulunmakta. Bu doğrulamalar önemli, programın çalışma
şeklini bozabilir.

*/