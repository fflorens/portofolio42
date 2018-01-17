#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/20 19:09:59 by abanvill          #+#    #+#              #
#    Updated: 2014/06/26 21:36:30 by abanvill         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME    = gfx

SERV	:= $(shell pwd | grep -o 'zfs-student-[0-5]')
USER	:= $(shell whoami)

INCDIR	= inc/
SRCDIR	= src/
OBJDIR	= obj/src

LIBFTDIR  = ../libft/
LIBFTINC  = $(LIBFTDIR)

BREWDIR = /nfs/$(SERV)/users/2013/$(USER)/.brew/lib/
BREWINC = /nfs/$(SERV)/users/2013/$(USER)/.brew/include/

LIBDIR = lib/

LIBSDL = -L$(LIBDIR) -lSDL -lSDLmain -lSDL_TTF -lSDL_mixer

FLAGS_INCLUDES = -I$(INCDIR) -I$(LIBFTINC) -I$(BREWINC)
CFLAGS = $(FLAGS_ERROR) $(FLAGS_INCLUDES) $(FLAG_GDB)
LDFLAGS = -L$(LIBFTDIR) -lft $(FLAG_GDB) $(LIBSDL) $(FRAMEWORK) -lpthread
FRAMEWORK = -framework GLUT -framework OpenGL -framework Cocoa

FLAGS_ERROR = -Wall -Werror -Wextra

SRC		 = calc.cpp
SRC		+= case.cpp
SRC		+= char.cpp
SRC		+= draw.cpp
SRC		+= free.cpp
SRC		+= gets.cpp
SRC		+= init.cpp
SRC		+= keys.cpp
SRC		+= load.cpp
SRC		+= link.cpp
SRC		+= main.cpp
SRC		+= play.cpp
SRC		+= sets.cpp

SRC		+= client.cpp
SRC		+= read.cpp
SRC		+= write.cpp
SRC		+= fn.cpp
SRC		+= ft_strjcat.cpp
SRC		+= ft_strjoin.cpp
SRC		+= ft_truncate.cpp
SRC		+= ft_strsub.cpp

SRC		+= debug.cpp

OBJ = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

$(OBJDIR)/%.o: $(addprefix $(SRCDIR), %.cpp)
	@mkdir -p `dirname $@`
	$(CC) $(CFLAGS) -c $< -o $@

CC = /usr/bin/clang++
export CC
RMF = rm -rf

all: $(NAME)

lib:
	$(MAKE) -C $(LIBFTDIR) FLAG_GDB=$(FLAG_GDB)

