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

void make_int_arr(int num[],struct card *mycard_p[]) {
    for(int i=0;i<5;i++) {
        num[i] = numtonnum(mycard_p[i]->num);
    }
}



void sort(int num[],struct card *mycard_p[]) {
    

    for(int i=0;i<5;i++) {
        for(int j=i+1;j<5;j++) {
            if(num[i]>num[j]) {
                struct card *temp = mycard_p[i];
                int temp_i = num[i];
                mycard_p[i]=mycard_p[j];
                num[i] = num[j];
                mycard_p[j]=temp;
                num[j] = temp_i;

                          
            }
        }
    }

}

int find_something(int num[],int target) {
    for(int i = 0;i<size;i++) {
        if (num[i]==target) {
            return 1;
        }
    }
    return 0;
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
    int check_s = check_shape(mycard);
    int count =0;
    if (check_s==1) {
        int num[size];
        make_int_arr(&mycard, num);
        sort(num,&mycard);
        count+=find_something(num,10);
        count+=find_something(num,11);
        count+=find_something(num,12);
        count+=find_something(num,13);
        count+=find_something(num,14);
        if(count == 5) return 1;
        return 0;
    }

    return 0;
    

}

_Bool back_straight_flush(struct card mycard[]) {
    int check_s = check_shape(mycard);
    int count =0;
    if (check_s==1) {
        int num[size];
        make_int_arr(&mycard, num);
        sort(num,&mycard);
        count+=find_something(num,2);
        count+=find_something(num,3);
        count+=find_something(num,4);
        count+=find_something(num,5);
        count+=find_something(num,14);
        if(count == 5) return 1;
        return 0;
    }

    return 0;
}
_Bool straight_flush(struct card mycard[]) {
    int check_s = check_shape(mycard);
    int a=1;
    if (check_s==1) {
        int num[size];
        make_int_arr(mycard, num);
        sort(num,mycard);
        for(int i = 0;i<size-1;i++) {
            if (++num[i]!=num[i+1]) {
                a=0; break;
            }
        }
        if (a==1) return 1;
        else return 0;

    }
}
_Bool four_card(struct card mycard[]) {
    int num[size];
    make_int_arr(mycard, num);
    for(int i=0;i<size;i++) {
        int c=0;
        for(int j=0;j<size;j++) {
            if(num[i]==num[j]) c++;
        }
        if(c==4) return 1;
    }
    return 0;

}


_Bool flush(struct card mycard[]) {
    int check = check_shape(mycard);
    if (check==1) return 1;
    else 0;
} //완성

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