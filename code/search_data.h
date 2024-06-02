#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void part2(){
    system("cls");
    printf("请输入你要查看的种类:\n1.休闲零食\n2.饮料冲调\n3.鲜甜水果\n4.营养早餐\n5.牛奶面包\n6.速冻食品\n");
    printf("\n");
    int j;
    scanf("%d",&j);
    
    for(int i=1;i<11;i++){
        if(a[i][j].sign){
            puts(a[i][j].name);
            printf("价格:%.2f/包\n",a[i][j].price);
            printf("还剩%d包\n",a[i][j].number);
            printf("生产日期：%d年%d月%d日\n",a[i][j].sc.year,a[i][j].sc.month,a[i][j].sc.day);
            printf("保质日期：%d年%d月%d日\n",a[i][j].jz.year,a[i][j].jz.month,a[i][j].jz.day);
            printf("\n");
            }

        }
    printf("若想查询其它信息输入1,输入0表示返回上一界面\n");

    int next;
    scanf("%d",&next);
    if(next)
        part2();
    
    control();



    }

