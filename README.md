# Cub3D

Este proyecto está inspirado en el juego epónimo mundialmente conocido,considerado como el primer FPS jamás realizado. Le permitirá explorar la técnica del ray-casting. El objetivo es crear una vista dinámica dentro de un laberinto.

### Parte obligatoria

- Debe mostar texturas diferentes para cada muro en función de la orientación.
- Se debe poder mostrar un sprite en lugar de un muro.
- Colores distintos para suelo y techo.
- Si se pasa como segundo argumento `--save`, el programa guardará la primera imagen en formato `bmp`, sin abrir el juego.
- Si no hay segundo argumento, se muestra el programa en una ventana.

##### Archivo de configuración

- Debe contener:
    - R: indica la resolución de la ventana.
    - NO, SO, EA y WE: indica el path hacia las texturas de los muros.
    - S: indica el path hacia la textura del sprite.
    - F: indica el color del suelo en formato rgb.
    - C: indica el color del techo en formato rgb.
- El mapa solo puede contener:
    - 0: Espacios vacios.
    - 1: Muros.
    - 2: Sprites.
    - N, S, W o W: Indica la posición y orientación dle jugador.
- El mapa debe estar cerrado por muros.

#### Ejemplo de juego en parte obligatoria

![](https://raw.githubusercontent.com/dalba-de/42_cub3D/master/mandatory.bmp)

### Parte Bonus

Se añade a las especificaciones anteriores, los siguientes bonus:
- Colisión contra los muros.
- Una skybox.
- Texturas en techo y suelo.
- Un hud.
- Más objetos en el laberinto.
- Colisión con los objetos.
- Ganancia y pérdida de puntos de vida.
- Puertas y puertas secretas.
- Animaciones.
- Varios niveles.
- Armas y malos con los que pelear.

#### Arhivo de configuración bonus

Se añaden a las anteriores especificaciones las siguientes posibilidades:
- T: indica el path hacia la textura de los tesoros para recoger.

El mapa puede contener:
- T: Tesoros.
- H: Item de vida.
- D: Puerta cerrada.
- O: Puerta abierta.
- X: Puertas secretas.
- L: Cambio de nivel.
- B: Enemigos.
- 4 y 5: Diferentes tipos de sprites.

#### Ejemplo de juego en parte bonus

![](https://raw.githubusercontent.com/dalba-de/42_cub3D/master/bonus.bmp)
