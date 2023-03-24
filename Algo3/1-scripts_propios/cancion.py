class Cancion:
    def __init__(self,nombre,duracion):
        self.__nombre = nombre
        self.__duracion = duracion

    @property
    def nombre(self):
        return self.__nombre

    @nombre.setter
    def nombre(self, nombre_nuevo):
        self.__nombre = nombre_nuevo
    
    @property
    def duracion(self):
        return self.__duracion

    @duracion.setter
    def duracion(self, duracion_actualizada):
        self.__duracion = duracion_actualizada
    
    def __str__(self) -> str:
        return f"Nombre: {self.nombre} - Duracion en MIN: {self.duracion}"
    
class Catalogo:
    def __init__(self):
        self.canciones = []

    def agregar_cancion(self,cancion:Cancion):
        self.canciones.append(cancion)
    
    def mostrar(self):
        for cancion in self.canciones:
            print(cancion)


def suma_minutos(lista):
    duracion_total=0
    for cancion in lista:
        duracion_total += cancion.duracion
    return duracion_total


def llenarDisco(catalogo:Catalogo,sol_parcial,indice:int,topeDisco:int,mejorSuma):
    """Backtracking CD:
    Dado un n = cantidad de minutos en disco, devuelvo una lista con canciones
    del catálogo de tal forma que se obtenga la mayor cantidad de minutos con música"""
    if indice == (len(catalogo.canciones)-1):
        if suma_minutos(sol_parcial) <= topeDisco and suma_minutos(sol_parcial) > mejorSuma:
            mejorSuma = suma_minutos(sol_parcial)
    else:
        llenarDisco(catalogoAirbag, sol_parcial + [catalogo.canciones[indice]], indice+1, tope, mejorSuma)
        llenarDisco(catalogoAirbag, sol_parcial, indice+1, tope,mejorSuma)
        
    return mejorSuma
    # def llenarDiscoCotas():
    #     """Lo mismo que llenarDisco pero le pongo las cotas"""


#------------------Main--------------------    
tema1 = Cancion("Por mil noches", 4)
tema2 = Cancion("Cae el sol", 3)
tema3 = Cancion("Cicatrices", 2)
tema4 = Cancion("Noches de Insomnio", 5)
tema5 = Cancion("Vivamos el momento", 1)

catalogoAirbag = Catalogo()
catalogoAirbag.agregar_cancion(tema1)
catalogoAirbag.agregar_cancion(tema2)
catalogoAirbag.agregar_cancion(tema3)
catalogoAirbag.agregar_cancion(tema4)
catalogoAirbag.agregar_cancion(tema5)

catalogoAirbag.mostrar()

vacio = []
tope = 12                       #tope = max cant de minutos
res = llenarDisco(catalogoAirbag,vacio,0,tope,mejorSuma=0)       
print(res)
#vacio es la solparcial, 0 es el indice, 200 es el tope de minutos