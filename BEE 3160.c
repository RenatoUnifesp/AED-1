#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 100
#define MAX_NAME_LENGTH 20

int main() {
    char luiggyFriendText[MAX_TEXT_LENGTH];
    char newFriendText[MAX_TEXT_LENGTH];
    char input_name[MAX_NAME_LENGTH];
    char *luigyFriendList[10];
    char *newFriendList[10];
    int num_luigyFriendList = 0;
    int num_newFriendList = 0;
    int index;

    scanf("%[^\n]", luiggyFriendText);
    scanf("%[^\n]", newFriendText);

    char *token = strtok(luiggyFriendText, " ");
    while (token != NULL) {
        luigyFriendList[num_luigyFriendList++] = token;
        token = strtok(NULL, " ");
    }

    index = num_luigyFriendList;

    token = strtok(newFriendText, " ");
    while (token != NULL) {
        newFriendList[num_newFriendList++] = token;
        token = strtok(NULL, " ");
    }

    scanf("%s", input_name);

    if (input_name == "nao") {
        printf("%s%s\n", luiggyFriendText, newFriendText);
    } else {
        for (int i = 0; i < num_luigyFriendList; i++) {
            if (strcmp(input_name, luigyFriendList[i]) == 0) {
                index = i;
                break;
            }
        }

        int j = 0;
        int k = 0;
        char *result[num_luigyFriendList + num_newFriendList];
        
        for (int i = 0; i < num_luigyFriendList + num_newFriendList; i++) {
            if(i < index || i >= index + num_newFriendList){
                result[i] = luigyFriendList[j++];
            }else{
                result[i] = newFriendList[k++];
            }
        }
        
        for(int i = 0; i < num_luigyFriendList + num_newFriendList; i++){
            printf("%s ", result[i]);
        }
    }

    return 0;
}
