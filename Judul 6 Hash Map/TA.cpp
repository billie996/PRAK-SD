#include <iostream>
using namespace std;

const int SIZE = 10;

struct Pasien {
    int idPasien;
    Pasien* next;

    Pasien(int id, Pasien* nxt = nullptr)
        : idPasien(id), next(nxt) {}
};

Pasien* table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = nullptr;
}

int hashFunc(int idPasien) {
    return idPasien % SIZE;
}

void insertPasien(int idPasien) {
    int idx = hashFunc(idPasien);
    Pasien* baru = new Pasien(idPasien, table[idx]);
    table[idx] = baru;
    cout << "Pasien dengan ID " << idPasien << " berhasil ditambahkan ke antrian.\n";
}

Pasien* searchPasien(int idPasien) {
    int idx = hashFunc(idPasien);
    Pasien* temp = table[idx];
    while (temp) {
        if (temp->idPasien == idPasien)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void deletePasien(int idPasien) {
    int idx = hashFunc(idPasien);
    Pasien* temp = table[idx];
    Pasien* prev = nullptr;

    while (temp && temp->idPasien != idPasien) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Pasien dengan ID " << idPasien << "tidak ditemukan.\n";
        return;
    }

    if (!prev)
        table[idx] = temp->next;
    else
        prev->next = temp->next;

    cout << "Pasien dengan ID " << idPasien << "telah dihapus dari antrian.\n";
    delete temp;
}

void displayPasien() {
    cout << "\n=== DATA ANTRIAN PASIEN ===\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        Pasien* temp = table[i];
        if (!temp)
            cout << "Kosong";
        while (temp) {
            cout << "[" << temp->idPasien << "]";
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    init();
    int pilihan = -1;

    while (pilihan != 0) {
        cout << "\n===== MENU RUMAH SAKIT =====\n";
        cout << "1. Tambah Pasien (Insert)\n";
        cout << "2. Cari Pasien (Search)\n";
        cout << "3. Hapus Pasien (Delete)\n";
        cout << "4. Tampilkan Semua Pasien (Display)\n";
        cout << "0. Keluar\n";
        cout << "=============================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int id;
            cout << "Masukkan ID Pasien: ";
            cin >> id;
            insertPasien(id);
        } 
        else if (pilihan == 2) {
            int id;
            cout << "Masukkan ID Pasien yang dicari: ";
            cin >> id;
            Pasien* p = searchPasien(id);
            if (p)
                cout << "Ditemukan pasien dengan ID " << p->idPasien << ".\n";
            else
                cout << "Pasien tidak ditemukan.\n";
        } 
        else if (pilihan == 3) {
            int id;
            cout << "Masukkan ID Pasien yang akan dihapus: ";
            cin >> id;
            deletePasien(id);
        } 
        else if (pilihan == 4) {
            displayPasien();
        } 
        else if (pilihan == 0) {
            cout << "Terima kasih, program selesai.\n";
        } 
        else {
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    }

    return 0;
}
