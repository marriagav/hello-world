#from statistics import mode
import pandas as pd
import numpy as np

#start
def getRatings(peliculas):
    accumList=[]
    for x in peliculas:
        msg= "Califique la película "+x+": "
        var= input(msg)
        accumList.append(float(var))
    return accumList

def getViews(ratings):
    accum=[]
    for x in ratings:
        if x!=0:
            accum.append(x)
    return accum

def divideIndexes(ratings):
    sinVer=[]
    vistas=[]
    for x in range(len(ratings)):
        #print(ratings[x])
        if ratings[x]==0:
            sinVer.append(x)
        else:
            vistas.append(x)
    return sinVer, vistas

def getNewBase(dataf,lista):
    newBase=dataf.iloc[:, lista]
    return newBase

#Función que calcula distancia entre dos coordenadas
def dist(coord1,coord2):
    dist=0
    #print (coord1[1])
    #print (coord2[1])
    for x in range (len(coord1)):
        dist+=(coord1[x] -coord2[x])**2
    dist=dist**(1/2)
    #print(dist)
    return dist

#Función que acepta una lista y regresa una lista de lista con índices
def putInd(lista1):
    accum=[]
    for x in range (len(lista1)):
        accum.append([lista1[x],x])
    return accum

#Función que acepta un entero y una lista, regresa los k elementos más pequeños
def kMin(K, lista):
    #accum=[]
    lista.sort()
    accum=lista[:K]
    #for i in range(K):
        #accum.append(lista[i])
    return accum

def maxPun(base):
    mx=0
    indx=0
    for x in base:
        p1=base.loc[:,x]
        prom=np.mean(p1)
        if prom>mx:
            mx=prom
            indx=x
    return indx

#Algorítmo KNN
def recomendar(K,base):
    ratings=getRatings(base)
    sinVer,vistas=divideIndexes(ratings)
    views=getViews(ratings)
    baseVistas=getNewBase(base,vistas)
    baseSinVer=getNewBase(base,sinVer)

    #print(baseVistas)
    #print(views)
    #print(sinVer)

    listaDistancias=[]
    for index, row in baseVistas.iterrows():
        #print(row)
        listaDistancias.append(dist(row,views))

    listaIndex=putInd(listaDistancias)
    Ksmallest=kMin(K,listaIndex)
    #print(listaIndex)
    #print(Ksmallest)

    smallestInd=[]
    for j in Ksmallest:
        smallestInd.append(j[-1])
    
    nearEst=baseSinVer.iloc[smallestInd,:]
    #print(nearEst)
    return(maxPun(nearEst))


def main():
    mensaje="Hola, este es un programa que te da recomendaciones de películas a partir de tus gustos personales.\n"
    mensaje+="Se te preguntarán las calificaciones que le pones a una serie de películas, calificalas del 1 al 5, 1 siendo que no te gustó y 5 que te encantó.\n"
    mensaje+="Al calificarlas, puedes incluir medios puntos. Por ejemplo: 4.5.\n"
    mensaje+="En las películas que no hayas visto, coloca un 0, esto le indicará al programa que no las has visto y te recomendará alguna de ellas."
    print(mensaje)
    mnsj="Te recomendamos ver:"
    baseP_df = pd.read_csv("CF.csv", index_col = 0)
    baseP_df=baseP_df.drop('Y', axis = 1)

    #Toy Dataset
    # peliculas = ['Exmachina', 'Yo, Robot', 'Inteligencia Artificial', '2001, odisea', 'Matrix', 'Blade Runner']
    # basep = [[3, 4, 3, 4, 4, 2], [3, 5, 3, 4, 5, 4], [3, 4.5, 5, 3, 4, 3], [3.5, 4, 3.5, 4.5, 5, 5], [4.5, 3.5, 4, 4, 4.5, 4],
    #         [3, 4.5, 4, 3, 2.5, 3], [4, 4.5, 3.5, 5, 4, 4], [5, 4.5, 4, 4, 4.5, 4.5], [3.5, 3, 4, 5, 3.5, 4.5],
    #         [3, 5, 1, 4.5, 3.5, 1.5], [3, 5, 3, 4, 5, 3.5], [2.5, 4.5, 3, 3, 3.5, 4.5], [3.5, 5, 2.5, 3, 4.5, 5]]
    # baseP_df = pd.DataFrame(basep, columns = peliculas)

    #print(baseP_df)
    print("CASOS DE PRUEBA:")
    print(mnsj,recomendar(3,baseP_df))
    # print(mnsj,recomendar(2, baseP_df, ratings = [4.5, 0, 4, 4.5, 0, 5]))
    # print(mnsj,recomendar(2, baseP_df, [3, 0, 5, 3, 0, 4]))
    # print(mnsj,recomendar(3, baseP_df, [5, 0, 0, 0, 4, 2]))
    # print(mnsj,recomendar(5, baseP_df, [4, 0, 0, 0, 3, 3]))
    # print(mnsj,recomendar(7, baseP_df, [4, 5, 5, 0, 5, 0]))
    # print(mnsj,recomendar(7, baseP_df, [4.5, 0, 0, 0, 4.5, 5]))
    # print(mnsj,"Shrek")


main()


