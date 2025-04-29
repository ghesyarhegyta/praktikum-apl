#include <iostream>
using namespace std;

const int MAKS = 100;

struct Mahasiswa
{
    string nama;
    string jurusan;
};

Mahasiswa mahasiswa[MAKS];
int jumlahData = 0;

// CREATE
void tambahMahasiswa(Mahasiswa *data, int &jumlah, string namaBaru, string jurusanBaru)
{
    if (jumlah < MAKS)
    {
        data[jumlah].nama = namaBaru;
        data[jumlah].jurusan = jurusanBaru;
        jumlah++;
        cout << "Mahasiswa ditambahkan.\n";
    }
    else
    {
        cout << "Data penuh!\n";
    }
}

// READ
void tampilMahasiswa(Mahasiswa *data, const int &jumlah)
{
    cout << "\nDaftar Mahasiswa:\n";
    if (jumlah == 0)
    {
        cout << "Belum ada data mahasiswa.\n";
        return;
    }
    for (int i = 0; i < jumlah; i++)
    {
        cout << i + 1 << ". Nama: " << data[i].nama << ", Jurusan: " << data[i].jurusan << endl;
    }
}

// UPDATE
void ubahMahasiswa(Mahasiswa *data, const int &jumlah, int index, string namaBaru, string jurusanBaru)
{
    if (index >= 0 && index < jumlah)
    {
        data[index].nama = namaBaru;
        data[index].jurusan = jurusanBaru;
        cout << "Data berhasil diubah.\n";
    }
    else
    {
        cout << "Index tidak valid!\n";
    }
}

// DELETE
void hapusMahasiswa(Mahasiswa *data, int &jumlah, int index)
{
    if (index >= 0 && index < jumlah)
    {
        for (int i = index; i < jumlah - 1; i++)
        {
            data[i] = data[i + 1];
        }
        jumlah--;
        cout << "Data berhasil dihapus.\n";
    }
    else
    {
        cout << "Index tidak valid!\n";
    }
}

// Bubble Sort
void bubbleSort(Mahasiswa *data, const int &jumlah)
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = 0; j < jumlah - i - 1; j++)
        {
            if (data[j].nama > data[j + 1].nama)
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
    cout << "Data telah diurutkan dengan Bubble Sort.\n";
}

// Selection Sort
void selectionSort(Mahasiswa *data, const int &jumlah)
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < jumlah; j++)
        {
            if (data[j].nama < data[minIdx].nama)
            {
                minIdx = j;
            }
        }
        swap(data[i], data[minIdx]);
    }
    cout << "Data telah diurutkan dengan Selection Sort.\n";
}

// Insertion Sort
void insertionSort(Mahasiswa *data, const int &jumlah)
{
    for (int i = 1; i < jumlah; i++)
    {
        Mahasiswa key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].nama > key.nama)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
    cout << "Data telah diurutkan dengan Insertion Sort.\n";
}

int main()
{
    int pilihan;
    string nama, jurusan;
    int index;

    do
    {
        cout << "\n===== MENU CRUD MAHASISWA (Struct + Sorting) =====\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Mahasiswa\n";
        cout << "3. Ubah Mahasiswa\n";
        cout << "4. Hapus Mahasiswa\n";
        cout << "5. Urutkan Mahasiswa (berdasarkan Nama)\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nama: ";
            getline(cin, nama);
            cout << "Masukkan jurusan: ";
            getline(cin, jurusan);
            tambahMahasiswa(mahasiswa, jumlahData, nama, jurusan);
            break;
        case 2:
            tampilMahasiswa(mahasiswa, jumlahData);
            break;
        case 3:
            tampilMahasiswa(mahasiswa, jumlahData);
            cout << "Masukkan nomor yang ingin diubah: ";
            cin >> index;
            cin.ignore();
            cout << "Masukkan nama baru: ";
            getline(cin, nama);
            cout << "Masukkan jurusan baru: ";
            getline(cin, jurusan);
            ubahMahasiswa(mahasiswa, jumlahData, index - 1, nama, jurusan);
            break;
        case 4:
            tampilMahasiswa(mahasiswa, jumlahData);
            cout << "Masukkan nomor yang ingin dihapus: ";
            cin >> index;
            hapusMahasiswa(mahasiswa, jumlahData, index - 1);
            break;
        case 5:
            int metode;
            cout << "Pilih metode sorting:\n";
            cout << "1. Bubble Sort\n";
            cout << "2. Selection Sort\n";
            cout << "3. Insertion Sort\n";
            cout << "Pilihan: ";
            cin >> metode;
            switch (metode)
            {
            case 1:
                bubbleSort(mahasiswa, jumlahData);
                break;
            case 2:
                selectionSort(mahasiswa, jumlahData);
                break;
            case 3:
                insertionSort(mahasiswa, jumlahData);
                break;
            default:
                cout << "Metode tidak valid!\n";
            }
            break;
        case 6:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}
