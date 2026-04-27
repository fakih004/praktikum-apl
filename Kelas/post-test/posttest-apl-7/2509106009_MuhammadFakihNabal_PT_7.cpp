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
daftarObat[5] = {"Loratadine", 25, 6000, "1x24"};

// Data untuk mengecek error handling create

// daftarObat[6] = {"Aspirin", 40, 9000, "1x24"};
// daftarObat[7] = {"Asam Mefenamat", 60, 12000, "3x24"};
// daftarObat[8] = {"Diklofenak", 35, 14000, "2x24"};
// daftarObat[9] = {"Meloksikam", 15, 18000, "1x24"};
// daftarObat[10] = {"Cefadroxil", 25, 20000, "2x24"};
// daftarObat[11] = {"Ciprofloxacin", 40, 18000, "2x24"};
// daftarObat[12] = {"Azithromycin", 10, 35000, "1x24"};
// daftarObat[13] = {"Eritromisin", 15, 16000, "4x24"};
// daftarObat[14] = {"Tetrasiklin", 50, 5000, "4x24"};
// daftarObat[15] = {"Doksisiklin", 30, 8000, "2x24"};
// daftarObat[16] = {"Klindamisin", 20, 15000, "3x24"};
// daftarObat[17] = {"Levofloxacin", 15, 25000, "1x24"};
// daftarObat[18] = {"Cefixime", 25, 30000, "2x24"};
// daftarObat[19] = {"Cotrimoxazole", 40, 7000, "2x24"};
// daftarObat[20] = {"CTM", 100, 2000, "3x24"};
// daftarObat[21] = {"Dextromethorphan", 55, 6000, "3x24"};
// daftarObat[22] = {"Guaifenesin", 60, 5000, "3x24"};
// daftarObat[23] = {"Ambroxol", 45, 7500, "3x24"};
// daftarObat[24] = {"Bromhexine", 50, 8000, "3x24"};
// daftarObat[25] = {"Pseudoephedrine", 30, 12000, "3x24"};
// daftarObat[26] = {"Diphenhydramine", 40, 5000, "3x24"};
// daftarObat[27] = {"Promethazine", 20, 15000, "1x24"};
// daftarObat[28] = {"Salbutamol", 35, 4000, "3x24"};
// daftarObat[29] = {"Terbutaline", 25, 6000, "3x24"};
// daftarObat[30] = {"Vitamin D3", 80, 25000, "1x24"};
// daftarObat[31] = {"Vitamin B Complex", 90, 15000, "1x24"};
// daftarObat[32] = {"Zinc", 60, 12000, "1x24"};
// daftarObat[33] = {"Kalsium", 70, 18000, "1x24"};
// daftarObat[34] = {"Zat Besi", 50, 10000, "1x24"};
// daftarObat[35] = {"Magnesium", 40, 20000, "1x24"};
// daftarObat[36] = {"Asam Folat", 85, 5000, "1x24"};
// daftarObat[37] = {"Omega 3", 30, 45000, "1x24"};
// daftarObat[38] = {"Multivitamin", 50, 35000, "1x24"};
// daftarObat[39] = {"Vitamin E", 45, 25000, "1x24"};
// daftarObat[40] = {"Omeprazole", 60, 10000, "1x24"};
// daftarObat[41] = {"Lansoprazole", 50, 15000, "1x24"};
// daftarObat[42] = {"Pantoprazole", 30, 25000, "1x24"};
// daftarObat[43] = {"Ranitidine", 70, 5000, "2x24"};
// daftarObat[44] = {"Antasida", 100, 3000, "3x24"};
// daftarObat[45] = {"Sukralfat", 25, 30000, "4x24"};
// daftarObat[46] = {"Domperidone", 55, 8000, "3x24"};
// daftarObat[47] = {"Metoclopramide", 40, 6000, "3x24"};
// daftarObat[48] = {"Loperamide", 65, 4000, "Bila Perlu"};
// daftarObat[49] = {"Attapulgite", 80, 5000, "Bila Perlu"};
// daftarObat[50] = {"Amlodipine", 75, 8000, "1x24"};
// daftarObat[51] = {"Captopril", 85, 5000, "2x24"};
// daftarObat[52] = {"Lisinopril", 40, 10000, "1x24"};
// daftarObat[53] = {"Valsartan", 30, 20000, "1x24"};
// daftarObat[54] = {"Candesartan", 25, 25000, "1x24"};
// daftarObat[55] = {"Bisoprolol", 50, 15000, "1x24"};
// daftarObat[56] = {"Propranolol", 45, 6000, "3x24"};
// daftarObat[57] = {"Furosemide", 60, 4000, "1x24"};
// daftarObat[58] = {"Spironolactone", 35, 12000, "1x24"};
// daftarObat[59] = {"Digoxin", 15, 10000, "1x24"};
// daftarObat[60] = {"Metformin", 100, 5000, "2x24"};
// daftarObat[61] = {"Glibenclamide", 80, 4000, "1x24"};
// daftarObat[62] = {"Glimepiride", 60, 10000, "1x24"};
// daftarObat[63] = {"Acarbose", 45, 15000, "3x24"};
// daftarObat[64] = {"Pioglitazone", 30, 18000, "1x24"};
// daftarObat[65] = {"Sitagliptin", 20, 35000, "1x24"};
// daftarObat[66] = {"Linagliptin", 15, 40000, "1x24"};
// daftarObat[67] = {"Insulin Glargine", 10, 150000, "1x24"};
// daftarObat[68] = {"Insulin Aspart", 10, 140000, "Sesuai Dosis"};
// daftarObat[69] = {"Dapagliflozin", 20, 45000, "1x24"};
// daftarObat[70] = {"Simvastatin", 90, 7000, "1x24"};
// daftarObat[71] = {"Atorvastatin", 60, 20000, "1x24"};
// daftarObat[72] = {"Rosuvastatin", 40, 30000, "1x24"};
// daftarObat[73] = {"Fenofibrate", 35, 15000, "1x24"};
// daftarObat[74] = {"Gemfibrozil", 25, 12000, "2x24"};
// daftarObat[75] = {"Ezetimibe", 15, 25000, "1x24"};
// daftarObat[76] = {"Niacin", 20, 10000, "1x24"};
// daftarObat[77] = {"Lovastatin", 30, 14000, "1x24"};
// daftarObat[78] = {"Pravastatin", 25, 22000, "1x24"};
// daftarObat[79] = {"Allopurinol", 70, 5000, "1x24"};
// daftarObat[80] = {"Hidrokortison", 50, 10000, "Topikal"};
// daftarObat[81] = {"Betametason", 45, 15000, "Topikal"};
// daftarObat[82] = {"Miconazole", 60, 12000, "Topikal"};
// daftarObat[83] = {"Ketoconazole", 55, 18000, "Topikal"};
// daftarObat[84] = {"Acyclovir", 40, 8000, "5x24"};
// daftarObat[85] = {"Clotrimazole", 35, 14000, "Topikal"};
// daftarObat[86] = {"Asam Salisilat", 45, 6000, "Topikal"};
// daftarObat[87] = {"Permethrin", 20, 30000, "Topikal"};
// daftarObat[88] = {"Calamine", 40, 15000, "Topikal"};
// daftarObat[89] = {"Silver Sulfadiazine", 15, 25000, "Topikal"};
// daftarObat[90] = {"Insto Reguler", 30, 15000, "Bila Perlu"};
// daftarObat[91] = {"Rohto Cool", 25, 16000, "Bila Perlu"};
// daftarObat[92] = {"Cendo Xitrol", 15, 30000, "3x24"};
// daftarObat[93] = {"Cendo Fenicol", 20, 25000, "3x24"};
// daftarObat[94] = {"Otilon Tetes Telinga", 10, 40000, "2x24"};
// daftarObat[95] = {"Otopain", 15, 35000, "2x24"};
// daftarObat[96] = {"Ventolin Inhaler", 20, 120000, "Bila Sesak"};
// daftarObat[97] = {"Symbicort", 10, 250000, "2x24"};
// daftarObat[98] = {"Betadine", 40, 10000, "Topikal"};
// daftarObat[99] = {"Rivanol", 35, 8000, "Topikal"};

