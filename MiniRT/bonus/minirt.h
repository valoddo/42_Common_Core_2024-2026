/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:41:34 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/29 14:59:35 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"

//window size
# define IMAGE_WIDTH 900
# define IMAGE_HEIGHT 600
# define ASPECT_RATIO 1.5
# define BACKGROUND 0x131B26

//keysym
# define KEY_ESC	65307
# define KEY_A	97
# define ARROW_LEFT	65361
# define KEY_W	119
# define ARROW_UP	65362
# define KEY_D	100
# define ARROW_RIGHT	65363
# define KEY_S	115
# define ARROW_DOWN	65364
# define KEY_Q 113
# define KEY_E 101
# define KEY_N 110
# define KEY_M 109
# define CAM 99
# define LIGHT 108

// usato come soglia per confronti di numeri in virgola mobile,
# define EPSILON 1e-6

//plane, sphere, cylinder, cone
# define SP 0
# define PL 1
# define CY 2
# define CO 3

//zoom
# define ZOOM_STEP 0.10
# define FOV_MIN 0.01
# define FOV_MAX 3.13
# define MOVE_STEP 10
# define ROTATE_STEP 0.1

typedef struct s_scene	t_scene;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef t_vector		t_point;

typedef struct s_quadratic_abc
{
	double	a;
	double	b;
	double	c;
}	t_quadratic_abc;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_color2
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_color2;

typedef struct s_ray
{
	t_point		origin;
	t_vector	dir;
}	t_ray;

typedef struct s_ambient_l
{
	t_color		color;
	double		ratio;
}	t_ambient_l;

typedef struct s_light
{
	t_point			pos;
	t_color			color;
	double			ratio;
	struct s_light	*next;
}	t_light;

typedef struct s_viewport
{
	t_point		pixel00;
	t_vector	delta_u;
	t_vector	delta_v;
}	t_viewport;

typedef struct s_camera
{
	t_point		pos;
	t_vector	vec;
	t_vector	forward;
	t_vector	right;
	t_vector	up;
	t_viewport	vp;
	double		fov;
}	t_camera;

typedef struct s_vp_size
{
	double	width;
	double	height;
}	t_vp_size;

typedef struct s_object
{
	int				id;
	t_point			pos;
	t_vector		dir;
	double			radius;
	double			height;
	double			angle;
	t_color			color;
	struct s_object	*next;
}	t_object;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_window
{
	void		*mlx_ptr;
	void		*window_ptr;
	t_img		img;
	t_scene		*scene;
}	t_window;

typedef struct s_hit
{
	double		t;
	t_object	*obj;
	t_point		point;
	t_vector	normal;
}	t_hit;

typedef struct s_scene
{
	t_ambient_l	ambient;
	t_camera	camera;
	t_light		*light;
	t_object	*objects;
	t_object	*selected_object;
	t_light		*selected_light;
	int			select_flag;	
	int			num_objects;
	int			num_light;
}	t_scene;

/********************************* vectors ************************************/

t_vector	ft_create_vec(double x, double y, double z);
t_point		ft_create_point(double x, double y, double z);
void		ft_fill_vec(t_point *new, double *vec);
void		ft_fill_point(t_point *new, double *xyz);
double		vec_len(t_vector v);

/***************************************** rays *******************************/

t_point		ray_at(t_ray *r, double t);
t_ray		ft_ray_from_2_points(t_point origin, t_point endpoint);
t_ray		generate_ray(t_camera cam, int x, int y);

/**************************** vector operations *******************************/

t_vector	vec_add(t_vector a, t_vector b);
t_vector	vec_sub(t_vector a, t_vector b);
t_vector	vec_mul(t_vector a, double t);
t_vector	vec_div(t_vector a, double t);
t_vector	vec_opposite(t_vector a);

/******************************* vector math **********************************/

double		dot_product(t_vector a, t_vector b);
t_vector	ft_cross_product(t_vector a, t_vector b);
t_vector	ft_normalize(t_vector v);
int			ft_is_normalized(double x, double y, double z);
t_vector	reflect_vector(t_vector light_dir, t_vector normal);

/******************************* camera ***************************************/

void		ft_setup_camera(t_camera *cam, double fov);

/****************************** viewport.c ************************************/

t_viewport	ft_setup_viewport(t_camera cam);

/****************************intersections*************************************/

double		ft_quadratic_equation(double a, double b, double c);
double		ft_sphere_intersection(t_ray *ray, t_object *sp);
double		ft_plane_intersection(t_ray *ray, t_object *pl);
double		ft_get_intersection_point(t_ray ray, t_object *obj);

/************************** cylinder ******************************************/

double		ft_cylinder_intersection(t_ray	*ray, t_object *cy);

/************************** cone ******************************************/

double		ft_cone_intersection(t_ray *ray, t_object *co);

/********************************* colors *************************************/

void		ft_create_color(t_color *new, int *rgb);
int			ft_t_color_to_int(unsigned char t, t_color c);
void		ft_put_pixel_to_img(t_img *img, int x, int y, unsigned int color);
t_color2	color_add(t_color2 c1, t_color2 c2);
t_color		color_clamp(t_color2 color);

