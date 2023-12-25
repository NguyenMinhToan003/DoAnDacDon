#include "Header.h"
int main() {

	Phuong phuong;

	int option = 1;

	while (option)
	{
		cout << "\n1.Tao Phuong. ";
		cout << "\n2.Quan Ly Phuong.";
		cout << "\n3.Tim Thong Tin Ho Khau.";
		cout << "\n4.Them Ho Khau Moi.";
		cout << "\n5.Them Thanh Vien.";
		cout << "\n6.Xoa Thanh Vien. ";
		cout << "\n7.Xoa Ho Khau.";
		cout << "\n8.Sap Xep Ten Theo Alphabet.";
		cout << "\n9.Mo file.";
		cout << "\n10.Ghi file.";
		cout << "\n0.Dung Chuong Trinh.";

		cout << "\nNhap Lua Chon : ";
		cin >> option;
		system("cls");

		if (option == 1)
			nhapPhuong(phuong);
		else if (option == 2)
			xuatPhuong(phuong);
		else if (option == 3) {
			int maHoKhau;
			cout << "\nNhap ma ho khau can tim: ";
			cin >> maHoKhau;

			HoKhau* hoKhau = timHoKhauBangMa(phuong.dsHoKhau, maHoKhau);
			if (hoKhau != nullptr) {
				
				cout << "\nThong tin ho khau tim thay:\n";
				xuatHoKhau(*hoKhau);
			}
			else {
				cout << "\nKhong tim thay ho khau co ma " << maHoKhau << endl;
			}
		}
		else if (option == 4)
			ThemHoKhau(phuong.dsHoKhau);
		/*else if (option == 5) {
			int maHoKhau;
			cout << "\nNhap ma ho khau can them: ";
			cin >> maHoKhau;
			TTTV newMember;
			nhapTTThanhVien(newMember);
			ThemThanhVienVaoHoKhau(phuong.dsHoKhau, maHoKhau, newMember);

			xuatDSHoKhau(phuong.dsHoKhau);
		}
		else if (option == 6)
		{
			xuatPhuong(phuong);
			string mshk;
			int idtv;
			cout << "Nhap MHK: ";
			cin >> mshk;
			cout << "Nhap ID thanh vien: ";
			cin >> idtv;
			xoaThanhVien(phuong.dsHoKhau, mshk, idtv);
			xuatPhuong(phuong);
		}*/
		else if (option == 7)
		{
			xuatPhuong(phuong);
			int maHoKhau;
			cout << "\nNhap ma ho khau can them: ";
			cin >> maHoKhau;;
			xoaHoKhauTheoMa(maHoKhau,phuong.dsHoKhau);
			cout << "\nXoa HK thanh cong!" << endl;
			xuatPhuong(phuong);
		}
		/*else if (option == 8)
		{
			xuatPhuong(phuong);
			string msx;
			cout << "Nhap MHK: ";
			cin >> msx;
			sapXepTheoMaHoKhau(phuong.dsHoKhau, msx);
			cout << "\nSap Xep Theo Ten Thanh Cong!" << endl;
			xuatPhuong(phuong);
		}
		else if (option == 9) {
			docFile("PhuongMoi.txt", phuong);
			cout << "\nDOC FILE THANH CONG!" << endl;
		}
		else if (option == 10)
		{
			ghiFile("WritePhuongMoi.txt", phuong);
			cout << "\nGHI FILE THANH CONG!" << endl;
		}*/

		else if (option == 0) break;
	}
	system("pause");
	return 0;
}