/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:08:34 by anoviedo          #+#    #+#             */
/*   Updated: 2025/12/09 11:24:34 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	mlx_init ... inicializa el puntero necesario para el resto de parametros
	de minilibx, si falla devuelve null.
	internamente conecta el programa con x server que es un servidor display.
	reserva algunas estructuras tambien.*/
static int	init_game(t_cub *game)
{
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIN_W, WIN_H, "cub3d");
	if (!game->mlx.win)
		return (perror("windows error"), 1);
	game->mlx.img = NULL;
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIN_W, WIN_H);
	if (!game->mlx.img)
		return (perror("image error"), 1);
	game->mlx.addr = NULL;
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bpp,
			&game->mlx.line_len, &game->mlx.endian);
	if (!game->mlx.addr)
		return (perror("address error"), 1);
	return (0);
}

/*
	Mover el dibujo al bucle de render y dejar key_press solo para actualizar
	estado

	Objetivo: que el frame se repinte constantemente y key_press solo cambie
	posición/rotación. Evita inconsistencias y parpadeos.
	Acción:
		Añadir un game_loop y registrar mlx_loop_hook en main.
		Quitar dibujado “manual” en key_press.
*/
int	game_loop(t_cub *game)
{
	double	now;

	now = get_time_ms();
	game->tm.frame_time = now - game->tm.old_time;
	game->tm.old_time = now;
	clear_window(&game->mlx, 0x000000);
	// mlx_clear_window(game->mlx.mlx, game->mlx.win);
	cast_all_rays(game);
	movements(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
	if (game->mini == true)
		draw_map(game);
	return (0);
}

void	render_game(t_cub *game)
{
	void	*win;

	win = game->mlx.win;
	mlx_hook(win, 17, 0, close_windows, game);
	mlx_hook(win, 2, 1L << 0, key_press, game);
	mlx_hook(win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx.mlx, game_loop, game);
}

/*	mlx_hook 17 = X presionada
	mlx_hook_key corresponde a la reaccion de la ventana con las teclas
	en este caso es para cerrar con escape(key_press)*/
int	main(int ac, char **av)
{
	t_cub		game;

	if (!check_file_format_n_extention(av[1]) || ac != 2)
	{
		perror(CLR_RED"Error:\nIncorrect # arguments:"
			CLR_YLLW"./bin/cub3d '[*file*.cub]'"RST_ALL);
		return (1);
	}
	init_variables(&game);
	game.map_path = av[1];
	if (!check_for_params(game.map_path, &game))
	{
		// printf("Error here in check_for_params\n"); // debug
		// error_handler(NULL, E_MAP, EMPTY_ID, &game); // debug
		close_windows(&game);
		return (1);
	}
	init_player(&game);
	if (init_game(&game))
		close_windows(&game);
	render_game(&game);
	mlx_loop(game.mlx.mlx);
	return (0);
}

/*

lista completa de las funciones de **MiniLibX** (mlx) utilizadas en el proyecto

---

### **1. `mlx_init()`**
- **Ubicación en tu código**: `init_var.c`, `main.c`
- **Explicación**:
  Inicializa la conexión entre tu programa y el sistema gráfico (X11 en Linux).
  Devuelve un puntero `void*` que representa el "contexto" gráfico. Todas las
  demás funciones de mlx requieren este puntero. Si falla, devuelve `NULL`.

---

### **2. `mlx_new_window()`**
- **Ubicación**: `main.c`
- **Explicación**:
  Crea una nueva ventana gráfica. Recibe el contexto de mlx, el ancho,
  alto y un título. Devuelve un puntero `void*` a la ventana. Si falla,
  devuelve `NULL`.

---

### **3. `mlx_new_image()`**
- **Ubicación**: `main.c`
- **Explicación**:
  Crea un buffer de imagen en memoria (no visible directamente).
  Se usa para dibujar píxeles fuera de pantalla y luego copiarlos a la
  ventana. Devuelve un puntero `void*` a la imagen.

---

### **4. `mlx_get_data_addr()`**
- **Ubicación**: `main.c`
- **Explicación**:
  Obtiene la dirección de memoria del buffer de una imagen creada con
  `mlx_new_image()`. Devuelve información sobre los bits por píxel (`bpp`),
  el tamaño de una línea (`line_len`) y el formato de color (`endian`).
  Esencial para dibujar píxeles manualmente.

---

### **5. `mlx_put_image_to_window()`**
- **Ubicación**: `game_start.c`, `main.c`
- **Explicación**:
  Copia una imagen (buffer) a la ventana en una posición dada `(x, y)`.
  Se usa para renderizar el frame completo después de dibujar en el buffer.

---

### **6. `mlx_destroy_image()`**
- **Ubicación**: `free_and_destroy.c`
- **Explicación**:
  Libera la memoria de una imagen creada con `mlx_new_image()`.
  Debe llamarse antes de cerrar el programa para evitar leaks.

---

### **7. `mlx_destroy_window()`**
- **Ubicación**: `free_and_destroy.c`
- **Explicación**:
  Cierra y destruye una ventana creada con `mlx_new_window()`. Debe llamarse
  antes de salir.

---

### **8. `mlx_destroy_display()`**
- **Ubicación**: `free_and_destroy.c`
- **Explicación**:
  Libera los recursos internos del sistema gráfico (X11) asociados al contexto
  mlx. Siempre debe llamarse antes de `free(mlx)`.

---

### **9. `mlx_loop()`**
- **Ubicación**: `main.c`
- **Explicación**:
  Inicia el bucle principal de eventos de mlx. La ventana se mantiene abierta
  y escucha eventos (teclado, ratón, cierre). El programa queda bloqueado aquí
  hasta que se cierra la ventana.

---

### **10. `mlx_hook()`**
- **Ubicación**: `main.c`
- **Explicación**:
  Registra una función callback para un evento específico.
  - `17`: Evento de cerrar ventana (clic en la X).
  - `2`: Evento de tecla presionada.
  Permite vincular tus funciones (ej. `close_windows`, `key_press`) a eventos del
  sistema.

---

### **11. `mlx_loop_hook()`**
- **Ubicación**: `main.c`
- **Explicación**:
  Registra una función que se ejecutará en cada iteración del bucle principal de
  mlx (`mlx_loop`). Se usa para renderizado continuo (por ejemplo, `game_loop`).

---

### **Resumen de flujo típico en mlx:**
1. `mlx_init()` → Obtener contexto.
2. `mlx_new_window()` → Crear ventana.
3. `mlx_new_image()` + `mlx_get_data_addr()` → Crear buffer para dibujar.
4. `mlx_hook()` → Registrar callbacks para eventos.
5. `mlx_loop_hook()` → Registrar función de renderizado continuo.
6. `mlx_loop()` → Iniciar bucle de eventos.
7. Al salir: destruir imágenes, ventana, display y liberar memoria.

---

*/
