#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "students.dat"
#define BUFFER_SIZE 5   

typedef struct {
    int roll;
    char name[50];
    float marks;
} Student;
FILE* openFile(const char *mode) {
    FILE *fp = fopen(DATA_FILE, mode);
    if (!fp) {
        perror("File operation failed");
    }
    return fp;
}

void addRecord() {
    FILE *fp = openFile("ab");
    if (!fp) return;

    Student s;

    printf("Enter Roll: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);

    printf("Record added successfully.\n");
}
void displayRecords() {
    FILE *fp = openFile("rb");
    if (!fp) return;

    Student buffer[BUFFER_SIZE];

    printf("\n--- Student Records ---\n");

    while (1) {
        size_t readCount = fread(buffer, sizeof(Student), BUFFER_SIZE, fp);

        if (readCount == 0)
            break;

        for (size_t i = 0; i < readCount; i++) {
            printf("Roll: %d | Name: %s | Marks: %.2f\n",
                   buffer[i].roll,
                   buffer[i].name,
                   buffer[i].marks);
        }
    }

    fclose(fp);
}

void searchRecord() {
    FILE *fp = openFile("rb");
    if (!fp) return;

    int roll;
    printf("Enter Roll to search: ");
    scanf("%d", &roll);

    Student s;
    int found = 0;

    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll == roll) {
            printf("Found -> Name: %s | Marks: %.2f\n", s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found.\n");

    fclose(fp);
}

void updateRecord() {
    FILE *fp = openFile("rb+");
    if (!fp) return;

    int roll;
    printf("Enter Roll to update: ");
    scanf("%d", &roll);

    Student s;
    int found = 0;

    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll == roll) {

            printf("Enter new Name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new Marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);

            printf("Record updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found.\n");

    fclose(fp);
}

void deleteRecord() {
    FILE *fp = openFile("rb");
    if (!fp) return;

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        perror("Temp file error");
        fclose(fp);
        return;
    }

    int roll;
    printf("Enter Roll to delete: ");
    scanf("%d", &roll);

    Student s;
    int found = 0;

    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll != roll) {
            fwrite(&s, sizeof(Student), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(DATA_FILE);
    rename("temp.dat", DATA_FILE);

    if (found)
        printf("Record deleted successfully.\n");
    else
        printf("Record not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Data Management =====\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}