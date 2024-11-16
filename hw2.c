#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 5



struct card
{
char shape;
char num[3];
};
int check_shape(struct card *mycard_p[]) {
    for (int i = 1; i < 5; i++) {
        if (mycard_p[0]->shape != mycard_p[i]->shape) {
            return 0; 
        }
    }
    return 1;
    
}
int numtonum(char num[]) {
    if (strcmp(num, "J") == 0) return 11;
    if (strcmp(num, "Q") == 0) return 12;
    if (strcmp(num, "K") == 0) return 13;
    if (strcmp(num, "A") == 0) return 14;
    return atoi(num);
}

void sort_with_num(struct card *mycard_p[]) {
    int num[size];
    for(int i=0;i<5;i++) {
        num[i] = numtonnum(mycard_p[i]->num);
    }
    for(int i=0;i<5;i++) {
        for(int j=i+1;j<5;j++) {
            if(num[i]>num[j]) {
                struct card *temp = mycard_p[i];
                mycard_p[i]=mycard_p[j];
                mycard_p[j]=temp;
                          
            }
        }
    }

}


void input_manual(struct card a[]) {
    for(int i=0;i<size;i++) {
        printf("%d번 카드 무늬와 숫자 : ",i+1);
        scanf("%c",&a[i].shape);
        getchar();
        char temp[3];
        scanf("%[^\n]", temp);
        getchar();
        strcpy(a[i].num,temp);
        printf("%c %s\n",a[i].shape,a[i].num);      
    } 

}
_Bool royal_straight_flush(struct card mycard[]) {
    //카드 5장 모두 무늬가 같으면서 10,J,Q,K,A 연달아
    int check_s = check_shape(&mycard);
    if (check_s==1) {
        
    }

    
    
}
_Bool flush(struct card mycard[]) {
    int check = check_shape(&mycard);
    if (check==1) return 1;
    else 0;
}

int main(void) {
    int menu;

    printf("1. 직접 입력 2. 랜덤 생성 3. 종료\n");
    printf("번호를 입력하세요: ");
    scanf("%d",&menu);
    getchar();
    struct card a[size];
    input_manual(a);


    return 0;
}