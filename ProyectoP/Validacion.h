#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED
#include<iostream>
#include<stdlib.h>
using namespace std;
int ingresarInt(char *p)
{
    char tecla;
    int i=0;
    p[0]='\0';
    do
    {
        tecla=getch();
        if(i> 0 && tecla == 8)
        {
            cout<<"\b \b";
            p[--i]='\0';
        }
        else{
            if((tecla>=48 && tecla<=57))
            {
                cout<<tecla;
                p[i++]=tecla;
            }
        }
    }while(tecla!=13 || p[0]=='\0');
    p[i]='\0';
    cout<<endl;
    return atoi(p);
}
#endif // VALIDACION_H_INCLUDED
