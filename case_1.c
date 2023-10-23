
tipo

        palabra = tupla
                letras:tabla[MAX] de caracter;
                l:entero;
        ftupla
ftipo

//* Fecha
tipo
        fecha = tupla
                dia = entero;
                mes = {enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre};
                año = entero;
        ftupla
ftipo

//* 11.A Declara tipo de datos tEmppresa
tipo

        tEmpresa = tupla 
                CIF: tabla [9] de palabra;
                nombre: tabla [20] de palabra;
                nombre_contacto: tabla [20] de palabra;
                apellidos1_contacto: tabla [20] de palabra;
                apellidos2_contacto: tabla [20] de palabra;
                telefono: entero;
                direccion_contacto: tabla [50] de palabra;
                facturado: real;
                numPedidos: entero;
                fecha_inicio: tabla[10] de fecha;
        ftupla 
ftipo


//* 11.B Declara un tipo de datos tCarteraClientes y las constantes necesarias para almacenar lo facturado
const 
        MAXEmpresas: entero = 1000;
fconst

tipo 
        tCarteraClientes = tupla
                Empresa: tabla [MAXEmpresas] de tEmpresa;
                numCarteraClientes: entero;
        ftupla
ftipo


//* 1.2 Diseñar una acción que escriba en el canal estándar el nombre comercial de la empresa a la que se han servido más pedidos en número

funcion MaxPedidos(Empresa: tEmpresa): entero;

        var
                i,j: entero;
                Empresa: tEmpresa;
                recorrido, max: entero;
        fvar


        max :=0;
        actual := 0,
        recorrido := 0;

        para i:=1 hasta Empresa.numPedidos hacer
                numPedido:=Empresa.numPedidos[i];
                recorrido:=0;
                        para j:=1 hasta Empresa.numPedidos hacer
                                recorrido:=recorrido+numPedido.tEmpresa[j].numPedidos;     
                        fpara

                        si recorrido > max entonces
                                max:=recorrido;
                        fsi
        fpara

        retorna max;

ffuncion

//* 1.3 Sin diseñar ningún algoritmo declara las variables necesarias, sin necesidad de inicializarlas, y realiza una llamada a la acción

var 
        Empresa: tEmpresa;
        MasPedidos: entero;
fvar

        MasPedidos:=MaxPedidos(Empresa);

//* 1.4 Diseñar una función que devuelva la media en importe facturado por pedido de todos los pedidos servidos

funcion MediaFacturado(Cliente: tEmpresa): real;

        var
                i: entero;
                Cliente: tEmpresa;
                media, total: real;
        fvar

        media:=0;
        total:=0;
        i:=0;

        mientras (Cliente.numPedidos > 0) hacer
                Cliente.facturado := leerReal();
                total:=total+Cliente.facturado;
                i:=i+1;
                Cliente.numPedidos := leerEntero();
                        
        fmientras

        media:= total / i;

        retorna media;

ffuncion


//* 1.5 Sin diseñar ningún algoritmo declara las variables necesarias, sin necesidad de inicializarlas, y realiza una llamada a funcion


var 
        Empresa: tEmpresa;
        MediaFacturados: real;
fvar

        MediaFacturados:=MediaFacturado(Empresa);