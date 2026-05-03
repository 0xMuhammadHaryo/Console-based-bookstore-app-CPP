#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

namespace TokoBuku {

    // Struct Buku
    struct Buku {
        string judul;
        string kategori;
        double harga;
        int stok;
        int terjual;
    };

    // Fungsi untuk hitung total transkasi
    inline double hitungTotal(double harga, int jumlah) {
        return harga * jumlah;
    }

    // template untuk mencari index terbesar 
    template <typename T>
    int cariTerbesar(T arr[], int n) {
        int idx = 0;
        for (int i = 1; i < n; i++)
            if (arr[i] > arr[idx]) idx = i;
        return idx;
    }

    void updateBuku(Buku &b, double hargaBaru) {
        b.harga = hargaBaru;
    }

    void updateBuku(Buku &b, int stokBaru) {
        b.stok = stokBaru;
    }

    void updateBuku(Buku &b, double hargaBaru, int stokBaru) {
        b.harga = hargaBaru;
        b.stok = stokBaru;
    }

    // Fungsi untuk menampilkna data buku
    void tampilBuku(const Buku &b, bool detail = true) {
        cout << "Judul   : " << b.judul << endl;
        if (detail) {
            cout << "Kategori: " << b.kategori << endl;
            cout << "Harga   : " << b.harga << endl;
            cout << "Stok    : " << b.stok << endl;
            cout << "Terjual : " << b.terjual << endl;
        }
        cout << "---------------------------\n";
    }

    void tampilSemua(Buku *arr, int n) {
        if (n == 0) {
            cout << "Data kosong!\n";
            return;
        }
        for (int i = 0; i < n; i++)
            tampilBuku(arr[i]);
    }

    // Fungsi untuk load data buku dari file txt
    void loadData(Buku *&arr, int &n) {
        ifstream file("data_buku.txt");
        if (!file) return;

        file >> n;
        file.ignore();

        arr = new Buku[n];
        for (int i = 0; i < n; i++) {
            getline(file, arr[i].judul);
            getline(file, arr[i].kategori);
            file >> arr[i].harga >> arr[i].stok >> arr[i].terjual;
            file.ignore();
        }
        file.close();
    }

    // Fungsi untuk save data buku ke file txt
    void saveData(Buku *arr, int n) {
        ofstream file("data_buku.txt");
        file << n << endl;
        for (int i = 0; i < n; i++) {
            file << arr[i].judul << endl;
            file << arr[i].kategori << endl;
            file << arr[i].harga << " "
                 << arr[i].stok << " "
                 << arr[i].terjual << endl;
        }
        file.close();
    }

    // Fungsi untuk menambahkan buku
    void tambahBuku(Buku *&arr, int &n) {
        Buku *temp = new Buku[n + 1];
        for (int i = 0; i < n; i++)
            temp[i] = arr[i];

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Judul   : "; getline(cin, temp[n].judul);
        cout << "Kategori: "; getline(cin, temp[n].kategori);
        cout << "Harga   : "; cin >> temp[n].harga;
        cout << "Stok    : "; cin >> temp[n].stok;
        temp[n].terjual = 0;

        delete[] arr;
        arr = temp;
        n++;

        cout << "Buku berhasil ditambahkan!\n";
    }

    // Fungsi untuk update buku 
   void updateBuku(Buku *arr, int n) {
    string cari;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Judul buku: ";
    getline(cin, cari);

    for (int i = 0; i < n; i++) {
        if (arr[i].judul == cari) {

            int pilih;
            cout << "1. Update Harga\n";
            cout << "2. Update Stok\n";
            cout << "3. Update Keduanya\n";
            cout << "Pilih: ";
            cin >> pilih;

            if (pilih == 1) {
                double hargaBaru;
                cout << "Harga baru: ";
                cin >> hargaBaru;
                updateBuku(arr[i], hargaBaru);

            } else if (pilih == 2) {
                int stokBaru;
                cout << "Stok baru: ";
                cin >> stokBaru;
                updateBuku(arr[i], stokBaru);

            } else if (pilih == 3) {
                double hargaBaru;
                int stokBaru;
                cout << "Harga baru: ";
                cin >> hargaBaru;
                cout << "Stok baru: ";
                cin >> stokBaru;
                updateBuku(arr[i], hargaBaru, stokBaru);
            }

            cout << "Update berhasil!\n";
            return;
        }
    }

    cout << "Buku tidak ditemukan!\n";
    }

