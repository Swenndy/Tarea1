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
## 📜 Explicación de cada opción
### 1️⃣ Registrar ticket
#### Permite ingresar un nuevo ticket con un **ID** único y una **descripción**.
#### ✅ El ticket se guarda con prioridad baja por defecto y se le asigna automáticamente la hora de llegada.
#### 📌 Ejemplo:
```bash
Ingrese el ID del ticket: 101
Ingrese la Descripcion del ticket: Problema con la impresora
Ticket registrado con éxito.
```
### 2️⃣ Asignar prioridad a ticket
Permite modificar la prioridad de un ticket previamente registrado.
🔍 El usuario debe ingresar el ID del ticket. Si se encuentra en la lista de baja prioridad, se le puede asignar:
- 1 → Alta prioridad.
- 2 → Media prioridad.
- 3 → Mantener baja prioridad.
```bash
Ingrese el ID del ticket: 101
Ingrese la prioridad del ticket 
1) Alta
2) Media
3) Baja
Seleccione una opción: 1
Ticket asignado a la lista de alta prioridad.
```
### 3️⃣ Mostrar lista de tickets pendientes
#### 📋 Muestra todos los tickets pendientes organizados por:
- Prioridad Alta.
- Prioridad Media.
- Prioridad Baja.
#### Cada ticket muestra:
- ID
- Descripción
- Hora de llegada
#### 📌 Ejemplo:
```bash
Prioridad Alta:
ID: 101
Descripción: Problema con la impresora
Hora de llegada: 10:32:15
```
### 4️⃣ Procesar siguiente ticket
#### ⚙️ Procesa el ticket con mayor prioridad disponible:

- Primero busca en alta prioridad.
- Si no hay, busca en media.
- Si tampoco hay, busca en baja.

#### El ticket procesado es el primero que llegó dentro de su lista y se elimina del sistema.

#### 📌 Ejemplo:
```bash
Ticket de alta prioridad:
ID: 101
Descripción: Problema con la impresora
Hora de llegada: 10:32:15
Ticket procesado.
```
### 5️⃣ Buscar ticket por ID
#### 🔎 Permite buscar un ticket ingresando su ID.
#### Si el ticket se encuentra, muestra:
- Prioridad (Alta / Media / Baja)
- Descripción
- Hora de llegada
#### 📌 Ejemplo:
```bash
Ingrese el ID del ticket: 101
Ticket encontrado
Prioridad: Alta
ID: 101
Descripción: Problema con la impresora
Hora de llegada: 10:32:15
```
### 6️⃣ Salir
#### ❌ Cierra el programa.
