#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void control(){
    system("cls");
    printf("请选择你要进行的操作:\n");
    printf("1.商品信息查询\n2.添加货物功能\n3.删除货物功能\n4.选择商品促销\n5.查询过期商品\n6.退出\n\n");
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
            break;
        case 5:
            park();
            break;
        case 6:
            printf("谢谢使用，再见！\n");

            // 退出系统前保存数据到文件
            FILE *file = fopen("data.txt", "wb");
            
            if (file != NULL) {
                fwrite(zh, sizeof(char), 20, file);
                fwrite(mm, sizeof(char), 20, file);
                for (int i = 1; i < 11 ; i++) {
                    for (int j = 1; j < 7; j++) {
                        fwrite(&a[i][j], sizeof(a), 1, file);
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

    

