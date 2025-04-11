#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Kategori {
    string kategori;
};

struct Skincare {
    string merk;
    string jenis;
    double harga;
    Kategori kategori;
};

struct User {
    string nama;
    string nim;
};

void login(User users[], int total_user);
void registrasi(User users[], int &total_user, const int MAX_USER);
void tambahProduk(Skincare produk[], int &total_produk);
void tampilkanProduk(Skincare produk[], int total_produk);
void perbaruiProduk(Skincare produk[], int total_produk);
void hapusProduk(Skincare produk[], int &total_produk);

int main() {
    const int MAX_USER = 10;
    User users[MAX_USER];
    int total_user = 0;

    users[total_user++] = {"Ghesya", "023"};

    Skincare produk[100];
    int total_produk = 5;

    produk[0] = {"Azarine", "Sunscreen", 60000, {"Face"}};
    produk[1] = {"Npure", "Toner", 90000, {"Face"}};
    produk[2] = {"Senka", "Sabun", 50000, {"Body"}};
    produk[3] = {"Innisfree", "Serum", 350000, {"Face"}};
    produk[4] = {"Skintific", "Moisturizer", 100000, {"Face"}};

    cout << "=== LOGIN / REGISTER ===" << endl;
    while (true) {
        cout << "1. Login\n2. Register\nPilih opsi (1-2): ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            login(users, total_user);
            break;
        } else if (pilihan == 2) {
            registrasi(users, total_user, MAX_USER);
            break;
        } else {
            cout << "Pilihan tidak valid, coba lagi.\n" << endl;
        }
    }

    while (true) {
        int pilihan;
        cout << "\n++-------------------------------------++" << endl;
        cout << "||            === Menu ===             ||" << endl;
        cout << "++-------------------------------------++" << endl;
        cout << "||  1. Tambah Data Produk Skincare     ||" << endl;
        cout << "||  2. Tampilkan Data Produk Skincare  ||" << endl;
        cout << "||  3. Perbarui Data Produk Skincare   ||" << endl;
        cout << "||  4. Hapus Data Produk Skincare      ||" << endl;
        cout << "||  5. Keluar dari program             ||" << endl;
        cout << "++-------------------------------------++" << endl;
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahProduk(produk, total_produk); break;
            case 2: tampilkanProduk(produk, total_produk); break;
            case 3: perbaruiProduk(produk, total_produk); break;
            case 4: hapusProduk(produk, total_produk); break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini!!! Papayyy" << endl;
                return 0;
            default:
                cout << "Pilihan anda tidak valid!" << endl;
        }
    }
}

void login(User users[], int total_user) {
    string nama, nim;
    int attempts = 0;
    while (attempts < 3) {
        cout << "\nMasukkan nama: ";
        cin >> nama;
        cout << "Masukkan 3 digit terakhir NIM: ";
        cin >> nim;

        for (int i = 0; i < total_user; ++i) {
            if (users[i].nama == nama && users[i].nim == nim) {
                cout << "Login berhasil!" << endl;
                return;
            }
        }
        attempts++;
        cout << "Login gagal! Percobaan ke-" << attempts << " dari 3" << endl;
    }
    cout << "Login gagal setelah 3 kali percobaan. Program berhenti." << endl;
    exit(0);
}

void registrasi(User users[], int &total_user, const int MAX_USER) {
    if (total_user < MAX_USER) {
        cout << "Masukkan nama: ";
        cin >> users[total_user].nama;
        cout << "Masukkan 3 digit terakhir NIM: ";
        cin >> users[total_user].nim;
        total_user++;
        cout << "Register berhasil!" << endl;
    } else {
        cout << "Jumlah pengguna sudah mencapai batas maksimum." << endl;
    }
}

void tambahProduk(Skincare produk[], int &total_produk) {
    if (total_produk < 100) {
        cout << "Masukkan merk skincare: ";
        cin >> produk[total_produk].merk;
        cout << "Masukkan jenis skincare: ";
        cin >> produk[total_produk].jenis;
        cout << "Masukkan harga skincare: ";
        cin >> produk[total_produk].harga;
        cout << "Masukkan kategori skincare (Face/Body/Hair): ";
        cin >> produk[total_produk].kategori.kategori;

        total_produk++;
        cout << "Data berhasil ditambahkan!" << endl;
    } else {
        cout << "Jumlah data sudah penuh." << endl;
    }
}

void tampilkanProduk(Skincare produk[], int total_produk) {
    if (total_produk == 0) {
        cout << "Belum ada data produk skincare untuk ditampilkan" << endl;
    } else {
        cout << "\n                === Data Produk Skincare ===                " << endl;
        cout << "---+--------------+---------------+-----------+-------------" << endl;
        cout << "   |     Merk     |     Jenis     |   Harga   |  Kategori  " << endl;
        cout << "---+--------------+---------------+-----------+-------------" << endl;
        for (int i = 0; i < total_produk; ++i) {
            cout << setw(2) << i + 1 << " | " << setw(12) << produk[i].merk 
                 << " | " << setw(13) << produk[i].jenis 
                 << " | " << setw(9) << produk[i].harga
                 << " | " << setw(10) << produk[i].kategori.kategori << endl;
        }
        cout << "---+--------------+---------------+-----------+-------------" << endl;
    }
}

void perbaruiProduk(Skincare produk[], int total_produk) {
    tampilkanProduk(produk, total_produk);
    int no;
    cout << "\nMasukkan nomor produk yang ingin diperbarui: ";
    cin >> no;

    if (no < 1 || no > total_produk) {
        cout << "Nomor produk tidak valid" << endl;
    } else {
        cout << "Masukkan merk baru: ";
        cin >> produk[no - 1].merk;
        cout << "Masukkan jenis baru: ";
        cin >> produk[no - 1].jenis;
        cout << "Masukkan harga baru: ";
        cin >> produk[no - 1].harga;
        cout << "Masukkan kategori baru (Face/Body/Hair): ";
        cin >> produk[no - 1].kategori.kategori;
        cout << "Data berhasil diperbarui!" << endl;
    }
}

void hapusProduk(Skincare produk[], int &total_produk) {
    tampilkanProduk(produk, total_produk);
    int no;
    cout << "\nMasukkan nomor produk yang ingin dihapus: ";
    cin >> no;

    if (no < 1 || no > total_produk) {
        cout << "Nomor produk tidak valid" << endl;
    } else {
        for (int i = no - 1; i < total_produk - 1; ++i) {
            produk[i] = produk[i + 1];
        }
        total_produk--;
        cout << "Data berhasil dihapus!" << endl;
    }
}