#include <stdio.h>
#include<string.h>
struct details{
    char name[20];
    char number[20];
    char email[20];
};
void print(struct details *det,int s){
    for(int i=0;i<s;i++){
        printf("name : %s\nnumber : %s\nemail Id : %s\n",det[i].name,det[i].number,det[i].email);
    }
}
void Add(struct details *det,int *s){
    printf("Enter name:");
    scanf("%s",det[*s].name);
    printf("Enter number:");
    scanf(" %s",det[*s].number);
    printf("Enter email:");
    scanf(" %s",det[*s].email);
    *s=*s+1;
}
void search(struct details *det,int s){
    printf("Enter a name:");
    char n[20];
    scanf("%s",n);
    for(int i=0;i<s;i++){
        /*if(strcmp(det[s].name,n)){
        printf("Not fount, Try again!\n");
    }
    else{
        printf("Name found\n");
        printf("name : %s\nnumber : %s\nemail Id : %s\n",det[s].name,det[s].number,det[s].email);
    }*/
    if(strcmp(det[i].name,n) && i==s-1){
        printf("Not fount, Try again!\n");
    }
    else{
        printf("Name found\n");
        printf("name : %s\nnumber : %s\nemail Id : %s\n",det[i].name,det[i].number,det[i].email);
        break;
    }
    }
}
void Edit(struct details *det,int s){
    printf("Enter a name:");
    char n[20];
    scanf("%s",n);
    for(int i=0;i<s;i++){
    if(strcmp(det[s].name,n) && i==s-1){
        printf("Not fount, Try again!\n");
    }
    else{
        printf("what do you want to edit\n1. name\n2. number\n3. email\n");
        int i;
        scanf("%d",&i);
        switch(i){
            case 1:
                scanf("%s",det[s-1].name);
                printf("name : %s\nnumber : %s\nemail Id : %s\n",det[s-1].name,det[s-1].number,det[s-1].email);
                break;
            case 2:
                scanf("%s",det[s-1].number);
                printf("name : %s\nnumber : %s\nemail Id : %s\n",det[s-1].name,det[s-1].number,det[s-1].email);
                break;
            case 3:
                scanf("%s",det[s].email);
                printf("name : %s\nnumber : %s\nemail Id : %s\n",det[s-1].name,det[s-1].number,det[s-1].email);
                break;
        }
    }
    }
}

int main() {
    struct details det[100];
    static int s=0;
    int i;
    while(1){
    printf("1. Add details\n2. search details\n3. Edit details\n4. print details\n5. Exit\n");
    printf("select option:");
    scanf("%d",&i);
    
    switch(i){
        case 1:
             Add(det,&s);
            printf("Details add sucessfully\n");
            break;
        case 2:
             search(det,s);
            break;
        case 3:
             Edit(det,s);
            break;
        case 4:
             print(det,s);
            break;
        case 5:
            return 0;
    }
}
    return 0;
}