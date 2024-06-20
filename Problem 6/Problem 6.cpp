// Problem 6.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

int sumOfTheSquare(int* array, int array_size);
int SquareOfSum(int* array, int array_size);

int main()
{
    int array_size = 100;
    int difference;
    int* numbers = new int[array_size];
    for (int i = 0; i < array_size; i++) {
        numbers[i] = i + 1;
    }
    difference = SquareOfSum(numbers, array_size) - sumOfTheSquare(numbers, array_size);
    std::cout << difference;
    return 0;
    
}

int SquareOfSum(int* array, int array_size) {
    int sum = 0;
    for (int i = 0; i < array_size; i++) {
        sum += array[i];
    }
    sum = sum * sum;
    return sum;
}

int sumOfTheSquare(int* array, int array_size) {
    int sum = 0;
    for (int i = 0; i < array_size; i++) {
        array[i] = array[i] * array[i];
    }
    for (int i = 0; i < array_size; i++) {
        sum += array[i];
    }
    return sum;
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
