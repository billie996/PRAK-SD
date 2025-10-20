#include <iostream>
using namespace std;

struct Node {
    int idBuku;
    Node* kiri;
    Node* kanan;

    Node(int id) {
        idBuku = id;
        kiri = kanan = nullptr;
    }
};

Node* insert(Node* akar, int id) {
    if (akar == nullptr)
        return new Node(id);
    if (id < akar->idBuku)
        akar->kiri = insert(akar->kiri, id);
    else if (id > akar->idBuku)
        akar->kanan = insert(akar->kanan, id);
    return akar;
}

bool search(Node* akar, int id) {
    if (akar == nullptr)
        return false;
    if (akar->idBuku == id)
        return true;
    else if (id < akar->idBuku)
        return search(akar->kiri, id);
    else
        return search(akar->kanan, id);
}

void inorder(Node* akar) {
    if (akar == nullptr)
        return;
    inorder(akar->kiri);
    cout << akar->idBuku << " ";
    inorder(akar->kanan);
}

int hitungNode(Node* akar) {
    if (akar == nullptr)
        return 0;
    return 1 + hitungNode(akar->kiri) + hitungNode(akar->kanan);
}

int findMin(Node* akar) {
    if (akar == nullptr)
        return -1;
    while (akar->kiri != nullptr)
        akar = akar->kiri;
    return akar->idBuku;
}

int findMax(Node* akar) {
    if (akar == nullptr)
        return -1;
    while (akar->kanan != nullptr)
        akar = akar->kanan;
    return akar->idBuku;
}

int main() {
    Node* rak = nullptr;
    int pilihan, id;

    do {
        cout << "\n=== SISTEM MANAJEMEN RAK BUKU (BST) ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Cari Buku\n";
        cout << "3. Tampilkan Semua Buku (Inorder)\n";
        cout << "4. Lihat Buku dengan ID Terkecil\n";
        cout << "5. Lihat Buku dengan ID Terbesar\n";
        cout << "6. Hitung Jumlah Buku\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan ID Buku: ";
            cin >> id;
            rak = insert(rak, id);
            cout << "Buku berhasil ditambahkan ke rak.\n";
        } 
        else if (pilihan == 2) {
            cout << "Masukkan ID Buku yang ingin dicari: ";
            cin >> id;
            if (search(rak, id))
                cout << "Buku dengan ID " << id << " ditemukan.\n";
            else
                cout << "Buku tidak ditemukan.\n";
        } 
        else if (pilihan == 3) {
            cout << "Daftar Buku (Inorder): ";
            inorder(rak);
            cout << endl;
        } 
        else if (pilihan == 4) {
            cout << "ID Buku Terkecil: " << findMin(rak) << endl;
        } 
        else if (pilihan == 5) {
            cout << "ID Buku Terbesar: " << findMax(rak) << endl;
        } 
        else if (pilihan == 6) {
            cout << "Jumlah Buku di Rak: " << hitungNode(rak) << endl;
        } 
        else if (pilihan == 7) {
            cout << "Keluar dari program...\n";
        } 
        else {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 7);

    return 0;
}
