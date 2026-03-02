#include <iostream>
#include <string>
using namespace std;

int main(){
    string nama, password;
    int percobaan = 0;
    bool login = false;

    while (percobaan < 3) {
        cout << "=== SISTEM LOGIN ===" << endl;
        cout << "Masukkan Nama: " << endl;
        cin >> nama;
        cout << "Masukkan password: " << endl;
        cin >> password;

        if(nama == "fakih" && password == "009"){
            login = true;
            cout << "Login berhasil Selamat datang " << nama << endl;
            break;
        } else {
            percobaan ++;
            cout << "Nama atau Password salah! Sisa percobaan: " << 3 - percobaan << endl;
        }
    }

if (!login) {
    cout << "Akses ditolak. Program berhenti" << endl;
    return 0;
}

int pilihan;
double nilai;

do{
    cout << "=== MENU UTAMA KONVERSI ===" << endl;
    cout << "1. jam -> Menit dan Detik" << endl;
    cout << "2. Menit -> jam dan Detik" << endl;
    cout << "3. Detik -> jam dan Menit" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu (1-4): ";
    cin >> pilihan;

    if (pilihan >= 1 && pilihan <= 3) {
        cout << "Masukkan nilai waktu: ";
        cin >> nilai;

        switch (pilihan) {
            case 1:
                cout << "Hasil: " << nilai << nilai << " jam = " << (nilai * 60) << " Menit dan " << (nilai * 3600) << " Detik " << endl;
                break;
            case 2: // Menit ke Jam & Detik
                cout << "Hasil: " << nilai << " Menit = " << (nilai / 60) << " Jam dan " << (nilai * 60) << " Detik" << endl;
                break;
            case 3: // Detik ke Jam & Menit
                cout << "Hasil: " << nilai << " Detik = " << (nilai / 3600) << " Jam dan " << (nilai / 60) << " Menit" << endl;
                break;    
        }
    } else if (pilihan == 4) {
        cout << "Terimakasih telah menggunakan program ini" << endl;
    } else {
        cout << "Pilihan tidak valid!" << endl;
    }
} while (pilihan != 4); 

    return 0;
}