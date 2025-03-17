#include <iostream>
#include <string>
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
    
    string merk[100], jenis[100];
    double harga[100];
    int total_produk = 5;

    merk[0] = "Azarine";
    jenis[0] = "Sunscreen";
    harga[0] = 60000;

    merk[1] = "Npure";
    jenis[1] = "Toner";
    harga[1] = 90000;

    merk[2] = "Senka";
    jenis[2] = "Sabun";
    harga[2] = 50000;

    merk[3] = "Innisfree";
    jenis[3] = "Serum";
    harga[3] = 350000;

    merk[4] = "Skintific";
    jenis[4] = "Moisturizer";
    harga[4] = 100000;

    while (true) {
        int pilihan;
        cout << "\n-----------------------------------------" << endl;
        cout << "||            === Menu ===             ||" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "||  1. Tambah Data Produk Skincare     ||" << endl;
        cout << "||  2. Tampilkan Data Produk Skincare  ||" << endl;
        cout << "||  3. Perbarui Data Produk Skincare   ||" << endl;
        cout << "||  4. Hapus Data Produk Skincare      ||" << endl;
        cout << "||  5. Keluar dari program             ||" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

        if (pilihan == 1) {
            if (total_produk < 100) {
                cout << "Masukkan merk skincare: ";
                cin >> merk[total_produk];
                cout << "Masukkan jenis skincare: ";
                cin >> jenis[total_produk];
                cout << "Masukkan harga skincare: ";
                cin >> harga[total_produk];

                total_produk++;
                cout << "Data berhasil ditambahkan!" << endl;
            } else {
                cout << "Jumlah data sudah penuh >_< huhuhuu tidak bisa ditambah lagi" << endl;
            }
        }
        else if (pilihan == 2) {
            if (total_produk == 0) {
                cout << "Belum ada data produk skincare untuk ditampilkan" << endl;
            } else {
                cout << "\n-----------------------------------------------------" << endl;
                cout << "=== Data Produk Skincare ===" << endl;
                cout << "-----------------------------------------------------" << endl;
                for (int i = 0; i < total_produk; ++i) {
                    cout << i + 1 << " | Merk : " << merk[i] << ", Jenis : " << jenis[i] << ", Harga : " << harga[i] << endl;
                }
                cout << "-----------------------------------------------------" << endl;
            }
        }
        else if (pilihan == 3) {
            if (total_produk == 0) {
                cout << "Belum ada data produk skincare untuk diperbarui" << endl;
            } else {
                int no;
                cout << "\n=== Data Produk Skincare ===" << endl;
                cout << "-----------------------------------------------------" << endl;
                for (int i = 0; i < total_produk; ++i) {
                    cout << i + 1 << " | Merk : " << merk[i] << ", Jenis : " << jenis[i] << ", Harga : " << harga[i] << endl;
                }
                cout << "-----------------------------------------------------" << endl;
                cout << "\nMasukkan nomor produk yang ingin diperbarui: ";
                cin >> no;

                if (no < 1 || no > total_produk) {
                    cout << "Nomor produk tidak valid" << endl;
                } else {
                    cout << "Masukkan merk baru: ";
                    cin >> merk[no - 1];
                    cout << "Masukkan jenis baru: ";
                    cin >> jenis[no - 1];
                    cout << "Masukkan harga baru: ";
                    cin >> harga[no - 1];
                    cout << "Data berhasil diperbarui!" << endl;
                }
            }
        }
        else if (pilihan == 4) {
            if (total_produk == 0) {
                cout << "Belum ada data produk skincare untuk dihapus" << endl;
            } else {
                int no;
                cout << "\n=== Data Produk Skincare ===" << endl;
                cout << "-----------------------------------------------------" << endl;
                for (int i = 0; i < total_produk; ++i) {
                    cout << i + 1 << " | Merk : " << merk[i] << ", Jenis : " << jenis[i] << ", Harga : " << harga[i] << endl;
                }
                cout << "-----------------------------------------------------" << endl;
                cout << "\nMasukkan nomor produk yang ingin dihapus: ";
                cin >> no;

                if (no < 1 || no > total_produk) {
                    cout << "Nomor produk tidak valid" << endl;
                } else {
                    for (int i = no - 1; i < total_produk - 1; ++i) {
                        merk[i] = merk[i + 1];
                        jenis[i] = jenis[i + 1];
                        harga[i] = harga[i + 1];
                    }
                    total_produk--;
                    cout << "Data berhasil dihapus!" << endl;
                }
            }
        }
        else if (pilihan == 5) {
            cout << "Timaaci telah menggunakan program ini!!! papayyy" << endl;
            break;
        } else {
            cout << "Pilihan anda tidak valid!" << endl;
        }
    }

    return 0;
}
