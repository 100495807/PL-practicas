# PL-practicas

Repositorio de practicas de Procesadores de Lenguaje. Reune ejercicios progresivos con Bison/Yacc, Lex/Flex, calculadoras, analizadores sintacticos, generacion de AST, traduccion dirigida por sintaxis y un proyecto final de traductor.

## Objetivo

Construir herramientas de analisis y traduccion de lenguajes, pasando desde calculadoras sencillas hasta un traductor con frontend y backend para un subconjunto de lenguaje tipo C.

## Tecnologias

- C
- Bison / Yacc
- Lex / Flex
- Makefile
- Gramatica LL y LR
- AST y traduccion dirigida por sintaxis

## Contenido

| Carpeta | Descripcion |
| --- | --- |
| `practica_1` - `practica_5` | Calculadoras y primeros analizadores con Bison/Flex. |
| `practica_6` | Gramatica y descendente recursivo LL. |
| `practica_7` - `practica_9` | Aproximaciones al proyecto final, AST y generacion diferida. |
| `practica_10` - `practica_13` | Evolucion del traductor y backend. |
| `practica_final` | Entrega final con frontend (`trad.y`) y backend (`back.y`). |

## Proyecto Final

La carpeta `practica_final` contiene un traductor construido con Bison que trabaja con:

- variables globales y locales,
- expresiones aritmeticas y logicas,
- asignaciones,
- `if`, `else`, `while`, `for`,
- `puts`, `printf`,
- funciones y `return`,
- generacion de codigo intermedio/salida.

## Como Compilar

Ejemplo en la practica final:

```bash
cd practica_final
make
```

Esto genera ejecutables para el frontend y backend definidos en el `Makefile`.

## Como Probar

Usar los ficheros de prueba incluidos en:

```text
practica_final/tests_trad/
practica_final/tests_back/
practica_final/tests_profe/
```

## Aprendizajes

- Definir tokens y reglas gramaticales.
- Asociar acciones semanticas a producciones.
- Construir y recorrer AST.
- Separar frontend y backend de un traductor.
- Compilar herramientas generadas por Bison/Flex y validarlas con casos de prueba.

## Estado

Proyecto academico finalizado. Se conserva como recorrido completo por analisis lexico, sintactico y traduccion de lenguajes.