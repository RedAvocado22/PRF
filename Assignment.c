#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

int menu(){
	printf("---------------------------\n");
	printf("1.  Add a new student\n");
	printf("2.  Remove a student by name\n");
	printf("3.  Remove a student by ID\n");
	printf("4.  Search a student by name\n");
	printf("5.  Search a student by ID\n");
	printf("6.  Sort the list in ascending order of student's name\n");
    printf("7.  Sort the list in ascending order of student's ID\n");
    printf("8.  Sort the list in ascending order of student's scores\n");
    printf("9.  Print student list following rank\n");
    printf("10. Update student's information\n");
    printf("11. Print out the list\n");
	printf("0: Quit\n");
	printf("Select: ");
	int choice;
	scanf("%d", &choice);
	return choice;
}

char* lTrim (char s[]) {
    int i = 0;
    while (s[i] == ' ')	i++;
    if (i > 0) strcpy(&s[0], &s[i]);
    return s;
}

char* rTrim (char s[]) {
    int i = strlen(s) - 1;
    while (s[i] == ' ') i--;
    s[i+1] = '\0';
    return s;
}

char* trim (char s[]) {
    rTrim(lTrim(s));
    char *ptr = strstr(s, "  ");
    while (ptr != NULL)
    {
        strcpy(ptr, ptr + 1);
        ptr = strstr(s, "  ");
    }
    return s;
}

void xoaXuongDong(char x[]){
    size_t len = strlen(x);
    if(x[len-1]=='\n'){
        x[len-1]='\0';
    }
}

typedef struct Date {
        int day;
        int month;
        int year;
}date;

bool validDate(int d, int m, int y) {
        int maxd = 31;
        if ((d < 1) || (d > 31) || (m < 1) || (m > 12) || y < 0)
            return false;
        if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
            maxd = 30;
        if (m == 2)
        {
            if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
                maxd = 29;
            else
                maxd = 28;
        }
        if(d > maxd) return false;

        return true;
}

int ranking_student(int a, int b, int c, int d) {
        float average = (a + b + c + d) / 4;
        if(average <= 10 && average >= 9) return 1;
        if(average < 9.0 && average >= 8.0) return 2;
        if(average < 8.0 && average >= 7.0) return 3;
        if(average < 7.0 && average >= 6.0) return 4;
        if(average < 6.0 && average >= 5.0) return 5;
        return 6;
}

float average_student_score(int a, int b, int c, int d) {
    float ave = (float) (a + b + c + d) / 4;
    return ave;
}

typedef struct Student {
    char ID[10];
    char name[30];
    char gender[5];
    date birth;
    int years_old;
    int MAE_score;
    int PRF_score;
    int CSI_score;
    int CEA_score;
    int rank;
    float average_score;
}ST;

char* nameStr(char s[]) {
    trim(s);
    int L = strlen(s);
    int i;
    for(i = 0; i < L; i++)
        if(i == 0 || (i > 0 && s[i-1] == ' ')) s[i] = toupper(s[i]);
            else s[i] = tolower(s[i]);
    return s;
}

char* ID_set(char s[]) {
    trim(s);
    strupr(s);
    return s;
}

struct Student a[100];
int n = 0;

bool check_ID_exist(char s[]) {
    int i;
    if(n == 1) return 1;
    for(i = 1; i < n; i++)
        if(strcmp(s, a[i].ID) == 0) return false;
    return true;
}

bool check_score(int n) {
    if(n < 0) return false;
    if(n > 10) return false;
    return true;
}

