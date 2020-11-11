#include <conio.h>
#include <stdio.h>
typedef char cadenaDeCaracteres [50];
#define NI 50
cadenaDeCaracteres provincias[]={
    "Azuay",
    "Bolivar",
    "Caniar",
    "Carchi",
    "Cotopaxi",
    "Chimborazo",
    "El Oro",
    "Esmeralda",
    "Guayas",
    "Imbabura",
    "Loja",
    "Los Rios",
    "Manabi",
    "Morona De Santiago",
    "Napo",
    "Pastaza",
    "Pichincha",
    "Tungurahua",
    "Zamora De Chinchipe",
    "Galapagos",
    "Sucumbios",
    "Orellana",
    "Santo Domingo de los Tsachilas",
    "Santa Elena"
};
cadenaDeCaracteres mesesDelAnio[]={
    "Enero",
    "Febrero",
    "Marzo",
    "Abril",
    "Mayo",
    "Junio",
    "Julio",
    "Agosto",
    "Septiembre",
    "Octuble",
    "Noviembre",
    "Diciembre"
};
cadenaDeCaracteres causaMuerte[]={
    "COVID",
    "CARDIACOS",
    "ACCIDENTES VIALES",
    "SUICIDIOS",
    "ACCIDENTES DOMESTICOS",
    "MUERTE NATURAL"
};
void mostrarCodigosProvicias(){
     for(int i=0;i<24;i++)
    {
        printf("%i %s\n",i+1,provincias[i]);
    }
}
void mostrarMeses(){
     for(int i=0;i<12;i++)
    {
        printf("%s\n",mesesDelAnio[i]);
    }
}
char*devolverProvincia(int i){
    return provincias[i-1];
}
char*devolverMes(int i){
    return mesesDelAnio[i-1];
}
char*devolverCausaDeMuerte(int i){
    return causaMuerte[i-1];
}
 struct Informes{
    int nRegistro;
    int mesR;
    int codProvincia;
    int nCausaM;
    int cantM;
}inf[NI],temp;
int main()
{
    int nRegistro=1,registro=1;
    int mesNum;
    int teclaPresion;
    int codigoProvincia;
    int cantidadMuertos;
    int opc;
    int contS=0,contCV=0,contAV=0,contAD=0,contMN=0,contCA=0;
   while(registro>0){
    int validacionMes=0,validacionProvincia=0,validacionEnfermedad=0,validacionMuertos=0;
    printf("                             Informe\n");
    do{
        printf("Ingrese el mes a Registrar(En numeros)\n");
        scanf("%i",&mesNum);
        if(mesNum<13){
           validacionMes=1;
           do{
            system("cls");
            printf("Ingrese el codigo de Provincian\n");
            scanf("%i",&codigoProvincia);
            if(codigoProvincia<23){
                system("cls");
                validacionProvincia=1;
                do{
                    printf("Ingrese La Cantidad de Muertos\n");
                    scanf("%i",&cantidadMuertos);
                    if(cantidadMuertos>0)
                    {
                        validacionMuertos=1;
                    }
                    else{
                        validacionMuertos=0;
                        system("cls");
                        printf("Ingrese valores Positivos\n");
                        system("Pause");
                        system("cls");
                    }
                }while(validacionMuertos==0);
                system("cls");
                do{
                    printf("Seleccione Causa de Muerte\n");
                printf("1.-COVID\n");
                printf("2.-CARDIOCOS\n");
                printf("3.-ACCIDENTES VIALES\n");
                printf("4.-SUICIDIOS\n");
                printf("5.-ACCIDENTES DOMESTICOS\n");
                printf("6.-MUERTE NATURAL\n");
                scanf("%i",&opc);
                if(opc>0 && opc<=6){
                    validacionEnfermedad=1;
                    inf[nRegistro-1].nRegistro=nRegistro;
                    inf[nRegistro-1].mesR=mesNum;
                    inf[nRegistro-1].codProvincia=codigoProvincia;
                    inf[nRegistro-1].nCausaM=opc;
                    inf[nRegistro-1].cantM=cantidadMuertos;
                    nRegistro++;
                    system("cls");
                    printf("Ingrese Numero de Registro\n");
                    scanf("%i",&registro);
                }
                else{
                    system("cls");
                    validacionEnfermedad=0;
                    printf("Recuerde que solo son 6 enfermedades\n");
                    system("Pause");
                    system("cls");
                }
                }while(validacionEnfermedad==0);

            }
            else{
                validacionProvincia=0;
                system("cls");
                printf("Recuerde que solo existe 22 Provincias\n");
                system("Pause");
                system("cls");
            }
           }while(validacionProvincia==0);
        }
        else{
            validacionMes=0;
            system("cls");
            printf("Recuerde que solo existe 12 meses\n");
            system("Pause");
            system("cls");
        }
    }while(validacionMes==0);
   }
    for(int i=0;i<NI;i++){
    if(inf[i].nCausaM==1){
        contCV=inf[i].cantM+contCV;
    }
    else if(inf[i].nCausaM==2){
        contCA=inf[i].cantM+contCA;
     }
     else if(inf[i].nCausaM==3){
        contAV=inf[i].cantM+contAV;
     }
     else if(inf[i].nCausaM==4){
        contS=inf[i].cantM+contS;
     }
     else if(inf[i].nCausaM==5){
        contAD=inf[i].cantM+contAD;
     }
     else if(inf[i].nCausaM==6){
        contMN=inf[i].cantM+contMN;
     }
   }
   printf("Se Registro %i casos de muerte por Suicidio\n",contS);
   for (int i=1; i<NI; i++)
    {
        for ( int j=0 ; j<NI - 1; j++)
        {
            if (inf[j].cantM < inf[j+1].cantM)
            {
                temp = inf[j];
                inf[j] = inf[j+1];
                inf[j+1] = temp;
            }
        }
   }
   printf("La causa de muerte mayor fue %s en la provincia de %s\n",devolverCausaDeMuerte(inf[0].nCausaM),devolverProvincia(inf[0].codProvincia));
   printf("Total de Muertes por Cada Causa:\n");
   printf("Covid: %i\n",contCV);
   printf("Cardiacos: %i\n",contCA);
   printf("Accidentes Viales: %i\n",contAV);
   printf("Suicidios: %i\n",contS);
   printf("Accidentes Domesticos: %i\n",contAV);
   printf("Muerte Natural: %i\n",contMN);
   printf("Existen menos muertos en la Provincia de %s\n",devolverProvincia(inf[NI-1].codProvincia));
   printf("\n\n");
   printf("Mostrar el Informe Ordenada de Mayor a Menor\n");
   for(int i=0;i<nRegistro-1;i++){
    printf("Mes: %s\n",devolverMes(inf[i].mesR));
    printf("Provincia: %s\n", devolverProvincia(inf[i].codProvincia));
    printf("Causa de Muerte: %s\n",devolverCausaDeMuerte(inf[i].nCausaM));
    printf("Cantidad de Muertos: %i\n",inf[i].cantM);
    printf("\n\n");
   }
    system("pause");
    return 0;
}
