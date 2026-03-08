#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Loginname[64];
    char password[64];
} account;

typedef struct {
    char stdID[16];
    char nameSurname[25];
    account stdACC;   
} hoststd;

int main() {
    hoststd cs[5] = {
        {"66-040626-2686-9","MR.A",{"user1","passwd1"}},
        {"66-040626-2686-8","MR.B",{"user2","passwd2"}},
        {"66-040626-2686-7","MR.C",{"user3","passwd3"}},
        {"66-040626-2686-6","MR.D",{"user4","passwd4"}},
        {"66-040626-2686-5","MR.E",{"user5","passwd5"}}
    };

    char inputLogin[64], inputPass[64];
    int i, found = 0;

    printf("Enter Loginname: ");
    scanf("%s", inputLogin);
    printf("Enter Password: ");
    scanf("%s", inputPass);

    for(i = 0; i < 5; i++) {
        if(strcmp(inputLogin, cs[i].stdACC.Loginname) == 0 &&
           strcmp(inputPass, cs[i].stdACC.password) == 0) {
            printf("Welcome %s (%s)\n", cs[i].nameSurname, cs[i].stdID);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Incorrect login or password\n");
    }

    return 0;
}
