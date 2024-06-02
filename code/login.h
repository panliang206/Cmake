#include<stdio.h>
#include<string.h>


int cnt=0;
char zh[20];
char mm[20];


int part1(void){
    printf("请输入您的账号和密码：\n");
    char s1[20];
    char s2[20];
    gets(s1);
    gets(s2);


    if(!strcmp(s1,zh)){
        if(!strcmp(s2,mm)){
            printf("登陆成功!\n");
            printf("\n");
            control();
        }
    
    }

    cnt++;

    if(cnt==3){
        printf("请重设账号密码!\n\n\n");
        printf("请输入你要重设的账号:\n");
        gets(zh);

        printf("请输入你要重设的密码:\n");
        gets(mm);

        part1();

        
    }
    

    printf("账号或密码错误请重试！\n");

   
    printf("\n");
    part1();

    
    
}