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

void khoiTaoDSTV(ThanhVienPtr& DSTV);
ThanhVienPtr taoNodeThanhVien(TTTV x);
void nhapTTThanhVien(TTTV& tv);
void nhapDSThanhVien(ThanhVienPtr& DSTV);
void xuatTTThanhVien(TTTV tv);
void xuatDSThanhVien(ThanhVienPtr DSTV);

void nhapHoKhau(HoKhau& hoKhau);
void xuatHoKhau(HoKhau hoKhau);

void nhapDSHoKhau(DSHoKhau& dsHoKhau);
void xuatDSHoKhau(DSHoKhau dsHoKhau);

void nhapTTPhuong(Phuong& phuong);
void xuatTTPhuong(Phuong phuong);
void nhapPhuong(Phuong& phuong);
void xuatPhuong(Phuong phuong);

HoKhau* timHoKhauBangMa(DSHoKhau dsHoKhau, int maHoKhau);

void ThemHoKhau(DSHoKhau& dsHoKhau);

//void ThemThanhVienVaoHoKhau(DSHoKhau& dsHoKhau, int maHoKhau, TTTV x);

void xoaHoKhauTheoMa(int maHoKhau, DSHoKhau& dsHoKhau);