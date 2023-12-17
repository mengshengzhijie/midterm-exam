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

// ��¼����
int login() {
    int attempt = 0;
    while(attempt < 3) {
        char username[50], password[50];
        printf("�û���: ");
        scanf("%s", username);
        printf("����: ");
        scanf("%s", password);

        if(strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
            return 1;
        } else {
            attempt++;
            printf("{{{(>_<)}}}������� %d/%d\n", attempt, 3);
        }
    }
    return 0;
}

// ��ʾ�˵�����
void menu() {
    system("cls");
    printf("Menu:\n");
    printf("1.¼��ѧ����Ϣ\n");
    printf("2.��ʾѧ����Ϣ\n");
    printf("3.����ѧ����Ϣ\n");
    printf("4.ɾ��ѧ����Ϣ\n");
    printf("5.����ѧ����Ϣ\n");
    printf("6.����ѧ����Ϣ\n");
    printf("7.�˳�ϵͳ\n");
}

// ¼��ѧ����Ϣ����
void inputStudentInfo() {
    // ʵ��¼��ѧ����Ϣ����

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
                    printf("���������");
                    exit(1);
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        }
    } else {
        printf("(��m����������������࣬���Ժ�����һ�ԣ���\n");
    }

    return 0;
}