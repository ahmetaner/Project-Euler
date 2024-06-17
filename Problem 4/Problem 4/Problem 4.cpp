// Problem 4.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#define MAX 10
#include <cmath>

class Number {
public:
    
    int* calculate_digits(int num, int digit_num) {
        int* result = new int[digit_num]; // eğer dizinin boyutunu değişkenle seçmek istiyorsan bu methodla yap.
        for (int i = 0; i < digit_num; ++i) {
            result[i] = 0; // Initialize the array
        }
        int previous = 0;
        for (int i = 0; i < digit_num; i++) {
            result[i] = ((num % (int)pow(10, i + 1)) - (previous)) / pow(10,i);
            previous += result[i] * pow(10, i);
            
        }
        return result;
    }

    bool IsPalindrome(int num, int digit) {
        Number number;
        int* fout = number.calculate_digits(num, digit);
        bool is_palindrome = true; // To keep track of palindrome status
        for (int j = 0; j < digit; j++) {
            //std::cout << fout[j] << "ile" << fout[digit - 1 - j] << std::endl;
            if (fout[j] != fout[digit - 1 - j]) {
                return false;
            }
        }
        delete[] fout; // deallocate memory
        return true;
    }
};

int main()
{
    Number number;
    int greatest_palindrome = 0;
    for (int i = 0; i < 999; i++) {
        for (int j = 0; j < 999; j++) {
            int multipy_result = i * j;
            if (number.IsPalindrome(multipy_result, 6) == true) {
                if (i * j > greatest_palindrome) {
                    greatest_palindrome = i * j;
                }
            }
            
        }
    }
    std::cout <<greatest_palindrome << std::endl;
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
