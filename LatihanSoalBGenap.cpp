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

