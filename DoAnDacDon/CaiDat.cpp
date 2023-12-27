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
		<< left << setw(5) << "ID Chu Ho" << "|"
		<< left << setw(23) << "Ten Chu Ho" << "|"
		<< left << setw(22) << "Dia Chi" << "|"
		<< left << setw(8) << "CCCD" << "|"
		<< left << setw(22) << "Ho Va Ten" << "|"
		<< left << setw(10) << "Nam Sinh" << "|"
		<< left << setw(11) << "Gioi Tinh" << "|"
		<< left << setw(15) << "Que Quan" << "|";
	cout << endl;
}
void khoiTaoDSTV(ThanhVienPtr& DSTV) {
	DSTV = NULL;
}

ThanhVienPtr taoNodeThanhVien(TTTV x) {
	ThanhVienPtr p = new ThanhVien;
	p->data = x;
	p->next = NULL;
	return p;
}
void nhapTTThanhVien(TTTV& tv) {
	cout << "\nNhap ID thanh vien : ";
	cin >> tv.id;
	cout << "Nhap ho ten thanh vien: ";
	cin.ignore();
	cin >> tv.hoTen;
	bool isValidYear;
	do {
		cout << "Nhap nam sinh thanh vien: ";
		cin >> tv.namSinh;

		if (tv.namSinh >= 1900 && tv.namSinh <= 2023) {
			isValidYear = true;
		}
		else {
			cout << "Nam sinh khong hop le. Vui long nhap lai.\n";
			isValidYear = false;
		}
	} while (isValidYear == false);
	cout << "Nhap que quan thanh vien: ";
	cin.ignore();
	cin >> tv.queQuan;
	cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
	int gender;
	cin >> gender;
	gender == 0 ? tv.gioiTinh = 0 : tv.gioiTinh = 1;
}
ThanhVienPtr ThemThanhVien(ThanhVienPtr& DSTV, TTTV x) {
	ThanhVienPtr p = taoNodeThanhVien(x);
	p->next = DSTV;
	DSTV = p;
	return p;
}
void nhapDSThanhVien(ThanhVienPtr& DSTV) {
	khoiTaoDSTV(DSTV);
	int option = 1;
	do {
		TTTV x;
		nhapTTThanhVien(x);
		ThemThanhVien(DSTV, x);
		cout << "\nNhap tiep thanh vien khac (0: Khong, 1: Co): ";
		cin >> option;
		option != 0 ? option = 1 : option = 0;
	} while (option != 0);
}
void xuatDSThanhVien(ThanhVienPtr DSTV) {
	ThanhVienPtr p = DSTV;
	while (p != NULL) {
		xuatTTThanhVien(p->data);
		p = p->next;
		dongGachNgang();
	}
}
void xuatTTThanhVien(TTTV tv) {
	cout << "|"
		<< right << setw(8) << tv.id << "|"
		<< left << setw(22) << tv.hoTen << "|"
		<< right << setw(10) << tv.namSinh << "|"
		<< left << setw(11) << (tv.gioiTinh ? "Nam" : "Nu") << "|"
		<< left << setw(24) << tv.queQuan << "|" << endl;
}

void nhapHoKhau(HoKhau& hoKhau) {
	cout << "\nNhap Thong tin Chu Ho: ";
	cin.ignore();
	cout << "\nNhap Ma Ho Khau: ";
	cin >> hoKhau.maHoKhau;
	cout << "Nhap ID chu ho: ";
	cin >> hoKhau.idChuHo;
	cout << "Nhap Ten Chu Ho: ";
	cin.ignore();
	cin >> hoKhau.tenChuHo;
	cout << "Nhap Dia Chi Ho Khau: ";
	cin >> hoKhau.diaChi;
	nhapDSThanhVien(hoKhau.dsThanhVien);
}

void xuatHoKhau(HoKhau hoKhau) {

	ThanhVienPtr p = hoKhau.dsThanhVien;
	while (p != NULL) {
		dongGachNgang();
		cout << "|"
			<< right << setw(5) << hoKhau.maHoKhau << "|"
			<< left << setw(9) << hoKhau.idChuHo << "|"
			<< left << setw(23) << hoKhau.tenChuHo << "|"
			<< left << setw(22) << hoKhau.diaChi << "|"
			<< right << setw(8) << p->data.id << "|"
			<< left << setw(22) << p->data.hoTen << "|"
			<< right << setw(10) << p->data.namSinh << "|"
			<< left << setw(11) << (p->data.gioiTinh ? "Nam" : "Nu") << "|"
			<< left << setw(15) << p->data.queQuan << "|" << endl;
		p = p->next;
	}
}

