

## Cómo ejecutar los casos de prueba de la Segunda Tarea

**Nota:**  Este test debe ser ejecutado en linux.

En esta página se describen varios archivos que sirven para probar la
tarea. Estos están comprimidos en el archivo `pruebas.tar.gz` (se
encuentra en la sección de laboratorio del curso).

***El contenido del archivo comprimido se debe extraer en una carpeta
cualquiera y en la misma se debe copiar el archivo `tarea2.pas` con los
subprogramas solicitados en esta tarea.***

## Como descomprimir los archivos

El archivo se puede descomprimir con el siguiente comando: `tar xzf pruebas.tar.gz`.
También funciona accionar con doble click sobre el archivo.

## Archivos proporcionados

En la carpeta donde se realizó la descompresión se van a encontrar los siguientes archivos y carpetas:

-    Los archivos `definiciones.pas` y `principal.pas`.
-    Una carpeta  `entradas` que contiene las entradas al programa principal para realizar los casos de prueba.
-    Una carpeta  `textos` que contiene los archivos de texto que se usan en los casos de prueba.
-    Una carpeta  `salidas` con las salidas oficiales, o esperadas.
-    Una carpeta  `mios` con las salidas que se obtienen al ejecutar el programa.
-    Una carpeta  `diffs` con las resultados de comparar las salidas correctas y las salidas obtenidas
-    Un script Python `test.py` para compilar, ejecutar y comparar los casos de prueba automáticamente.


## Comportamiento del programa principal

 Para probar el programa, compilamos el programa `principal.pas`. 
 Esto se hace una sola vez mientras no se hagan cambios.

```bash
    fpc -Co -Cr -Miso -gl principal.pas
```

y nos aseguramos que no hay errores de compilación y que se ha generado el ejecutable llamado `principal`.

Se debe compilar en **línea de comandos**.

## Probando de manera interactiva

El programa se puede ejecutar de manera interactiva con el comando:

```bash
    ./principal
```

En esta modalidad el programa imprime el mensaje:
```bash
Ingrese Nombre de Archivo:
```
y queda esperando que se ingrese el nombre de archivo, se puede utilizar cualquier archivo .txt. 
En particular, se proveen cuatro textos en la carpeta `textos`, a modo de ejemplo se puede acceder a `texto3.txt` escribiendo:
```bash
textos/texto3.txt
```

También se pueden utilizar textos propios, basta con agregarlos a la carpeta `textos` y cargarlos en el programa de la siguiente manera:

```bash
textos/miTexto.txt
```

Luego se imprime el mensaje: 
```bash
--------------------------------
Ingrese Opción
--------------------------------
0=fin
1=todosTienenFormatoEnLinea
2=aplicarFormatoEnLinea
3=contarCaracteresEnTexto
4=buscarCadenaEnLineaDesde
5=buscarCadenaEnTextoDesde
6=insertarCadenaEnLinea
7=insertarLineaEnTexto
100=mostrar texto
101=mostrar formatos
--------------------------------
```
Una vez accedido al menú principal, se puede elegir las funcionalidades con el número indicado. Luego, cada una de ellas dará indicaciones
sobre como usarlo.

Se muestra un ejemplo de ejecución, correspondiente a buscar la subcadena "subrayado" desde el principio de `texto1.txt`:

```bash
Ingrese Nombre de Archivo: textos/texto1.txt
--------------------------------
Ingrese Opción
--------------------------------
0=fin
1=todosTienenFormatoEnLinea
2=aplicarFormatoEnLinea
3=contarCaracteresEnTexto
4=buscarCadenaEnLineaDesde
5=buscarCadenaEnTextoDesde
6=insertarCadenaEnLinea
7=insertarLineaEnTexto
100=mostrar texto
101=mostrar formatos
--------------------------------
5
Ingrese línea: 1
Ingrese columna: 1
Texto a buscar:
subrayado
Resultado:
Línea:4 Columna:16
Este solo esta subrayado.
               ^
```


## Probando un Caso de Prueba

Si queremos probar un caso de prueba particular, por ejemplo  `11.txt`, procedemos así:

Ejecutamos nuestro programa de la siguiente forma:

```bash
     ./principal  < entradas/11.txt  > mios/11.txt
```

El comando anterior ejecuta el programa principal de manera tal que la
entrada es leída desde el archivo `entradas/11.txt` y la salida es
guardada en el archivo `mios/11.txt`.

Luego se debe verificar que la salida obtenida coincida con la salida esperada ejecutando el comando:

```bash
     diff  mios/11.txt  salidas/11.txt 
```

Si no hay diferencias entre los archivos `mios/11.txt` y `salidas/11.txt` el comando no emite ninguna salida.
Eso significa que el test es correcto para el caso 11.

En cambio, si el comando `diff` emite alguna salida, el test es incorrecto. Para conocer la diferencia
recomendamos mirar (*a ojo*) el contenido de los archivos `mios/11.txt` y `salidas/11.txt`. 
El primero es el resultado desplegado por el programa del estudiante y el segundo el resultado correcto.

## Verificando todos los casos

Adjuntamos además un script de *Python* que permite ejecutar
automáticamente todos los casos y nos indica para cada test si es
correcto o no. El test se ejecuta de la siguiente manera en la
terminal:

```python
    python3 test.py
```

Este comando: compila el programa principal, ejecuta cada uno de los
casos de prueba de la carpeta `entradas`, y compara cada resultado
obtenido con la salida esperada que está en la carpeta `salidas`. 
Las salidas quedan en la
carpeta `mios`.
Además en la
pantalla se indica el resultado al ejecutar cada caso y al final se
informa la cantidad de casos correctos e incorrectos.

## Descarga de Archivos

El archivo `pruebas.tar.gz` se puede descargar de la sección de Laboratorio del EVA del curso.


