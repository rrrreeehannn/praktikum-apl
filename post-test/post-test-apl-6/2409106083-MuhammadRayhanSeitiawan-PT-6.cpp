#include <iostream>
#include <string>
using namespace std;

const int MAKS_TIKET = 100;

string namaPemesan[MAKS_TIKET];
string tujuanPelayaran[MAKS_TIKET];
string tanggalPelayaran[MAKS_TIKET];
int jumlahTiket = 0;

// Fungsi login (parameter reference)
void login(const string& namaBenar, const string& nimBenar) {
    string namaInput, nimInput;
    int attempts = 0;
    bool loginBerhasil = false;

    while (attempts < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, namaInput);
        cout << "Masukkan NIM: ";
        cin >> nimInput;
        cin.ignore();

        if (namaInput == namaBenar && nimInput == nimBenar) {
            loginBerhasil = true;
            break;
        } else {
            cout << "Nama atau NIM salah! Coba lagi.\n";
            attempts++;
        }
    }

    if (!loginBerhasil) {
        cout << "Login gagal setelah 3 kali percobaan. Program berhenti.\n";
        exit(0);
    }
}

// Fungsi tambah tiket (parameter dereference pointer)
void tambahTiket(string* nama, string* tujuan, string* tanggal) {
    namaPemesan[jumlahTiket] = *nama;
    tujuanPelayaran[jumlahTiket] = *tujuan;
    tanggalPelayaran[jumlahTiket] = *tanggal;
    jumlahTiket++;
}

void inputTiket() {
    if (jumlahTiket >= MAKS_TIKET) {
        cout << "Tiket sudah penuh!\n";
        return;
    }

    string nama, tujuan, tanggal;
    cout << "Masukkan Nama Pemesan: ";
    getline(cin, nama);
    cout << "Masukkan Tujuan Pelayaran: ";
    getline(cin, tujuan);
    cout << "Masukkan Tanggal Pelayaran (DD-MM-YYYY): ";
    getline(cin, tanggal);

    tambahTiket(&nama, &tujuan, &tanggal);
    cout << "Tiket berhasil dipesan!\n";
}

void tampilkanTiket() {
    if (jumlahTiket == 0) {
        cout << "Belum ada tiket kapal yang dipesan.\n";
        return;
    }

    cout << "\nDaftar Tiket Kapal yang Sudah Dipesan:\n";
    for (int i = 0; i < jumlahTiket; i++) {
        cout << "Tiket " << i + 1 << " - "
             << "Nama: " << namaPemesan[i]
             << ", Tujuan: " << tujuanPelayaran[i]
             << ", Tanggal: " << tanggalPelayaran[i] << endl;
    }
}

void ubahTiket(int* nomor) {
    if (*nomor < 1 || *nomor > jumlahTiket) {
        cout << "Tiket tidak ditemukan.\n";
        return;
    }

    int idx = *nomor - 1;
    cout << "Data tiket saat ini:\n";
    cout << "Nama: " << namaPemesan[idx] << "\n";
    cout << "Tujuan: " << tujuanPelayaran[idx] << "\n";
    cout << "Tanggal: " << tanggalPelayaran[idx] << "\n";

    cout << "Masukkan Nama Baru: ";
    getline(cin, namaPemesan[idx]);
    cout << "Masukkan Tujuan Baru: ";
    getline(cin, tujuanPelayaran[idx]);
    cout << "Masukkan Tanggal Baru: ";
    getline(cin, tanggalPelayaran[idx]);

    cout << "Tiket berhasil diperbarui!\n";
}

void hapusTiketRekursif(int index) {
    if (index >= jumlahTiket - 1) return;

    namaPemesan[index] = namaPemesan[index + 1];
    tujuanPelayaran[index] = tujuanPelayaran[index + 1];
    tanggalPelayaran[index] = tanggalPelayaran[index + 1];

    hapusTiketRekursif(index + 1);
}

void hapusTiket(int* nomor) {
    if (*nomor < 1 || *nomor > jumlahTiket) {
        cout << "Tiket tidak ditemukan.\n";
        return;
    }

    hapusTiketRekursif(*nomor - 1);
    jumlahTiket--;
    cout << "Tiket berhasil dihapus!\n";
}

