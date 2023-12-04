#include<stdio.h>
#include<string.h>
typedef struct{
    char id[50];
    char name[50];
    char author[50];
    float price;
    char genre[100];
} Book;
Book books[100];
int bookCount = 0;
void inputbook(Book *book){
    printf("nhap ma sach?\n");
    scanf("%s"book->id);
    printf("nhap ten sach?\n");
    scanf("%s"book->name);
    printf("Nhap tac gia?\n");
    scanf("%s"book->author);
    printf("Nhap gia tien?"\n);
    scanf("%.2f"book->price);
    printf("Nhap the loai?\n");
    scanf("%s"book->genre);
}
void displayBook(){
    for(int i = 0 ; i<bookCount ; i++){
    printf("Ma sach: %s\n"books[i].id);
    printf("ten sach: %s\n"books[i].name);
    printf("Tac gia: %s\n"books[i].author);
    printf("Gia tien: %.2f\n"books[i].price);
    printf("The loai: %s"books[i].genre);
    }
}
void addBook(Book book, int pos) {
    if(pos < 0 || pos > bookCount) {
        printf("Nhap so khong hop le vui long nhap trong khoang tu 0 den %d.\n", bookCount);
        return;
    }
    for(int i = bookCount; i > pos; i--) {
        books[i] = books[i - 1];
    }
    books[pos] = book;
    bookCount++;
    printf("Sach voi id %d duoc them vao thanh cong trong %d.\n", book.id, pos);
}

void deleteBook(int id) {
    int i;
    for(i = 0; i < bookCount; i++) {
        if(books[i].id == id) {
            break;
        }
    }
    if(i < bookCount) {
        for(int j = i; j < bookCount - 1; j++) {
            books[j] = books[j + 1];
        }
        bookCount--;
        printf("Sach co id %d duoc xoa thanh cong.\n", id);
    } else {
        printf("Sach co id  %d khong tim thay.\n", id);
    }
}
void updateBook() {
    char id[20];
    printf("Nhap ma sach can cap nhat: ");
    scanf("%s", id);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].id, id) == 0) {
            printf("Nhap ten sach moi: ");
            scanf("%s", books[i].name);
            printf("Nhap ten tac gia moi: ");
            scanf("%s", books[i].author);
            printf("Nhap gia tien moi: ");
            scanf("%f", &books[i].price);
            printf("Nhap the loai moi: ");
            scanf("%s", books[i].genre);
            printf("Thong tin sach da duoc cap nhat.\n");
            return;
        }
    }

    printf("Khong tim thay sach voi ma da nhap.\n");
}
void sortBooksByPrice() {
    for(int i = 0; i < bookCount - 1; i++) {
        for(int j = 0; j < bookCount - i - 1; j++) {
            if(books[j].price > books[j + 1].price) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    printf("Tim thanh cong.\n");
    void searchBookByName(){
    char tenSachCanTim[100];
    printf("Nhap ten sach can tim: ");
    scanf(" %[^\n]", tenSachCanTim);
    int timThay = 0;
    for(int i = 0; i < soLuongSach; i++){
        if(strstr(danhSachBook[i].tenSach, tenSachCanTim) != NULL){
            xuatBooks(i);
            timThay = 1;
        }
    }
    if(!timThay){
        printf("Khong tim thay sach voi ten %s.\n", tenSachCanTim);
    }
}

void arrangeBookByPrice(
    int tangGiam){
    struct Books temp;
    for(int i = 0; i < soLuongSach - 1; i++){
        for(int j = 0; j < soLuongSach - i - 1; j++){
            if(tangGiam == 1 && strcmp(danhSachBook[j].giaTien, danhSachBook[j + 1].giaTien) > 0){
                temp = danhSachBook[j];
                danhSachBook[j] = danhSachBook[j + 1];
                danhSachBook[j + 1] = temp;
            } else if(tangGiam == 2 && strcmp(danhSachBook[j].giaTien, danhSachBook[j + 1].giaTien) < 0){
                temp = danhSachBook[j];
                danhSachBook[j] = danhSachBook[j + 1];
                danhSachBook[j + 1] = temp;
            }

}
int main() {
    int choice;
    do {
        printf("MENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin theo ma sach\n");
        printf("6. Sap xep sach theo gia\n");
        printf("7. tim kiem sach theo ten sach\n");
        printf("8. Tim kiem sach theo khoang gia\n");
        printf("9. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice );
        switch (choice) {
            case 1:
                inputBook();
                break;
            case 2:
                displayBook();
                break;
            case 3:
                addBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                updateBook();
                break;
            case 6:
                arrangeBookByPrice();
                break;
            case 7:
                searchBookByName();
                break;
            case 8:
                searchBookByPrice();
                break;
            case 9:

        }
    } while (choice != 9);
    return 0;
}

