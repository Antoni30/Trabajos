b=True
palabras=[]
sumaPalabras=[]
cont=0;
p=0
arregloPuntaje =[1,3,3,5,2,1,4,2,4,1,8,8,1,8,3,1,8,1,3,5,1,8,1,1,1,4,10,8,4,10,0]
while(b==True):
   a=0
   c=0
   i=0
   ic=1
   cont=0
   es=" ";
   palabra=input("Ingrese Palabra: ").lower()
   palabras.append(palabra)
   while(a!=len(palabra)):
       if palabra[i] == 'a':
           cont=cont+arregloPuntaje[0]
       elif(palabra[i] == 'b'):
           cont=cont+arregloPuntaje[1]
       elif(palabra[i]=='c'):
           cont=cont+arregloPuntaje[2]
       elif(palabra[i]=='d'):
           cont=cont+arregloPuntaje[4]
       elif(palabra[i]=='e'):
            cont=cont+arregloPuntaje[5]
       elif(palabra[i]=='f'):
            cont=cont+arregloPuntaje[6]
       elif(palabra[i]=='g'):
           cont=cont+arregloPuntaje[7]
       elif(palabra[i]=='h'):
           cont=cont+arregloPuntaje[8]
       elif(palabra[i]=='i'):
           cont=cont+arregloPuntaje[9]
       elif(palabra[i]=='j'):
           cont=cont+arregloPuntaje[10]
       elif(palabra[i]=='k'):
           cont=cont+arregloPuntaje[11]
       elif(palabra[i]=='l'):
           cont=cont+arregloPuntaje[12]
       elif(palabra[i]=='m'):
           cont=cont+arregloPuntaje[14]
       elif(palabra[i]=='n'):
           cont=cont+arregloPuntaje[15]
       elif(palabra[i]=='ñ'):
           cont=cont+arregloPuntaje[16]
       elif(palabra[i]=='o'):
           cont=cont+arregloPuntaje[17]
       elif(palabra[i]=='p'):
           cont=cont+arregloPuntaje[18]
       elif(palabra[i]=='q'):
           cont=cont+arregloPuntaje[19]
       elif(palabra[i]=='r'):
           cont=cont+arregloPuntaje[20]
       elif(palabra[i]=='s'):
           cont=cont+arregloPuntaje[22]
       elif(palabra[i]=='t'):
           cont=cont+arregloPuntaje[23]
       elif(palabra[i]=='u'):
           cont=cont+arregloPuntaje[24]
       elif(palabra[i]=='v'):
           cont=cont+arregloPuntaje[25]
       elif(palabra[i]=='w'):
           cont=cont+arregloPuntaje[26]
       elif(palabra[i]=='x'):
           cont=cont+arregloPuntaje[27]
       elif(palabra[i]=='y'):
           cont=cont+arregloPuntaje[28]
       elif(palabra[i]=='z'):
           cont=cont+arregloPuntaje[29]
       elif(palabra[i]=='?'):
           cont=cont+arregloPuntaje[30]
       a=a+1
       i=i+1
   a=0
   c=0
   i=0
   while(a!=len(palabra)):
       if(ic==len(palabra)):
           ic=ic-1
       es=palabra[i]+palabra[ic]
       if(es=='ll'):
           cont=cont+arregloPuntaje[13]
           cont=cont-(arregloPuntaje[12]+arregloPuntaje[12])
       elif(es=='ch'):
           cont=cont+arregloPuntaje[3]
           cont=cont-(arregloPuntaje[2]+arregloPuntaje[8])
       elif(es=='rr'):
           cont=cont+arregloPuntaje[21]
           cont=cont-(arregloPuntaje[20]+arregloPuntaje[20])
       ic=ic+1
       i=i+1
       a=a+1
   sumaPalabras.append(cont)
   opc=input("Si desea ingresar otra palabra precione S caso contrario cualquier letra: ").lower()
   if(opc!='s'):
      b=False      
a=0
k=0
l=0
while(k!=len(sumaPalabras)):
   while(l!=k):
      if(sumaPalabras[l]<sumaPalabras[l+1]):
         temp=sumaPalabras[l]
         tempS=palabras[l]
         sumaPalabras[l]=sumaPalabras[l+1]
         sumaPalabras[l+1]=temp
         palabras[l]=palabras[l+1]
         palabras[l+1]=tempS
      l=l+1
   k=k+1
print("Palabra con mayor puntaje: ")
print(palabras[a])
print("Puntaje: ")
print(sumaPalabras[a])

       
       
