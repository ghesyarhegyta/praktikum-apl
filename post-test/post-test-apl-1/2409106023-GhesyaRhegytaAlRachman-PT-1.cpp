#include <iostream>
using namespace std;

int main() {
    string nama, inputNama;
    string nim, inputNIM;
    int attempts = 0;

    cout << "=== LOGIN ===" << endl;
    cout << "Masukkan nama: ";
    cin >> nama;
    cout << "Masukkan 3 digit terakhir NIM: ";
    cin >> nim;

    if (nama == "Ghesya" && nim == "023") {
        cout << "Login berhasil!" << endl;
    } else {
        attempts++;
        while (attempts < 3) {
            cout << "\nLogin Ulang" << endl;
            cout << "Masukkan nama: ";
            cin >> inputNama;
            cout << "Masukkan 3 digit terakhir NIM: ";
            cin >> inputNIM;

            if (inputNama == "Ghesya" && inputNIM == "023") {
                cout << "Login berhasil!" << endl;
                break;
            } else {
                attempts++;
                cout << "Login gagal! Percobaan ke-" << attempts << " dari 3" << endl;
            }
        }
    }

    if (attempts == 3) {
        cout << "Login gagal setelah 3 kali percobaan. Program berhenti." << endl;
        return 0;
    }

    while (true) {
        int pilihan;
        cout << "\n=====================================================" << endl;
        cout << "           = = = MENU KONVERSI SUHU = = =           " << endl;
        cout << "=====================================================" << endl;
        cout << "||  1. Celcius ke Fahrenheit, Reamur, dan Kelvin    ||" << endl;
        cout << "||  2. Fahrenheit ke Celcius, Reamur, dan Kelvin    ||" << endl;
        cout << "||  3. Reamur ke Celcius, Fahrenheit, dan Kelvin    ||" << endl;
        cout << "||  4. Kelvin ke Celcius, Fahrenheit, dan Reamur    ||" << endl;
        cout << "||  5. Keluar dari program                          ||" << endl;
        cout << "=====================================================" << endl;
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

        if (pilihan == 5) {
            cout << "Keluar dari program." << endl;
            break;
        }

        float suhu;
        cout << "\nMasukkan suhu: ";
        cin >> suhu;

        cout << "\n=====================================================" << endl;
        cout << "                     KONVERSI SUHU                   " << endl;
        cout << "=====================================================" << endl;

        switch (pilihan) {
            case 1:
                cout << "Fahrenheit:" << (suhu * 9/5) + 32 << endl;
                cout << "Reamur:" << (suhu * 4/5) << endl;
                cout << "Kelvin:" << (suhu + 273.15) << endl;
                break;
            case 2:
                cout << "Celcius:" << (suhu - 32) * 5/9 << endl;
                cout << "Reamur:" << (suhu - 32) * 4/9 << endl;
                cout << "Kelvin:" << (suhu - 32) * 5/9 + 273.15 << endl;
                break;
            case 3:
                cout << "Celcius:" << (suhu * 5/4) << endl;
                cout << "Fahrenheit:" << (suhu * 9/4) + 32 << endl;
                cout << "Kelvin:" << (suhu * 5/4) + 273.15 << endl;
                break;
            case 4:
                cout << "Celcius:" << (suhu - 273.15) << endl;
                cout << "Fahrenheit:" << (suhu - 273.15) * 9/5 + 32 << endl;
                cout << "Reamur:" << (suhu - 273.15) * 4/5 << endl;
                break;
            default:
                cout << "Pilihan anda tidak valid!" << endl;
        }
        cout << "=====================================================" << endl;
    }

    return 0;
}