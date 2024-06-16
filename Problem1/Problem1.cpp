// Problem1.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
class Number {
    public:
        int number, ones, tens, hundreds;
        

        void calculate_digits(int num) {
            number = num;
            ones = number % 10;
            tens = ((number % 100) - ones) / 10;
            hundreds = (number - (ones + (tens * 10))) / 100;
        }
};

int main()
{
    Number number;
    int number_sum = 0;
    for (int i = 0; i < 1000; i++) {
        number.calculate_digits(i); // burada fonksiyon kullanılmazsa initilization sıkıntısı oluyor ve kod yanlış çalışıyor.
        int digit_sum = number.ones + number.tens + number.hundreds;
        if (digit_sum % 3 == 0) {
            number_sum += number.number;
            std::cout << "3girdim" << std::endl;
        }
        else if (number.ones == 0 || number.ones == 5) {
            number_sum += number.number;
            std::cout << "5girdim" << number.number << number.ones<< std::endl;
        }
    }
    std::cout << number_sum;
    
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
