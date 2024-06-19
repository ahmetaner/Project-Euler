// Smallest multiple(5).cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <cmath>

class Prime {
public:
    int prime = 0; 
    int quantity = 0;
};



Prime* CalculatePrimeFactor(int number, int prime_num);
int CountPrime(int number);
void LCM(int* numbersp, int number_quan); // least common multiple
Prime* Convert2Dto1D(Prime** array2D, int size1D, int* numbersp, int column2D_size);
Prime* SelectionSort(Prime* array, int array_size);


int main()
{
    int number[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    LCM(&number[0], 20);
    
}

Prime* SelectionSort(Prime* array, int array_size) {
    Prime temp;
    int lowest;
    for (int i = 0; i < array_size - 1; i++) {
        lowest = i;
        for (int j = i + 1; j < array_size; j++) {
            if (array[lowest].prime > array[j].prime) {
                lowest = j;
            }
        }
        temp = array[lowest];
        array[lowest] = array[i];
        array[i] = temp;
    }
    return array;
}

Prime* Convert2Dto1D(Prime** array2D, int size1D, int* numbersp, int column2D_size) { 
    Prime* array1D = new Prime[size1D];
    int i = 0;
        for (int j = 0; j < column2D_size; j++) {
            for (int k = 0; k < CountPrime(*(numbersp + j)); k++) {
                array1D[i] = array2D[j][k];
                std::cout << "prime: " << array1D[i].prime << std::endl;
                std::cout << "quantity: " << array2D[j][k].quantity << std::endl;
                i++;
                
            }
        }
    return array1D;
    
}

void LCM(int* numbersp, int number_quan) { // first variable -> array, second variable -> array size
    Prime** numbers; // to create dynamic two dimensions array
    numbers = new Prime * [number_quan];
    int rows_count = 0;
    int size1D = 0;
    for (int i = 0; i < number_quan; i++) {
        numbers[i] = CalculatePrimeFactor(*(numbersp + i), CountPrime(*(numbersp + i)));
        rows_count = CountPrime(*(numbersp + i));
        size1D += rows_count;
    }
    
    Prime* primes1D = Convert2Dto1D(numbers, size1D, numbersp, number_quan);
    Prime* sorted_prime1D = SelectionSort(primes1D, size1D);
    for (int i = 0; i < size1D; i++) {
        std::cout << "Prime: " << primes1D[i].prime << " Quantity: " << primes1D[i].quantity << std::endl;
    }

    int LCM = 1;
    Prime temp;
    for (int i = 0; i < size1D; i++) {
        if (temp.prime == sorted_prime1D[i].prime) {
            continue;
        }
        temp.prime = sorted_prime1D[i].prime;
        temp.quantity = sorted_prime1D[i].quantity;
        for (int j = i + 1; j < size1D; j++) {
            if ((temp.prime == sorted_prime1D[j].prime) && (temp.quantity < sorted_prime1D[j].quantity)) {
                temp.quantity = sorted_prime1D[j].quantity;
            }

        }
        LCM = LCM * (int)pow(temp.prime, temp.quantity);
        std::cout << temp.prime << std::endl;
        std::cout << temp.quantity << std::endl;
        std::cout << LCM << std::endl;
    }
    

   
    // each array should be deleted independently
    for (int i = 0; i < number_quan; i++) {
        delete[] numbers[i];
    }
    delete[] numbers;
    delete[] primes1D;
}

int CountPrime(int number) {
    int quantity = 0;
    for (int i = 2; i <= number; i++) {
        if (number % i == 0) {
            number = number / i;
            if (number % i != 0) {
                quantity++;
            }
            i--;
        }
    }
    return quantity;
}

Prime* CalculatePrimeFactor(int number, int prime_num) {
    Prime* primes = new Prime[prime_num];
    int j = 0;
    for (int i = 2; i <= number; i++) { // 0 -> undefined, 1 -> not expire 
        if (number % i == 0) {
            primes[j].prime = i;
            primes[j].quantity++;
            number = number / i;
            if (number % i != 0) {
                j++;
            }
            i--;
        }
    }
    /*for (int i = 0; i < j; i++) {
        std::cout << "Asal: " << primes[i].prime << std::endl;
        std::cout << "Kac kere: " << primes[i].quantity << std::endl;
        std::cout << "****************************************"<< std::endl;
    }*/
    return primes;
    //delete[] primes;
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
