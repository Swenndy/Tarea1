 # 🛠️ Sistema de Gestión de Tickets

Este programa en C utiliza un sistema de gestión de tickets que permite registrar, clasificar por prioridad y procesar solicitudes. Los tickets pueden tener prioridad **alta**, **media** o **baja**, y se gestionan en orden de prioridad y llegada.

---

## ✅ Funcionalidades implementadas

- Registro de tickets.
- Asignación de prioridad (alta, media, baja).
- Visualización de tickets pendientes por prioridad.
- Procesamiento del siguiente ticket (siguiendo prioridad y orden de llegada).
- Búsqueda de ticket por ID.

---

## 🚫 Funcionalidades no implementadas

- Los datos no se almacenan (los tickets no se guardan en un archivo).
- No se implementó validación para evitar IDs duplicados.
- No hay validación estricta de entradas inválidas (por ejemplo, ingresar letras cuando se espera un número puede causar errores).

---

## ▶️ Cómo ejecutar el programa

1. Asegúrate de tener instalado un compilador de C (como `gcc`).
2. Coloca los siguientes archivos en el mismo directorio:
   - `main.c` (este archivo que contiene el código principal).
   - `arraylist.c` y `arraylist.h` (implementación de listas enlazadas).
3. Compila el programa:
   - Ejecuta el primer comando para crear el archivo .exe
   - En caso de querer ejecutarlo en el terminal ejecutar el segundo comando despues del primero.
   ```bash
   gcc main.c -o main
   ./main
## 💡 Ejemplo de uso
```bash
========================================
     Sistema de Gestión ticket
========================================
1) Registrar ticket
2) Asignar prioridad a ticket
3) Mostrar lista de ticket pendientes
4) Procesar siguiente ticket
5) Buscar ticket por ID y mostrar detalles
6) Salir
Seleccione una opción: 1

Ingrese el ID del ticket: 101
Ingrese los Descripción del ticket: Problema con conexión WiFi
ticket registrado con éxito.

Seleccione una opción: 2

Ingrese el ID del ticket: 101
Ingrese la prioridad del ticket 
1) Alta
2) Media
3) Baja
Seleccione una opción: 1
ticket asignado a la lista de alta prioridad.
```