void nhapDSHoKhau(DSHoKhau& dsHoKhau) {
	cout << "\nNhap so luong ho khau :";
	cin >> dsHoKhau.n;
	for (int i = 0; i < dsHoKhau.n; i++) {
		cout << "\nHo Khau Thu " << i + 1 << endl;
		dsHoKhau.ds[i].maHoKhau = i;
		nhapHoKhau(dsHoKhau.ds[i]);
	}
}
void xuatDSHoKhau(DSHoKhau dsHoKhau) {
	dongGachNgang();
	dongTieuDe();

	for (int i = 0; i < dsHoKhau.n; i++) {
		xuatHoKhau(dsHoKhau.ds[i]);
	}
	dongGachNgang();
}
void nhapTTPhuong(Phuong& phuong) {
	cout << "\nNhap Thong Tin Phuong : ";
	cin.ignore();
	cin.getline(phuong.tenPhuong, 20);
}
void xuatTTPhuong(Phuong phuong) {
	cout << "\nThong Tin Phuong : " << phuong.tenPhuong << endl;
}

void nhapPhuong(Phuong& phuong) {
	nhapTTPhuong(phuong);
	nhapDSHoKhau(phuong.dsHoKhau);
}

void xuatPhuong(Phuong phuong) {
	cout << "\n\t\t\t\t\t\t\tQUAN LY DAN CU CUA PHUONG " << endl;
	xuatTTPhuong(phuong);
	xuatDSHoKhau(phuong.dsHoKhau);

}

int timHoKhauBangMa_Chiso(DSHoKhau dsHoKhau, string maHoKhau) {
	for (int i = 0; i < dsHoKhau.n; i++) {
		if (dsHoKhau.ds[i].maHoKhau == maHoKhau) {
			return i;
		}
	}
	return -1;
}

void ThemHoKhau(DSHoKhau& dsHoKhau) {
	if (dsHoKhau.n == MAX) {
		cout << "Danh sach ho khau da day. Khong the them moi.\n";
		return;
	}

	HoKhau hoKhau;
	cout << "\nNhap Thong tin Ho Khau moi:\n";
	cout << "Nhap Ma Ho Khau: ";
	cin >> hoKhau.maHoKhau;
	cin.ignore();
	cout << "Nhap Ten Chu Ho: ";
	cin >> hoKhau.tenChuHo;
	cout << "Nhap Dia Chi: ";
	cin.ignore();
	cin >> hoKhau.diaChi;

	nhapDSThanhVien(hoKhau.dsThanhVien);

	dsHoKhau.ds[dsHoKhau.n] = hoKhau;
	dsHoKhau.n++;

	cout << "Ho Khau moi da them thanh cong.\n";
}


void xoaHoKhauTheoMa(string maHoKhau, DSHoKhau& dsHoKhau) {
	for (int i = 0; i < dsHoKhau.n; i++) {
		if (dsHoKhau.ds[i].maHoKhau == maHoKhau) {
			for (int j = i; j < dsHoKhau.n - 1; j++) {
				dsHoKhau.ds[j] = dsHoKhau.ds[j + 1];
			}
			dsHoKhau.n--;
			break;
		}
	}
}

ThanhVienPtr timThanhVienTheoID(DSHoKhau danhSachHoKhau, int id) {
	for (int i = 0; i < danhSachHoKhau.n; i++) {
		ThanhVienPtr current = danhSachHoKhau.ds[i].dsThanhVien;
		while (current != nullptr) {
			if (current->data.id == id) {
				return current;
			}
			current = current->next;
		}
	}
	return nullptr;
}

void themThanhVienVaoHoKhau(DSHoKhau& dsHoKhau, string maHoKhau) {
	int chisoHoKhau = timHoKhauBangMa_Chiso(dsHoKhau, maHoKhau);
	if (chisoHoKhau != -1) {
		TTTV tv;
		nhapTTThanhVien(tv);
		ThemThanhVien(dsHoKhau.ds[chisoHoKhau].dsThanhVien, tv);
		cout << "Them thanh vien moi thanh cong!" << endl;
	}
	else {
		cout << "Khong tim thay ho khau voi ma ho khau " << maHoKhau << endl;
	}
}


void sapXepTenThanhVienTrongHoKhau(HoKhau& hoKhau) {

	if (hoKhau.dsThanhVien == nullptr || hoKhau.dsThanhVien->next == nullptr) {
		return;
	}


	ThanhVienPtr current = hoKhau.dsThanhVien;
	while (current != nullptr) {
		ThanhVienPtr minNode = current;
		ThanhVienPtr temp = current->next;

		while (temp != nullptr) {
			if (temp->data.hoTen < minNode->data.hoTen) {
				minNode = temp;
			}
			temp = temp->next;
		}

		if (minNode != current) {

			TTTV tempData = current->data;
			current->data = minNode->data;
			minNode->data = tempData;
		}

		current = current->next;
	}
}

