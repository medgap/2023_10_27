#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct String{
    char* data;
    int len;
}String;

String* initString(){
    String* s = (String*)malloc(sizeof(String));
    s->data = NULL;
    s->len = 0;
    return s;
}

void StringAssign(String* s,char* data){
    if(s->data){
        free(s->data);
    }
    else{
        int len = 0;
        char* temp = data;
        while(*temp){
            len++;
            temp++;
        }
        if(len){
            temp = data;
            s->len = len;
            s->data = (char*)malloc(sizeof(char)*(len+1));
            for(int i = 0; i < len; i++,temp++){
                s->data[i] = *temp;
            }
        }
        else{
            s->data = NULL;
            s->len = 0;
        }
    }
}

void forceMatch(String* s1,String* s2){
    int i = 0;
    int j = 0;
    while(j < s2->len && i < s1->len){
        if(s1->data[i] == s2->data[j]){
            i++;
            j++;
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == s2->len){
        printf("force match success.\n");
    }
    else{
        printf("force match fail.\n");
    }
}

void PrintString(String* s){
    for(int i = 0; i < s->len; i++){
        printf(i==0 ? "%c" : "->%c",s->data[i]);
    }
    printf("\n");
}

int main(){
    String* s1 = initString();
    String* s2 = initString();
    StringAssign(s1,"ABABC");
    PrintString(s1);
    StringAssign(s2,"ABC");
    PrintString(s2);
    forceMatch(s1,s2);
    return 0;
}