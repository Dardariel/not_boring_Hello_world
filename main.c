#include <stdio.h>
#include "symbols.h"
void symbol(char s, bool *buf);
void setSymbol(char s, int lenght, char *buf, int pos, char sym);
int main(int argc, char** argv)
{
    //printf("Hello world!");
    // Скучно! Сделаем так:
    char str[15]="HELLO WORLD";
    char outputstr[HEIGHT_SYMBOL][WIDTH_SYMBOL*15]={0};
    for(int i=0; i<15; i++)
    {
        setSymbol(str[i], 15, &outputstr[0][0], i*WIDTH_SYMBOL, 'C');
    }
    //вывод
    printf("\n");
    for(int i=0; i<HEIGHT_SYMBOL; i++)
    {
        for(int j=0; j<WIDTH_SYMBOL*15; j++)
        {
            printf("%c", outputstr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
void setSymbol(char s, int lenght, char *buf, int pos, char sym)
{   
    bool sb[HEIGHT_SYMBOL][WIDTH_SYMBOL]={0};
    symbol(s,&sb[0][0]);
    for(int i=0; i<HEIGHT_SYMBOL; i++)
    {
        for(int j=0; j<WIDTH_SYMBOL; j++)
        {
            if(sb[i][j])
            {
                *(buf+(lenght*WIDTH_SYMBOL*i)+pos+j)=sym;
            }
            else
            {
                *(buf+(lenght*WIDTH_SYMBOL*i)+pos+j)=' ';
            }
        }
    }
}
void symbol(char s, bool *buf)
{
    bool *b;
    switch(s)
    { 
        case 'd':
        case 'D':
        {
            b=sybol_D;
            break;
        }
        case 'e':
        case 'E':
        {
            b=sybol_E;
            break;
        }
        case 'h':
        case 'H':
        {
            b=sybol_H;
            break;
        }
        case 'l':
        case 'L':
        {
            b=sybol_L;
            break;
        }
        case 'o':
        case 'O':
        {
            b=sybol_O;
            break;
        }
        case 'r':
        case 'R':
        {
            b=sybol_R;
            break;
        }
        case 'w':
        case 'W':
        {
            b=sybol_W;
            break;
        }
        default:
        {
            b=sybol_clear;
            break;
        }
    }   
    for(int i=0; i<HEIGHT_SYMBOL; i++)
    {
        for(int j=0; j<WIDTH_SYMBOL; j++)
        {
            *(buf+(i*WIDTH_SYMBOL)+j)=*(b+(i*WIDTH_SYMBOL)+j);
        }
    }
}
