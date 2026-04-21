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
bool hargaUrut = false; 
bool Login(User& admin); 
void Menu();
void Create();
void Read();
void Search();
void Sort();
void Update();
void Delete();

int main() {
    daftarObat[0] = {"Paracetamol", 50, 5000, "3x24"};
    daftarObat[1] = {"Amoxicillin", 30, 15000, "3x24"};
    daftarObat[2] = {"Vitamin C", 100, 10000, "1x24"};
    daftarObat[3] = {"Ibuprofen", 45, 8000, "2x24"};
    daftarObat[4] = {"Cetirizine", 20, 7500, "1x24"};
    jumlahData = 5;

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
        hargaUrut = false;
        cout << "Data berhasil diurutkan berdasarkan nama obat (ascending)" << endl;
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
        hargaUrut = true; 
        cout << "Data berhasil diurutkan berdasarkan harga (descending)" << endl;
        Read();
    } 
    else if (pil == 3) {                            // Insertion sort
        for (int i = 1; i < jumlahData; i++) {
            Obat key = daftarObat[i];
            int j = i - 1;
            while (j >= 0 && daftarObat[j].stok > key.stok) { 
                daftarObat[j + 1] = daftarObat[j];
                j--;
            }
            daftarObat[j + 1] = key;
        }
        hargaUrut = false;
        cout << "Data berhasil diurutkan berdasarkan Stok (ascending)" << endl;
        Read();
    } else {
        cout << "Pilihan tidak valid" << endl;
    } 
}

void Create() {
    cout << "\n=== Tambah Obat ===" << endl;
    cin.ignore(1000, '\n');
    cout << "Nama obat      : "; getline(cin, daftarObat[jumlahData].nama);
    cout << "Waktu pakai  (pemakaian x jam)  : "; getline(cin, daftarObat[jumlahData].waktuPakai);
    cout << "Jumlah stok    : "; cin >> daftarObat[jumlahData].stok;
    cout << "Harga satuan  (angka) : "; cin >> daftarObat[jumlahData].harga;
    jumlahData++;
    hargaUrut = false; 
    cout << "\nData berhasil disimpan" << endl;
}

void Read() {
    if (jumlahData == 0) {
        cout << "\nData masih kosong" << endl;
    } else {
        cout << "\nNo\tNama\t\tWaktu\t\tStok\tHarga" << endl;
        cout << "------------------------------------------------------------" << endl;
        for (int i = 0; i < jumlahData; i++) {
            cout << i + 1 << "\t" << daftarObat[i].nama;
            if (daftarObat[i].nama.length() < 8) cout << "\t\t"; else cout << "\t";
            cout << daftarObat[i].waktuPakai;
            if (daftarObat[i].waktuPakai.length() < 8) cout << "\t\t"; else cout << "\t";
            cout << daftarObat[i].stok << "\t" << "Rp" << daftarObat[i].harga;
            if (daftarObat[i].stok < 5) cout << " (Stok hampir habis)";
            cout << endl;
        }
        char subPilihan;
        cout << "\nIngin mencari obat? (y/n): "; cin >> subPilihan;
        if (subPilihan == 'y' || subPilihan == 'Y') {
            Search(); 
        }
    }
}

void Search() {
    if (jumlahData == 0) {
        cout << "Data masih kosong!" << endl;
        return;
    }
    int pilPencarian;
    cout << "\n=== METODE PENCARIAN ===" << endl;
    cout << "1. Cari berdasarkan Nama Obat (Linear Search)" << endl;
    cout << "2. Cari berdasarkan Harga Obat (Binary Search)" << endl;
    cout << "Pilih [1-2]: ";
    cin >> pilPencarian;
    if (pilPencarian == 1) {                                                                 // Linear search
        cin.ignore(1000, '\n');
        string cari;
        cout << "Masukkan Nama Obat: "; getline(cin, cari);
        bool temu = false;
        for (int i = 0; i < jumlahData; i++) {
            if (daftarObat[i].nama == cari) {
                cout << "\n-> Ditemukan: " << daftarObat[i].nama 
                    << " | Stok: " << daftarObat[i].stok 
                    << " | Harga: Rp" << daftarObat[i].harga << endl;
                temu = true;
            }
        }
        if (!temu) cout << "Obat dengan nama '" << cari << "' tidak ditemukan." << endl;

    } else if (pilPencarian == 2) {                                                           // Binary search
        if (!hargaUrut) {
            cout << "\nData harus terurut jika menggunakan binary search" << endl;
            cout << "Urutkan data terlebih dahulu melalui Menu Utama -> 3. Urutkan Obat -> Pilih opsi ke-2" << endl;
            return;
        }
        int cariHarga;
        cout << "Masukkan Harga Obat yang dicari: Rp"; cin >> cariHarga;
        int awal = 0;
        int akhir = jumlahData - 1;
        bool temu = false;
        while (awal <= akhir) {
            int tengah = awal + (akhir - awal) / 2;
            if (daftarObat[tengah].harga == cariHarga) {
                temu = true;
                cout << "\n=== HASIL PENCARIAN ===" << endl;
                int startIdx = tengah;
                while (startIdx >= 0 && daftarObat[startIdx].harga == cariHarga) {
                    startIdx--;
                }
                startIdx++;
                int endIdx = tengah;
                while (endIdx < jumlahData && daftarObat[endIdx].harga == cariHarga) {
                    endIdx++;
                }
                endIdx--;
                for (int k = startIdx; k <= endIdx; k++) {
                    cout << "-> Ditemukan: " << daftarObat[k].nama 
                        << " | Stok: " << daftarObat[k].stok 
                        << " | Harga: Rp" << daftarObat[k].harga << endl;
                }
                break;
            } 
            else if (daftarObat[tengah].harga < cariHarga) {
                akhir = tengah - 1; 
            } 
            else {
                awal = tengah + 1; 
            }
        }
        if (!temu) cout << "Obat dengan harga Rp" << cariHarga << " tidak ditemukan" << endl;
    } else {
        cout << "Pilihan tidak valid" << endl;
    }
}

void Update() {
    if (jumlahData == 0) {
        cout << "Data masih kosong" << endl;
        return;
    }
    cout << "\n=== DAFTAR OBAT ===" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << i + 1 << ". " << daftarObat[i].nama << endl;
    }
    int nomor;
    cout << "\nNomor urut yang diupdate: "; cin >> nomor;
    if (nomor > 0 && nomor <= jumlahData) {
        int idx = nomor - 1;
        cin.ignore(1000, '\n'); 
        cout << "Nama Baru: "; getline(cin, daftarObat[idx].nama);
        cout << "Stok Baru: "; cin >> daftarObat[idx].stok;
        cout << "Harga Baru: "; cin >> daftarObat[idx].harga;
        hargaUrut = false; 
        cout << "Update Berhasil!" << endl;
    } else {
        cout << "Nomor tidak valid" << endl;
    }
}

void Delete() {
    if (jumlahData == 0) {
        cout << "Data masih kosong" << endl;
        return;
    }
    cout << "\n=== DAFTAR OBAT ===" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << i + 1 << ". " << daftarObat[i].nama << endl;
    }
    int nomor;
    cout << "\nNomor urut yang dihapus: "; cin >> nomor;
    if (nomor > 0 && nomor <= jumlahData) {
        for (int i = nomor - 1; i < jumlahData - 1; i++) {
            daftarObat[i] = daftarObat[i + 1];
        }
        jumlahData--;
        cout << "Data terhapus" << endl;
    } else {
        cout << "Nomor tidak valid" << endl;
    }
}