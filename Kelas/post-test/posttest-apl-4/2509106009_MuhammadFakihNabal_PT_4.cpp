#include <iostream>
#include <string>
using namespace std;

struct User {
    string username;
    string password;
};

struct Obat {
    string nama;
    string waktuPakai;
    int stok;
    int harga;
};

Obat daftarObat[100];
int jumlahData = 0;

bool Login(User* admin) {        //---------------- Parameter pointer (User* admin)
    string inputNama, inputPass;
    int percobaan = 0;
    while (percobaan < 3) {
        cout << "\n======================================" << endl;
        cout << "           SISTEM LOGIN ADMIN" << endl;
        cout << "======================================" << endl;
        cout << "Masukkan Nama      : "; cin >> inputNama;
        cout << "Masukkan Password  : "; cin >> inputPass;

        if (inputNama == admin->username && inputPass == admin->password) {  //---------------- dereference operator (->)
            return true;
        } else {
            percobaan++;
            cout << "Nama atau Password salah. Sisa: " << 3 - percobaan << endl;
        }
    }
    return false;
}

void Menu() {
    cout << "\n======================================" << endl;
    cout << "    SISTEM MANAJEMEN OBAT APOTEK      " << endl;
    cout << "======================================" << endl;
    cout << "1. Tambah Obat" << endl;
    cout << "2. Lihat & Cari Stok" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Hapus Data" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu [1-5]: ";
}

void Create() {
    cout << "\n=== Tambah Obat ===" << endl;
    cin.ignore();
    cout << "Nama obat      : "; getline(cin, daftarObat[jumlahData].nama);
    cout << "Waktu pakai (pemakaian x jam)   : "; getline(cin, daftarObat[jumlahData].waktuPakai);
    cout << "Jumlah stok    : "; cin >> daftarObat[jumlahData].stok;
    cout << "Harga satuan (Angka): "; cin >> daftarObat[jumlahData].harga;
    cin.ignore(1000, '\n');
    jumlahData++;
    cout << "\nData berhasil disimpan" << endl;
}

void Read() {
    if (jumlahData == 0) {
        cout << "\nData masih kosong" << endl;
    } else {
        cout << "No\tNama\t\tWaktu\t\tStok\tHarga" << endl;
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
        cin.ignore(1000, '\n');
        if (subPilihan == 'y' || subPilihan == 'Y') {
            string cari;
            cout << "Masukkan Nama Obat: "; getline(cin, cari);
            bool temu = false;
            for (int i = 0; i < jumlahData; i++) {
                if (daftarObat[i].nama == cari) {
                    cout << "Ditemukan: " << daftarObat[i].nama << " | Stok " << daftarObat[i].stok << endl;
                    temu = true;
                }
            }
            if (!temu) cout << "Obat tidak ditemukan" << endl;
        }
    }
}

void Update() {
    if (jumlahData == 0) {
        cout << "\nData kosong" << endl;
    } else {
        for (int i = 0; i < jumlahData; i++) cout << i + 1 << ". " << daftarObat[i].nama << endl;
        int nomor;
        cout << "\nNomor urut yang diupdate: "; cin >> nomor;
        cin.ignore(1000, '\n');
        if (nomor > 0 && nomor <= jumlahData) {
            int idx = nomor - 1;
            cout << "Masukkan Nama Baru: "; getline(cin, daftarObat[idx].nama);
            cout << "Masukkan Stok Baru: "; cin >> daftarObat[idx].stok;
            cout << "Masukkan Harga Baru: "; cin >> daftarObat[idx].harga;
            cin.ignore(1000, '\n');
            cout << "Update Berhasil!" << endl;
        } else {
            cout << "[!] Nomor tidak valid." << endl;
        }
    }
}

void Delete() {
    if (jumlahData == 0) {
        cout << "\nData kosong." << endl;
        return;
    }
    for (int i = 0; i < jumlahData; i++)cout << i + 1 << ". " << daftarObat[i].nama << endl;
    int nomor;
    cout << "\nNomor urut yang dihapus: "; cin >> nomor;
    if (nomor > 0 && nomor <= jumlahData) {
        for (int i = nomor - 1; i < jumlahData - 1; i++) daftarObat[i] = daftarObat[i + 1];
        jumlahData--;
        cout << "Data telah terhapus" << endl;
    } else {
        cout << "Nomor tidak valid" << endl;
    }
    cin.ignore(1000, '\n');
}

int main() {
    User admin = {"fakih", "009"};

    if (!Login(&admin)) {     //--------------- Address-of Operator (&)
        cout << "Kesempatan habis. Program berhenti" << endl;
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
            case 3: Update(); break;
            case 4: Delete(); break;
            case 5: cout << "Program Selesai" << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
    return 0;
}