// === FUNGSI SORTING ===

// 1. Sorting Nama Pemesan ASCENDING (Bubble Sort)
void sortingNamaAscending() {
    for (int i = 0; i < jumlahTiket - 1; i++) {
        for (int j = 0; j < jumlahTiket - i - 1; j++) {
            if (namaPemesan[j] > namaPemesan[j + 1]) {
                swap(namaPemesan[j], namaPemesan[j + 1]);
                swap(tujuanPelayaran[j], tujuanPelayaran[j + 1]);
                swap(tanggalPelayaran[j], tanggalPelayaran[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Nama (A-Z).\n";
}

// 2. Sorting Tanggal DESCENDING (Selection Sort)
void sortingTanggalDescending() {
    for (int i = 0; i < jumlahTiket - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < jumlahTiket; j++) {
            if (tanggalPelayaran[j] > tanggalPelayaran[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(namaPemesan[i], namaPemesan[maxIdx]);
        swap(tujuanPelayaran[i], tujuanPelayaran[maxIdx]);
        swap(tanggalPelayaran[i], tanggalPelayaran[maxIdx]);
    }
    cout << "Data berhasil diurutkan berdasarkan Tanggal (terbaru dulu).\n";
}

// 3. Sorting Tujuan Pelayaran ASCENDING (Insertion Sort)
void sortingTujuanAscending() {
    for (int i = 1; i < jumlahTiket; i++) {
        string keyNama = namaPemesan[i];
        string keyTujuan = tujuanPelayaran[i];
        string keyTanggal = tanggalPelayaran[i];
        int j = i - 1;

        while (j >= 0 && tujuanPelayaran[j] > keyTujuan) {
            namaPemesan[j + 1] = namaPemesan[j];
            tujuanPelayaran[j + 1] = tujuanPelayaran[j];
            tanggalPelayaran[j + 1] = tanggalPelayaran[j];
            j--;
        }
        namaPemesan[j + 1] = keyNama;
        tujuanPelayaran[j + 1] = keyTujuan;
        tanggalPelayaran[j + 1] = keyTanggal;
    }
    cout << "Data berhasil diurutkan berdasarkan Tujuan (A-Z).\n";
}

int main() {
    login("Muhammad Rayhan Setiawan", "083");

    int pilihan;
    do {
        cout << "\n=== Menu Sistem Pemesanan Tiket Kapal ===\n";
        cout << "1. Beli Tiket Kapal\n";
        cout << "2. Lihat Daftar Tiket\n";
        cout << "3. Ubah Tiket\n";
        cout << "4. Hapus Tiket\n";
        cout << "5. Urutkan Data Tiket\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                inputTiket();
                break;
            case 2:
                tampilkanTiket();
                break;
            case 3: {
                int nomor;
                cout << "Masukkan nomor tiket yang ingin diubah: ";
                cin >> nomor;
                cin.ignore();
                ubahTiket(&nomor);
                break;
            }
            case 4: {
                int nomor;
                cout << "Masukkan nomor tiket yang ingin dihapus: ";
                cin >> nomor;
                cin.ignore();
                hapusTiket(&nomor);
                break;
            }
            case 5: {
                int pilihSort;
                cout << "\n=== Menu Sorting ===\n";
                cout << "1. Urutkan berdasarkan Nama (Ascending)\n";
                cout << "2. Urutkan berdasarkan Tanggal (Descending)\n";
                cout << "3. Urutkan berdasarkan Tujuan (Ascending)\n";
                cout << "Pilih metode sorting: ";
                cin >> pilihSort;
                cin.ignore();

                if (pilihSort == 1)
                    sortingNamaAscending();
                else if (pilihSort == 2)
                    sortingTanggalDescending();
                else if (pilihSort == 3)
                    sortingTujuanAscending();
                else
                    cout << "Pilihan sorting tidak valid!\n";

                break;
            }
            case 6:
                cout << "Terima kasih telah menggunakan sistem pemesanan tiket kapal.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 6);

    return 0;
}