jumlahData = 5; // ubah dulu ini jika ingin mengecek error handling create

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
    cout << "\n=== Tambah Obat ===" << endl;         // ERROR HANDLING
    try {
        if (jumlahData >= 100) {
            throw runtime_error("Data sudah penuh");
        }
        cin.ignore(1000, '\n');
        cout << "Nama obat      : "; getline(cin, daftarObat[jumlahData].nama);
        cout << "Waktu pakai  (pemakaian x jam)  : "; getline(cin, daftarObat[jumlahData].waktuPakai);
        cout << "Jumlah stok    : "; cin >> daftarObat[jumlahData].stok;
        cout << "Harga satuan  (angka) : "; cin >> daftarObat[jumlahData].harga;
        jumlahData++;
        hargaUrut = false; 
        cout << "\nData berhasil disimpan" << endl;
    }
    catch (const runtime_error& e) {
    cout << "Error ditangkap: " << e.what() << endl;
    }
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
    cout <<  "\n=== DAFTAR OBAT ===" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << i + 1 << ". " << daftarObat[i].nama << endl;
    }
    int nomor;
    cout << "\nNomor urut yang dihapus: "; cin >> nomor;
    try {                                                          // ERROR HANDLING
        if (nomor <= 0 || nomor > jumlahData) {
            throw out_of_range("Error: Nomor tidak valid");
        }
        for (int i = nomor - 1; i < jumlahData - 1; i++){
            daftarObat[i] = daftarObat[i + 1];
        }
        jumlahData--;
        cout << "Data berhasil dihapus" << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
    }





