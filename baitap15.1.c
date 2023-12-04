#include<stdio.h>
    struct student{
        int id;
        char hoVaTen[50];
        int tuoi;
        char soDienThoai[15];
        char email[100]
};
int main(){
    struct student st1;
    strcpy(st1.hoVaTen,"Tran Quang Linh");
    st1.id = 1;
    st1.tuoi = 18;
    strcpy(st1.soDienThoai,"0867159132");
    strcpy(st1.email,"tuhithanahihi@gmail.com");
    printf("id %d\n Name %s\n Age %d\n phone number %s\n email %s\n", st1.id , st1.hoVaTen , st1.tuoi , st1.soDienThoai , st1.email);
    return 0;
}