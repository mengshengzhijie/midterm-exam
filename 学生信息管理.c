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
        printf("���û���½��\n");
        printf("\t�û���: ");
        scanf("%s", username);
        printf("\t����: ");
        scanf("%s", password);
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
    if (count >= MAX_STUDENTS) {
        printf("ѧ�������Ѵ����ֵ���޷�������µ�ѧ����Ϣ��\n");
        return;
    }

    Student new_student;

    printf("������ѧ����Ϣ��\n");
    printf("ѧ��: ");
    scanf("%d", &new_student.id);

    printf("����: ");
    scanf("%s", new_student.name);

    printf("����1: ");
    scanf("%d", &new_student.score1);

    printf("����2: ");
    scanf("%d", &new_student.score2);

    printf("����3: ");
    scanf("%d", &new_student.score3);

    new_student.average_score = (new_student.score1 + new_student.score2 + new_student.score3) / 3.0f;

    students[count++] = new_student;

    printf("ѧ����Ϣ¼��ɹ���\n");
}

// ��ʾѧ����Ϣ����
void displayStudentInfo() {
    // ʵ����ʾѧ����Ϣ����
    if (count == 0) {
        printf("����ѧ����Ϣ�ɹ���ʾ��\n");
        return;
    }

    printf("ѧ����Ϣ���£�\n");
    printf("ID\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\tƽ����\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",
               students[i].id, students[i].name,
               students[i].score1, students[i].score2, students[i].score3,
               students[i].average_score);
    }
}

// ����ѧ����Ϣ����
void insertStudentInfo() {
    // ʵ�ֲ���ѧ����Ϣ����
        if (count >= MAX_STUDENTS) {
            printf("ѧ�������Ѵ����ֵ���޷��������ѧ����Ϣ��\n");
            return;
        }

        Student newStudent;
        printf("������Ҫ�����ѧ����Ϣ��\n");
        printf("ID: ");
        scanf("%d", &newStudent.id);

        printf("����: ");
        scanf("%s", newStudent.name);

        printf("�ɼ�1: ");
        scanf("%d", &newStudent.score1);

        printf("�ɼ�2: ");
        scanf("%d", &newStudent.score2);

        printf("�ɼ�3: ");
        scanf("%d", &newStudent.score3);

        newStudent.average_score = (newStudent.score1 + newStudent.score2 + newStudent.score3) / 3.0;

        students[count] = newStudent;
        count++;

        printf("ѧ����Ϣ����ɹ�!\n");
    }

// ɾ��ѧ����Ϣ����
void removeStudentInfo() {
    // ʵ��ɾ��ѧ����Ϣ����
    int id_to_remove;
    printf("������Ҫɾ����ѧ����ID��\n");
    scanf("%d", &id_to_remove);

    // ���Ҳ�ɾ��ѧ����Ϣ
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id_to_remove) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            break;
        }
    }

    if (found) {
        printf("ѧ��IDΪ%d����Ϣ�ѳɹ�ɾ����\n", id_to_remove);
    } else {
        printf("δ�ҵ�ѧ��IDΪ%d����Ϣ��\n", id_to_remove);
    }
}

// ����ѧ����Ϣ����
void searchStudentInfo() {
    // ʵ�ֲ���ѧ����Ϣ����
    int target_id;
    printf("\t������Ҫ���ҵ�ѧ����ID��");
    scanf("%d", &target_id);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id == target_id) {
            found = 1;
            printf("\n�����ҽ����\n");
            printf("ID: %d\n", students[i].id);
            printf("����: %s\n", students[i].name);
            printf("�ɼ�1: %d\n", students[i].score1);
            printf("�ɼ�2: %d\n", students[i].score2);
            printf("�ɼ�3: %d\n", students[i].score3);
            printf("ƽ����: %.2f\n", students[i].average_score);
            break;
        }
    }

    if (!found) {
        printf("\n�����ҽ����\n");
        printf("δ�ҵ�IDΪ%d��ѧ����Ϣ��\n", target_id);
    }
}

// ����ѧ����Ϣ����
void sortStudentInfo() {
    // ʵ������ѧ����Ϣ����
    void swap(Student* a, Student* b) {
        Student temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition(Student arr[], int low, int high) {
        Student pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j].average_score < pivot.average_score) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    void quickSort(Student arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void sortStudentInfo() {
        quickSort(students, 0, count - 1);

        printf("\n��������ѧ����Ϣ��\n");
        for (int i = 0; i < count; i++) {
            printf("ID: %d\n", students[i].id);
            printf("����: %s\n", students[i].name);
            printf("�ɼ�1: %d\n", students[i].score1);
            printf("�ɼ�2: %d\n", students[i].score2);
            printf("�ɼ�3: %d\n", students[i].score3);
            printf("ƽ����: %.2f\n", students[i].average_score);
            printf("\n");
        }
    }
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

                    system("pause");
                    system("cls");
                    break;
                case 5:
                    displayStudentInfo();
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    searchStudentInfo();
                    displayStudentInfo();
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    printf("���������");
                    exit(1);
                    break;
                default:
                    printf("(��?��)����Ч��ѡ��!\n");
            }
        }
    } else {
        printf("'(��m����...������Ĵ������࣬���Ժ�����һ�ԣ���\n");
    }
    return 0;

}