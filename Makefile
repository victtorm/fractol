FRACTOL_FILES = check_julia.c check_mandelbrot.c fractal_init.c fractal_img.c math_utils.c fractal_events.c events_utils.c koch.c koch_events.c koch_img.c koch_utils.c
OBJS = ${FRACTOL_FILES:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
NAME = fractol
MINILIBXD = ./minilibx-linux
MINILIBX = ./minilibx-linux/libmlx.a


all:		${NAME}

${NAME}:	${OBJS} ${MINILIBX}
			${CC} ${CFLAGS} main.c ${OBJS} -lmlx_Linux -L${MINILIBXD} -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

${MINILIBX}:	
		make -C ${MINILIBXD}

#${MINILIBXD}:
#	@git clone http://github.com/42Paris/minilibx-linux.git
bonus: ${CHECKER} 

${CHECKER}:		${OBJSB}
				${CC} ${CFLAGS} ${OBJS} ${OBJSB} ${MINILIBX} -o ${CHECKER}

clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME} ${CHECKER}

re:			fclean ${NAME}

.phony: all clean fclean re bonus
