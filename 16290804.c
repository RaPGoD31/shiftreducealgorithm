#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[50], action[50];
int top=0, alt=0;
struct stack {
    char value[3];
    int a;
    struct stack *next;
    struct stack *back;
};
void check(struct stack *head, char *input);
struct stack * push(struct stack * head, char* value, int a){
    struct stack * new;
    new = (struct stack*) malloc(sizeof(struct stack));
    new->a = a;
    strcpy(new->value ,value);
    if(head == NULL){
        new->next = NULL;
        new->back = NULL;
        head = new;
    }
    else{
        new->next = head;
        head->back = new;
        head = new;
    }
    return head;
}

void display(struct stack* head){
    struct stack *temp = head;
    struct stack *temp2 = head;

    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    while(temp2!=NULL){
        printf("%s%d ",temp2->value,temp2->a);
        temp2=temp2->back;
    }
}

struct stack * pop(struct stack *head){
    struct stack * ptr;
    ptr = head;
    if(head==NULL){
        printf("ERROR");
    }
    else{
        head = head->next;
        head->back = NULL;
        free(ptr);
    }
    return head;
}

int main(){
    scanf("%s",input);
    printf("\nSTACK \t\t\t\t INPUT \t\t\t\t ACTION \n");
    printf("----------------------------------------------------------------------------\n");
    struct stack* head = (struct stack*) malloc(sizeof(struct stack));
    head->a = 0;
    strcpy(head->value," ");
    head->next = NULL;
    int c = strlen(input);
    input[c] ='$';
    check(head,input);

}

