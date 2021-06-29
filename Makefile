NAME = cub3d
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = include
OPTION = -I include
INCLUDEH = -I minilibx_opengl
AUXILIARY_FUNCTIONS = auxiliary_functions
CREATE_MAP = create_map
MAIN_HERO = main_hero
MAP_PARSER = parser_map
RENDERING_PICTURES = rendering_pictures
SCREENSHOTS = screenshots
VALIDATION = validation
GNL = gnl
LIBA = libft
OPENGL = minilibx_opengl
FRAMEWORK = -framework OpenGL -framework AppKit
II = npc
SRCS =	$(AUXILIARY_FUNCTIONS)/additional_features.c \
		$(AUXILIARY_FUNCTIONS)/additional_features_utils.c \
		$(AUXILIARY_FUNCTIONS)/additional_features_utils_more_plus.c\
		$(AUXILIARY_FUNCTIONS)/additional_features_utils_more.c \
		$(MAIN_HERO)/maint_hero_management.c \
		$(MAIN_HERO)/maint_hero_muvment.c \
		$(MAIN_HERO)/main_her_management_utils.c \
		$(CREATE_MAP)/ft_create_map.c \
		$(CREATE_MAP)/ft_create_map_3d.c \
		$(CREATE_MAP)/ft_create_map_3d_utils.c \
		$(CREATE_MAP)/ft_like_compass.c \
		$(MAP_PARSER)/create_texture.c \
		$(MAP_PARSER)/parser_collor.c \
		$(MAP_PARSER)/map_parser.c \
		$(MAP_PARSER)/gnl_reader.c \
		$(RENDERING_PICTURES)/rendering_pictures.c \
		$(VALIDATION)/validation_map.c \
		$(VALIDATION)/validation_map_utils.c \
		$(II)/ft_create_npc.c \
		$(II)/ft_create_npc_utils.c \
		$(SCREENSHOTS)/create_screenshot.c \
		ft_run_game.c 
		

OBJS =		${SRCS:.c=.o}

%.o: %.c
	$(CC) -o3 $(FLAGS) -I include $(INCLUDEH) -c $<  -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			@make re -C libft	
			@cp $(LIBA)/libft.a ./$(NAME)
			@make re -C minilibx_opengl
			@cp $(OPENGL)/libmlx.a ./$(NAME)
			@make re -C gnl
			@cp $(GNL)/gnl.a ./$(NAME)
			gcc -o -o3 $(NAME) $(OBJS) -I include $(INCLUDEH) ./gnl/gnl.a -L libft -lft -L$(OPENGL) -lmlx -framework OpenGL -framework AppKit

parser:
		gcc  -g ft_run_game.c ./auxiliary_functions/additional_features_utils.c ./auxiliary_functions/additional_features_utils_more.c ./auxiliary_functions/additional_features_utils_more_plus.c ./validation/validation_map_utils.c ./screenshots/create_screenshot.c ./npc/ft_create_npc_utils.c ./create_map/ft_create_map_3d_utils.c ./main_hero/main_her_management_utils.c ./main_hero/maint_hero_muvment.c ./parser_map/map_parser.c ./validation/validation_map.c ./create_map/ft_create_map.c ./auxiliary_functions/additional_features.c ./main_hero/maint_hero_management.c ./rendering_pictures/rendering_pictures.c ./create_map/ft_create_map_3d.c ./create_map/ft_like_compass.c ./npc/ft_create_npc.c ./parser_map/create_texture.c ./parser_map/gnl_reader.c ./parser_map/parser_collor.c ./gnl/gnl.a -I ./include $(INCLUDEH) -L libft -lft -L$(OPENGL) -lmlx -framework OpenGL -framework AppKit
	

clean:		
			rm -f $(OBJS)

fclean:	
			rm -f $(OBJS) $(NAME)

re:			fclean all

.PHONY:		
			all clean fclean re