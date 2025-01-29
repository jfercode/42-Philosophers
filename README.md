# 42-Philosophers 🍽️🧠 

Philosophers es un proyecto de la escuela 42 basado en el problema clásico de los **filósofos comensales** formulado por **Edsger Dijkstra**. El objetivo es simular un conjunto de filósofos que alternan entre **pensar, comer y dormir**, asegurando que no haya **interbloqueo (deadlock)** ni **condiciones de carrera** en un entorno multihilo.
</div>
<div align="center">
  <img src="https://github.com/user-attachments/assets/0b6dc235-5737-4a32-85b0-ce951447d710" alt="Philo-dinner" width="400"/>
  <br/>
</div>

## Descripción del Proyecto 📖 

El programa simula la vida de `N` filósofos sentados alrededor de una mesa, donde cada filósofo tiene acceso a **dos tenedores** (compartidos con sus vecinos) y deben tomar ambos para poder comer.  

La simulación debe manejar correctamente la sincronización de los filósofos, evitando estados de inanición y bloqueos.

## Reglas de la Simulación 📜  

- 🧠 Cada filósofo tiene tres estados: **pensando**, **comiendo**, **durmiendo**.
- 🍽️ Para comer, un filósofo necesita tomar los dos tenedores adyacentes.
- 💀 Si un filósofo no logra comer dentro de un tiempo determinado, muere.
- ⏳ La simulación termina si algún filósofo muere o si todos han comido un número específico de veces.

## Uso del Programa 🏃  

Los siguientes comandos deben ser ejecutados en la terminal, dentro del directorio de tu proyecto:

- **`make all`**: Compila el proyecto, genera la biblioteca estática `philo.a`, y genera un ejecutable llamado `philo`.

- **`make clean`**: Elimina los archivos objeto (`.o`) generados durante la compilación.
  
- **`make fclean`**: Ejecuta el comando `clean` y, además, elimina el archivo `push_swap.a` y cualquier ejecutable generado.

- **`make re`**: Ejecuta los comandos `fclean` y `all`, recompilando todo el proyecto desde cero.

Una vez compilado el proyecto podrá ejecutarse con los siguientes comandos:

```sh
./philo n_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Parámetros 📌
  - **n_philosophers** -> Número de filósofos y de tenedores.
  - **time_to_die** -> Tiempo en (ms) antesd de que un filósofo muera si no ha comido.
  - **time_to_eat** -> Tiempo en (ms) que tarda un filósofo en comer.
  - **time_to_sleep** -> Tiempo en (ms) que pasa un filósofo durmiendo.
  - **number_of_times_each_philosopher_must_eat** -> Como parámetro opcional, es el número de comidas que cada filósofo debe hacer antes de que termine la simulación.

### Ejemplo de ejecución 
```sh
./philo 5 800 200 200 7
```
En este caso, 5 filósofos en la mesa moriran si no comen en 800 ms, tardando 200 ms en comer y 200 ms en dormir y acabará la ejecución si estos llegan a comer 7 veces.

## Casos de error ⚠️
El programa mostrará un mensaje de error si:

- ❌ Hay un número incorrecto de argumentos.
- 🔢 Alguno de los valores ingresados no es un número válido.
- 📉 Se ingresan valores negativos o cero en parámetros inválidos.

## Configuración 🛠️

Puedes ajustar las opciones de compilación en el Makefile según tus necesidades específicas.

## Autor 👨‍💻
  <br/>
  <br/>
  <br/>

</div>
<div align="center">
  <img src="https://avatars.githubusercontent.com/u/102600920?v=4" alt="Logo" width="200"/>
  <br/>
  <br/>
  <div style="margin: 20px 0 30px;">
  <a href="https://github.com/jfercode">Javier Fernández Correa</a>
  </div>
</div>
  <br/>
<div align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTVInHuUPtp3uiEuvF0aYAkFBUzpnr65b2CDA&s" alt="Logo"/>
</div>
