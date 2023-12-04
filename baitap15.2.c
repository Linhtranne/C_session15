#include <stdio.h>

typedef struct {
    char hoVaTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[30];
} SinhVien;

void nhapThongTin(SinhVien* sv) {
    printf("Nhap ho va ten: ");
    gets(sv->hoVaTen);
    printf("Nhap tuoi: ");
    scanf("%d", &(sv->tuoi));
    printf("Nhap so dien thoai: ");
    scanf("%s", sv->soDienThoai);
    printf("Nhap email: ");
    scanf("%s", sv->email);
}
void xuatThongTin(SinhVien sv) {
    printf("Ho va ten: %s\n", sv.hoVaTen);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("So dien thoai: %s\n", sv.soDienThoai);
    printf("Email: %s\n", sv.email);
}

int main() {
    SinhVien sv;
    nhapThongTin(&sv);
    xuatThongTin(sv);
    return 0;
}
