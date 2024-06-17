#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"login.h"
#include"create_data.h"
#include"search_data.h"
#include"tools.h"
#include"gq.h"
#include<time.h>
#define FILENAME "data.txt"



void  Choice(void){
    printf("1:继续\n0:退出\n");
    int Pick;
    scanf("%d",&Pick);
    if(Pick!=0 && Pick!=1){
        printf("ERROR!!!\nTRY AGAIN!!!\n");
        Choice();
    }
    if(Pick)
        add();
       
    control();
}

void add(){
    system("cls");
    printf("请选择货物的种类:\n1.休闲零食\n2.饮料冲调\n3.鲜甜水果\n4.营养早餐\n5.牛奶面包\n6.速冻食品\n");
    int choice;
    scanf("%d",&choice);

    if (choice < 1 || choice > 6) {
        printf("输入的货物种类不合法。\n");
        return;
    }

    struct shangpin *p = NULL;
    int i = 1;
    while (i < 11 && a[i][choice].sign != 0) {
        i++;
    }

    if (i < 11) {
        p = &a[i][choice];
    } else {
        printf("该种类货物已满，请选择是否添加其它种类。\n");
        printf("按0返回上一届面,按1表示选择其它种类\n");

        int c;
        scanf("%d",&c);
        if(c)
        add();

        control();
    }

    getchar();

    printf("请输入你要添加商品的名称:\n");
    char s[60];
    gets(s);
    
    int flag=0;
    for(int i=1;i<11;i++){
        if(a[i][choice].sign){
            if(strcmp(a[i][choice].name,s)==0){
                p=&a[i][choice];
                printf("已存在该商品，请直接输入添加的数量:\n");
                int t;
                scanf("%d",&t);
                p->number+=t;
                flag=1;
                break;
            }
        }
    }

    if(flag){
        printf("数量添加完成，按任意键返回主菜单。\n");
        getchar();
        control();
    }

    

    strcpy(p->name,s);
    printf("请输入商品的价格和数量:\n");
    scanf("%f",&p->price);
    scanf("%d",&p->number);

    printf("请输入生产日期:\n");
    scanf("%d %d %d",&p->sc.year,&p->sc.month,&p->sc.day);
    
    printf("请输入过期日期:\n");
    scanf("%d %d %d",&p->jz.year,&p->jz.month,&p->jz.day);


    printf("%d %d %d",p->sc.year,p->sc.month,p->sc.day);    
    if(p->sc.year <= p->jz.year ){
        if( p->sc.month <= p->jz.month){
            if( p->sc.day < p->jz.day){
                p->sign=1;}
        } 
    }else {
        printf("日期格式错误！！！\n");
        printf("是否要继续操作?\n");
        Choice();
    }
            

    printf("添加完成，是否要继续添加还是退出？\n");
    Choice();
    

}



void sort(int x,int y){
    for ( x; x < 11; x++ ) {
        
            if (a[x+1][y].sign) {
                // 交换相邻元素
                struct shangpin temp = a[x+1][y];
                a[x+1][y] = a[x][y];
                a[x][y] = temp;
            }

    }
}


void del(){
    system("cls");
    printf("请输入你要删除的商品种类:\n");
    printf("1.休闲零食\n2.饮料冲调\n3.鲜甜水果\n4.营养早餐\n5.牛奶面包\n6.速冻食品\n");
    
    int y;
    scanf("%d",&y);

    if (y < 1 || y > 6) {
        printf("输入的货物种类不合法。\n");
        del();
    }
    

    for(int i=1;i<11;i++){

        int cnt=0;
    
        if(a[i][y].sign){ 
            cnt++;
            printf("\n");
            printf("%d.",i);
            puts(a[i][y].name);
            printf("\n");

            if(!cnt){
                printf("\n");
                printf("该种类商品无更多,请选择其它种类。\n");
                del();

            }
        }

    }
    printf("\n");
    printf("请选择你要删除的商品:\n");
    int x;
    scanf("%d",&x);

    if (x < 1 || x >= 10 || !a[x][y].sign) {
        printf("输入的商品序号不合法。\n");
        control();
    }

    
    strcpy(a[x][y].name, "");
    a[x][y].price=0.0;
    a[x][y].number=0;
    a[x][y].sc.year=a[x][y].sc.month=a[x][y].sc.day=0;
    a[x][y].jz.year=a[x][y].jz.month=a[x][y].jz.day=0;
    a[x][y].sign=0;

    sort(x,y);
    printf("删除成功!\n");
    control();




}

void abc(){
    system("cls");
    printf("请输入你要打折的商品种类:\n");
    printf("1.休闲零食\n2.饮料冲调\n3.鲜甜水果\n4.营养早餐\n5.牛奶面包\n6.速冻食品\n");

    int q;
    scanf("%d",&q);

    if (q < 1 || q > 6) {
        
        abc();
    }

    for(int i=1;i<11;i++){

        int cnt=0;
    
        if(a[i][q].sign){
            cnt++;
            printf("\n");
            printf("%d.",i);
            puts(a[i][q].name);
            printf("\n");
            printf("%.2f元",a[i][q].price);
            printf("\n");

            if(!cnt){
                printf("\n");
                printf("该种类商品无更多,请选择其它种类。\n");
                abc();

            }
        }

    }

    int s,j;
    float p; 
    printf("\n");
    printf("请选择你要打折的商品:\n");
    scanf("%d",&s);
    printf("请输入你要打几折:\n");
    scanf("%f",&p);

    a[s][q].price=a[s][q].price*p;
    printf("输入0返回菜单，输入1继续打折\n");
    scanf("%d",&j);
    if(j==0){
    control();
    }
    if(j==1){
    abc();
    }

}

int main(){
     FILE *file = fopen("data.txt", "rb");
    if (file != NULL) {
      
        fread(zh, sizeof(char), 20, file);
        fread(mm, sizeof(char), 20, file);
        for (int i = 1; i < 11; i++) {
            for (int j =1 ; j < 7; j++) {
                fread(&a[i][j], sizeof(a), 1, file);
            }
        }

        fclose(file);
        printf("数据读取成功\n");
        printf("\n");
    } else 
        printf("数据文件不存在，将创建新文件\n");


                    
    if(part1()){
        control();
    }

    return 0;}



