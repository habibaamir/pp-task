#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define USERNAME_LENGTH 19
#define PASSWORD_LENGTH 20

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    bool active;
} Account;

void register_account() {
    Account account;
    printf("Enter a username: ");
    scanf("%s", account.username);

    printf("Enter a password: ");
    scanf("%s", account.password);

    char active_flag[6];
    bool valid_flag = false;

    while (!valid_flag) {
        printf("Set the active flag (1 or true to activate, 0 or false to deactivate): ");
        scanf("%s", active_flag);

        for (int i = 0; i < strlen(active_flag); i++) {
            active_flag[i] = tolower(active_flag[i]);
        }

        if (strcmp(active_flag, "1") == 0 || strcmp(active_flag, "true") == 0) {
            account.active = true;
            valid_flag = true;
        } else if (strcmp(active_flag, "0") == 0 || strcmp(active_flag, "false") == 0) {
            account.active = false;
            valid_flag = true;
        } else {
            printf("Invalid active flag. Please enter 1, 0, true, or false.\n");
        }
    }

    printf("Now you have an account on my program :) . Please enter your username and password.\n");

    char input_username[USERNAME_LENGTH];
    char input_password[PASSWORD_LENGTH];

    while (1) {
        printf("Username: ");
        scanf("%s", input_username);

        printf("Password: ");
        scanf("%s", input_password);

        if (strcmp(input_username, account.username) == 0 && strcmp(input_password, account.password) == 0) {
            if (account.active) {
                printf("Welcome to my program!\n");

                char sign_out_choice[4];
                printf("Do you want to sign out? (yes/no): ");
                scanf("%s", sign_out_choice);

                if (strcmp(sign_out_choice, "yes") == 0) {
                    printf("Signed out successfully.\n");
                    break;
                }
            } else {
                printf("Your account is inactive. You cannot access the program.\n");
            }
        } else {
            printf("Wrong username or password. Please try again.\n");
        }
    }
}

int main() {
    char response[4];
    printf("to create an account on my program +_+type 'yes'. Otherwise, type 'no' ");
    scanf("%s", response);

    if (strcmp(response, "yes") == 0) {
        register_account();
    } else {
        printf("Welcome back!\n");

        char login_choice[4];
        printf("Do you have an account? (yes/no): ");
        scanf("%s", login_choice);

        if (strcmp(login_choice, "yes") == 0) {
            register_account();
        } else {
            printf("Thank you for using my program .\n");
        }
    }

    return 0;
}
