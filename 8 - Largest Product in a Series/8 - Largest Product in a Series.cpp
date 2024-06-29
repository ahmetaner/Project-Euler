// 8 - Largest Product in a Series.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <fstream>
#include <string>
#define ADJACENT_DIGIT 13

// Function prototypes
std::string read(std::string file_name);
long long Product(int int_array[], int digit_num);

int main() {
    std::string number = "number.txt"; // File name
    std::string content = read(number); // Read the file content into a string
    int length = content.length(); // Get the length of the content
    int* number_array = new int[length]; // Dynamically allocate an array to hold the digits

    // Convert characters in content to numeric values
    for (int i = 0; i < length; i++) {
        // You need to convert the character to its numeric value by subtracting the ASCII value of '0' 
        // (which is 48) from the ASCII value of the character.
        number_array[i] = (int)content[i] - '0';
    }

    long long greatest_product = 1; // Variable to hold the greatest product

    // Loop through the content to find the greatest product of ADJACENT_DIGIT digits
    for (int i = 0; i <= length - ADJACENT_DIGIT; i++) {
        int temp_array[ADJACENT_DIGIT]; // Temporary array to hold the current set of digits

        // Populate the temporary array with the current set of digits
        for (int j = 0; j < ADJACENT_DIGIT; j++) {
            temp_array[j] = number_array[i + j];
        }

        // Calculate the product of the current set of digits
        long long product = Product(temp_array, ADJACENT_DIGIT);

        // Update the greatest product if the current product is greater
        if (product > greatest_product) {
            greatest_product = product;
        }
    }

    // Output the greatest product
    std::cout << "Greatest product: " << greatest_product << std::endl;
    std::cout << "Content: " << content << std::endl;
    std::cout << "Length: " << length << std::endl;

    // Free the dynamically allocated array
    delete[] number_array;
}

// Function to calculate the product of an array of integers
long long Product(int int_array[], int digit_num) {
    long long result = 1; // Initialize result to 1

    // Multiply each digit in the array
    for (int i = 0; i < digit_num; i++) {
        result = result * int_array[i];
    }
    return result; // Return the product
}

// Function to read the content of a file into a string
std::string read(std::string file_name) {
    std::string numbers_str; // String to hold the file content
    std::ifstream myfile; // Input file stream
    std::string chars; // String to accumulate characters from the file
    char ch; // Character variable to hold each character read from the file
    myfile.open(file_name); // Open the file

    if (!myfile.is_open()) {
        // Print an error message if the file couldn't be opened
        std::cerr << "The file couldn't be opened!";
        return "1"; // Return "1" to indicate error
    }

    // Read the file character by character
    while (myfile.get(ch)) {
        // Append the character to chars if it's not a newline
        if (ch != '\n') {
            chars += ch;
        }
    }
    myfile.close(); // Close the file
    return chars; // Return the accumulated characters
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
