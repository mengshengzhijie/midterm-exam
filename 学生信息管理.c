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
        char username[50]={"admin"}, password[50]={"admin"};
        printf("���û���½��\n");
        printf("\t�û���: ");
//        scanf("%s", username);
        printf("\t����: ");
//        scanf("%s", password);
        if(strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
            return 1;
        } else {
            attempt++;
            printf("{{{(>_<)}}}��������û���������� %d/%d\n", attempt, 3);
        }
    }
    return 0;
}

// ��ʾ�˵�����
void menu() {
    system("cls");
    printf("");
    printf("        --------------------------------------\n");
    printf("        |             ѧ������ϵͳƽ̨           |\n");
    printf("        --------------------------------------\n");
    for (int i = 0; i < 60; ++i) {
        printf("����");
    }
    printf("\t���ܲ˵���\n");
    printf("\t\t1��¼�뵥��ѧ����Ϣ\n");
    printf("\t\t2����ʾ����ѧ������\n");
    printf("\t\t3��������ʾ����ѧ���ɼ�\n");
    printf("\t\t4�����뵥��ѧ����Ϣ\n");
    printf("\t\t5��ɾ������ѧ����Ϣ\n");
    printf("\t\t6�����ҵ���ѧ����Ϣ\n");
    printf("\t\t7���˳�ϵͳ\n");
}

// ¼��ѧ����Ϣ����
void inputStudentInfo() {
    // ʵ��¼��ѧ����Ϣ����
}

// ��ʾѧ����Ϣ����
void displayStudentInfo() {
    // ʵ����ʾѧ����Ϣ����
}

// ����ѧ����Ϣ����
void insertStudentInfo() {
    // ʵ�ֲ���ѧ����Ϣ����
}

// ɾ��ѧ����Ϣ����
void removeStudentInfo() {
    // ʵ��ɾ��ѧ����Ϣ����
}

// ����ѧ����Ϣ����
void searchStudentInfo() {
    // ʵ�ֲ���ѧ����Ϣ����
}

// ����ѧ����Ϣ����
void sortStudentInfo() {
    // ʵ������ѧ����Ϣ����
}

int main() {
    if(login()) {
        int choice;
        while(1) {
            menu();
            printf("��ѡ��: ");
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
        printf("'(��m����...������Ĵ������࣬���Ժ�����һ�ԣ���\n");
    }

    return 0;
}