/********************************* lighting **********************************/

t_color		ft_calculate_ambient(t_scene *scene, t_hit *hit);
t_color		ft_calculate_diffuse(t_hit *hit, t_light *light);
t_color		ft_calculate_specular(t_scene *scene, t_hit *hit, t_light *light);
t_color2	ft_char_to_int_color(t_color color);

/******************************** shadows.c ***********************************/

bool		ft_is_in_shadow(t_scene *s, t_point inte, \
			t_object *ta, t_light *light);
void		ft_calculate_phong_with_shadows(t_scene *scene, \
			t_hit *hit, t_light *light, t_color2 *acc);
int			ft_get_color(t_scene *scene, int x, int y);

/******************************** events.c ************************************/

void		ft_zoom_in(t_window	*win);
void		ft_zoom_out(t_window	*win);
t_hit		ft_find_clicked_object(t_scene *scene, int x, int y);
void		ft_click_select(t_window	*win, int x, int y);
void		ft_click_deselect(t_window	*win);

/**************************** translate_events ********************************/

void		ft_translate(t_window	*win, int key);

/***************************** rotate_events **********************************/

t_vector	ft_rotate_vector(t_vector v, t_vector axis, int direction);
t_vector	ft_get_rotation_axis(t_camera *cam, int key, int *direction);
void		ft_rotate_cam(t_window *win, int key);
void		ft_rotate_obj(t_window *win, int key);
void		ft_rotate(t_window	*win, int key);

/***************************** rotate_axis **********************************/

int			ft_set_x_axis(int key, t_vector *axis, int *direction);
int			ft_set_y_axis(int key, t_vector *axis, int *direction);
t_vector	ft_get_rotation_axis_global(int key, int *direction);

/********************************* main ***************************************/

int			ft_init_and_check_elements(char *file, t_scene *scene);
t_hit		ft_trace_ray(t_ray ray, t_object *tmp);
void		ft_init_scene(t_scene *scene);
void		ft_init_t_hit(t_hit *hit);

/********************************* checks *********************************/

int			ft_check_extention(char *file);
int			ft_check_file(char *file);
int			ft_check_items(char *array, t_scene *scene);
int			ft_check_elements(char *array, t_scene *scene);

/********************************* normal *********************************/

void		ft_cylinder_normal(t_hit *hit);
void		ft_cone_normal(t_hit *hit);
void		ft_point_normal(t_ray *ray, t_hit *hit);

/********************************* error_free *********************************/

int			ft_error(int code);
void		ft_free_array(char **array);
void		ft_free_scene(t_scene *scene);

/********************************* utils **************************************/

int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
int			count_lines(const char *file);
int			fill_array(char **array, const char *file, int rows);
char		**ft_create_array(const char *file);

/********************************* utils_2 ***********************************/

int			ft_arrlen(char **array);
int			ft_isspace(char c);
char		*ft_trim_and_space(char *str);
void		ft_print_selected(int i);

/********************************* atof ***************************************/

int			ft_atoi(char *str);
double		ft_dec(char *str);
double		ft_atof(char *str);

/********************************* split **************************************/

char		**ft_split(char *s, char c);

/********************************* window *************************************/

int			ft_init_window(t_window *win, t_scene *scene);
void		ft_render_img(t_window *win, t_scene *scene);
int			ft_window_event(int keycode, t_window *win);
int			ft_close_window(t_window *win);
int			ft_mouse_event(int button, int x, int y, t_window *win);

/********************************* parse **************************************/

int			ft_parse_rgb(char *tokens, int *rgb);
int			ft_parse_vec(char *tokens, double *vec);
int			ft_parse_point(char *tokens, double *xyz);

/********************************* check_items ********************************/

int			ft_check_ambient(char *array, t_scene *scene);
int			ft_check_camera(char *array, t_scene *scene);
int			ft_check_object(char *array, t_scene *scene);
int			ft_check_light(char *array, t_light *new_light);
char		**ft_tokens_creation(char *array);

/*************************** add_light_object ******************************/

int			ft_create_light(char *array, t_scene *scene);
int			ft_add_light(t_light *new_light, double ratio, \
			double *xyz, int *rgb);
void		ft_add_light_list(t_scene *scene, t_light *new_light);
int			ft_parse_object(char *array, t_object *new_obj);
void		ft_add_obj_list(t_scene *scene, t_object *new_obj);

/************************* add_sp_pl ********************************/

int			ft_check_sp(char *array, t_object *new_obj);
int			ft_add_sp(t_object *new_obj, double radius, double *xyz, int *rgb);
int			ft_check_pl(char *array, t_object *new_obj);
int			ft_add_pl(t_object *new_obj, double *vec, double *xyz, int *rgb);

/************************* add_cy_co ********************************/
int			ft_check_cy(char *array, t_object *new_obj);
int			ft_add_cy(t_object *new_obj, double *vec, double *xyz, int *rgb);
int			ft_check_co(char *array, t_object *new_obj);
int			ft_add_co(t_object *new_obj, double *vec, double *xyz, int *rgb);

#endif
