#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 5
struct card
{
char shape;
char num[3];
};

void input_manual(struct card a[]) {
    for(int i=0;i<size;i++) {
        printf("%d번 카드 무늬와 숫자 : ",i+1);
        scanf("%c",&a[i].shape);
        char temp[3];
        scanf("%[^\n]", temp);
        getchar();
        strcpy(a[i].num,temp);
        printf("%c %s\n",a[i].shape,a[i].num);      
    } 

}
_Bool royal_straight_flush(struct card mycard[]) {
    //카드 5장 모두 무늬가 같으면서 10,J,Q,K,A 연달아
}

int main(void) {
    int menu;

    printf("1. 직접 입력 2. 랜덤 생성 3. 종료\n");
    printf("번호를 입력하세요: ");
    scanf("%d",&menu);
    struct card a[size];
    input_manual(a);


    return 0;
}