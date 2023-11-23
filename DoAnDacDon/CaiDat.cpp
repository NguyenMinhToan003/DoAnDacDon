#include "Header.h"
void dongGachNgang() {
    for (int i = 0; i < 133; i++) {
        cout << "-";
    }
    cout << endl;
}
void dongTieuDe() {
    cout << "|"
        << left << setw(5) << "MHK" << "|"
        << left << setw(22) << "Ten Chu Ho" << "|"
        << left << setw(22) << "Dia Chi" << "|"
        << left << setw(8) << "CCCD" << "|"
        << left << setw(22) << "Ho Va Ten" << "|"
        << left << setw(10) << "Nam Sinh" << "|"
        << left << setw(11) << "Gioi Tinh" << "|"
        << left << setw(24) << "Que Quan" << "|";
    cout << endl;
}