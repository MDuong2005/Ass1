#include <stdio.h>
#include <string.h>

#define MAX_SACH 100

// Cấu trúc lưu thông tin sách
typedef struct {
    char maSach[20];
    char tenSach[100];
    char tenTacGia[100];
    char nhaXuatBan[100];
    char soISBN[20];
    float giaTien;
} Sach;

// Khai báo mảng sách
Sach danhSachSach[MAX_SACH];
int soLuongSach = 0;

// Hàm nhập thông tin sách
void nhapThongTinSach() {
    Sach sach;
    printf("Nhap ma sach: ");
    scanf("%s", sach.maSach);
    printf("Nhap ten sach: ");
    getchar();  // Xóa bộ đệm nhập
    fgets(sach.tenSach, sizeof(sach.tenSach), stdin);
    sach.tenSach[strcspn(sach.tenSach, "\n")] = 0;  // Xóa ký tự '\n' ở cuối
    printf("Nhap ten tac gia: ");
    fgets(sach.tenTacGia, sizeof(sach.tenTacGia), stdin);
    sach.tenTacGia[strcspn(sach.tenTacGia, "\n")] = 0;  // Xóa ký tự '\n'
    printf("Nhap nha xuat ban: ");
    fgets(sach.nhaXuatBan, sizeof(sach.nhaXuatBan), stdin);
    sach.nhaXuatBan[strcspn(sach.nhaXuatBan, "\n")] = 0;  // Xóa ký tự '\n'
    printf("Nhap so ISBN: ");
    scanf("%s", sach.soISBN);
    printf("Nhap gia tien: ");
    scanf("%f", &sach.giaTien);

    danhSachSach[soLuongSach++] = sach;
    printf("Nhap thong tin sach thanh cong!\n");
}

// Hàm tìm kiếm sách theo mã sách
int timSachTheoMa(char maSach[20]) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSachSach[i].maSach, maSach) == 0) {
            return i;
        }
    }
    return -1;  // Trả về -1 nếu không tìm thấy sách
}

// Hàm sửa giá tiền của sách theo mã sách
void suaGiaTienTheoMaSach() {
    char maSach[20];
    printf("Nhap ma sach can sua gia: ");
    scanf("%s", maSach);

    int index = timSachTheoMa(maSach);
    if (index != -1) {
        printf("Nhap gia tien moi: ");
        scanf("%f", &danhSachSach[index].giaTien);
        printf("Sua gia tien thanh cong!\n");
    } else {
        printf("Khong tim thay sach!\n");
    }
}

// Hàm sửa tên tác giả theo mã sách
void suaTenTacGiaTheoMaSach() {
    char maSach[20];
    printf("Nhap ma sach can sua tac gia: ");
    scanf("%s", maSach);

    int index = timSachTheoMa(maSach);
    if (index != -1) {
        printf("Nhap ten tac gia moi: ");
        getchar();  // Xóa bộ đệm nhập
        fgets(danhSachSach[index].tenTacGia, sizeof(danhSachSach[index].tenTacGia), stdin);
        danhSachSach[index].tenTacGia[strcspn(danhSachSach[index].tenTacGia, "\n")] = 0;  // Xóa ký tự '\n'
        printf("Sua tac gia thanh cong!\n");
    } else {
        printf("Khong tim thay sach!\n");
    }
}

// Hàm xóa sách theo mã sách
void xoaSachTheoMaSach() {
    char maSach[20];
    printf("Nhap ma sach can xoa: ");
    scanf("%s", maSach);

    int index = timSachTheoMa(maSach);
    if (index != -1) {
        for (int i = index; i < soLuongSach - 1; i++) {
            danhSachSach[i] = danhSachSach[i + 1];
        }
        soLuongSach--;
        printf("Xoa sach thanh cong!\n");
    } else {
        printf("Khong tim thay sach!\n");
    }
}

// Hàm sắp xếp sách theo tên tác giả giảm dần
void sapXepTheoTenTacGia() {
    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if (strcmp(danhSachSach[i].tenTacGia, danhSachSach[j].tenTacGia) < 0) {
                Sach temp = danhSachSach[i];
                danhSachSach[i] = danhSachSach[j];
                danhSachSach[j] = temp;
            }
        }
    }
    printf("Sap xep theo ten tac gia thanh cong!\n");
}