    // Fungsi untuk menghapus buku
    void hapusBuku(Buku *&arr, int &n) {
        string cari;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Judul buku: ";
        getline(cin, cari);

        int idx = -1;
        for (int i = 0; i < n; i++)
            if (arr[i].judul == cari) idx = i;

        if (idx == -1) {
            cout << "Buku tidak ditemukan!\n";
            return;
        }

        Buku *temp = new Buku[n - 1];
        for (int i = 0, j = 0; i < n; i++)
            if (i != idx) temp[j++] = arr[i];

        delete[] arr;
        arr = temp;
        n--;

        cout << "Buku berhasil dihapus!\n";
    }

    // Fungsi unntuk transaksi buku
    void transaksi(Buku *arr, int n, double &totalPendapatan) {
        string cari;
        int jumlah;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Judul buku : ";
        getline(cin, cari);
        cout << "Jumlah beli: ";
        cin >> jumlah;

        for (int i = 0; i < n; i++) {
            if (arr[i].judul == cari) {
                if (jumlah <= arr[i].stok) {
                    arr[i].stok -= jumlah;
                    arr[i].terjual += jumlah;

                    double total = hitungTotal(arr[i].harga, jumlah);
                    totalPendapatan += total;

                    cout << "Transaksi berhasil! Total: " << total << endl;
                } else {
                    cout << "Stok tidak cukup!\n";
                }
                return;
            }
        }
        cout << "Buku tidak ditemukan!\n";
    }

    // Fungsi untuk menampilkan buku terlaris dari data
    void bukuTerlaris(Buku *arr, int n) {
        if (n == 0) return;

        int *data = new int[n];
        for (int i = 0; i < n; i++)
            data[i] = arr[i].terjual;

        int idx = cariTerbesar(data, n);
        cout << "Buku Terlaris: " << arr[idx].judul << endl;

        delete[] data;
    }

    // Fungsi Hitung total buku terjual
    int hitungTotalTerjual(Buku *arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i].terjual;
    }
    return total;
    }

    // Fungsi cetak laporan     
    void cetakLaporan(Buku *arr, int n, double totalPendapatan) {
    ofstream file("laporan_harian.txt");

    file << "===== LAPORAN HARIAN TOKO BUKU =====\n\n";

    file << "Total Buku Terjual: " << hitungTotalTerjual(arr, n) << "\n";
    file << "Total Pendapatan: " << totalPendapatan << "\n";

    file << "===== DAFTAR BUKU TERJUAL =====\n";
    for (int i = 0; i < n; i++) {
        if (arr[i].terjual > 0) {
            file << "Judul   : " << arr[i].judul << "\n";
            file << "Kategori: " << arr[i].kategori << "\n";
            file << "Harga   : " << arr[i].harga << "\n";
            file << "Stok    : " << arr[i].stok << "\n";
            file << "Terjual : " << arr[i].terjual << "\n";
            file << "---------------------------\n";
        }
    }

    file.close();
    }
    
}


// Main Function
int main() {
    using namespace TokoBuku;

    Buku *buku = nullptr;
    int n = 0;
    double totalPendapatan = 0;
    int pilih;

    loadData(buku, n);

    do {
        cout << "\n===== MENU TOKO BUKU =====\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Buku\n";
        cout << "3. Update Buku\n";
        cout << "4. Hapus Buku\n";
        cout << "5. Transaksi\n";
        cout << "6. Buku Terlaris\n";
        cout << "7. Total Pendapatan\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahBuku(buku, n); break;
            case 2: tampilSemua(buku, n); break;
            case 3: updateBuku(buku, n); break;
            case 4: hapusBuku(buku, n); break;
            case 5: transaksi(buku, n, totalPendapatan); break;
            case 6: bukuTerlaris(buku, n); break;
            case 7: cout << "Total Pendapatan: " << totalPendapatan << endl; break;
            case 0: cout << "Keluar...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 0);

    saveData(buku, n);
    cetakLaporan(buku, n, totalPendapatan);
    delete[] buku;
} 