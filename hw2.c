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
            if (num[i]+1!=num[i+1]) {
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
    printf("===============================================================\n");

}

void deck(struct card all[]) { //한번만 실행
    char shapes[] = {'S', 'D', 'C', 'H'};
    char *nums[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int idx =0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<13;j++) {
            all[idx].shape=shapes[i];
            strcpy(all[idx].num, nums[j]);
            idx++;
        }
    }
}
void make_card(struct card all[], struct card mycard[]) {
    int check[5]={-1,-1,-1,-1,-1};
    for(int i=0;i<5;i++) {
        while (1) {
        check[i] = rand()%52;
        for(int j=0;j<i;j++) {
            if (check[i]==check[j]) break;
        }
        break;
        }
        mycard[i] = all[check[i]];
    }
    
}

int check_jokbo(_Bool(*type)(struct card[]), struct card mycard[]) {
    int a = type(mycard);
    if (a==1) return 1;
    else return 0;
    

}

void menu2() {
    clock_t start_clock, end_clock, diff_clock, ex_time;
    struct card all[52];
    deck(all);
    printf("1. royal_straight_flush\t2. back_straight_flush\n3. straight_flush\t4. four_card\n5. full_house\t6. flush\n7. mountain\t8. back_straight\n9. straight\t10. triple\n11. two_pair\t12. one_pair\n");
    printf("무슨 족보를 생성할까요? ");
    int select;
    scanf("%d",&select);

    struct card mycard[size];
    int count =1;
    int check=0;
    start_clock = clock();
    make_card(all,mycard);
    switch(select) {
        case 1: {
            check =check_jokbo(royal_straight_flush,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check=check_jokbo(royal_straight_flush,mycard);
                
            }
            end_clock = clock();
            break;
        }
        case 2:
        {
            check =check_jokbo(back_straight_flush,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check=check_jokbo(back_straight_flush,mycard);
                
            }
            end_clock = clock();
            break;
        }
        case 3:
        {
            check =check_jokbo(straight_flush ,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check=check_jokbo(straight_flush,mycard);
                
            }
            end_clock = clock();
            break;
        }
        case 4:
        {
            check =check_jokbo(four_card ,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check=check_jokbo(four_card,mycard);
                
            }
            end_clock = clock();
            break;
        }
        case 5:
        {
            check =check_jokbo(full_house  ,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check=check_jokbo(full_house ,mycard);
                
            }
            end_clock = clock();
            break;
        }
        case 6:
        {
            check =check_jokbo(flush ,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check=check_jokbo(flush,mycard);
                
            }
            end_clock = clock();
            break;
        }
        case 7:
        {
            check =check_jokbo(mountain  ,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check= check_jokbo(mountain ,mycard);
                
            }
            end_clock = clock();
            break;
        }
        case 8:
        {
            check =check_jokbo(back_straight,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check=check_jokbo(back_straight,mycard);
                
            }
            end_clock = clock();
            break;
        }
        case 9:
        {
            check =check_jokbo(straight ,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check=check_jokbo(straight ,mycard);
                
            }
            end_clock = clock();
            break;
        }
        case 10:
        {
            check =check_jokbo(triple ,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check =check_jokbo(triple,mycard);
                
            }
            end_clock = clock();
            break;
        }
        case 11:
        {
            check =check_jokbo(two_pair ,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check=check_jokbo(two_pair,mycard);
                
            }
            end_clock = clock();
            break;
        }
        case 12:
        {
            check =check_jokbo(one_pair ,mycard);
            while (check!=1) {
                make_card(all,mycard);
                count++;
                check=check_jokbo(one_pair,mycard);
                
            }
            end_clock = clock();
            break;
        }
    }
    printf("생성된 카드: ");
    for(int i=0;i<size;i++) {
        printf("%c %s",mycard[i].shape,mycard[i].num);
        if(i<4) printf(",");
    }
    diff_clock = end_clock - start_clock;
    ex_time = diff_clock / CLOCKS_PER_SEC;
    printf("\n컴퓨터로 %d번 족보를 생성하기 위한 카드 생성 시도 : %d번\n",select,count);
    printf("생성에 걸린 시간: %lu초\n",ex_time);
    printf("===============================================================\n");
     //카드 52장 생성 이후 menu2안에서 첫 카드 5장 생성하고 체크족보 함수 직접 호출. 호출하는 순간 시간 재기 

    
    
}


int main(void) {
    int menu;
    while(1) {
    printf("1. 직접 입력 2. 랜덤 생성 3. 종료\n");
    printf("\n번호를 입력하세요: ");
    scanf("%d",&menu);
    getchar();

    if (menu == 1) menu1();
    else if (menu==2) menu2();
    else if (menu == 3) {printf("종료\n"); break;}
    else printf("잘못 입력하셨습니다\n");

    }

    return 0;
}

