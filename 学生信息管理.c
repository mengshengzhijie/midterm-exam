//
// Created by MengShengZhiJie on 2023/12/15.
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
        printf("【用户登陆】\n");
        printf("\t用户名: ");
        scanf("%s", username);
        printf("\t密码: ");
        scanf("%s", password);
        if(strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
            return 1;
        } else {
            attempt++;
            printf("{{{(>_<)}}}你输入的用户或密码错误 %d/%d\n", attempt, 3);
        }
    }
    return 0;
}

// 显示菜单函数
void menu() {
    system("cls");
    printf("");
    printf("        --------------------------------------\n");
    printf("        |             学生管理系统平台           |\n");
    printf("        --------------------------------------\n");
    for (int i = 0; i < 60; ++i) {
        printf("——");
    }
    printf("\t功能菜单：\n");
    printf("\t\t1、录入单个学生信息\n");
    printf("\t\t2、显示所有学生的信\n");
    printf("\t\t3、排序显示所有学生成绩\n");
    printf("\t\t4、插入单个学生信息\n");
    printf("\t\t5、删除单个学生信息\n");
    printf("\t\t6、查找单个学生信息\n");
    printf("\t\t7、退出系统\n");
}

// 录入学生信息函数
void inputStudentInfo() {
    // 实现录入学生信息功能
    if (count >= MAX_STUDENTS) {
        printf("学生数量已达最大值，无法再添加新的学生信息。\n");
        return;
    }
    int verify;
    verify = 0;
    Student new_student;

    do {
        printf("请输入学生信息：\n");
        printf("学号: ");
        scanf("%d", &new_student.id);

        // 检查学号是否已存在
        for (int i = 0; i < count; i++) {
            if (students[i].id == new_student.id) {
                printf("该学号已存在，请重新输入。\n");
                verify = 1;
                break;
            }
        }
    } while (new_student.id <= 0 || new_student.id > MAX_STUDENTS); // 确保学号在有效范围内

    do {
        printf("姓名: ");
        scanf("%s", new_student.name);

        // 检查姓名是否包含数字
        for (int i = 0; new_student.name[i] != '\0'; i++) {
            if (isdigit(new_student.name[i])) {
                printf("姓名不能包含数字，请重新输入。\n");
                verify = 1;
                break;
            }
        }
        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, new_student.name) == 0) {
                printf("该姓名已存在，请重新输入。\n");
                return;
            }
        }
    } while (new_student.name[0] == '\0'); // 确保姓名不为空

    do {
        printf("分数1: ");
        scanf("%d", &new_student.score1);
        printf("分数2: ");
        scanf("%d", &new_student.score2);
        printf("分数3: ");
        scanf("%d", &new_student.score3);

        // 检查成绩是否在0-100之间
        if (new_student.score1 < 0 || new_student.score1 > 100 ||
            new_student.score2 < 0 || new_student.score2 > 100 ||
            new_student.score3 < 0 || new_student.score3 > 100) {
            printf("成绩必须在0-100之间，请重新输入。\n");
            verify = 1;
        }
    } while (new_student.score1 < 0 || new_student.score1 > 100 ||
             new_student.score2 < 0 || new_student.score2 > 100 ||
             new_student.score3 < 0 || new_student.score3 > 100);

    new_student.average_score = (new_student.score1 + new_student.score2 + new_student.score3) / 3.0f;

    students[count++] = new_student;

    printf("学生信息录入成功！\n");
}

// 显示学生信息函数
void displayStudentInfo() {
    // 实现显示学生信息功能
    if (count == 0) {
        printf("暂无学生信息可供显示。\n");
        return;
    }

    printf("学生信息如下：\n");
    printf("ID\t姓名\t成绩1\t成绩2\t成绩3\t平均分\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",
               students[i].id, students[i].name,
               students[i].score1, students[i].score2, students[i].score3,
               students[i].average_score);
    }
}

// 插入学生信息函数
void insertStudentInfo() {
    // 实现插入学生信息功能
        if (count >= MAX_STUDENTS) {
            printf("学生数量已达最大值，无法插入更多学生信息。\n");
            return;
        }

        Student newStudent;
        printf("请输入要插入的学生信息：\n");
        printf("ID: ");
        scanf("%d", &newStudent.id);

        printf("姓名: ");
        scanf("%s", newStudent.name);

        printf("成绩1: ");
        scanf("%d", &newStudent.score1);

        printf("成绩2: ");
        scanf("%d", &newStudent.score2);

        printf("成绩3: ");
        scanf("%d", &newStudent.score3);

        newStudent.average_score = (newStudent.score1 + newStudent.score2 + newStudent.score3) / 3.0;

        students[count] = newStudent;
        count++;

        printf("学生信息插入成功!\n");
    }

// 删除学生信息函数
void removeStudentInfo() {
    // 实现删除学生信息功能
    int id_to_remove;
    printf("请输入要删除的学生的ID：\n");
    scanf("%d", &id_to_remove);

    // 查找并删除学生信息
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
        printf("学生ID为%d的信息已成功删除。\n", id_to_remove);
    } else {
        printf("未找到学生ID为%d的信息。\n", id_to_remove);
    }
}

// 查找学生信息函数
void searchStudentInfo() {
    // 实现查找学生信息功能
    int target_id;
    printf("\t请输入要查找的学生的ID：");
    scanf("%d", &target_id);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id == target_id) {
            found = 1;
            printf("\n【查找结果】\n");
            printf("ID: %d\n", students[i].id);
            printf("姓名: %s\n", students[i].name);
            printf("成绩1: %d\n", students[i].score1);
            printf("成绩2: %d\n", students[i].score2);
            printf("成绩3: %d\n", students[i].score3);
            printf("平均分: %.2f\n", students[i].average_score);
            break;
        }
    }

    if (!found) {
        printf("\n【查找结果】\n");
        printf("未找到ID为%d的学生信息。\n", target_id);
    }
}

// 排序学生信息函数
void sortStudentInfo() {
    // 实现排序学生信息功能
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

        printf("\n【排序后的学生信息】\n");
        for (int i = 0; i < count; i++) {
            printf("ID: %d\n", students[i].id);
            printf("姓名: %s\n", students[i].name);
            printf("成绩1: %d\n", students[i].score1);
            printf("成绩2: %d\n", students[i].score2);
            printf("成绩3: %d\n", students[i].score3);
            printf("平均分: %.2f\n", students[i].average_score);
            printf("\n");
        }
    }
}

int main() {
    if(login()) {
        int choice;
        while(1) {
            menu();
            printf("请选择: ");
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
                    printf("程序结束！");
                    exit(1);
                    break;
                default:
                    printf("(⊙?⊙)？无效的选择!\n");
                    system("pause");
            }
        }
    } else {
        printf("'(￣m￣）...您输入的次数过多，请稍后在试一试！！\n");
    }
    return 0;

}