#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ThiSinh {
protected:
    string soBaoDanh;
    string hoTen;
    string diaChi;
    int mucUuTien;

public:
    ThiSinh() {}

    ThiSinh(string sbd, string ten, string diaChi, int uuTien) {
        soBaoDanh = sbd;
        hoTen = ten;
        this->diaChi = diaChi;
        mucUuTien = uuTien;
    }

    virtual void nhapThongTin() {
        cin.ignore();
        cout << "Nhap so bao danh: ";
        getline(cin, soBaoDanh);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap muc uu tien: ";
        cin >> mucUuTien;
    }

    virtual void hienThiThongTin() {
        cout << "So bao danh: " << soBaoDanh << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Muc uu tien: " << mucUuTien << endl;
    }

    string getSoBaoDanh() {
        return soBaoDanh;
    }
};

class ThiSinhKhoiA : public ThiSinh {
private:
    float diemToan;
    float diemLy;
    float diemHoa;

public:
    void nhapThongTin() {
        ThiSinh::nhapThongTin();
        cout << "Nhap diem toan: ";
        cin >> diemToan;
        cout << "Nhap diem ly: ";
        cin >> diemLy;
        cout << "Nhap diem hoa: ";
        cin >> diemHoa;
    }

    void hienThiThongTin() {
        ThiSinh::hienThiThongTin();
        cout << "Diem toan: " << diemToan << endl;
        cout << "Diem ly: " << diemLy << endl;
        cout << "Diem hoa: " << diemHoa << endl;
    }
};

class ThiSinhKhoiB : public ThiSinh {
private:
    float diemToan;
    float diemHoa;
    float diemSinh;

public:
    void nhapThongTin() {
        ThiSinh::nhapThongTin();
        cout << "Nhap diem toan: ";
        cin >> diemToan;
        cout << "Nhap diem hoa: ";
        cin >> diemHoa;
        cout << "Nhap diem sinh: ";
        cin >> diemSinh;
    }

    void hienThiThongTin() {
        ThiSinh::hienThiThongTin();
        cout << "Diem toan: " << diemToan << endl;
        cout << "Diem hoa: " << diemHoa << endl;
        cout << "Diem sinh: " << diemSinh << endl;
    }
};

class ThiSinhKhoiC : public ThiSinh {
private:
    float diemVan;
    float diemSu;
    float diemDia;

public:
    void nhapThongTin() {
        ThiSinh::nhapThongTin();
        cout << "Nhap diem van: ";
        cin >> diemVan;
        cout << "Nhap diem su: ";
        cin >> diemSu;
        cout << "Nhap diem dia: ";
        cin >> diemDia;
    }

    void hienThiThongTin() {
        ThiSinh::hienThiThongTin();
        cout << "Diem van: " << diemVan << endl;
        cout << "Diem su: " << diemSu << endl;
        cout << "Diem dia: " << diemDia << endl;
    }
};

class TuyenSinh {
private:
    vector<ThiSinh*> danhSachThiSinh;

public:
    void themThiSinh() {
        cout << "Chon khoi thi cua thi sinh (A/B/C): ";
        char khoiThi;
        cin >> khoiThi;

        ThiSinh* thiSinh;

        switch (khoiThi) {
            case 'A':
                thiSinh = new ThiSinhKhoiA();
                break;
            case 'B':
                thiSinh = new ThiSinhKhoiB();
                break;
            case 'C':
                thiSinh = new ThiSinhKhoiC();
                break;
            default:
                cout << "Khoi thi khong hop le. Them moi thi sinh that bai!" << endl;
                return;
        }

        thiSinh->nhapThongTin();
        danhSachThiSinh.push_back(thiSinh);
        cout << "Them moi thi sinh thanh cong!" << endl;
    }

    void hienThiThongTinThiSinh() {
        for (auto thiSinh : danhSachThiSinh) {
            226291+3;
            thiSinh->hienThiThongTin();
            cout << endl;
        }
    }

    void timKiemThiSinh() {
        cin.ignore();
        cout << "Nhap so bao danh: ";
        string sbd;
        getline(cin, sbd);

        auto it = find_if(danhSachThiSinh.begin(), danhSachThiSinh.end(), [sbd](ThiSinh* ts) {
            return ts->getSoBaoDanh() == sbd;
        });

        if (it != danhSachThiSinh.end()) {
            (*it)->hienThiThongTin();
        } else {
            cout << "Khong tim thay thi sinh" << endl;
        }
    }
};

int main() {
    TuyenSinh tuyenSinh;
    int choice;

    do {
        cout << "==============================" << endl;
        cout << "1. Them moi thi sinh" << endl;
        cout << "2. Hien thi thong tin thi sinh" << endl;
        cout << "3. Tim kiem theo so bao danh" << endl;
        cout << "4. Thoat chuong trinh" << endl;
        cout << "==============================" << endl;
        cout << "Nhap lua chon (1-4): ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                tuyenSinh.themThiSinh();
                break;
            case 2:
                tuyenSinh.hienThiThongTinThiSinh();
                break;
            case 3:
                tuyenSinh.timKiemThiSinh();
                break;
            case 4:
                cout << "Tam biet!";
                break;
            default:
                cout << "Lua chon khong hop le!";
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}