// Hàm sắp xếp sách theo giá tiền tăng dần
void sapXepTheoGiaTien() {
    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if (danhSachSach[i].giaTien > danhSachSach[j].giaTien) {
                Sach temp = danhSachSach[i];
                danhSachSach[i] = danhSachSach[j];
                danhSachSach[j] = temp;
            }
        }
    }
    printf("Sap xep theo gia tien thanh cong!\n");
}

// Hàm xuất toàn bộ danh sách sách
void xuatToanBoDanhSach() {
    if (soLuongSach == 0) {
        printf("Danh sach sach rong!\n");
        return;
    }
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < soLuongSach; i++) {
        printf("Ma Sach: %s\n", danhSachSach[i].maSach);
        printf("Ten Sach: %s\n", danhSachSach[i].tenSach);
        printf("Ten Tac Gia: %s\n", danhSachSach[i].tenTacGia);
        printf("Nha Xuat Ban: %s\n", danhSachSach[i].nhaXuatBan);
        printf("So ISBN: %s\n", danhSachSach[i].soISBN);
        printf("Gia Tien: %.2f\n\n", danhSachSach[i].giaTien);
    }
}

// Hàm xuất danh sách sách theo mã sách
void xuatDanhSachTheoMaSach() {
    char maSach[20];
    printf("Nhap ma sach can hien thi: ");
    scanf("%s", maSach);

    int index = timSachTheoMa(maSach);
    if (index != -1) {
        printf("Ma Sach: %s\n", danhSachSach[index].maSach);
        printf("Ten Sach: %s\n", danhSachSach[index].tenSach);
        printf("Ten Tac Gia: %s\n", danhSachSach[index].tenTacGia);
        printf("Nha Xuat Ban: %s\n", danhSachSach[index].nhaXuatBan);
        printf("So ISBN: %s\n", danhSachSach[index].soISBN);
        printf("Gia Tien: %.2f\n\n", danhSachSach[index].giaTien);
    } else {
        printf("Khong tim thay sach!\n");
    }
}

// Hàm xuất giá tiền trung bình, cao nhất và thấp nhất
void xuatThongTinGiaTien() {
    if (soLuongSach == 0) {
        printf("Danh sach sach rong!\n");
        return;
    }
    float max = danhSachSach[0].giaTien, min = danhSachSach[0].giaTien, total = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (danhSachSach[i].giaTien > max) max = danhSachSach[i].giaTien;
        if (danhSachSach[i].giaTien < min) min = danhSachSach[i].giaTien;
        total += danhSachSach[i].giaTien;
    }
    float avg = total / soLuongSach;
    printf("Gia tien trung binh: %.2f\n", avg);
    printf("Gia tien cao nhat: %.2f\n", max);
    printf("Gia tien thap nhat: %.2f\n", min);
}

int main() {
    int luaChon;
    do {
        printf("\n===== MENU QUAN LY SACH =====\n");
        printf("1. Nhap thong tin sach\n");
        printf("2. Sua gia tien theo ma sach\n");
        printf("3. Sua ten tac gia theo ma sach\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Sap xep theo ten tac gia\n");
        printf("6. Sap xep theo gia tien\n");
        printf("7. Xuat toan bo danh sach\n");
        printf("8. Xuat danh sach theo ma sach\n");
        printf("9. Xuat gia tien trung binh, cao nhat, thap nhat\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1: nhapThongTinSach(); break;
            case 2: suaGiaTienTheoMaSach(); break;
            case 3: suaTenTacGiaTheoMaSach(); break;
            case 4: xoaSachTheoMaSach(); break;
            case 5: sapXepTheoTenTacGia(); break;
            case 6: sapXepTheoGiaTien(); break;
            case 7: xuatToanBoDanhSach(); break;
            case 8: xuatDanhSachTheoMaSach(); break;
            case 9: xuatThongTinGiaTien(); break;
            case 0: printf("Thoat chuong trinh...\n"); break;
            default: printf("Lua chon khong hop le!\n"); break;
        }
    } while (luaChon != 0);
    return 0;
}