void add_new() {
    n++;
    int check = 0;
    while (check == 0){
        printf("\nID: ");
        fflush(stdin); gets(a[n].ID); ID_set(a[n].ID);
        check = check_ID_exist(a[n].ID);
        if(check == 0) printf("\nThere are same ID, please try again!\n");
        xoaXuongDong(a[n].ID);
    }
    printf("\nStudent's name: "); fflush(stdin); gets(a[n].name); nameStr(a[n].name); xoaXuongDong(a[n].name);
    printf("\nGender: "); fflush(stdin); gets(a[n].gender); nameStr(a[n].gender); xoaXuongDong(a[n].gender);
    printf("\nBirth day: xx/mm/yyyy: "); scanf("%d/%d/%d", &a[n].birth.day, &a[n].birth.month, &a[n].birth.year);
    int b_check = validDate(a[n].birth.day, a[n].birth.month, a[n].birth.year);
    if(b_check == false){
        while(b_check == false) {
            printf("\nError day, please try again!\n");
            printf("\nBirth day: xx/mm/yyyy: ");
            scanf("%d/%d/%d", &a[n].birth.day, &a[n].birth.month, &a[n].birth.year);
            b_check = validDate(a[n].birth.day, a[n].birth.month, a[n].birth.year);
        }
    }
    printf("\nMAE score: "); scanf("%d", &a[n].MAE_score); b_check = check_score(a[n].MAE_score); if(b_check == false){printf("\nError score, please try again!\n"); scanf("%d", &a[n].MAE_score);}
    printf("\nPRF score: "); scanf("%d", &a[n].PRF_score); b_check = check_score(a[n].PRF_score); if(b_check == false){printf("\nError score, please try again!\n"); scanf("%d", &a[n].PRF_score);}
    printf("\nCSI score: "); scanf("%d", &a[n].CSI_score); b_check = check_score(a[n].CSI_score); if(b_check == false){printf("\nError score, please try again!\n"); scanf("%d", &a[n].CSI_score);}
    printf("\nCEA score: "); scanf("%d", &a[n].CEA_score); b_check = check_score(a[n].CEA_score); if(b_check == false){printf("\nError score, please try again!\n"); scanf("%d", &a[n].CEA_score);}
    a[n].rank = ranking_student(a[n].MAE_score, a[n].PRF_score, a[n].CSI_score, a[n].CEA_score);
    a[n].average_score = average_student_score(a[n].MAE_score, a[n].PRF_score, a[n].CSI_score, a[n].CEA_score);
}

