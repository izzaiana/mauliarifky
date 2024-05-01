#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk mengecek apakah karakter merupakan digit
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Fungsi untuk mengecek apakah nomor kartu valid menggunakan Algoritma Luhn
bool isValidLuhn(string cardNumber, int &checksum) {
    int sum = 0;
    bool doubleDigit = false;

    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        if (!isDigit(cardNumber[i])) {
            return false;
        }

        int digit = cardNumber[i] - '0';

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) {
                digit = digit % 10 + digit / 10;
            }
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    checksum = sum;
    return sum % 10 == 0;
}

// Fungsi untuk menentukan jenis kartu berdasarkan digit pertama
string getCardType(string cardNumber) {
    if (cardNumber[0] == '4') {
        return "VISA";
    } else if (cardNumber.substr(0, 2) == "51"  cardNumber.substr(0, 2) == "52"  cardNumber.substr(0, 2) == "53"  cardNumber.substr(0, 2) == "54"  cardNumber.substr(0, 2) == "55") {
        return "MASTERCARD";
    } else {
        return "TIDAK DIKETAHUI";
    }
}

int main() {
    string cardNumber;
    cout << "Masukkan angka kartu: ";
    cin >> cardNumber;

    // Hapus karakter non-digit dari nomor kartu
    string cleanedCardNumber = "";
    for (char c : cardNumber) {
        if (isDigit(c)) {
            cleanedCardNumber += c;
        }
    }

    // Periksa apakah nomor kartu valid menggunakan Algoritma Luhn
    int checksum;
    bool isValid = isValidLuhn(cleanedCardNumber, checksum);

    if (isValid) {
        cout << "Nomor kartu VALID." << endl;
        cout << "Hasil checksum : " << checksum << endl;
        cout << "Tipe kartu anda: " << getCardType(cleanedCardNumber) << endl;
    } else {
        cout << "Nomor kartu TIDAK VALID." << endl;
    }

    return 0;
}