#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void control(){
    system("cls");
    printf("请选择你要进行的操作:\n");
    printf("1.商品信息查询\n2.添加货物功能\n3.删除货物功能\n4.选择商品促销\n5.退出\n\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1: 
            part2();
            break;
        case 2:
            add();
            break;
        case 3:
            del();
            break;
        case 4:
            abc();
        case 5:
            printf("谢谢使用，再见！\n");

            // 退出系统前保存数据到文件
            FILE *file = fopen("data.txt", "w");
            file = fopen("data.txt", "w");
            if (file != NULL) {
                fprintf(file,"%s %s\n",zh,mm);
                for (int i = 1; i < 11 ; i++) {
                    for (int j = 1; j < 7; j++) {
                        fprintf(file, "%s %f %d %d %d %d %d %d %d %d\n",
                        a[i][j].name, a[i][j].price, a[i][j].number,
                        a[i][j].sc.year, a[i][j].sc.month, a[i][j].sc.day,
                        a[i][j].jz.year, a[i][j].jz.month, a[i][j].jz.day,
                        a[i][j].sign);
            }
        }
        fclose(file);
        printf("数据已保存到文件: %s\n", "data.txt");
    } else {
        printf("无法打开文件进行写入\n");
    }
            exit(0); 
        default:
            printf("无效的选项，请重新输入。\n");
            control(); // 重新显示主菜单
    }

}


    

