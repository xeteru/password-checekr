#include <stdio.h>
#include <string.h>
#include <conio.h> 
#include <stdlib.h>
#include <ctype.h>

#define MAX 25

enum strength{Weak, Ok, Good, Strong};

double rnd(char pass[]) {
    double avg = 0;
    int size = strlen(pass) - 1;
    int diff[size];
    for (int i = 0; i < strlen(pass); i++) {
        if (isprint(pass[i]) && isprint(pass[i+1])) {
            diff[i] = (abs(pass[i] - pass[i + 1]));
            printf("%d\n", diff[i]);
        }
    }

    for (int i = 0; i < size; i++) {
        avg = avg + diff[i];
    }
    
   return avg = avg / size;
}

int strengthCheck(char pass[]) {
    int num;
    int letter;
    int special;
    int str;

    for (int i = 0; i < strlen(pass); i++) {
        if (isdigit(pass[i])) {
            num++;
        }
        else if (isalpha(pass[i])) {
            letter++;
        }
        else if (ispunct(pass[i])) {
            special++;
        }
    }

    if (strlen(pass) < 8 || letter == 0 && special == 0 || num == strlen(pass) || rnd(pass) <= 3) {
        str = 1;
    }
    else if (strlen(pass) >= 8 || num == 0 || letter == 0 || special == 0) {
        str = 2;
    }
}

int main(void) {
    // printf("Create Your Account\n\nEnter Username: ");
    // char user[MAX] = "test";
    // fgets(user, MAX, stdin);

    // enum strength str;
    // do {
    //     printf("Enter Password: ");
    //     char pass1[MAX] = "";
    //     fgets(pass1, MAX, stdin);

    //     printf("Confirm Password")
    // } while (str == Weak && );
    
    printf("%f", rnd("aaaaaaa\n"));
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
            printf("\nbreak\n");
            break;
        }
        else if (c[i] == '\b') {
            backspace++;
            printf("\r               \r");
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

    printf("\n%d", strlen(pass));

}   