#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
//#import <AppKit/NSScreen.h>

static int count;

//отрисовка картинки
/*
typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    void    *imege;
    t_data  img;
    t_data  img_2;
    int height;
    int width;
    int a;
    int b;
    int color;
    int len;

    a = 0;
    b = 0;
    len = 2;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img_2.img = mlx_new_image(mlx, 1920, 1080);
    img_2.addr = mlx_get_data_addr(img_2.img, &img_2.bits_per_pixel, &img_2.line_length, &img_2.endian);
    img.img = mlx_xpm_file_to_image(mlx, "textures/texture_1.xpm", &(width), &(height));
    if (img.img == NULL)
		exit(1);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (a < width)
    {
        b = 0;
        while (b < height)
        {
            //my_mlx_pixel_put(&img_2, a / 2, b / 2, *(unsigned int*)(img.addr + (a * img.line_length + (b * img.bits_per_pixel / 8))));
            my_mlx_pixel_put(&img_2, a/5, b/5, *(unsigned int*)(img.addr + (b * img.line_length + a * (img.bits_per_pixel / 8))));
            b++;
        }
        a++;
    }

    int k;
    int z;

    k = 0;
    z = 0;
    while(k < 1000)
    {
        z = 0;
        while (z < 10)
        {
            my_mlx_pixel_put(&img_2, (((0 * z) + z) + 5), (((0 * k) + k) + 5), 0x00FF0000);
            z++;
        }
        k++;
    }
    mlx_put_image_to_window(mlx, mlx_win, img_2.img, 0, 0);
    mlx_loop(mlx);
    return (0);
}
*/

/*
11111
10001
10N01
11111
*/
//работа с клавиатурой и мышью
/*
typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;

typedef struct  t_all_game_list
{
        float width;
        float hight;
        int pre_x;
        int pre_y;
        t_vars *vars;

}               t_all_game_list;

int            ft_close(int keycode, t_vars *vars)
{
    int key;
    key = keycode;
    count = count + 1;
    //mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

int check_mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
    int mouse;
    mouse = mousecode;
    return (0);
}

int changes_view_direction(t_all_game_list *game)
{
    int x; 
    int y;
    int a;
    int b;

    mlx_mouse_get_pos(game->vars->win, &x, &y);
    if ((1920 / 2) != x)
    {
        if ((1920 / 2) > x)
        {
            a = 1;
        }
        else
        {
            b = 1;
        }
    }
    mlx_mouse_move(game->vars->win, 1920 / 2, 1080 / 2);
    return (0);
}

int gaming(t_all_game_list *game)
{
    changes_view_direction(game);
    return (0);
}

int end_game(t_all_game_list *game)
{
    mlx_destroy_window(game->vars->mlx, game->vars->win);
    exit(EXIT_SUCCESS);
}

int             main(void)
{
    t_vars    vars;
    t_all_game_list game;
    game.vars = &vars;
    int x;
    int pre_x;
    int y;
    int pre_y;
    int width = 5120;
    int hight = 2880;    

    pre_x = 0;
    pre_y = 0;
    vars.mlx =mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
    mlx_mouse_hook(vars.win, check_mouse_hook, &vars);
    mlx_get_screen_size(&width, &hight);
    //mlx_get_screen_size(vars.mlx, &width, &hight);
    game.width = width;
    game.hight = hight;
    //mlx_mouse_get_pos(vars.win, &x, &y);
    mlx_mouse_move(vars.win, 1920 / 2, 1080 / 2);
    mlx_hook(vars.win, 17, 1, end_game, &game);
    mlx_loop_hook(vars.mlx, gaming, &game);
    mlx_loop(vars.mlx);
}
*/
//отрисовка 1 полоски текстуры разной высоты

typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;

typedef struct  s_pictures
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         width;
    int         height;
    float       kef_width;
    float       kef_height;
}               t_pictures;

