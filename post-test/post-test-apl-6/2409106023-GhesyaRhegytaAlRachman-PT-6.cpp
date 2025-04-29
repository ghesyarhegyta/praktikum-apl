#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Kategori {
    string nama;
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

void tambahProduk(Skincare *produk, int *total_produk) {
    if (*total_produk < 100) {
        cout << "Masukkan merk skincare: ";
        getline(cin, produk[*total_produk].merk);
        cout << "Masukkan jenis skincare: ";
        getline(cin, produk[*total_produk].jenis);
        cout << "Masukkan harga skincare: ";
        cin >> produk[*total_produk].harga;
        cin.ignore();
        cout << "Masukkan kategori skincare (Face/Body/Hair): ";
        getline(cin, produk[*total_produk].kategori.nama);
        (*total_produk)++;
        cout << "Data berhasil ditambahkan!" << endl;
    } else {
        cout << "Jumlah data sudah penuh!" << endl;
    }
}

void tampilkanProduk(Skincare *produk, int total_produk) {
    if (total_produk == 0) {
        cout << "Belum ada data produk skincare." << endl;
    } else {
        cout << "\n=== Data Produk Skincare ===" << endl;
        cout << "---+--------------+---------------+-----------+-------------" << endl;
        cout << "   |     Merk     |     Jenis     |   Harga   |  Kategori  " << endl;
        cout << "---+--------------+---------------+-----------+-------------" << endl;
        for (int i = 0; i < total_produk; ++i) {
            cout << setw(2) << i + 1 << " | " << setw(12) << produk[i].merk 
                 << " | " << setw(13) << produk[i].jenis 
                 << " | " << setw(9) << produk[i].harga
                 << " | " << setw(10) << produk[i].kategori.nama << endl;
        }
        cout << "---+--------------+---------------+-----------+-------------" << endl;
    }
}

void perbaruiProduk(Skincare *produk, int total_produk) {
    tampilkanProduk(produk, total_produk);
    int no;
    cout << "Masukkan nomor produk yang ingin diperbarui: ";
    cin >> no;
    cin.ignore();
    if (no < 1 || no > total_produk) {
        cout << "Nomor produk tidak valid" << endl;
    } else {
        cout << "Masukkan merk baru: ";
        getline(cin, produk[no - 1].merk);
        cout << "Masukkan jenis baru: ";
        getline(cin, produk[no - 1].jenis);
        cout << "Masukkan harga baru: ";
        cin >> produk[no - 1].harga;
        cin.ignore();
        cout << "Masukkan kategori baru: ";
        getline(cin, produk[no - 1].kategori.nama);
        cout << "Data berhasil diperbarui!" << endl;
    }
}

void hapusProduk(Skincare *produk, int *total_produk) {
    tampilkanProduk(produk, *total_produk);
    int no;
    cout << "Masukkan nomor produk yang ingin dihapus: ";
    cin >> no;
    cin.ignore();
    if (no < 1 || no > *total_produk) {
        cout << "Nomor produk tidak valid" << endl;
    } else {
        for (int i = no - 1; i < *total_produk - 1; ++i) {
            produk[i] = produk[i + 1];
        }
        (*total_produk)--;
        cout << "Data berhasil dihapus!" << endl;
    }
}

void bubbleSortMerk(Skincare *produk, int total_produk) {
    for (int i = 0; i < total_produk - 1; ++i) {
        for (int j = 0; j < total_produk - i - 1; ++j) {
            if (produk[j].merk > produk[j + 1].merk) {
                swap(produk[j], produk[j + 1]);
            }
        }
    }
}

void selectionSortHarga(Skincare *produk, int total_produk) {
    for (int i = 0; i < total_produk - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < total_produk; ++j) {
            if (produk[j].harga > produk[max_idx].harga) {
                max_idx = j;
            }
        }
        swap(produk[i], produk[max_idx]);
    }
}

void merge(Skincare *produk, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Skincare L[n1], R[n2];

    for (int i = 0; i < n1; ++i) L[i] = produk[left + i];
    for (int j = 0; j < n2; ++j) R[j] = produk[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].kategori.nama <= R[j].kategori.nama) {
            produk[k] = L[i];
            i++;
        } else {
            produk[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        produk[k++] = L[i++];
    }
    while (j < n2) {
        produk[k++] = R[j++];
    }
}

void mergeSortKategori(Skincare *produk, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortKategori(produk, left, mid);
        mergeSortKategori(produk, mid + 1, right);
        merge(produk, left, mid, right);
    }
}

