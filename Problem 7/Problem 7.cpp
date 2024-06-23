// Problem 7.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#define SIZE 10001          // Define the size of the prime array
#define MAX_NUM 1000000     // Define the maximum number to check for primes

// Function to check if a number is prime
bool CheckPrime(int number);

int main()
{
    int prime[SIZE];        // Array to store prime numbers
    int j = 1;              // Index to keep track of the number of primes found
    prime[0] = 2;           // The first prime number is 2
    for (int i = 3; (i < MAX_NUM) && (j < SIZE); i++) {
        // Check if the current number is prime
        if (CheckPrime(i) == true) {
            prime[j] = i;   // Store the prime number in the array
            std::cout << j << "th prime is " << i << std::endl; // Print the prime number
            j++;            // Increment the prime index
        }
    }
}

// Function to check if a number is prime
bool CheckPrime(int number) {
    bool prime = false;     // Initialize prime flag as false
    for (int i = 2; i < number; i++) {
        // Check if the number is divisible by any number other than 1 and itself
        if (number % i == 0) {
            prime = false;  // Number is not prime
            return prime;   // Return false
        }
        else {
            prime = true;   // Number might be prime
        }
    }
    return prime;           // Return the prime flag
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
