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
			int chiso = timHoKhauBangMa_Chiso(phuong.dsHoKhau, maHoKhau);
			if (chiso != -1) {
				
				cout << "\nThong tin ho khau tim thay:\n";
				dongTieuDe();
				xuatHoKhau(phuong.dsHoKhau.ds[chiso]);
			}
			else {
				cout << "\nKhong tim thay ho khau co ma " << maHoKhau << endl;
			}
		}
		else if (option == 4)
			ThemHoKhau(phuong.dsHoKhau);
		else if (option == 5) {
			int maHoKhau;
			cout << "Nhap ma ho khau: ";
			cin >> maHoKhau;

			themThanhVienVaoHoKhau(phuong.dsHoKhau, maHoKhau);

			xuatDSHoKhau(phuong.dsHoKhau);
		}
		else if (option == 6)
		{
			/*xuatPhuong(phuong);
			int mshk;
			int idtv;
			cout << "Nhap MHK: ";
			cin >> mshk;
			cout << "Nhap ID thanh vien: ";
			cin >> idtv;
			xoaThanhVien(phuong.dsHoKhau, mshk, idtv);
			xuatPhuong(phuong);*/

			//test

			xuatPhuong(phuong);
			int mshk=1111;
			int idtv;
			cout << "Nhap MHK: "<<mshk<<endl;
			//cin >> mshk;
			cout << "Nhap ID thanh vien: ";
			cin >> idtv;
			xoaThanhVien(phuong.dsHoKhau, mshk, idtv);
			xuatPhuong(phuong);
		}
		else if (option == 7)
		{
			xuatPhuong(phuong);
			int maHoKhau;
			cout << "\nNhap ma ho khau can xoa: ";
			cin >> maHoKhau;;
			xoaHoKhauTheoMa(maHoKhau,phuong.dsHoKhau);
			cout << "\nXoa thanh cong!" << endl;
			xuatPhuong(phuong);
		}
		else if (option == 8)
		{
			xuatPhuong(phuong);
			int maHoKhau;
			cout << "Nhap ma ho khau can sap xep: ";
			cin >> maHoKhau;
			int index = timHoKhauBangMa_Chiso(phuong.dsHoKhau, maHoKhau);
			if (index != -1) {
				sapXepTenThanhVienTrongHoKhau(phuong.dsHoKhau.ds[index]);
				cout << "Da sap xep thanh vien trong ho khau co ma " << maHoKhau << " theo ten." << endl;
			}
			else {
				cout << "Khong tim thay ho khau có ma " << maHoKhau << "." << endl;
			}
			xuatPhuong(phuong);
			break;

		}
		else if (option == 9) {
			docFileDSHoKhau(phuong, "PhuongMoi.txt");
			cout << "\nDOC FILE THANH CONG!" << endl;
		}
		else if (option == 10)
		{
			ghiFile(phuong, "Phuong.txt");
			cout << "\nGHI FILE THANH CONG!" << endl;
		}

		else if (option == 0) break;
	}
	system("pause");
	return 0;
}