void docFileDSHoKhau(Phuong& phuong, const string& tenFile) {
	ifstream file(tenFile);
	if (!file.is_open()) {
		cout << "Khong the mo file: " << tenFile << endl;
		return;
	}
	file >> phuong.tenPhuong;
	file.ignore();
	file >> phuong.dsHoKhau.n;
	file.ignore();

	for (int i = 0; i < phuong.dsHoKhau.n; i++) {
		HoKhau& hoKhau = phuong.dsHoKhau.ds[i];

		file >> hoKhau.maHoKhau;
		file.ignore();
		file >> hoKhau.idChuHo;
		file.ignore();
		file.getline(hoKhau.tenChuHo, 30);
		file.getline(hoKhau.diaChi, 30);

		int b;
		file >> b;
		file.ignore();
		for (int i = 0; i < b; i++) {
			TTTV newThanhVien;
			file >> newThanhVien.id;
			file.ignore();
			file.getline(newThanhVien.hoTen, 30);
			file >> newThanhVien.namSinh;
			file.ignore();
			file.getline(newThanhVien.queQuan, 30);
			int gioiTinh;
			file >> gioiTinh;
			file.ignore();
			newThanhVien.gioiTinh = gioiTinh != 0;
			ThemThanhVien(hoKhau.dsThanhVien, newThanhVien);
		}
	}

	file.close();
}


void ghiFile(const Phuong& phuong, const char* fileName) {
	ofstream file(fileName);
	if (!file) {
		cout << "Error opening file!";
		return;
	}
	file << phuong.tenPhuong << endl;
	file << phuong.dsHoKhau.n << endl;
	for (int i = 0; i < phuong.dsHoKhau.n; i++) {

		file << phuong.dsHoKhau.ds[i].maHoKhau << endl;
		file << phuong.dsHoKhau.ds[i].idChuHo << endl;
		file << phuong.dsHoKhau.ds[i].tenChuHo << endl;
		file << phuong.dsHoKhau.ds[i].diaChi << endl;

		ThanhVienPtr p = phuong.dsHoKhau.ds[i].dsThanhVien;
		while (p != NULL) {
			file << p->data.id << endl;
			file << p->data.hoTen << endl;
			file << p->data.namSinh << endl;
			file << p->data.gioiTinh << endl;
			file << p->data.queQuan << endl;
			p = p->next;
		}
		file << endl;
	}

	file.close();
}

void xoaThanhVien(DSHoKhau& dsHoKhau, string maHoKhau, int id) 
{
	int ma = timHoKhauBangMa_Chiso(dsHoKhau, maHoKhau);
	if (ma != -1)
	{
		HoKhau& hoKhau = dsHoKhau.ds[ma];

		// Kiểm tra ID có trùng với ID thành viên không
		ThanhVienPtr prevThanhVien = nullptr;
		ThanhVienPtr currThanhVien = hoKhau.dsThanhVien;
		while (currThanhVien != nullptr && currThanhVien->data.id != id)
		{
			prevThanhVien = currThanhVien;
			currThanhVien = currThanhVien->next;
		}

		// Kiểm tra ID có trùng với ID chủ hộ không
		if (hoKhau.idChuHo == id)
		{
			int idtvThayThe;
			cout << "NHAP ID NGUOI THAY THE: ";
			cin >> idtvThayThe;
			ThanhVienPtr thanhVienThayThe = timThanhVienTheoID(dsHoKhau, idtvThayThe);
			if (thanhVienThayThe == nullptr) {
				cout << "KHONG TIM THAY THANH VIEN THAY THE!!" << endl;
				return;
			}
			else {
				dsHoKhau.ds[ma].idChuHo = idtvThayThe;
				strncpy(dsHoKhau.ds[ma].tenChuHo, thanhVienThayThe->data.hoTen, 30);
				strncpy(dsHoKhau.ds[ma].diaChi, thanhVienThayThe->data.queQuan, 30);
				dsHoKhau.ds[ma].dsThanhVien = thanhVienThayThe->next;
				delete thanhVienThayThe;
				
				cout << "THAY THE CHU HO THANH CONG!" << endl;
			}
		}
		else
		{
			if (currThanhVien == nullptr)
			{
				cout << "THANH VIEN KHONG TON TAI TRONG HO KHAU!!" << endl;
				return;
			}

			if (prevThanhVien == nullptr)
				dsHoKhau.ds[ma].dsThanhVien = currThanhVien->next;
			else {
				prevThanhVien->next = currThanhVien->next;
				delete currThanhVien;
				return;
				cout << "XOA THANH CONG THANH VIEN!" << endl;
			}
		}
	}
	else
	{
		cout << "KHONG TIM THAY HO KHAU";
	}

}