void            my_mlx_pixel_put(t_pictures *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


int             main(void)
{
    t_vars    vars;
    t_pictures win;
    t_pictures texture;
    t_pictures texture_2;
    int width_win = 1920;
    int height_win = 1080;
    int width_texture = 0;
    int height_texture = 0;
    int i;
    int j;
    int height_rendering = 540;
    float h;
    float height_scy;
    float height_floor;

    i = 0;
    j = 0;
    vars.mlx =mlx_init();
    win.width = width_win;
    win.height = height_win;
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    win.img = mlx_new_image(vars.mlx, win.width, win.height);
    win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length, &win.endian);
    texture.img = mlx_xpm_file_to_image(vars.mlx, "textures/sprit.xpm", &(width_texture), &(height_texture));
    texture.width = width_texture;
    texture.height = height_texture;
    if (texture.img == NULL)
		exit(1);
    texture.addr = mlx_get_data_addr(texture.img, &texture.bits_per_pixel, &texture.line_length, &texture.endian);
    if (texture.width != win.width)
        texture.kef_width = (float)texture.width / (float)win.width;
    else
        texture.kef_width = 1;
    if (texture.height != win.height)
        texture.kef_height = (float)texture.height / (float)win.height;
    else
        texture.kef_height = 1;
    texture.kef_width = 1;
    texture_2.img = mlx_new_image(vars.mlx, win.width, win.height);
    texture_2.addr = mlx_get_data_addr(texture_2.img, &texture_2.bits_per_pixel, &texture_2.line_length, &texture_2.endian);
    h = 10;
    /*
    while (j < (texture.width))
    {
        i = 0;
        while(i < (texture.height))
        {
            my_mlx_pixel_put(&texture_2, (j / texture.kef_height), (i / (texture.kef_height * h)), *(unsigned int*)(texture.addr + (i * texture.line_length + j * (texture.bits_per_pixel / 8))));
            i++;
        }
        j++;
    }*/
    height_scy = (win.height - (win.height / h)) / 2;
    height_floor = (win.height - (win.height / h)) / 2;
    j = 0;
    while (j < 1920)
    {
        i = 0;
        while (i < height_scy)
        {
            my_mlx_pixel_put(&win, j, i, 0x00FF0000);
            i++;
        }
        while (i < 1080 / h + height_scy)
        {
            //my_mlx_pixel_put(&texture, i/5, j/5, *(unsigned int*)(img.addr + (j * img.line_length + i * (img.bits_per_pixel / 8))));
            my_mlx_pixel_put(&win, j, i, *(unsigned int*)(texture.addr + ((int)((i - height_scy) / (texture.kef_height * h)) * texture_2.line_length + ((int)(j / texture.kef_height) * (texture_2.bits_per_pixel / 8)))));
            i++;
        }
        while (i < 1080)
        {
            my_mlx_pixel_put(&win, j, i, 0x0000FF00);
            i++;
        }
        j++;
    }
    j = 0;
    while (j < 1920 / h)
    {
        i = height_scy;
        while (i < 1080 / h + height_scy)
        {
            my_mlx_pixel_put(&win, j, i, *(unsigned int*)(texture.addr + (int)((i - height_scy) * texture.kef_height * h) * texture.line_length + (int)(j * texture.kef_height * h) * (texture.bits_per_pixel / 8)));
            //my_mlx_pixel_put(&win, (j / texture.kef_height), (i / (texture.kef_height * h)), *(unsigned int*)(texture.addr + (i * texture.line_length + j * (texture.bits_per_pixel / 8))));
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(vars.mlx, vars.win, win.img, 0, 0);
    mlx_loop(vars.mlx);
}

//atan2
/*
int main (void)
{
    double x;
    double y;
    double a;

    x = -10;
    y = 15;
    a = atan2(y, x) * 180 / 3.14;
    printf("%f\n", a);
    return (0);
}
*/

/*
int main(void)
{
    int fd;
    char  *file = "./screenshot.bmp";
    int padsize;
    padsize = (4 - ((int)p->mlx->screen_w * 3) % 4) % 4;
    if ((fd = open("screenshot.bmp", O_WRONLY |
	O_CREAT, 0777 | O_TRUNC | O_APPEND)) < 0)

    return (0);
}
*/

//fsanitize address