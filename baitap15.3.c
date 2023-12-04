
#include <stdio.h>

typedef struct {
    char hoVaTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[30];
} SinhVien;
SinhVien danhSach[100];
int soLuong = 0;
void nhapThongTin(SinhVien* sv){
    printf("Nhap ho va ten?");
    gets(sv ->hoVaTen);
    printf("Nhap tuoi?");
    scanf("%d", &(sv->tuoi));
    printf("Nhap so dien thoai");
    scanf("%s", (sv->soDienThoai));
    printf("Nhap email");
    scanf("%s", (sv->email));
}
void themSinhVien(SinhVien sv){
    danhSach[soLuong] = sv;
    soLuong++;
}
void suaThongTin(viTri, thongTin,themSinhVien){
    if(viTri > 0 && viTri < soLuong){
        for(int i = viTri ; i < soLuong - 1 ; i++){
            danhSach[i] = danhSach[i + 1];
        }
        soLuong--;
    }
    else {printf("Nhap sai roi \n");};
}
void inThongTin(SinhVien sv){
     printf("Ho va ten: %s\n", sv.hoVaTen);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("So dien thoai: %s\n", sv.soDienThoai);
    printf("Email: %s\n", sv.email);
}
void inDanhSach() {
    for (int i = 0; i < soLuong; i++) {
        printf("Sinh vien thu %d:\n", i + 1);
        inThongTin(danhSach[i]);
    }
}
int main(){
    SinhVien sv;
    nhapThongTin (&sv);
    themSinhVien(sv);
    inDanhSach();
    return 0;
}

