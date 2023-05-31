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
    char str[MAX] = "";
    char c;
    int size = 2;
    for (int i = 0; i < MAX; ++i) {
        c = getch();
        if (isalnum(c) || ispunct(c)) {
            str[i] = c;
            printf("*");
            size++;
        }
        else if (!isprint(c) && c != '\b') {
            break;
        }
        else if (c == '\b' && i != 0) {
            str[i - 1] = str[i];
            i -= 2;
            size--;
            printf("\r                            \rEnter Password: ");
            for (int j = 0; j < size - 2; j++) {
                printf("*");
            }
        }   
    }

    char pass[MAX] = "";
    puts("");
    for (int i = 0; i < strlen(str); i++) {
        if (isprint(str[i])) {
            pass[i] = str[i];
            printf("%c", pass[i]);
        }
    }

    printf("\nThe size of the password is: %d\n", strlen(pass));
    strengthCheck(pass);


}   