#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee{
    char id[10];
    char name[20];
    char sex;
    int salary;
}E;
int main(){
    char i[20],*a,*b,*c,*d;
    FILE *Emp;
    if((Emp = fopen("Employee.db","rb")) == NULL){
        printf("檔案無法開啟！\n");
        exit(0);
    }
    a = &E.id;
    b = &E.name;
    c = &E.sex;
    d = &E.salary;
    printf("請輸入想查詢的資料：\n");
    scanf("%s",&i);
    if(strcmp(i,"id") == 0){
        fseek(Emp,0,SEEK_SET);
        fread(a,sizeof(E.id),1,Emp);
        printf("%s\n",a);
    }else if(strcmp(i,"name") == 0){
        fseek(Emp,10,SEEK_SET);
        fread(b,sizeof(E.name),1,Emp);
        printf("%s\n",b);
    }else if(strcmp(i,"sex") == 0){
        fseek(Emp,30,SEEK_SET);
        fread(c,sizeof(E.sex),1,Emp);
        printf("%s\n",c);
    }else if(strcmp(i,"salary") == 0){
        fseek(Emp,31,SEEK_SET);
        fread(d,sizeof(E.salary),1,Emp);
        printf("%d\n",E.salary);
    }
    fclose(Emp);
    printf("讀取完成\n");
    system("PAUSE");
    return 0;
}





