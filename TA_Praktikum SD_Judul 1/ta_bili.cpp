#include <iostream>
using namespace std;

struct Node {
    string item;     
    Node* next;      
};

void tambahBarang(Node*& head, string namaBarang) {
    Node* newNode = new Node();
    newNode->item = namaBarang;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode; 
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void tampilkanDaftar(Node* head) {
    if (head == nullptr) {
        cout << "Daftar belanja kosong." << endl;
        return;
    }
    cout << "Daftar Belanja: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->item;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void hapusBarang(Node*& head, string namaBarang) {
    if (head == nullptr) {
        cout << "Daftar belanja kosong, tidak bisa menghapus." << endl;
        return;
    }

    if (head->item == namaBarang) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << namaBarang << " berhasil dihapus." << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->item != namaBarang) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* hapus = temp->next;
        temp->next = temp->next->next;
        delete hapus;
        cout << namaBarang << " berhasil dihapus." << endl;
    } else {
        cout << namaBarang << " tidak ada dalam daftar belanja." << endl;
    }
}

int main() {
    Node* daftarBelanja = nullptr;
    int pilihan;
    string barang;

    do {
        cout << "\n=== MENU DAFTAR BELANJA ===" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Hapus Barang" << endl;
        cout << "3. Tampilkan Daftar Belanja" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama barang: ";
                cin >> barang;
                tambahBarang(daftarBelanja, barang);
                cout << barang << " berhasil ditambahkan." << endl;
                break;
            case 2:
                cout << "Masukkan nama barang yang ingin dihapus: ";
                cin >> barang;
                hapusBarang(daftarBelanja, barang);
                break;
            case 3:
                tampilkanDaftar(daftarBelanja);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}