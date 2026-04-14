#include <iostream>
#include <string>
using namespace std;

struct User {
    string username;
    string password;
};

struct Obat {
    string nama;
    int stok;
    int harga;
    string waktuPakai;
};
Obat daftarObat[100];
int jumlahData = 0;

bool Login(User& admin); 
void Menu();
void Create();
void Read();
void Search();
void Sort();
void Update();
void Delete();

int main() {
    User admin = {"fakih", "009"};
    if (!Login(admin)) { 
        cout << "Kesempatan habis program berhenti" << endl;
        return 0;
    }
    int pilihan;
    do {
        Menu();
        if (!(cin >> pilihan)) {
            cout << "Input harus angka!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        switch (pilihan) {
            case 1: Create(); break;
            case 2: Read(); break;
            case 3: Sort(); break;
            case 4: Update(); break;
            case 5: Delete(); break;
            case 6: cout << "Program Selesai" << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 6);
    return 0;
}



bool Login(User& admin) {
    string inputNama, inputPass;
    int percobaan = 0;
    while (percobaan < 3) {
        cout << "\n======================================" << endl;
        cout << "           SISTEM LOGIN ADMIN" << endl;
        cout << "======================================" << endl;
        cout << "Masukkan Nama      : "; cin >> inputNama;
        cout << "Masukkan Password  : "; cin >> inputPass;

        if (inputNama == admin.username && inputPass == admin.password) { 
            return true;
        } else {
            percobaan++;
            cout << "Nama atau Password salah. Sisa: " << 3 - percobaan << " percobaan" << endl;
        }
    }
    return false;
}

void Menu() {
    cout << "\n======================================" << endl;
    cout << "    SISTEM MANAJEMEN OBAT APOTEK      " << endl;
    cout << "======================================" << endl;
    cout << "1. Tambah Obat" << endl;
    cout << "2. Tampilkan Semua Obat" << endl;
    cout << "3. Urutkan Obat" << endl;
    cout << "4. Update Data" << endl;
    cout << "5. Hapus Data" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih menu [1-6]: ";
}

void Sort() {
    if (jumlahData < 2) {
        cout << "\nData terlalu sedikit untuk diurutkan" << endl;
        return;
    }
    cout << "\n=== MENU SORTING OBAT ===" << endl;
    cout << "1. Urutkan Nama (Ascending - Bubble Sort)" << endl;
    cout << "2. Urutkan Harga (Descending - Selection Sort)" << endl;
    cout << "3. Urutkan Stok (Ascending - Insertion Sort)" << endl;
    cout << "Pilih [1-3]: ";
    int pil; cin >> pil;
    if (pil == 1) {                                  // Bubble sort
        for (int i = 0; i < jumlahData - 1; i++) {
            for (int j = 0; j < jumlahData - i - 1; j++) {
                if (daftarObat[j].nama > daftarObat[j + 1].nama) {
                    Obat temp = daftarObat[j];
                    daftarObat[j] = daftarObat[j + 1];
                    daftarObat[j + 1] = temp;
                }
            }
        }
        cout << "Data berhasil diurutkan berdasarkan nama obat(ascending)" << endl;
        Read();
    } 
    else if (pil == 2) {                              // Selection sort 
        for (int i = 0; i < jumlahData - 1; i++) {
            int maxIdx = i; 
            for (int j = i + 1; j < jumlahData; j++) {
                if (daftarObat[j].harga > daftarObat[maxIdx].harga) {
                    maxIdx = j;
                }
            }
            Obat temp = daftarObat[i];
            daftarObat[i] = daftarObat[maxIdx];
            daftarObat[maxIdx] = temp;
        }
        cout << "Data berhasil dirutkan berdasarkan harga(descending)" << endl;
        Read();
    } else if (pil == 3) {                            // Insertion sort
        for (int i = 1; i < jumlahData; i++) {
            Obat key = daftarObat[i];
            int j = i - 1;
            while (j >= 0 && daftarObat[j].stok > key.stok) { 
                daftarObat[j + 1] = daftarObat[j];
                j--;
            }
            daftarObat[j + 1] = key;
        }
        cout << "Data berhasil diurutkan berdasarkan Stok(ascending)" << endl;
        Read();
    } else {
        cout << "Pilihan tidak valid" << endl;
    } 
}

void Create() {
    cout << "\n=== Tambah Obat ===" << endl;
    cin.ignore();
    cout << "Nama obat      : "; getline(cin, daftarObat[jumlahData].nama);
    cout << "Waktu pakai  (pemakaian x jam)  : "; getline(cin, daftarObat[jumlahData].waktuPakai);
    cout << "Jumlah stok    : "; cin >> daftarObat[jumlahData].stok;
    cout << "Harga satuan  (angka) : "; cin >> daftarObat[jumlahData].harga;
    jumlahData++;
    cout << "\nData berhasil disimpan" << endl;
}

void Read() {
    if (jumlahData == 0) {
        cout << "\nData masih kosong" << endl;
    } else {
        cout << "\nNo\tNama\t\tStok\tHarga\tWaktu" << endl;
        cout << "------------------------------------------------------------" << endl;
        for (int i = 0; i < jumlahData; i++) {
            cout << i + 1 << "\t" << daftarObat[i].nama << "\t\t" 
                << daftarObat[i].stok << "\tRp" << daftarObat[i].harga 
                << "\t" << daftarObat[i].waktuPakai << endl;
        }
        char subPilihan;
        cout << "\nIngin mencari obat? (y/n): "; cin >> subPilihan;
        if (subPilihan == 'y' || subPilihan == 'Y') {
            cin.ignore(1000, '\n');
            string cari;
            cout << "Masukkan Nama Obat: "; getline(cin, cari);
            bool temu = false;
            for (int i = 0; i < jumlahData; i++) {
                if (daftarObat[i].nama == cari) {
                    cout << "\nDitemukan: " << daftarObat[i].nama << " | Stok: " << daftarObat[i].stok << " | Harga: Rp" << daftarObat[i].harga << endl;
                    temu = true;
                }
            }
            if (!temu) cout << "Obat tidak ditemukan" << endl;
        }
    }
}

void Search() {
    cin.ignore();
    string cari;
    cout << "Masukkan Nama Obat: "; getline(cin, cari);
    bool temu = false;
    for (int i = 0; i < jumlahData; i++) {
        if (daftarObat[i].nama == cari) {
            cout << "Ditemukan: " << daftarObat[i].nama << " | Stok: " << daftarObat[i].stok << endl;
            temu = true;
        }
    }
    if (!temu) cout << "Obat tidak ditemukan" << endl;
}

void Update() {
    if (jumlahData == 0) return;
        for (int i = 0; i < jumlahData; i++) cout << i + 1 << ". " << daftarObat[i].nama << endl;
        int nomor;
        cout << "\nNomor urut yang diupdate: "; cin >> nomor;
        cin.ignore(1000, '\n');
    cout << "Nomor urut update: "; cin >> nomor;
    if (nomor > 0 && nomor <= jumlahData) {
        int idx = nomor - 1;
        cin.ignore();
        cout << "Nama Baru: "; getline(cin, daftarObat[idx].nama);
        cout << "Stok Baru: "; cin >> daftarObat[idx].stok;
        cout << "Harga Baru: "; cin >> daftarObat[idx].harga;
        cout << "Update Berhasil" << endl;
    }
}

void Delete() {
    if (jumlahData == 0) return;
        for (int i = 0; i < jumlahData; i++) cout << i + 1 << ". " << daftarObat[i].nama << endl;
        int nomor;
        cout << "\nNomor urut yang diupdate: "; cin >> nomor;
        cin.ignore(1000, '\n');
    cout << "Nomor urut hapus: "; cin >> nomor;
    if (nomor > 0 && nomor <= jumlahData) {
        for (int i = nomor - 1; i < jumlahData - 1; i++) daftarObat[i] = daftarObat[i + 1];
        jumlahData--;
        cout << "Data terhapus" << endl;
    }
}