void menuSorting(Skincare *produk, int total_produk) {
    if (total_produk == 0) {
        cout << "Belum ada produk yang dapat diurutkan" << endl;
        return;
    }

    cout << "\n---------------------------------------" << endl;
    cout << "      === Menu Sorting Produk ===      " << endl;
    cout << "1. Urutkan berdasarkan Merk (A-Z)" << endl;
    cout << "2. Urutkan berdasarkan Harga (termahal)" << endl;
    cout << "3. Urutkan berdasarkan Kategori (A-Z)" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Pilih opsi (1-3): ";
    int pilih;
    cin >> pilih;
    cin.ignore();

    switch (pilih) {
        case 1:
            bubbleSortMerk(produk, total_produk);
            cout << "Data berhasil diurutkan berdasarkan Merk (A-Z)." << endl;
            break;
        case 2:
            selectionSortHarga(produk, total_produk);
            cout << "Data berhasil diurutkan berdasarkan Harga (termahal)." << endl;
            break;
        case 3:
            mergeSortKategori(produk, 0, total_produk - 1);
            cout << "Data berhasil diurutkan berdasarkan Jenis (A-Z)." << endl;
            break;
        default:
            cout << "Pilihan anda tidak valid!" << endl;
    }
}

int main() {
    const int MAX_USER = 10;
    User users[MAX_USER];
    int total_user = 0;

    users[total_user++] = {"Ghesya", "023"};

    while (true) {
        string nama, nim;
        int attempts = 0;

        cout << "\n=== LOGIN / REGISTER ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Keluar dari program" << endl;
        cout << "Pilih opsi (1-3): ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            while (attempts < 3) {
                cout << "\nMasukkan nama: ";
                getline(cin, nama);
                cout << "Masukkan 3 digit terakhir NIM: ";
                getline(cin, nim);

                int login_index = -1;
                for (int i = 0; i < total_user; ++i) {
                    if (users[i].nama == nama && users[i].nim == nim) {
                        login_index = i;
                        break;
                    }
                }

                if (login_index != -1) {
                    cout << "Login berhasil! Awooo " << nama << "!" << endl;

                    Skincare produk[100];
                    int total_produk = 6 ;

                    produk[0] = {"Azarine", "Sunscreen", 60000, {"Face"}};
                    produk[1] = {"Npure", "Toner", 90000, {"Face"}};
                    produk[2] = {"Senka", "Sabun", 50000, {"Body"}};
                    produk[3] = {"Innisfree", "Serum", 350000, {"Face"}};
                    produk[4] = {"Skintific", "Moisturizer", 100000, {"Face"}};
                    produk[5] = {"Lavojoy", "Shampoo", 110000, {"Hair"}};

                    while (true) {
                        cout << "\n++-------------------------------------++" << endl;
                        cout << "||            === Menu ===             ||" << endl;
                        cout << "++-------------------------------------++" << endl;
                        cout << "||  1. Tambah Data Produk Skincare     ||" << endl;
                        cout << "||  2. Tampilkan Data Produk Skincare  ||" << endl;
                        cout << "||  3. Perbarui Data Produk Skincare   ||" << endl;
                        cout << "||  4. Hapus Data Produk Skincare      ||" << endl;
                        cout << "||  5. Urutkan Data Produk Skincare    ||" << endl;
                        cout << "||  6. Logout                          ||" << endl;
                        cout << "++-------------------------------------++" << endl;
                        cout << "Pilih opsi (1-6): ";
                        int pilihan_menu;
                        cin >> pilihan_menu;
                        cin.ignore();

                        switch (pilihan_menu) {
                            case 1:
                                tambahProduk(produk, &total_produk);
                                break;
                            case 2:
                                tampilkanProduk(produk, total_produk);
                                break;
                            case 3:
                                perbaruiProduk(produk, total_produk);
                                break;
                            case 4:
                                hapusProduk(produk, &total_produk);
                                break;
                            case 5:
                                menuSorting(produk, total_produk);
                                break;
                            case 6:
                                cout << "Logout berhasil! Kembali ke menu login/register >,<" << endl;
                                goto akhirMenu;
                            default:
                                cout << "Pilihan anda tidak valid!" << endl;
                        }
                    }
                akhirMenu:
                    break;

                } else {
                    attempts++;
                    cout << "Login gagal! Percobaan ke-" << attempts << " dari 3" << endl;
                    if (attempts == 3) {
                        cout << "Login gagal setelah 3 kali percobaan:b Program berhenti wlee" << endl;
                        return 0;
                    }
                }
            }
        }
        else if (pilihan == 2) {
            if (total_user < MAX_USER) {
                cout << "\nMasukkan nama: ";
                getline(cin, nama);
                cout << "Masukkan 3 digit terakhir NIM: ";
                getline(cin, nim);

                bool sudahAda = false;
                for (int i = 0; i < total_user; ++i) {
                    if (users[i].nama == nama && users[i].nim == nim) {
                        sudahAda = true;
                        break;
                    }
                }

                if (sudahAda) {
                    cout << "Username sudah ada:b gunakan nama atau NIM lain dek" << endl;
                } else {
                    users[total_user++] = {nama, nim};
                    cout << "Registrasi berhasil!" << endl;
                }

            } else {
                cout << "Yahhh jumlah pengguna sudah maksimal" << endl;
            }
        }
        else if (pilihan == 3) {
            cout << "\nTimaaci sudah menggunakan program ini!!! Papayyy" << endl;
            return 0;
        }
        else {
            cout << "Pilihan tidak valid, coba lagi yaaa" << endl;
        }
    }

    return 0;
}
