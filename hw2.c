#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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



void make_random(struct card mycard[size]) {
    
    srand(time(NULL));
    for (int i =0;i<size;i++) {
        int s =rand()%4;
        switch (s) {
            case 0: mycard[i].shape = 'S'; break;
            case 1: mycard[i].shape = 'D'; break;
            case 2: mycard[i].shape = 'C'; break;
            case 3: mycard[i].shape = 'H'; break;
        }
        int ran_n = rand()%13 +2;
        if (ran_n == 2) strcpy(mycard[i].num,"2");
        else if(ran_n == 3) strcpy(mycard[i].num,"3");
        else if(ran_n == 4) strcpy(mycard[i].num,"4");
        else if(ran_n == 5) strcpy(mycard[i].num,"5");
        else if(ran_n == 6) strcpy(mycard[i].num,"6");
        else if(ran_n == 7) strcpy(mycard[i].num,"7");
        else if(ran_n == 8) strcpy(mycard[i].num,"8");
        else if(ran_n == 9) strcpy(mycard[i].num,"9");
        else if(ran_n ==10) strcpy(mycard[i].num,"10");
        else if(ran_n == 11) strcpy(mycard[i].num,"J");
        else if(ran_n == 12) strcpy(mycard[i].num,"Q");
        else if(ran_n == 13) strcpy(mycard[i].num,"K");
        else  strcpy(mycard[i].num,"A");
    //이후 구조체 포인터째로 전달

    
        
    }   
}

void check(int select) {
    clock_t start_clock, end_clock, diff_clock, ex_time;
    int count = 0;
    struct card mycard[5];
    make_random(mycard);
    start_clock = clock();
    switch (select)
    {
    case 1: {while (1){
        int a = royal_straight_flush(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    case 2: {while (1){
        int a = back_straight_flush(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    case 3: {while (1){
        int a = straight_flush(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    case 4: {while (1){
        int a = four_card(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    case 5: {while (1){
        int a = full_house(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    case 6: {while (1){
        int a = flush(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    case 7: {while (1){
        int a = mountain(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    case 8: {while (1){
        int a = back_straight(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    case 9: {while (1){
        int a = straight(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    case 10: {while (1){
        int a = triple(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    case 11: {while (1){
        int a = two_pair(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    case 12: {while (1){
        int a = one_pair(mycard);
        if (a==0) {make_random(mycard); count++;}
        else {end_clock = clock();break;}
    }
    break;
    }
    }

    printf("생성된 카드: ");
    for(int i = 0; i < 5; i++) {
        printf("%c %s", mycard[i].shape, mycard[i].num);
        if (i < 4) printf(", "); 
}
    printf("\n");
    printf("컴퓨터로 1번 족보를 생성하기 위한 카드 생성 시도 : %d번\n",count);
    diff_clock = end_clock - start_clock;
    ex_time = diff_clock / CLOCKS_PER_SEC;
    printf("생성에 걸린 시간 %lu초", ex_time);
}

void menu2() {
    printf("1. royal_straight_flush\t2. back_straight_flush\n3. straight_flush\t4. four_card\n5. full_house\t6. flush\n7. mountain\t8. back_straight\n9. straight\t10. triple\n11. two_pair\t12. one_pair\n");
    printf("무슨 족보를 생성할까요? ");
    int select;
    scanf("%d",&select);
    check(select);
    
}


int main(void) {
    int menu;
    while(1) {
    printf("1. 직접 입력 2. 랜덤 생성 3. 종료\n");
    printf("번호를 입력하세요: ");
    scanf("%d",&menu);
    getchar();

    if (menu == 1) menu1();
    else if (menu==2) menu2();
    else if (menu == 3) {printf("종료\n"); break;}
    else printf("잘못 입력하셨습니다\n");

    }

    return 0;
}