install:
	mkdir -p lib/
	mkdir -p inc/SDL/
	brew update
	brew install sdl
	cp -rf $(BREWDIR)* lib/
	cp -rf $(BREWINC)SDL/* inc/SDL/
	brew install sdl_mixer
	brew link sdl_mixer
	cp -rf $(BREWINC)SDL/* inc/SDL/
	cp -rf $(BREWDIR)* lib/
	brew unlink sdl && brew link --overwrite sdl_mixer sdl
	brew install sdl_ttf
	brew link sdl_ttf
	cp -rf $(BREWINC)SDL/* inc/SDL/
	cp -rf $(BREWDIR)* lib/

$(NAME): $(OBJ)
	@$(MAKE) lib
	@$(MAKE) depend
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

gdb:
	$(MAKE) re FLAG_GDB=-g

clean:
	$(RMF) $(OBJ)
	$(RMF) $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) $@ FLAG_GDB=$(FLAG_GDB)
	$(RMF) $(NAME)

clear: fclean
	@rm -rf lib/
	@rm -rf inc/SDL

uninstall:
	brew uninstall sdl_mixer
	brew uninstall sdl
	brew uninstall sdl_ttf

re: fclean all

depend:
	@makedepend -pobj/ -Y. $(FLAGS_INCLUDES) $(addprefix $(SRCDIR)/, $(SRC)) 2>/dev/null
	@$(RMF) Makefile.bak

.PHONY: depend clear clean fclean re all gdb lib
# DO NOT DELETE

obj/src//calc.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//calc.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//calc.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//calc.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//calc.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//calc.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//calc.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//calc.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//calc.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//calc.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//calc.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//calc.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//calc.o: inc/SDL/SDL_types.h
obj/src//case.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//case.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//case.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//case.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//case.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//case.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//case.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//case.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//case.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//case.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//case.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//case.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//case.o: inc/SDL/SDL_types.h
obj/src//char.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//char.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//char.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//char.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//char.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//char.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//char.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//char.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//char.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//char.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//char.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//char.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//char.o: inc/SDL/SDL_types.h
obj/src//draw.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//draw.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//draw.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//draw.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//draw.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//draw.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//draw.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//draw.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//draw.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//draw.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//draw.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//draw.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//draw.o: inc/SDL/SDL_types.h inc/write.h inc/struct_reseau.h
obj/src//free.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//free.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//free.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//free.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//free.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//free.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//free.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//free.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//free.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//free.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//free.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//free.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//free.o: inc/SDL/SDL_types.h
obj/src//gets.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//gets.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//gets.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//gets.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//gets.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//gets.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//gets.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//gets.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//gets.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//gets.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//gets.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//gets.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//gets.o: inc/SDL/SDL_types.h
obj/src//init.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//init.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//init.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//init.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//init.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//init.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//init.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//init.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//init.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//init.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//init.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//init.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//init.o: inc/SDL/SDL_types.h inc/SDL/SDL_ttf.h inc/SDL/SDL.h
obj/src//init.o: inc/SDL/SDL_thread.h inc/SDL/SDL_timer.h inc/reseau.h
obj/src//init.o: inc/struct_reseau.h
obj/src//keys.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//keys.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//keys.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//keys.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//keys.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//keys.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//keys.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//keys.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//keys.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//keys.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//keys.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//keys.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//keys.o: inc/SDL/SDL_types.h
obj/src//load.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//load.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//load.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//load.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//load.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//load.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//load.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//load.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//load.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//load.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//load.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//load.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//load.o: inc/SDL/SDL_types.h
obj/src//link.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//link.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//link.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//link.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//link.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//link.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//link.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//link.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//link.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//link.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//link.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//link.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//link.o: inc/SDL/SDL_types.h
obj/src//main.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//main.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//main.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//main.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//main.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//main.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//main.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//main.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//main.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//main.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//main.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//main.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//main.o: inc/SDL/SDL_types.h inc/SDL/SDL_thread.h
obj/src//play.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//play.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//play.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//play.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//play.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//play.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//play.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//play.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//play.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//play.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//play.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//play.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//play.o: inc/SDL/SDL_types.h
obj/src//sets.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//sets.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//sets.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//sets.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//sets.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h
obj/src//sets.o: inc/SDL/SDL_thread.h inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//sets.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//sets.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//sets.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h
obj/src//sets.o: inc/SDL/SDL_joystick.h inc/SDL/SDL_quit.h
obj/src//sets.o: inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//sets.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//sets.o: inc/SDL/SDL_types.h
obj/src//client.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//client.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//client.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//client.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h
obj/src//client.o: inc/SDL/SDL_error.h inc/SDL/SDL_endian.h
obj/src//client.o: inc/SDL/SDL_mutex.h inc/SDL/SDL_thread.h
obj/src//client.o: inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//client.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//client.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//client.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h
obj/src//client.o: inc/SDL/SDL_video.h inc/SDL/SDL_joystick.h
obj/src//client.o: inc/SDL/SDL_quit.h inc/SDL/SDL_loadso.h
obj/src//client.o: inc/SDL/SDL_timer.h inc/SDL/SDL_version.h
obj/src//client.o: inc/SDL/SDL_mixer.h inc/SDL/SDL_types.h inc/read.h
obj/src//client.o: inc/struct_reseau.h inc/write.h
obj/src//read.o: inc/reseau.h inc/struct_reseau.h inc/read.h inc/write.h
obj/src//read.o: inc/libft.h inc/fn.h
obj/src//write.o: inc/reseau.h inc/struct_reseau.h inc/write.h inc/libft.h
obj/src//write.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//write.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//write.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//write.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h
obj/src//write.o: inc/SDL/SDL_error.h inc/SDL/SDL_endian.h
obj/src//write.o: inc/SDL/SDL_mutex.h inc/SDL/SDL_thread.h
obj/src//write.o: inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//write.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//write.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//write.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h
obj/src//write.o: inc/SDL/SDL_video.h inc/SDL/SDL_joystick.h
obj/src//write.o: inc/SDL/SDL_quit.h inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//write.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//write.o: inc/SDL/SDL_types.h
obj/src//fn.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//fn.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//fn.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//fn.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h inc/SDL/SDL_error.h
obj/src//fn.o: inc/SDL/SDL_endian.h inc/SDL/SDL_mutex.h inc/SDL/SDL_thread.h
obj/src//fn.o: inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h inc/SDL/SDL_cpuinfo.h
obj/src//fn.o: inc/SDL/SDL_events.h inc/SDL/SDL_active.h
obj/src//fn.o: inc/SDL/SDL_keyboard.h inc/SDL/SDL_keysym.h
obj/src//fn.o: inc/SDL/SDL_mouse.h inc/SDL/SDL_video.h inc/SDL/SDL_joystick.h
obj/src//fn.o: inc/SDL/SDL_quit.h inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//fn.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h inc/SDL/SDL_types.h
obj/src//ft_strjcat.o: inc/libft.h
obj/src//ft_strjoin.o: inc/libft.h
obj/src//ft_truncate.o: inc/libft.h
obj/src//ft_strsub.o: inc/libft.h
obj/src//debug.o: inc/zproject.h inc/SDL/SDL.h inc/SDL/SDL_main.h
obj/src//debug.o: inc/SDL/SDL_stdinc.h inc/SDL/SDL_config.h
obj/src//debug.o: inc/SDL/SDL_platform.h inc/SDL/begin_code.h
obj/src//debug.o: inc/SDL/close_code.h inc/SDL/SDL_audio.h
obj/src//debug.o: inc/SDL/SDL_error.h inc/SDL/SDL_endian.h
obj/src//debug.o: inc/SDL/SDL_mutex.h inc/SDL/SDL_thread.h
obj/src//debug.o: inc/SDL/SDL_rwops.h inc/SDL/SDL_cdrom.h
obj/src//debug.o: inc/SDL/SDL_cpuinfo.h inc/SDL/SDL_events.h
obj/src//debug.o: inc/SDL/SDL_active.h inc/SDL/SDL_keyboard.h
obj/src//debug.o: inc/SDL/SDL_keysym.h inc/SDL/SDL_mouse.h
obj/src//debug.o: inc/SDL/SDL_video.h inc/SDL/SDL_joystick.h
obj/src//debug.o: inc/SDL/SDL_quit.h inc/SDL/SDL_loadso.h inc/SDL/SDL_timer.h
obj/src//debug.o: inc/SDL/SDL_version.h inc/SDL/SDL_mixer.h
obj/src//debug.o: inc/SDL/SDL_types.h
