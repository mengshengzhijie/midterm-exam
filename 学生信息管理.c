//
// Created by MengShengZhiJie on 2023/12/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define USERNAME "admin"
#define PASSWORD "admin"

typedef struct {
    int id;
    char name[50];
    int score1, score2, score3;
    float average_score;
} Student;

Student students[MAX_STUDENTS];
int count = 0;

// 登录函数
int login() {
    int attempt = 0;
    while(attempt < 3) {
        char username[50], password[50];
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if(strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
            return 1;
        } else {
            attempt++;
            printf("Incorrect username or password. Attempt %d/%d\n", attempt, 3);
        }
    }
    return 0;
}

// 显示菜单函数
void menu() {
    system("cls");
    printf("Menu:\n");
    printf("1.录入学生信息\n");
    printf("2.显示学生信息\n");
    printf("3.插入学生信息\n");
    printf("4.删除学生信息\n");
    printf("5.查找学生信息\n");
    printf("6.排序学生信息\n");
    printf("7.退出系统\n");
}

// 录入学生信息函数
void inputStudentInfo() {
    // 实现录入学生信息功能
}

// 显示学生信息函数
void displayStudentInfo() {
    // 实现显示学生信息功能
}

// 插入学生信息函数
void insertStudentInfo() {
    // 实现插入学生信息功能
}

// 删除学生信息函数
void removeStudentInfo() {
    // 实现删除学生信息功能
}

// 查找学生信息函数
void searchStudentInfo() {
    // 实现查找学生信息功能
}

// 排序学生信息函数
void sortStudentInfo() {
    // 实现排序学生信息功能
}

int main() {
    if(login()) {
        int choice;
        while(1) {
            menu();
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    inputStudentInfo();
                    break;
                case 2:
                    displayStudentInfo();
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    insertStudentInfo();
                    displayStudentInfo();
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    removeStudentInfo();
                    displayStudentInfo();
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    searchStudentInfo();
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    sortStudentInfo();
                    displayStudentInfo();
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    printf("程序结束！");
                    exit(1);
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        }
    } else {
        printf("Login failed!\n");
    }

    return 0;
}