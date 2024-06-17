// Problem 3.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

//#include <iostream>
#include <iostream>


#include <cstdint>  // int64_t türünü kullanmak için

int main()
{
	
	int64_t number = 600851475143;

	int64_t greatest_factor = 0;
	for (int64_t i = 2; i <= number; i++) {
		if (number % i == 0) {
			number = number / i;
			greatest_factor = i;
			i = i - 1;// aynı sayıya tekrar bölünme kontrol etmek için.
			
			std::cout << greatest_factor << "  +++   " << number << std::endl;
		}
	}
	

	return 0;
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
