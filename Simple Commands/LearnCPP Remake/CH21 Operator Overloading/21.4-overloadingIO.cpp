/* Aslına bakarsak operator<< ile diğer operatörlerin overload edilmesi arasında çok da bir fark yok, sadece parametre türleri arasında bazı farklar var.
Burada örnek olarak std::cout << point; bloğunu ele alalım. Sol operand std::out objesi, sağ operand da Point sınıfı objesi diyebiliriz. std::cout da 
aslında std::ostream türünün bir objesidir. Bu yüzden syntax biraz daha farklı hale gelir. Aşağıda tam olarak doğru olmasa da bir kullanım var.
friend std::ostream& operator<< (std::ostream& out, const Point& point){
    out << "Point(" << point.m_x << " " << point.m_y << ")"; // asıl yazdırma işlemi burada yapılıyor
    return out; // return ediyoruz ki operator<< ile zincirleme istekler gönderebilelim
}
Burada ostream'i değer ile döndürmeye çalışırsak hata verir. ostream özellikle kopyalanmaya karşı dirençlidir diyebiliriz :)
Aynı zamanda operator>>'yı da overload edebiliriz. O da std::istream'in bir objesidir. Benzer bir örneği aşağıda yazayım.
std::istream& operator>> (std::istream& in, Point& point){
double x,y,z;
in >> x >> y >> z;
if(in) // eğer tüm input işlemleri başarılı şekilde gerçekleştiyse
    point = Point{x, y, z}; // yeni bir obje oluşturup elemanları eşitle
return in;
}
Burada yanlış girişlerden kaçınmak önemli, bu yüzden giriş alırken direkt eşitleme yapma, önce bir validasyon işlemi yapılsa iyi olur. Konsoldan giriş
ve çıkışta bu overload işlemleri çok işe yarar.
*/