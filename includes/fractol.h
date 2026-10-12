/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:23:35 by yaabdall          #+#    #+#             */
/*   Updated: 2024/10/14 18:38:53 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "mlx.h"
# include "X11/keysym.h"
# include "X11/keysymdef.h"

// BUFFER SIZE FOR STORING TEMPORARY HUD LINE
# define BUFFER_SIZE		64

// SCALING PARAMETERS
# define MOVE_STEP			1.0
# define ZOOM_FACTOR		1.2
# define SCALE_ITERATION	5

typedef enum e_color_theme
{
	PSYCHEDELIC,
	MONOCHROME,
	GRADIENT,
	SMOOTH,
	FIRE,
	OCEAN,
	CUSTOM
}	t_color_theme;

// EVENT TYPES ENUM
typedef enum e_event_type
{
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	BUTTON_PRESS = 4,
	BUTTON_RELEASE = 5,
	DESTROY_NOTIFY = 17
}	t_event_type;

// EVENT MASKS ENUM
typedef enum e_event_mask
{
	KEYPRESSMASK = 1,
	KEYRELEASEMASK = 2,
	BUTTONPRESSMASK = 4,
	BUTTONRELEASEMASK = 8,
	STRUCNOTIFYMASK = 131072
}	t_event_mask;

// FRACTAL TYPE ENUM
typedef enum e_fractal_type
{
	JULIA,
	MANDELBROT,
	SIERPINSKI
}	t_fractal_type;

// MOUSE CODES ENUM
typedef enum e_mouse
{
	LEFT_CLICK = 1,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5
}	t_mouse;

// KEY CODES ENUM
typedef enum e_keys
{
	SPACE = 32,
	PLUS = 61,
	A = 97,
	C = 99,
	D = 100,
	H = 104,
	R = 114,
	S = 115,
	W = 119,
	ESC = 65307,
	LEFT = 65361,
	UP = 65362,
	RIGHT = 65363,
	DOWN = 65364,
	SHIFT = 65505
}	t_keys;

// typedef enum e_keys
// {
// 	SPACE = XK_space,
// 	PLUS = XK_plus,
// 	A = XK_A,
// 	C = XK_C,
// 	D = XK_D,
// 	H = XK_H,
// 	R = XK_R,
// 	S = XK_S,
// 	W = XK_W,
// 	ESC = XK_Escape,
// 	LEFT = XK_Left,
// 	UP = XK_Up,
// 	RIGHT = XK_Right,
// 	DOWN = XK_Down,
// 	SHIFT = XK_Shift_L
// }	t_keys;

// IMAGE STRUCTURE
typedef struct s_image
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}	t_image;

// VIEWPORT STRUCTURE
typedef struct s_view
{
	double			scale;
	double			scale_x;
	double			scale_y;
	double			center_x;
	double			center_y;
}	t_view;

// COMPLEX NUMBER STRUCTURE
typedef struct s_complex
{
	double			r;
	double			i;
}	t_complex;

// FRACTAL STRUCTURE
typedef struct s_fractal
{
	t_fractal_type	type;
	int				iteration_max;
	int				depth;
	t_view			view;
	t_complex		z;
	t_complex		c;
	t_complex		mouse;
}	t_fractal;

// COLOR STRUCTURE
typedef struct s_color
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	uint8_t			base_r;
	uint8_t			base_g;
	uint8_t			base_b;
	double			t;
	int				shift;
	t_color_theme	theme;
	char			*theme_name;
}	t_color;

// HUD STRUCTURE
typedef struct s_hud
{
	bool			visible;
	char			buffer[BUFFER_SIZE];
	int				x;
	int				start_y;
	int				txt_color;
	int				line_gap;
	int				width;
	int				height;
	int				bg_color;
	double			bg_opacity;
}	t_hud;

// DATA STRUCTURE
typedef struct s_fractol
{
	void			*mlx;
	void			*window;
	int				select_mode;
	t_image			img;
	t_fractal		f;
	t_color			color;
	t_hud			hud;
}	t_fractol;

// INITIALIZATION
int			is_int(const char *value);
void		viewport_init(t_view *view, t_fractal *f, t_image *img);
void		fractal_init(int argc, char **argv, t_fractal *f, t_fractol *data);
void		set_color_theme_name(t_color_theme *theme, char **theme_name);
void		data_init(int argc, char **argv, t_fractol *data, t_image *img);

// FRACTAL CALCULATIONS
t_complex	map_position_to_complex(int x, int y, t_image *img, t_view *view);
int			calculate_julia(t_fractal *f, t_image *img, int x, int y);
int			calculate_mandelbrot(t_fractal *f, t_image *img, int x, int y);
int			calculate_sierpinski(t_fractal *f, int x, int y);

// HUD
void		draw_hud_background(t_hud *hud, t_image *img);
void		render_hud(t_fractol *data, t_fractal *f, t_hud *hud);

// DRAWING
void		render_fractal(t_fractol *data, t_fractal *f);

// EVENTS HANDLERS
int			mouse_move(int x, int y, t_fractol *data);
int			mouse_press(int button, int x, int y, t_fractol *data);
int			key_press(int keycode, t_fractol *data);
int			key_release(int keycode, t_fractol *data);
int			close_window(t_fractol *data);

// USER CONTROLS
void		reset_view(t_fractal *f, t_image *img);
void		activate_selection_mode(t_fractol *data, t_fractal *f);
int			change_julia_cst(t_fractal *f, t_fractol *data, int x, int y);
void		change_color_theme(t_color *color, t_fractal *f);

// UTILS
int			clamp(int value, int min, int max);
void		free_split(char **s);
void		print_help(void);
void		clean_exit(int status, t_fractol *data);
void		error(const char *error_msg, int status, t_fractol *data);

#endif
