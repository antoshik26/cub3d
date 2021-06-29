//не трож дибил
int sprite_printing(t_win_list *win, t_map_list *map, t_list_main_hero_management *hero)
{
    t_list_item *sprite;
    double h_offset;
    double v_offset;
    int sprite_size;
    double a;

    //scrin_size = min(2000, map->height/sprite->distance_from_the_player);
    sprite = map->sprite;
    while (sprite)
    {
        if (sprite->visable == 1)
        {
            //printf("%f\n", sprite->distance_from_the_player);
            sprite->sprite_size = (double)map->width / (double)sprite->distance_from_the_player;
            //sprite->sprite_size = (map->height / sprite->distance_from_the_player) * 1 - (sprite->a - (hero->view_direction / 180 * 3.14)/(3.14 / 3.0 / 2.0));
            printf("%f\n", sprite->sprite_size);
            h_offset = (sprite->a - ((double)hero->view_direction / 180.0 * 3.14))/(3.14 / 3.0) * ((double)map->width) + ((double)map->width) / 2 - sprite->sprite_size / 2.0;
            printf("%f\n", h_offset);
            v_offset =  (double)map->height / 2.0 - sprite->sprite_size / 2.0;
            printf("%f\n", v_offset);
            //sort_sprite(win, map, hero);
            rendering_sprite(win, map, hero, h_offset, v_offset, sprite->sprite_size);
        }
        sprite = sprite->next;
    }
    reset_to_zero_sprite(win, map, hero);
    return (0);
}
//не трож дибил
int rendering_sprite(t_win_list *win, t_map_list *map, t_list_main_hero_management *hero, double h_offset, double v_offset, int sprite_size)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (i < sprite_size)
    {
        if (i + h_offset > 0 && i + h_offset < map->width)
        {
            j = 0;
            while (j < sprite_size)
            {
                if (j + v_offset > 0 && j + v_offset < map->height)
                {
                    my_mlx_pixel_put_3d(win, h_offset + i, v_offset + j, 0x00000000);
                }
                j++;
            }
        }
        i++;
    }
    return (0);
}




sprite->a = atan2(((float)sprite->position_y * -32.0) - (float)hero->position_y * -1, (((float)sprite->position_x) * -32) - (float)hero->position_x * -1);
        printf("%f\n", atan2(-2.0, 0));
        sprite->a = sprite->a * -1;
        printf("%f\n", sprite->a);
        hero_a = (double)hero->view_direction / 180.0 * 3.14 - 1.570796;
        printf("%f\n", hero_a);
        printf("%f\n", sprite->a - hero_a);
        while (sprite->a >  M_PI) 
        {
            sprite->a -= 2*M_PI; 
        }
        while (sprite->a< -M_PI) 
        {
            sprite->a += 2*M_PI;
        }
        printf("%f\n", sprite->a);
        sprite->h = sqrt(pow(hero->position_x - (sprite->position_x - 1 * 32), 2) + pow(hero->position_y - (sprite->position_y - 1 * 32), 2));
        sprite->distance_from_the_player = sprite->h / 32;// * cos(a - ((double)hero->view_direction / 180 * 3.14));
        sprite->sprite_size = (double)map->width / (double)sprite->distance_from_the_player;
        printf("%f\n", sprite->sprite_size);
        h_offset = (sprite->a  - hero_a)/(3.14 / 3.0) * ((double)map->width) + ((double)map->width) / 2 - map->sprite->sprite_size / 2;
        printf("%f\n", h_offset);
        v_offset =  (double)map->height / 2.0 - sprite->sprite_size / 2.0;
            //printf("%f\n", v_offset);
        sort_sprite(win, map, hero);
        rendering_sprite(win, map, hero, h_offset, v_offset, sprite->sprite_size);
        sprite = sprite->next;


/*
test: 
		gcc -g test.c -L libft -lft -L$(OPENGL) -lmlx -framework OpenGL -framework AppKit 

parser:
		gcc -g ft_run_game.c ./parser_map/map_parser.c ./validation/validation_map.c ./create_map/ft_create_map.c ./auxiliary_functions/additional_features.c ./main_hero/maint_hero_management.c ./rendering_pictures/rendering_pictures.c ./create_map/ft_create_map_3d.c ./create_map/ft_like_compass.c ./npc/ft_create_npc.c ./parser_map/create_texture.c ./parser_map/gnl_reader.c ./parser_map/parser_collor.c ./gnl/gnl.a -I ./include -L libft -lft -L$(OPENGL) -lmlx -framework OpenGL -framework AppKit
	
map:
		gcc -g ft_run_game ./parser_map/map_parser.c ./main_hero/maint_hero_management.c ./create_map/ft_create_map.c ./auxiliary_functions/additional_features.c ./validation/validation_map.c ./gnl/gnl.a -I ./include -L libft -lft -L$(OPENGL) -lmlx -framework OpenGL -framework AppKit
*/


