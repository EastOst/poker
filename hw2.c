#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 5



struct card
{
char shape;
char num[3];
};
int check_shape(struct card *mycard_p) {
    for (int i = 1; i < 5; i++) {
        if (mycard_p->shape != (mycard_p+i)->shape) {
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

void make_int_arr(int num[],struct card *mycard_p) {
    for(int i=0;i<5;i++) {
        num[i] = numtonum((mycard_p+i)->num);
    }
}



void sort(int num[], struct card *mycard_p) {
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (num[i] > num[j]) {
                
                int temp_i = num[i];
                num[i] = num[j];
                num[j] = temp_i;
                struct card temp_card = *(mycard_p + i);
                *(mycard_p + i) = *(mycard_p + j);
                *(mycard_p + j) = temp_card;
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
    } 

}
_Bool royal_straight_flush(struct card mycard[]) {
    //카드 5장 모두 무늬가 같으면서 10,J,Q,K,A 연달아
    int check_s = check_shape(mycard);
    int count =0;
    if (check_s==1) {
        int num[size];
        make_int_arr(num,mycard);
        sort(num,mycard);
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
        make_int_arr(num,mycard);
        sort(num,mycard);
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
        make_int_arr(num,mycard);
        sort(num,mycard);
        for(int i = 0;i<size-1;i++) {
            if (num[i]+1!=num[i+1]+1) {
                a=0; break;
            }
        }
        if (a==1) return 1;
        else return 0;

    }
    return 0;
}
_Bool four_card(struct card mycard[]) {
    int num[size];
    make_int_arr(num, mycard);
    for(int i=0;i<size;i++) {
        int c=0;
        for(int j=0;j<size;j++) {
            if(num[i]==num[j]) c++;
        }
        if(c==4) return 1;
    }
    return 0;

}
_Bool full_house(struct card mycard[]) {
    int num[size];
    make_int_arr(num,mycard);
    sort(num, mycard);
    if ((num[0] == num[1] && num[1] == num[2] && num[3] == num[4]) || 
        (num[0] == num[1] && num[2] == num[3] && num[3] == num[4])) {
        return 1;
    }
    return 0;
}

_Bool flush(struct card mycard[]) {
    int check = check_shape(mycard);
    if (check==1) return 1;
    else return 0;
} //완성

_Bool mountain(struct card mycard[]) {
    int check_s = check_shape(mycard);
    int count =0;
    if (check_s==0) {
        int num[size];
        make_int_arr(num,mycard);
        sort(num,mycard);
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
_Bool back_straight(struct card mycard[]) {
    int check_s = check_shape(mycard);
    int count =0;
    if (check_s==0) {
        int num[size];
        make_int_arr(num,mycard);
        sort(num,mycard);
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

_Bool straight(struct card mycard[]) {
    int check_s = check_shape(mycard);
    int a=1;
    if (check_s==0) {
        int num[size];
        make_int_arr(num,mycard);
        sort(num,mycard);
        for(int i = 0;i<size-1;i++) {
            if (num[i]+1!=num[i+1]) {
                a=0; break;
            }
        }
        if (a==1) return 1;
        else return 0;

    }
    return 0;
}
_Bool triple(struct card mycard[]) {
    int num[size];
    make_int_arr(num, mycard);
    sort(num, mycard);
    for (int i = 0; i < size - 2; i++) {
        if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
            return 1;  
        }
    }

    return 0;  
}
_Bool two_pair(struct card mycard[]) {
    int c =0;
    int num[size];
    make_int_arr(num,mycard);
    sort(num, mycard);
    for(int i=0;i<size-1;i++) {
        if(num[i]==num[i+1]) {i++;c++;}
    }
    if(c==2) return 1;
    else return 0;
}
_Bool one_pair(struct card mycard[]) {
    int c =0;
    int num[size];
    make_int_arr(num,mycard);
    sort(num, mycard);
    for(int i=0;i<size-1;i++) {
        if(num[i]==num[i+1]) {i++;c++;}
    }
    if(c==1) return 1;
    else return 0;
}

void menu1() {
    struct card mycard[size];
    input_manual(mycard);
    if (royal_straight_flush(mycard)) printf("로얄 스트레이트 플러쉬\n");
    else if(back_straight_flush(mycard)) printf("백 스트레이트 플러쉬\n");
    else if (straight_flush(mycard)) printf("스트레이트 플러쉬\n");
    else if(four_card(mycard)) printf("포 카드\n");
    else if(full_house(mycard)) printf("풀 하우스\n");
    else if (flush(mycard)) printf("플러쉬\n");
    else if (mountain(mycard)) printf("마운틴\n");
    else if (back_straight(mycard)) printf("백 스트레이트\n");
    else if (straight(mycard)) printf("스트레이트\n");
    else if (triple(mycard)) printf("트리플\n");
    else if (two_pair(mycard)) printf("투 페어\n");
    else if (one_pair(mycard)) printf("원 페어\n");
    else printf("노 페어");

}


int main(void) {
    int menu;
    while(1) {
    printf("1. 직접 입력 2. 랜덤 생성 3. 종료\n");
    printf("번호를 입력하세요: ");
    scanf("%d",&menu);
    getchar();

    if (menu == 1) menu1();
    else if (menu == 3) {printf("종료\n"); break;}
    else printf("잘못 입력하셨습니다\n");

    }

    return 0;
}