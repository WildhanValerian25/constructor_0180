#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Petugas;
class Admin;

// =====================
// CLASS BUKU
// =====================
class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    void tampilkanInfo() {
        cout << "Judul: " << judul << ", Penulis: " << penulis
             << ", Status: " << (dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    // Friend class
    friend class Petugas;

    // Friend function untuk Admin
    friend void lihatStatusBuku(const Buku& b, const Admin& a);
};

// =====================
// CLASS PEMINJAM
// =====================
class Peminjam {
private:
    string nama;
    string id;
    int totalPinjaman;

public:
    Peminjam(string n, string i) : nama(n), id(i), totalPinjaman(0) {}

    void tampilkanInfo() {
        cout << "Nama: " << nama << ", ID: " << id << ", Total Pinjaman: " << totalPinjaman << endl;
    }

    // Friend class
    friend class Petugas;

    // Friend function untuk Admin
    friend void lihatTotalPinjaman(const Peminjam& p, const Admin& a);
};

