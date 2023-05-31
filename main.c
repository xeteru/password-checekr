#include <stdio.h>
#include <string.h>
#include <conio.h> 
#include <stdlib.h>
#include <ctype.h>

#define MAX 25

double rnd(char pass[]) {
    double avg = 0;
    int size = strlen(pass) - 1;
    int diff[size];
    for (int i = 0; i < strlen(pass); i++) {
        if (isgraph(pass[i]) && isprint(pass[i+1])) {
            diff[i] = (abs(pass[i] - pass[i + 1]));
        }
    }

    for (int i = 0; i < size; i++) {
        avg = avg + diff[i]; 
    }
   return avg = avg / size;
}

int strengthCheck(char pass[]) {
    int num = 0;
    int letter = 0;
    int special = 0;
    int str = 0;
    int upper = 0 ;
    int lower = 0;

    for (int i = 0; i < strlen(pass); i++) {
        if (isdigit(pass[i])) {
            num++;
        }
        else if (isalpha(pass[i])) {
            letter++;
            if (isupper(pass[i])) {
                upper++;
            }
            else {
                lower++;
            }
        }
        else if (ispunct(pass[i])) {
            special++;
        }
    }
    
    printf("%d numbers\n", num);
    printf("%d letters\n", letter);
    printf("%d upper\n", upper);
    printf("%d lower\n", lower);
    printf("%d special\n", special);
    printf("It has a variety of: %f\n", rnd(pass));

    if (strlen(pass) >= 12 && letter >= 2 && lower >= 1 && upper >= 1 && num >= 8 && special >= 2 && num >= 8 && rnd(pass) >= 15) {
        printf("Strong");
        return 4;
    }
    else if (strlen(pass) >= 10 && letter >= 2 && lower >= 1 && upper >= 1 && num >= 7 && special >= 1 && rnd(pass) >= 10) {
        printf("Good");
        return 3;
    }
    else if (strlen(pass) >= 8 && letter == 2 && rnd(pass) >= 1) {
        printf("Ok");
        return 2;
    }
    else {    
        printf("Weak");
        return 1;
    }
}

int main(void) {
    printf("//Create Your Account//\n\nEnter Username: ");

    char user[MAX];
    scanf("%s", user);

    printf("Enter Password: ");
    char c[MAX] = "";
    int size = 2;
    int backspace = 0;
    for (int i = 0; i < size; ++i) {
        c[i] = getch();
        if (isalnum(c[i]) || ispunct(c[i])) {
            size++;
            printf("*");
        }
        if (!isprint(c[i]) && c[i] != '\b') {
        }
        else if (c[i] == '\b') {
            backspace++;
            printf("\r               \rEnter Password: ");
            for (int i = 0; i < size - backspace - 2; i++) {
                printf("*");
            }
            i-=2;
        }
    }

    printf("%s\n", c);
    char pass[MAX] = "";
    for (int i = 0; i < strlen(c); i++) {
        if (isprint(c[i])) {
            pass[i] = c[i];
            printf("%c", pass[i]);
        }
    }

    printf("\nThe size of the password is: %d\n", strlen(pass));
    strengthCheck(pass);


}   