void sort_students_name() {
    ST tmp;
    int i, j;
    for(i = 1; i <= n; i++) {
        int min = i;
        for(j = i+1; j <= n; j++)
            if(strcmp(a[j].name, a[min].name) > 0) min = j;
        if(min != i) {
            tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}

void sort_students_ID() {
    ST tmp;
    int i, j;
    for(i = 1; i <= n; i++) {
        int min = i;
        for(j = i+1; j <= n; j++)
            if(strcmp(a[j].ID, a[min].ID) > 0) min = j;
        if(min != i) {
            tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}

void sort_students_rank() {
    ST tmp;
    int i, j;
    for(i = 1 ;i <= n; i++) {
        for(j = i+1; j <= n; j++) {
            if(a[i].average_score < a[j].average_score) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int search_student(char student_name[]) {
    char tenSV[30];
    int i;
    for(i = 1; i <= n; i++) {
        strcpy(tenSV, a[i].name);
        if(strcmp(tenSV, student_name) == 0) return i;
    }
    return -1;
}

int search_ID(char student_id[]) {
    char sID[10];
    int i;
    for(i = 1; i <= n; i++) {
        strcpy(sID, a[i].ID);
        if(strcmp(sID, student_id) == 0) return i;
    }
    return -1;
}

int remove_student(char student_name[]) {
    int position;
    position = search_student(student_name);
    if (position == -1) return -1;
    int i;
    for(i = position; i < n; i++)
        a[i] = a[i+1];
    n--;
    return 1;
}

int remove_student_id(char student_id[]) {
    int position;
    position = search_ID(student_id);
    if(position == -1) return -1;
    position--;
    int i;
    for(i = position; i < n; i++)
        a[i] = a[i+1];
    n--;
    return 1;
}

void update_student_data(int request, int index) {
    if(request == 1) {
        printf("Entry new ID: ");
        fflush(stdin);
        gets(a[index].ID);
        ID_set(a[index].ID);
        xoaXuongDong(a[index].ID);
    }
    if(request == 2) {
        printf("Entry new name: ");
        fflush(stdin);
        gets(a[index].name);
        nameStr(a[index].name);
        xoaXuongDong(a[index].name);
    }
    if(request == 3) {
        printf("Entry new gender: ");
        fflush(stdin);
        gets(a[index].gender);
        nameStr(a[index].gender);
        xoaXuongDong(a[index].gender);
    }
    if(request == 4) {
        printf("Entry new birthday: ");
        scanf("%d%d%d", &a[index].birth.day, &a[index].birth.month, &a[index].birth.year);
        int b_check = validDate(a[index].birth.day, a[index].birth.month, a[index].birth.year);
        if(b_check == false){
            while(b_check == false) {
                printf("Error day, please try again!\n");
                scanf("%d/%d/%d", &a[index].birth.day, &a[index].birth.month, &a[index].birth.year);
                b_check = validDate(a[index].birth.day, a[index].birth.month, a[index].birth.year);
            }
        }
    }
    if(request == 5) {
        int score_to_fix;
        printf("1. MEA score\n");
        printf("2. PRF score\n");
        printf("3. CSI score\n");
        printf("4. CEA score\n");
        printf("Entry score need to fix: ");
        scanf("%d", &score_to_fix);
        if(score_to_fix == 1) {printf("Enter new score: "); scanf("%d", &a[index].MAE_score);}
        if(score_to_fix == 2) {printf("Enter new score: "); scanf("%d", &a[index].PRF_score);}
        if(score_to_fix == 3) {printf("Enter new score: "); scanf("%d", &a[index].CSI_score);}
        if(score_to_fix == 4) {printf("Enter new score: "); scanf("%d", &a[index].CEA_score);}
        a[index].rank = ranking_student(a[index].MAE_score, a[index].PRF_score, a[index].CSI_score, a[index].CEA_score);
        a[index].average_score = average_student_score(a[index].MAE_score, a[index].PRF_score, a[index].CSI_score, a[index].CEA_score);
    }
    printf("Update succeful!\n");
}

void out_put_all_student() {
        int i = 0;
        for(i = 1; i <= n; i++) {
            printf("%s\t", a[i].ID);
            printf("%s\t", a[i].name);
            printf("%s\t", a[i].gender);
            printf("%d/%d/%d\t", a[i].birth.day, a[i].birth.month, a[i].birth.year);
            if(a[i].rank == 1) printf("Excellent");
            if(a[i].rank == 2) printf("Very good");
            if(a[i].rank == 3) printf("Good");
            if(a[i].rank == 4) printf("Adequate");
            if(a[i].rank == 5) printf("Sufficient");
            if(a[i].rank == 6) printf("Failed");
            printf("\n");
        }
        printf("\n");
    }

void out_put_one(int index) {
    printf("%s\t", a[index].ID);
    printf("%s\t", a[index].name);
    printf("%s\t", a[index].gender);
    printf("%d/%d/%d\t", a[index].birth.day, a[index].birth.month, a[index].birth.year);
    if(a[index].rank == 1) printf("Excellent\n");
    if(a[index].rank == 2) printf("Very good\n");
    if(a[index].rank == 3) printf("Good\n");
    if(a[index].rank == 4) printf("Adequate\n");
    if(a[index].rank == 5) printf("Sufficient\n");
    if(a[index].rank == 6) printf("Failed\n");
}

void static_student(){
    int i, x, count = 0;
    printf("1. Excellent\n");
    printf("2. Very good\n");
    printf("3. Good\n");
    printf("4. Adequate\n");
    printf("5. Sufficient\n");
    printf("6. Failed\n");
    printf("Enter choice student's type: ");
    scanf("%d", &x);
    for(i = 1; i <= n; i++)
        if(a[i].rank == x) {
            out_put_one(i);
            count++;
        }
    if(count == 0) printf("There are not student in that type\n");
}

int main() {
    int userChoice, x;
    char id[10], choice[5];
    char name[30];
	do {
		userChoice=menu();
		switch(userChoice){
			case 1:
			    if(n == 100) {
                    printf("The list is full!\n");
                    break;
			    }
				add_new();
				break;
			case 2:
			    if(n < 0) {
                    printf("The list is empty.\n");
                    break;
                }
				printf("Enter student's name need to remove: ");
				fflush(stdin);
				gets(name);
				nameStr(name);
				if(remove_student(name) == -1) printf("Student's name doesnt exist in list.\n");
                    else printf("Remove successful.\n");
				break;
			case 3:
			    if(n < 0) {
                    printf("The list is empty.\n");
                    break;
                }
				printf("Enter student's ID need to remove: ");
				fflush(stdin);
				gets(id);
				ID_set(id);
				if(remove_student_id(id) == -1) printf("Student's ID doesnt exist in list.\n");
                    else printf("Remove successful.\n");
				break;
			case 4:
                if(n < 0) {
                    printf("The list is empty.\n");
                    break;
                }
                printf("Enter student's name need to find: ");
				fflush(stdin);
				gets(name);
				nameStr(name);
                x = search_student(name);
				if(x <= 0) printf("Student's name doesnt exist in list.\n");
                    else out_put_one(x);
				break;
            case 5:
                if(n < 0) {
                    printf("The list is empty.\n");
                    break;
                }
                printf("Enter student's ID need to find: ");
				fflush(stdin);
				gets(id);
				ID_set(id);
                x = search_ID(id);
				if(x <= 0) printf("Student's ID doesnt exist in list.\n");
                    else out_put_one(x);
				break;
            case 6:
                if(n < 0) {
                    printf("The list is empty.\n");
                    break;
                }
                sort_students_name();
                printf("Do you want to print the list out?\n");
                printf("Type: YES or NO\n");
                fflush(stdin);
                gets(choice);
                strupr(choice);
                if(strcmp(choice, "YES") == 0) out_put_all_student();
                break;
            case 7:
                if(n < 0) {
                    printf("The list is empty.\n");
                    break;
                }
                sort_students_ID();
                printf("Do you want to print the list out?\n");
                printf("Type: YES or NO\n");
                fflush(stdin);
                gets(choice);
                strupr(choice);
                if(strcmp(choice, "YES") == 0) out_put_all_student();
                break;
            case 8:
                if(n < 0) {
                    printf("The list is empty.\n");
                    break;
                }
                sort_students_rank();
                printf("Do you want to print the list out?\n");
                printf("Type: YES or NO\n");
                fflush(stdin);
                gets(choice);
                strupr(choice);
                if(strcmp(choice, "YES") == 0) out_put_all_student();
                break;
            case 9:
                if(n < 0) {
                    printf("The list is empty.\n");
                    break;
                }
                static_student();
                break;
            case 10:
                if(n < 0) {
                    printf("The list is empty.\n");
                    break;
                }
                int request, index;
                printf("1. Find by ID.\n");
                printf("2. Find by name.\n");
                printf("Choice: ");
                scanf("%d", &request);
                if(request == 1) {
                    printf("Enter student's ID need to change information: ");
                    fflush(stdin);
                    gets(id);
                    ID_set(id);
                    index = search_ID(id);
                } else {
                    printf("Enter student's name need to change information: ");
                    fflush(stdin);
                    gets(name);
                    nameStr(name);
                    index = search_student(name);
                }
                if(index > 0) {
                    printf("1. ID\n");
                    printf("2. Name\n");
                    printf("3. Gender\n");
                    printf("4. Birth\n");
                    printf("5. Score\n");
                    printf("Chose information need to update: ");
                    scanf("%d", &request);
                }
                else {
                    printf("Student's ID doesnt exist in list.\n");
                    break;
                }
                update_student_data(request, index);
                break;
            case 11:
                if(n < 0) {
                    printf("The list is empty.\n");
                    break;
                }
                out_put_all_student();
                break;
		}
	} while(userChoice > 0 && userChoice <= 11);
	printf("\nGood bye!");
    return 0;
}
