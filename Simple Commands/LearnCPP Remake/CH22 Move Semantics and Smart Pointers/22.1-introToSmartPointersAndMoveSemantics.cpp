/* Kod bloklarının sonlarında pointerlara tahsis edilen bellekleri geri sisteme tahsis ettiğimiz delete kullanımları olabilir ancak fonksiyonlardan erken
çıkış durumlarında bellek sızıntısı gerçekleşebilir. Bu da pointerların kendilerini temizleyecek mekanizmaları olmamasındandır. 
Sınıfların en iyi özelliklerinden birisi de kendiliğinden bu temizleme işlemini yapan destructorlara sahip olmalarıdır. Peki bu bellek tahsisini  
constructor içinde yaptığımız, bu alanı geri verme işlemini de destructor ile yaptığımız bir yapı nasıl olurdu? Yani bir sınıf yardımıyla bu bellek 
tasis ve geri verme işlemlerini kolaylaştırabiliriz. Burada tek işi bir pointer tutmak olan bir adet sınıf düşünelim, normal bir değişken gibi 
kullanıldığı düşünüldüğünde scope alanı dışına çıktığında da destructor ile belleği geri sisteme verir. Aslında burada pointer'a destructor özelliği
kazandırdık diyebiliriz. Sonuç olarak smart pointer, dinamik olarak tahsis edilen belleği yönetmek ve scope alanı dışına çıkınca bu belleğin geri 
verildiğinden emin olmamızı sağlayan bir sınıf türüdür diyebiliriz. 
---
Burada copy constructor ve assignmentlara dikkat edilmeli, aynı adresin saklanması ve bir objenin scope dışına çıkması durumunda istenmeyen davranışlar
görülebilir. Burada birkaç seçenek mevcut:
1. explicit olarak bu constructor ve assignment'ın delete anahtar sözcüğüyle kullanımının engellenmesi.
2. bu constructor ve assignment'ın tanımlamalarının elle yazılması ve de burada deep copy işlemlerinin gerçekleştirilmesi. Burada da bazı objelerin
kopyalanması çok pahalı işlemler olabilir. 
3. Pointer'ın sahipliğinin transfer edilmesi/taşınması. Move semantics'in genel fikri de budur. Move semantic kopyalanma yerine bir sınıfın sahipliğinin 
transfer edilmesi demektir. 
(Bizim bildiğimiz normal pointerlara aptal (dumb) pointer da denir. Temizlik işlemini otomatik olarak yapmadıklarından ötürü)
Aşağıda LearnCpp'den aldığım bir örneği de açıklamaya çalışacağım
*/

#include <iostream>

// Sınıfı şablon olarak tanımlayacağız ki türlerin değişimine rağmen çalışsın
template <typename T>
class Auto_ptr2
{
    // pointer değişkeninin tanımlanması
	T* m_ptr {};
public:
    // default olarak nullptr, bir şey gönderildiği taktirde ise tahsis edilen o bellek alanının başının eşitlenmesi
	Auto_ptr2(T* ptr=nullptr)
		:m_ptr(ptr)
	{
	}

    // belleğin geri sisteme verilmesi
	~Auto_ptr2()
	{
		delete m_ptr;
	}

	// move semantics'i implemente eden bir copy constructor
	Auto_ptr2(Auto_ptr2& a) // ref const değil dikkat
	{
        // m_ptr'yi delete etmeye gerek yok çünkü zaten şu an tanımlama yapıyoruz, tahsis edilmiş bir bellek alanına sahip değil
		m_ptr = a.m_ptr; // kaynak objedeki aptal pointer'ın yeni objeye kopyalanması
		a.m_ptr = nullptr; // kaynak objedeki pointer'ın nullptr'ye eşitlenmesi (direkt delete yapılırsa tahsis edilen bellek sisteme verilir.)
	}

	// move semantics içeren copy assignment
	Auto_ptr2& operator=(Auto_ptr2& a) // ref const değil dikkat
	{
		if (&a == this) // self assignment mı kontrolü
			return *this;

		delete m_ptr; // hedef objenin sahip olduğu belleğin sisteme geri verilmesi
		m_ptr = a.m_ptr; // kaynak objeden hedef objeye aptal pointer'ın transferi
		a.m_ptr = nullptr; // kaynak objenin pointer'ının nullptr'ye eşitlenmesi
		return *this;
	}

    // aşağıda bazı operatörlerin overload işlemi var. Normalde bu operatörler direkt sınıf objesini gösterecekken şimdi ise objenin içindeki
    // pointer üzerinden sanki aptal pointermış gibi işlemler gerçekleştiriyor. Olması gereken de zaten bu
	T& operator*() const { return *m_ptr; } 
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

// Yer tahsis edilecek kaynak sınıf
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    // Smart pointer sınıfı tanımımıza uygun değişken tanımlamaları
	Auto_ptr2<Resource> res1(new Resource());
	Auto_ptr2<Resource> res2; // nullptr olarak init edilir

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	res2 = res1; // sahipliği res2 aldı, res1'de hiçbir şey kalmadı

	std::cout << "Ownership transferred\n";

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	return 0;
}