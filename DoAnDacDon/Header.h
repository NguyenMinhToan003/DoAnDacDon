#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <random>


const int MAX = 100;
using namespace std;
struct TTTV
{
	int id;
	char hoTen[30];
	int namSinh;
	char queQuan[30];
	bool gioiTinh;
};
struct ThanhVien {
	TTTV data;
	ThanhVien* next;
};
typedef ThanhVien* ThanhVienPtr;

struct HoKhau
{
	int maHoKhau;
	char tenChuHo[20];
	char diaChi[20];
	ThanhVienPtr dsThanhVien;

};
struct DSHoKhau {
	int n = 0;
	HoKhau ds[MAX];
};
struct Phuong
{
	char tenPhuong[20];
	DSHoKhau dsHoKhau;
};

void dongGachNgang();
void dongTieuDe();