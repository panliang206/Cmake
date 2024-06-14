#include<time.h>
struct Product {
    char name[60];
    time_t expirationDate;
};

void park()
{ system("cls");
    for (int j = 1; j < 7 ; j++){ 
     switch(j){
        case 1: 
            printf("1.休闲零食\n");
            break;
        case 2:
            printf("2.饮料冲调\n");
            break;
        case 3:
            printf("3.鲜甜水果\n");
            break;
        case 4:
            printf("4.营养早餐\n");
            break;
        case 5:
            printf("5.牛奶面包\n");
            break;
        case 6:
            printf("6.速冻食品\n");
            break;}
    for (int i = 1; i < 11; i++) 
    {
    if(a[i][j].sign==0)
    {
        printf("\n");
        break;}
    
    struct Product sp;
    strcpy(sp.name,a[i][j].name);
    struct tm expirationDate = {0};
    expirationDate.tm_year = a[i][j].jz.year-1900;
    expirationDate.tm_mon = a[i][j].jz.month-1;
    expirationDate.tm_mday = a[i][j].jz.day;
    sp.expirationDate = mktime(&expirationDate); 

    time_t currentTime;
    time(&currentTime);

    if (difftime(sp.expirationDate, currentTime) > 0) {
        printf("%s 没有过期\n", sp.name);}
    else {
        printf("%s 已经过期\n", sp.name);}
    }
    }
    int j;
    printf("按0返回上一届面");
    printf("\n");
    scanf("%d",&j);
    control();
 }