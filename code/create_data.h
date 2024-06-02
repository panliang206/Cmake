#include<stdio.h>
#include<string.h>

struct begin{
    int year;
    int month;
    int day;
};

struct end{
    int year;
    int month;
    int day;
};

struct shangpin{
    char name[60];
    int price;
    int number;
    struct begin sc;
    struct end jz;
    int sign;
}a[11][7];