void check(struct stack* head,char* input){
    while(strcmp(input,"")!=0){
        if(head->a == 0){
            display(head);
            if(input[top] == 'i' && input[top+1] == 'd'){
                strcpy(action,"s5");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"id", 5);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+2];
                }
                continue;
            }
            else if(input[top] == '('){
                strcpy(action,"s4");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"(", 4);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+1];
                }
                continue;
            }
            else {
                printf("\t\t\t\t %s \n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
        else if(head->a == 1){
            display(head);
            if(input[top]=='+'){
                strcpy(action,"s6");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"+", 6);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+1];
                }
                continue;
            }
            else if(input[top] == '$'){
                strcpy(action,"ACCEPTED");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                break;
            }
            else {
                printf("\t\t\t\t %s\n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
        else if(head->a == 2){
            display(head);
            if(input[top]=='+' || input[top]==')' || input[top]=='$'){
                head = pop(head);
                if(head->a == 0){
                    strcpy(action, "r2 GOTO[0,E]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"E", 1);
                    continue;
                }
                else if(head->a == 1){
                    strcpy(action, "r2 GOTO[1,E]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"E", 1);
                    continue;
                }
                else if(head->a == 4){
                    strcpy(action, "r2 GOTO[4,E]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"E", 8);
                    continue;
                }
                else {
                    printf("\t\t\t\t %s\n",input);
                    printf("INVALID SYNTAX\n");
                    break;
                }
            }
            else if(input[top] == '*'){
                strcpy(action,"s7");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"*", 7);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+1];
                }
                continue;
            }
            else {
                printf("\t\t\t\t %s\n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
        else if(head->a == 3){
            display(head);
            if(input[top]=='+' || input[top]==')' || input[top]=='$' || input[top] == '*'){
                head = pop(head);
                if(head->a == 0){
                    strcpy(action, "r4 GOTO[0,T]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"T", 2);
                    continue;
                }
                else if(head->a == 4){
                    strcpy(action, "r4 GOTO[4,T]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"T", 2);
                    continue;
                }
                else if(head->a == 6){
                    strcpy(action, "r4 GOTO[6,T]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"T", 9);
                    continue;
                }
                else {
                    printf("\t\t\t\t %s\n",input);
                    printf("INVALID SYNTAX\n");
                    break;
                }
            }
            else {
                printf("\t\t\t\t %s\n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
        else if(head->a == 4){
            display(head);
            if(input[top] == 'i' && input[top+1] == 'd'){
                strcpy(action,"s5");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"id", 5);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+2];
                }
                continue;
            }
            else if(input[top] == '('){
                strcpy(action,"s4");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"(", 4);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+1];
                }
                continue;
            }
            else {
                printf("\t\t\t\t %s\n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
        else if(head->a == 5){
            display(head);
            if(input[top]=='+' || input[top]==')' || input[top]=='$' || input[top] == '*'){
                head = pop(head);
                if(head->a == 0){
                    strcpy(action, "r6 GOTO[0,F]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"F", 3);
                    continue;
                }
                else if(head->a == 4){
                    strcpy(action, "r6 GOTO[4,F]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"F", 3);
                    continue;
                }
                else if(head->a == 6){
                    strcpy(action, "r6 GOTO[6,F]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"F", 3);
                    continue;
                }
                else if(head->a == 7){
                    strcpy(action, "r6 GOTO[7,F]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"F", 10);
                    continue;
                }
                else {
                    printf("\t\t\t\t%s\n",input);
                    printf("INVALID SYNTAX\n");
                    break;
                }
            }
            else {
                printf("\t\t\t\t%s\n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
        else if(head->a == 6){
            display(head);
            if(input[top] == 'i' && input[top+1] == 'd'){
                strcpy(action,"s5");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"id", 5);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+2];
                }
                continue;
            }
            else if(input[top] == '('){
                strcpy(action,"s4");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"(", 4);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+1];
                }
                continue;
            }
            else {
                printf("\t\t\t\t %s\n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
        else if(head->a == 7){
            display(head);
            if(input[top] == 'i' && input[top+1] == 'd'){
                strcpy(action,"s5");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"id", 5);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+2];
                }
                continue;
            }
            else if(input[top] == '('){
                strcpy(action,"s4");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"(", 4);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+1];
                }
                continue;
            }
            else {
                printf("\t\t\t\t %s\n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
        else if(head->a==8){
            display(head);
            if(input[top]=='+'){
                strcpy(action,"s6");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"+", 6);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+1];
                }
                continue;
            }
            else if(input[top] == ')'){
                strcpy(action,"s11");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,")", 11);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+1];
                }
                continue;
            }
            else {
                printf("\t\t\t\t %s\n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
        else if(head->a==9){
            display(head);
            if(input[top] == '*'){
                strcpy(action,"s7");
                printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                head = push(head,"*", 7);
                int k = strlen(input);
                for(int j = 0; j<k; j++){
                    input[j] = input[j+1];
                }
                continue;
            }
            else if(input[top] == '+' || input[top] == ')' || input[top] == '$'){
                head = pop(head);
                head = pop(head);
                head = pop(head);
                if(head->a == 0){
                    strcpy(action, "r1 GOTO[0,E]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"E", 1);
                    continue;
                }
                else if(head->a == 1){
                    strcpy(action, "r1 GOTO[1,E]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"E", 1);
                    continue;
                }
                else if(head->a == 4){
                    strcpy(action, "r1 GOTO[4,E]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"E", 8);
                    continue;
                }
                else {
                    printf("\t\t\t\t %s\n",input);
                    printf("INVALID SYNTAX\n");
                    break;
                }
            }
            else {
                printf("\t\t\t\t %s\n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
        else if(head->a == 10){
            display(head);
            if(input[top]=='+' || input[top]==')' || input[top]=='$' || input[top] == '*'){
                head = pop(head);
                head = pop(head);
                head = pop(head);
                if(head->a == 0){
                    strcpy(action, "r3 GOTO[0,T]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"T", 2);
                    continue;
                }
                else if(head->a == 4){
                    strcpy(action, "r3 GOTO[4,T]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"T", 2);
                    continue;
                }
                else if(head->a == 6){
                    strcpy(action, "r3 GOTO[6,T]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"T", 9);
                    continue;
                }
                else {
                    printf("\t\t\t\t %s\n",input);
                    printf("INVALID SYNTAX\n");
                    break;
                }
            }
            else {
                printf("\t\t\t\t %s\n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
        else if(head->a == 11){
            display(head);
            if(input[top]=='+' || input[top]==')' || input[top]=='$' || input[top] == '*'){
                head = pop(head);
                head = pop(head);
                head = pop(head);
                if(head->a == 0){
                    strcpy(action, "r5 GOTO[0,F]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"F", 3);
                    continue;
                }
                else if(head->a == 4){
                    strcpy(action, "r5 GOTO[4,F]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"F", 3);
                    continue;
                }
                else if(head->a == 6){
                    strcpy(action, "r5 GOTO[6,F]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"F", 3);
                    continue;
                }
                else if(head->a == 7){
                    strcpy(action, "r5 GOTO[7,F]");
                    printf("\t\t\t\t %s \t\t\t\t %s\n",input,action);
                    head = push(head,"F", 10);
                    continue;
                }
                else {
                    printf("\t\t\t\t %s\n",input);
                    printf("INVALID SYNTAX\n");
                    break;
                }
            }
            else {
                printf("\t\t\t\t %s\n",input);
                printf("INVALID SYNTAX\n");
                break;
            }
        }
    }
}