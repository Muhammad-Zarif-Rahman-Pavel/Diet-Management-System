#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct Person {
    char name[50];
    char profession[50];
    int age;
    char gender;
    float height_m;
    float weight_kg;
    float bmi;
    int entryID;
};

int getCalculatedAge() {
    int bd, bm, by;
    int mDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("\n--- Age Calculator ---");
    printf("\nEnter Birth Day (1-31): "); scanf("%d", &bd);
    printf("Enter Birth Month (1-12): "); scanf("%d", &bm);
    printf("Enter Birth Year (YYYY): "); scanf("%d", &by);
    while (getchar() != '\n');

    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    int cd = now->tm_mday, cm = now->tm_mon + 1, cy = now->tm_year + 1900;

    if ((by % 4 == 0 && by % 100 != 0) || (by % 400 == 0)) mDays[1] = 29;
    if (bd > cd) { cd += mDays[bm - 1]; cm--; }
    if (bm > cm) { cy--; cm += 12; }

    return cy - by;
}

void displaySortedData(struct Person p[], int n);
void suggestExercise(float bmi);
void showMealPlan();
int deletePerson(struct Person p[], int n);

int main() {
    struct Person people[MAX];
    int count = 0, choice;

    while (1) {
        printf("\n==========================================");
        printf("\n========= DIET MANAGEMENT SYSTEM =========");
        printf("\n==========================================");
        printf("\n1. Add Individual Data");
        printf("\n2. View & Sort Stored Records");
        printf("\n3. View Meal Plan & Calories");
        printf("\n4. Delete Individual Record");
        printf("\n5. Exit");
        printf("\nChoice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        if (choice == 5) break;

        switch (choice) {
            case 1:
                if (count < MAX) {
                    char ageInput[20];
                    people[count].entryID = count;

                    printf("Enter Name: ");
                    fgets(people[count].name, 50, stdin);
                    people[count].name[strcspn(people[count].name, "\n")] = 0;

                    printf("Enter Profession: ");
                    fgets(people[count].profession, 50, stdin);
                    people[count].profession[strcspn(people[count].profession, "\n")] = 0;

                    printf("Enter Age (or type 'calc' if unknown): ");
                    fgets(ageInput, 20, stdin);
                    ageInput[strcspn(ageInput, "\n")] = 0;

                    if (strcmp(ageInput, "calc") == 0 || strcmp(ageInput, "CALC") == 0) {
                        people[count].age = getCalculatedAge();
                        printf("Calculated Age: %d Years\n", people[count].age);
                    } else {
                        people[count].age = atoi(ageInput);
                    }

                    printf("Enter Gender (M/F): ");
                    scanf(" %c", &people[count].gender);
                    while (getchar() != '\n');

                    int hUnit;
                    printf("Height Unit (1. Meters, 2. CM, 3. Feet & Inches): ");
                    scanf("%d", &hUnit);
                    if (hUnit == 1) {
                        printf("Enter Meters: "); scanf("%f", &people[count].height_m);
                    } else if (hUnit == 2) {
                        float cm; printf("Enter CM: "); scanf("%f", &cm);
                        people[count].height_m = cm / 100.0;
                    } else {
                        int ft, in;
                        printf("Enter Feet: "); scanf("%d", &ft);
                        printf("Enter Inches: "); scanf("%d", &in);
                        people[count].height_m = (ft * 0.3048) + (in * 0.0254);
                    }
                    while (getchar() != '\n');

                    int wUnit;
                    printf("Weight Unit (1. Kg, 2. Pounds): ");
                    scanf("%d", &wUnit);
                    if (wUnit == 1) {
                        printf("Enter Kg: "); scanf("%f", &people[count].weight_kg);
                    } else {
                        float lbs; printf("Enter Lbs: "); scanf("%f", &lbs);
                        people[count].weight_kg = lbs * 0.453592;
                    }
                    while (getchar() != '\n');

                    people[count].bmi = people[count].weight_kg / (people[count].height_m * people[count].height_m);

                    printf("\n--- ENTRY SAVED ---");
                    printf("\nBMI Result: %.2f", people[count].bmi);
                    suggestExercise(people[count].bmi);

                    count++;
                } else {
                    printf("\nSystem database full!\n");
                }
                break;

            case 2:
                if (count == 0) printf("\nNo records found. Please add individual data first.\n");
                else displaySortedData(people, count);
                break;

            case 3:
                showMealPlan();
                break;

            case 4:
                if (count == 0) printf("\nNo records found.\n");
                else count = deletePerson(people, count);
                break;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}

void suggestExercise(float bmi) {
    printf("\n--- PHYSICAL ACTIVITY ADVICE ---");
    if (bmi < 18.5) {
        printf("\nADVICE: Underweight. Focus on surplus nutrition and strength training.\n");
    } else if (bmi > 24.9) {
        float diff = bmi - 24.9;
        printf("\nADVICE: Overweight. To reach normal range (BMI 24.9), choose one daily:");
        printf("\n- Running: %.0f mins/day", diff * 15);
        printf("\n- Jogging: %.0f mins/day", diff * 25);
        printf("\n- Walking: %.0f mins/day\n", diff * 45);
    } else {
        printf("\nADVICE: Perfect Range! Maintain 20 mins of daily walking.\n");
    }
}

void displaySortedData(struct Person p[], int n) {
    int sortChoice, genderFilterChoice;
    char filterGender = '\0';

    printf("\n1. By Added Time\n2. By Name\n3. By Age\n4. By Gender\n5. BMI Low-High\n6. BMI High-Low\nChoice: ");
    scanf("%d", &sortChoice);
    while (getchar() != '\n');

    if (sortChoice == 4) {
        printf("\n1. Male\n2. Female\n3. All\nChoice: ");
        scanf("%d", &genderFilterChoice);
        while (getchar() != '\n');
        if (genderFilterChoice == 1) filterGender = 'M';
        else if (genderFilterChoice == 2) filterGender = 'F';
        else filterGender = 'A';
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int swap = 0;
            if (sortChoice == 1 && p[j].entryID > p[j+1].entryID) swap = 1;
            else if (sortChoice == 2 && strcmp(p[j].name, p[j+1].name) > 0) swap = 1;
            else if (sortChoice == 3 && p[j].age > p[j+1].age) swap = 1;
            else if (sortChoice == 4 && p[j].gender > p[j+1].gender) swap = 1;
            else if (sortChoice == 5 && p[j].bmi > p[j+1].bmi) swap = 1;
            else if (sortChoice == 6 && p[j].bmi < p[j+1].bmi) swap = 1;

            if (swap) { struct Person temp = p[j]; p[j] = p[j+1]; p[j+1] = temp; }
        }
    }

    float totalBMI = 0;
    int displayedCount = 0;

    printf("\n%-22s %-12s %-5s %-5s %-7s", "Name", "Profession", "Age", "Gen", "BMI");
    printf("\n-------------------------------------------------------------");
    for (int i = 0; i < n; i++) {
        if (sortChoice == 4 && filterGender != 'A' && p[i].gender != filterGender) continue;
        printf("\n%-15s %-12s %-5d %-5c %-7.2f", p[i].name, p[i].profession, p[i].age, p[i].gender, p[i].bmi);
        totalBMI += p[i].bmi;
        displayedCount++;
    }
    printf("\n-------------------------------------------------------------");
    if (displayedCount > 0) printf("\nAverage BMI of Selected: %.2f\n", totalBMI / displayedCount);
}

void showMealPlan() {
    printf("\n--- Standard Meal Plan ---");
    printf("\nBreakfast: 1 Cup Rice/Roti, 1 Egg, Dairies  [~450 kcal]");
    printf("\nLunch    : 2 Cups Rice, Fish/Meat, Veggie   [~850 kcal]");
    printf("\nDinner   : 1 Cup Rice, Small Fish, Fruits   [~600 kcal]\n");
}

int deletePerson(struct Person p[], int n) {
    char target[50];
    int foundIndex = -1;
    printf("\nEnter Name for deletion: ");
    fgets(target, 50, stdin);
    target[strcspn(target, "\n")] = 0;

    for (int i = 0; i < n; i++) {
        if (strstr(p[i].name, target) != NULL) {
            printf("\nFound: %s. Delete? (Y/N): ", p[i].name);
            char confirm; scanf(" %c", &confirm);
            while (getchar() != '\n');
            if (confirm == 'Y' || confirm == 'y') { foundIndex = i; break; }
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < n - 1; i++) p[i] = p[i + 1];
        printf("\nRecord removed.\n");
        return n - 1;
    }
    printf("\nRecord not found.\n");
    return n;
}