/*
int validation_p_f(t_map_list *map)
{
    int i;
    int j;
    int k;
    int key;

    key = 1;
    i = 0;
    j = 0;
    while (map->p_f[k])
        k++;
    i = 0;
    while (map->p_f[i])
    {
        if (i == 0)
        {
            while(map->p_f[i][j])
            {
                if (map->p_f[i][j] != '1')
                    key = 0;
                j++;
            }
        }
        if (i > 0 && i < k)
        {
            if (map->p_f[i][j] != '1' && map->p_f[i][ft_strlen(map->p_f[i])] != '1')
                key = 0;
        }
        j = 0;
        if (i == k)
        {
            while(map->p_f[i][j])
            {
                if (map->p_f[i][j] != '1')
                    key = 0;
                j++;
            }
        }
        i++;
    }
    if (key == 0)
        return (-1);
    return(0);
}
*/
/*
      if (map->p_f[i][j] == 0)
        {
            if (map->p_f[i + 1][j] != '\0' && map->p_f[i][j + 1] != ' ')
            {
                if (map->p_f[i][j + 1] != '\0' && map->p_f[i][j + 1] != ' ')
                {
                    if (map->p_f[i - 1][j] != '\0'&& map->p_f[i - 1][j] != ' ')
                    {
                        if (map->p_f[i][j - 1] != '\0'&& map->p_f[i][j - 1] != ' ')
                        {
                            if (map->p_f[i + 1][j + 1] != '\0'&& map->p_f[i + 1][j + 1] != ' ')
                            {
                                if (map->p_f[i - 1][j - 1] != '\0'&& map->p_f[i - 1][j - 1] != ' ')
                                {
                                    if (map->p_f[i + 1][j - 1] != '\0'&& map->p_f[i + 1][j - 1] != ' ')
                                    {
                                        if (map->p_f[i - 1][j + 1] != '\0'&& map->p_f[i - 1][j + 1] != ' ')
                                        {
                                            return(0);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
                return(-1);
        }
            
*/

/*
               if (map->p_f[i + 1][j] != '\0' && map->p_f[i][j + 1] != ' ')
                    if (map->p_f[i][j + 1] != '\0' && map->p_f[i][j + 1] != ' ')
                        if (map->p_f[i - 1][j] != '\0'&& map->p_f[i - 1][j] != ' ')
                            if (map->p_f[i][j - 1] != '\0'&& map->p_f[i][j - 1] != ' ')
                                if (map->p_f[i + 1][j + 1] != '\0'&& map->p_f[i + 1][j + 1] != ' ')
                                    if (map->p_f[i - 1][j - 1] != '\0'&& map->p_f[i - 1][j - 1] != ' ')
                                        if (map->p_f[i + 1][j - 1] != '\0'&& map->p_f[i + 1][j - 1] != ' ')
                                            if (map->p_f[i - 1][j + 1] != '\0'&& map->p_f[i - 1][j + 1] != ' ')
                                                key = 0;
*/


/*
 printf("\n");
        j = 0;
        while (map->p_f[i][j])
        {
            if (j == )
            printf("%c", map->p_f[i][j]);
            if (map->p_f[i][j] == '0' || map->p_f[i][j] == 'N' || map->p_f[i][j] == 'W' || map->p_f[i][j] == 'E' || map->p_f[i][j] == 'S')
            {
                if (map->p_f[i + 1][j] != '\0' && map->p_f[i][j + 1] != ' ')
                {
                    if (map->p_f[i][j + 1] != '\0' && map->p_f[i][j + 1] != ' ')
                    {
                        if (map->p_f[i - 1][j] != '\0'&& map->p_f[i - 1][j] != ' ')
                        {
                            if (map->p_f[i][j - 1] != '\0'&& map->p_f[i][j - 1] != ' ')
                            {
                                if (map->p_f[i + 1][j + 1] != '\0'&& map->p_f[i + 1][j + 1] != ' ')
                                {
                                    if (map->p_f[i - 1][j - 1] != '\0'&& map->p_f[i - 1][j - 1] != ' ')
                                    {
                                        if (map->p_f[i + 1][j - 1] != '\0'&& map->p_f[i + 1][j - 1] != ' ')
                                        {
                                            if (map->p_f[i - 1][j + 1] != '\0'&& map->p_f[i - 1][j + 1] != ' ')
                                            {
                                                key = 1;
                                            }
                                            else
                                            {
                                                key = 0;
                                            }
                                        }
                                        else
                                        {
                                            key = 0;
                                        }
                                    }
                                    else
                                    {
                                        key = 0;
                                    }
                                }
                                else
                                {
                                    key = 0;
                                }
                            }
                            else
                            {
                                key = 0;
                            }
                        }
                        else
                        {
                            key = 0;
                        }
                    }
                    else
                    {
                        key = 0;
                    }
                }
                else
                {
                    key = 0;
                }
            }
            */

