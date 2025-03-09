#include <iostream>
#include <limits>

using namespace std;

string getUsername() {
    return "Muhammad Rayhan Setiawan";
}

string getPassword() {
    return "2409106083";
}

bool login() {
    string username, password;
    int attempts = 0;
    
    while (attempts < 3) {
        cout << "\nUsername: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);
        
        if (username == getUsername() && password == getPassword()) {
            return true;
        }
        cout << "Login gagal! Coba lagi.\n";
        attempts++;
    }
    return false;
}

int menuUtama() {
    int pilihan;
    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Konversi Mata Uang\n";
        cout << "2. Konversi Jarak\n";
        cout << "3. Konversi Waktu\n";
        cout << "4. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (pilihan < 1 || pilihan > 4);
    return pilihan;
}

double konversiMataUang(int pilihan, double jumlah) {
    if (pilihan == 1) return jumlah / 15000;
    if (pilihan == 2) return jumlah / 16000;
    if (pilihan == 3) return jumlah * 15000;
    if (pilihan == 4) return jumlah * 0.9;
    if (pilihan == 5) return jumlah * 16000;
    if (pilihan == 6) return jumlah / 0.9;
    return 0;
}

double konversiJarak(int pilihan, double jumlah) {
    if (pilihan == 1) return jumlah * 1000;
    if (pilihan == 2) return jumlah * 100000;
    if (pilihan == 3) return jumlah / 1000;
    if (pilihan == 4) return jumlah * 100;
    if (pilihan == 5) return jumlah / 100000;
    if (pilihan == 6) return jumlah / 100;
    return 0;
}

double konversiWaktu(int pilihan, double jumlah) {
    if (pilihan == 1) return jumlah * 60;
    if (pilihan == 2) return jumlah * 3600;
    if (pilihan == 3) return jumlah / 60;
    if (pilihan == 4) return jumlah * 60;
    if (pilihan == 5) return jumlah / 3600;
    if (pilihan == 6) return jumlah / 60;
    return 0;
}

int main() {
    if (!login()) {
        cout << "Kesempatan habis! Program berhenti.\n";
        return 0;
    }
    
    while (true) {
        int pilihan = menuUtama();
        if (pilihan == 4) {
            cout << "Logout berhasil!\n";
            break;
        }
        
        int subPilihan;
        double jumlah;
        
        if (pilihan == 1) {
            do {
                cout << "\n===== KONVERSI MATA UANG =====\n";
                cout << "1. Rupiah ke Dolar AS\n2. Rupiah ke Euro\n";
                cout << "3. Dolar AS ke Rupiah\n4. Dolar AS ke Euro\n";
                cout << "5. Euro ke Rupiah\n6. Euro ke Dolar AS\n7. Kembali\nPilih: ";
                cin >> subPilihan;
                
                if (subPilihan >= 1 && subPilihan <= 6) {
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;
                    cout << "Hasil: " << konversiMataUang(subPilihan, jumlah) << "\n";
                }
            } while (subPilihan != 7);
        }
        
        else if (pilihan == 2) {
            do {
                cout << "\n===== KONVERSI JARAK =====\n";
                cout << "1. Kilometer ke Meter\n2. Kilometer ke Centimeter\n";
                cout << "3. Meter ke Kilometer\n4. Meter ke Centimeter\n";
                cout << "5. Centimeter ke Kilometer\n6. Centimeter ke Meter\n7. Kembali\nPilih: ";
                cin >> subPilihan;
                
                if (subPilihan >= 1 && subPilihan <= 6) {
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;
                    cout << "Hasil: " << konversiJarak(subPilihan, jumlah) << "\n";
                }
            } while (subPilihan != 7);
        }
        
        else if (pilihan == 3) {
            do {
                cout << "\n===== KONVERSI WAKTU =====\n";
                cout << "1. Jam ke Menit\n2. Jam ke Detik\n";
                cout << "3. Menit ke Jam\n4. Menit ke Detik\n";
                cout << "5. Detik ke Jam\n6. Detik ke Menit\n7. Kembali\nPilih: ";
                cin >> subPilihan;
                
                if (subPilihan >= 1 && subPilihan <= 6) {
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;
                    cout << "Hasil: " << konversiWaktu(subPilihan, jumlah) << "\n";
                }
            } while (subPilihan != 7);
        }
    }
    
    return 0;
}
