// Problem 2.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

int main()
{
    int array[999];
    int sum = 2;
    array[0] = 1;
    array[1] = 2;
    for (int i = 2; i < 100; i++) {
        array[i] = array[i - 1] + array[i - 2];
        
        if (array[i] % 2 == 0 && array[i] < 4000000) {
            sum += array[i];
           
        }
        else if (array[i] >= 4000000) {
            std::cout << "4 milyon gecildi.\n" << i<< std::endl;
            break;
        }
    }
  
    std::cout << sum <<"\n";
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
