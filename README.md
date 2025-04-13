 # 🛠️ Sistema de Gestión de Tickets

Este programa en C implementa un sistema de gestión de tickets que permite registrar, clasificar por prioridad y procesar solicitudes. Los tickets pueden tener prioridad **alta**, **media** o **baja**, y se procesan en orden de prioridad y llegada.

---

## ✅ Funcionalidades implementadas

- Registro de tickets.
- Asignación de prioridad (alta, media, baja).
- Visualización de tickets pendientes por prioridad.
- Procesamiento del siguiente ticket (siguiendo prioridad y orden de llegada).
- Búsqueda de ticket por ID.

---

## 🚫 Funcionalidades no implementadas

- No hay persistencia de datos (los tickets no se guardan en un archivo).
- No se implementó validación para evitar IDs duplicados.
- No hay validación estricta de entradas inválidas (por ejemplo, ingresar letras cuando se espera un número puede causar errores).

---

## ▶️ Cómo ejecutar el programa

1. Asegúrate de tener instalado un compilador de C (como `gcc`).
2. Coloca los siguientes archivos en el mismo directorio:
   - `main.c` (este archivo que contiene el código principal).
   - `arraylist.c` y `arraylist.h` (implementación de listas enlazadas).
3. Compila el programa:
   ```bash
   gcc main.c -o main
