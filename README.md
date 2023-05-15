# Algo-Analysis

Bu kod, genel olarak 1 ana fonksiyon ve 3 farklı ek fonksiyondan meydana gelmektedir. Ana fonkisyon içerisinde 10 ve -10 değerleri arasında random olarak bir matris oluşturulur. Ve diğer fonksiyonlarda bu matrisler üzerinde işlemler yapılır. Sırasıyla: 

#F1
Fonksiyon 1, dizideki tüm elemanları tarar ve elemanları büyükten küçüğe doğru sıralar. Bubble Sort yöntemi ile sıralanmaktadır. Bir eleman belirlenir ve belirlenen eleman sonraki elemandan büyükse yerleri değiştirilir.
Bu fonksiyonda iç içe geçmiş 2 for döngüsü bulunmaktadır bu yüzden n kez tekrarlanan bir döngü içinde tekrar n defa tekrarlanacaktır ve bu yüzden zaman karmaşıklığı bu fonksiyon için O(n^2) olacaktır.


#F2
Fonksiyon 2, alt dizilerdeki elemanları toplar ve bu alt dizilerin toplamlarını karılaştırır. Toplamı en büyük olan alt dizinin ortalamasını alır ve return ile ortalamayı döndürür. 
Bu fonksiyonda yalnızca 1 for döngüsü vardır bu yüzden n defa tekrarlanır ve zaman karmaşıklığı da bu yüzden O(n) olarak bulunur

#F3
Fonksiyon 3, Floyd-Marshall algoritması fonksiyonudur. Bu fonksiyon, graf matrisinde tüm çiftler arasındaki en kısa mesafeleri bulur. 

3 tane iç içe loop olduğu için O(n^3) şeklinde hesaplanır Çünkü her bir n değeri 3 defa tekrarlanacak şekilde iç içe döner ve kontrolü yapılır. 
1. Döngü: n kez
2. Döngü: n kez
3. Döngü: n kez
tekrarlanır yani n^3 kez tekrarlanır.

Genel olarak kodun zaman karmaşıklığı en üst seviyeden alınır bu yüzden O(n^3) şeklindedir.

#KODUN İYİLELŞTİRİLMESİ

1. Fonksiyon için sıralama algoritması bubble sorttur ve zaman karmaşıklığı açısından veri boyutu büyüdükçe algoritmanın çalışma süresi uzar ve bu da istenmeyecek bir durumdur. Bunun iyileştirilmesi için, “Bubble Sort” yerine “Quick Sort” algoritması kullanılabilir. O(n*logn) olarak yeni zaman karmaşıklığı elde edilir.

2. Fonksiyon için her bir elemanın yine de kontrolü yapılması gerekeceğinden dolayı O(n) fonksiyonundan iyi bir yöntem geliştiremedim.

3. Fonksiyon için zaman karmaşıklığını azaltmak için O(n^3) olan algoritmadan O( E log V) olan Dijkstra algoritmasına geçilirse, zaman karmaşıklığı düşer.

##Sonuç olarak algoritma iyileştirildikten sonra zaman karmaşıklığı O(n^3) ten O(n*logn) e düşer ve algoritmanın yeni gecikme süresi 0.000431 sn’den 0.000209 sn’ye düşer.
