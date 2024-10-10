/* Friend sınıflar da diğer sınıfların privare ve protected üyelerine erişebilirler. Burada dikkat edilmesi gereken şey arkadaşlığın sadece bir sınıfa kadar
gidebileceğidir. Arkadaş olunan sınıf da başka sınıfa arkadaş olabilir ancak o sınıfa erişimimiz olmaz. Burada bir sınıfı tümden arkadaş yapmak yerine 
fonksiyonu yapmak daha mantıklı olabilir. Ancak burada iki sınıfı da o fonksiyona üye yapmak gerekebilir. Burada en iyi çözüm sınıfları ayrı header 
dosyalarında tanımladıktan sonra bu fonksiyonu ayrı bir cpp dosyasında tanımlamak olabilir.
 
*/