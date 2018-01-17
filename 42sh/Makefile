# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/26 13:54:32 by nmokrane          #+#    #+#              #
#    Updated: 2014/03/27 22:49:52 by fflorens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = 42sh

# change these to set the proper directories where each files shoould be
SRCDIR  = src
OBJDIR  = obj
INCDIR  = includes

LIBDIR  = libft
LIBINC  = $(LIBDIR)/$(INCDIR)
BOONDIR = nboon
BOONINC = $(BOONDIR)/$(INCDIR)

INCLUDE = -I$(INCDIR) -I$(LIBINC) -I$(BOONINC)

# error flags
ERROR_BASE    = -Wall -Werror -Wextra
ERROR_CLASSIC = -ansi -pedantic-errors -pedantic
ERROR_EXTRA	  =	-fstack-protector-all -Wshadow -Wunreachable-code -Winline \
				-Wstrict-prototypes -Wmissing-prototypes -W -Wstack-protector \
				-Wunreachable-code -Wunknown-pragmas \
				-Wdeclaration-after-statement -Wold-style-definition \
				-Wmissing-field-initializers
ERROR_EXTREME = -Wwrite-strings
FLAGS_ERROR   = $(ERROR_BASE)
ifeq ($(ERROR), classic)
	FLAGS_ERROR +=	$(ERROR_CLASSIC)
endif
ifeq ($(ERROR), extra)
	FLAGS_ERROR +=	$(ERROR_CLASSIC) $(ERROR_EXTRA)
endif
ifeq ($(ERROR), extreme)
	FLAGS_ERROR +=	$(ERROR_CLASSIC) $(ERROR_EXTRA) $(ERROR_EXTREME)
endif

# all flags
ifeq ($(config), debug)
  CFLAGS = $(INCLUDE) -g3
else
  CFLAGS = $(INCLUDE) $(FLAGS_ERROR)
endif
LDFLAGS = -L$(LIBDIR) -L$(BOONDIR) -lft -lnboon

SRC		= \
		  main.c \
		  env.c \
		  getvar.c \
		  error.c \
		  rebuildenv.c \
		  signals.c \
		  option.c \
		  \
		  completion/completion.c \
		  completion/callback.c \
		  completion/file.c \
		  completion/bin.c \
		  completion/display.c \
		  completion/util.c \
		  \
		  structs/command.c \
		  structs/pipeline.c \
		  structs/process.c \
		  structs/redirector.c \
		  \
		  lexer/lexer.c \
		  lexer/lexer_processing.c \
		  lexer/lexer_tool.c \
		  \
		  parser/command.c \
		  parser/pipeline.c \
		  parser/process.c \
		  parser/redirector.c \
		  parser/error.c \
		  \
		  exec/build_process.c \
		  exec/build_redirector.c \
		  exec/exec_command.c \
		  exec/exec_pipeline.c \
		  exec/exec_process.c \
		  exec/exec_builtin.c \
		  \
		  builtins/builtin_loader.c \
		  builtins/cd.c \
		  builtins/env.c \
		  builtins/exit.c \
		  builtins/pwd.c \
		  builtins/setenv.c \
		  builtins/unsetenv.c \
		  builtins/echo.c \
		  builtins/history.c \
		  builtins/qexclamation.c \
		  builtins/w.c \
		  builtins/yes.c \
		  \
		  dynvars/dynvar_loader.c \
		  dynvars/random.c \
		  dynvars/seconds.c \
		  dynvars/ps1.c \
		  dynvars/ps2.c \
		  dynvars/sh_histfile.c \
		  dynvars/sh_histsize.c \
		  dynvars/ifs.c \
		  dynvars/char_question.c \
		  dynvars/char_underscore.c \
		  dynvars/char_dollar.c \
		  \
		  hash/hash_function.c \
		  hash/chainhash_init.c \
		  hash/chainhash.c \
		  \
		  array/array.c \
		  array/array_sort.c \
		  array/array_util.c \
		  \
		  core/core.c \
		  core/path_list.c \
		  \
		  option/argv.c \
		  option/argv_parser.c \
		  \
		  utils/closepipe.c \
		  utils/abspath.c \
		  utils/expanduser.c \
		  utils/realpath.c \
		  utils/joinpath.c \
		  utils/expandvar.c \
		  utils/globalize.c

ifndef CC
  CC = /usr/bin/clang
endif

ifndef config
  config = release
endif
export config
export OPTI
export CC

OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

lib:
	$(MAKE) depend
	$(MAKE) -C $(LIBDIR)
	$(MAKE) -C $(BOONDIR)

$(NAME): $(OBJ)
	$(MAKE) lib
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJDIR)/%.o: $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p `dirname $@`
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBDIR) $@
	$(MAKE) -C $(BOONDIR) $@
	/bin/rm -rf $(OBJ)
	for d in $(OBJ); \
		do echo "$$d"; \
		@rmdir `dirname "$$d"` 2>/dev/null || true; \
	done;
	@rmdir $(OBJDIR) 2>/dev/null || true

fclean: clean
	$(MAKE) -C $(LIBDIR) $@
	$(MAKE) -C $(BOONDIR) $@
	/bin/rm -f $(NAME)

re: fclean all

depend:
	@makedepend -Y. $(INCLUDE) $(addprefix $(SRCDIR)/, $(SRC)) 2>/dev/null
	@rm Makefile.bak

.PHONY: all clean fclean re
# DO NOT DELETE

src/main.o: libft/includes/sigconf.h libft/includes/libft.h includes/shell.h
src/main.o: includes/utils.h libft/includes/printf.h libft/includes/dynbuf.h
src/main.o: includes/core.h includes/structs.h includes/lexer.h
src/main.o: includes/lexer_struct.h includes/option.h includes/exec.h
src/main.o: includes/parser.h includes/builtins.h nboon/includes/nboon.h
src/main.o: nboon/includes/basic.h includes/completion.h includes/hash.h
src/main.o: includes/array.h
src/env.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/getvar.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/getvar.o: includes/dynvars.h
src/error.o: libft/includes/printf.h libft/includes/libft.h
src/error.o: libft/includes/dynbuf.h includes/shell.h includes/utils.h
src/error.o: nboon/includes/nboon.h nboon/includes/basic.h includes/lexer.h
src/error.o: includes/lexer_struct.h includes/core.h includes/structs.h
src/error.o: includes/option.h includes/completion.h includes/hash.h
src/error.o: includes/array.h
src/rebuildenv.o: libft/includes/libft.h includes/structs.h includes/lexer.h
src/rebuildenv.o: includes/shell.h includes/utils.h includes/lexer_struct.h
src/rebuildenv.o: libft/includes/dynbuf.h
src/signals.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/signals.o: libft/includes/printf.h libft/includes/dynbuf.h
src/option.o: nboon/includes/nboon.h nboon/includes/basic.h
src/option.o: libft/includes/printf.h libft/includes/libft.h
src/option.o: libft/includes/dynbuf.h includes/shell.h includes/utils.h
src/option.o: includes/core.h includes/structs.h includes/lexer.h
src/option.o: includes/lexer_struct.h includes/option.h includes/exec.h
src/option.o: includes/parser.h includes/builtins.h
src/completion/completion.o: libft/includes/libft.h libft/includes/printf.h
src/completion/completion.o: libft/includes/dynbuf.h includes/shell.h
src/completion/completion.o: includes/utils.h includes/builtins.h
src/completion/completion.o: includes/completion.h nboon/includes/nboon.h
src/completion/completion.o: nboon/includes/basic.h includes/hash.h
src/completion/completion.o: includes/array.h
src/completion/callback.o: libft/includes/libft.h libft/includes/printf.h
src/completion/callback.o: libft/includes/dynbuf.h nboon/includes/nboon.h
src/completion/callback.o: nboon/includes/basic.h includes/completion.h
src/completion/callback.o: includes/hash.h includes/array.h
src/completion/file.o: libft/includes/libft.h libft/includes/dynbuf.h
src/completion/file.o: includes/completion.h nboon/includes/nboon.h
src/completion/file.o: nboon/includes/basic.h includes/hash.h
src/completion/file.o: includes/array.h
src/completion/bin.o: libft/includes/libft.h includes/array.h
src/completion/bin.o: includes/completion.h nboon/includes/nboon.h
src/completion/bin.o: nboon/includes/basic.h includes/hash.h
src/completion/display.o: includes/array.h includes/builtins.h
src/completion/display.o: includes/core.h includes/structs.h includes/lexer.h
src/completion/display.o: includes/shell.h libft/includes/libft.h
src/completion/display.o: includes/utils.h includes/lexer_struct.h
src/completion/display.o: libft/includes/dynbuf.h includes/option.h
src/completion/display.o: includes/exec.h includes/parser.h
src/completion/display.o: libft/includes/sigconf.h
src/completion/util.o: libft/includes/libft.h includes/array.h
src/completion/util.o: includes/completion.h nboon/includes/nboon.h
src/completion/util.o: nboon/includes/basic.h includes/hash.h
src/structs/command.o: libft/includes/libft.h includes/structs.h
src/structs/command.o: includes/lexer.h includes/shell.h includes/utils.h
src/structs/command.o: includes/lexer_struct.h libft/includes/dynbuf.h
src/structs/pipeline.o: libft/includes/libft.h includes/structs.h
src/structs/pipeline.o: includes/lexer.h includes/shell.h includes/utils.h
src/structs/pipeline.o: includes/lexer_struct.h libft/includes/dynbuf.h
src/structs/process.o: libft/includes/libft.h includes/structs.h
src/structs/process.o: includes/lexer.h includes/shell.h includes/utils.h
src/structs/process.o: includes/lexer_struct.h libft/includes/dynbuf.h
src/structs/redirector.o: libft/includes/libft.h libft/includes/dynbuf.h
src/structs/redirector.o: includes/structs.h includes/lexer.h
src/structs/redirector.o: includes/shell.h includes/utils.h
src/structs/redirector.o: includes/lexer_struct.h
src/lexer/lexer.o: includes/lexer.h includes/shell.h libft/includes/libft.h
src/lexer/lexer.o: includes/utils.h includes/lexer_struct.h
src/lexer/lexer_processing.o: nboon/includes/nboon.h nboon/includes/basic.h
src/lexer/lexer_processing.o: includes/shell.h libft/includes/libft.h
src/lexer/lexer_processing.o: includes/utils.h includes/lexer.h
src/lexer/lexer_processing.o: includes/lexer_struct.h
src/lexer/lexer_tool.o: includes/lexer.h includes/shell.h
src/lexer/lexer_tool.o: libft/includes/libft.h includes/utils.h
src/lexer/lexer_tool.o: includes/lexer_struct.h
src/parser/command.o: includes/parser.h includes/structs.h includes/lexer.h
src/parser/command.o: includes/shell.h libft/includes/libft.h
src/parser/command.o: includes/utils.h includes/lexer_struct.h
src/parser/command.o: libft/includes/dynbuf.h includes/core.h
src/parser/command.o: includes/option.h
src/parser/pipeline.o: includes/parser.h includes/structs.h includes/lexer.h
src/parser/pipeline.o: includes/shell.h libft/includes/libft.h
src/parser/pipeline.o: includes/utils.h includes/lexer_struct.h
src/parser/pipeline.o: libft/includes/dynbuf.h
src/parser/process.o: libft/includes/libft.h includes/parser.h
src/parser/process.o: includes/structs.h includes/lexer.h includes/shell.h
src/parser/process.o: includes/utils.h includes/lexer_struct.h
src/parser/process.o: libft/includes/dynbuf.h
src/parser/redirector.o: libft/includes/libft.h libft/includes/printf.h
src/parser/redirector.o: libft/includes/dynbuf.h includes/parser.h
src/parser/redirector.o: includes/structs.h includes/lexer.h includes/shell.h
src/parser/redirector.o: includes/utils.h includes/lexer_struct.h
src/parser/redirector.o: nboon/includes/nboon.h nboon/includes/basic.h
src/parser/error.o: includes/parser.h includes/structs.h includes/lexer.h
src/parser/error.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/parser/error.o: includes/lexer_struct.h libft/includes/dynbuf.h
src/parser/error.o: libft/includes/printf.h
src/exec/build_process.o: includes/exec.h includes/structs.h includes/lexer.h
src/exec/build_process.o: includes/shell.h libft/includes/libft.h
src/exec/build_process.o: includes/utils.h includes/lexer_struct.h
src/exec/build_process.o: libft/includes/dynbuf.h includes/parser.h
src/exec/build_process.o: includes/builtins.h
src/exec/build_redirector.o: includes/exec.h includes/structs.h
src/exec/build_redirector.o: includes/lexer.h includes/shell.h
src/exec/build_redirector.o: libft/includes/libft.h includes/utils.h
src/exec/build_redirector.o: includes/lexer_struct.h libft/includes/dynbuf.h
src/exec/build_redirector.o: includes/parser.h includes/builtins.h
src/exec/exec_command.o: includes/exec.h includes/structs.h includes/lexer.h
src/exec/exec_command.o: includes/shell.h libft/includes/libft.h
src/exec/exec_command.o: includes/utils.h includes/lexer_struct.h
src/exec/exec_command.o: libft/includes/dynbuf.h includes/parser.h
src/exec/exec_command.o: includes/builtins.h includes/core.h
src/exec/exec_command.o: includes/option.h
src/exec/exec_pipeline.o: includes/shell.h libft/includes/libft.h
src/exec/exec_pipeline.o: includes/utils.h includes/exec.h includes/structs.h
src/exec/exec_pipeline.o: includes/lexer.h includes/lexer_struct.h
src/exec/exec_pipeline.o: libft/includes/dynbuf.h includes/parser.h
src/exec/exec_pipeline.o: includes/builtins.h
src/exec/exec_process.o: includes/shell.h libft/includes/libft.h
src/exec/exec_process.o: includes/utils.h includes/exec.h includes/structs.h
src/exec/exec_process.o: includes/lexer.h includes/lexer_struct.h
src/exec/exec_process.o: libft/includes/dynbuf.h includes/parser.h
src/exec/exec_process.o: includes/builtins.h includes/core.h
src/exec/exec_process.o: includes/option.h libft/includes/sigconf.h
src/exec/exec_builtin.o: includes/exec.h includes/structs.h includes/lexer.h
src/exec/exec_builtin.o: includes/shell.h libft/includes/libft.h
src/exec/exec_builtin.o: includes/utils.h includes/lexer_struct.h
src/exec/exec_builtin.o: libft/includes/dynbuf.h includes/parser.h
src/exec/exec_builtin.o: includes/builtins.h
src/builtins/builtin_loader.o: libft/includes/libft.h includes/builtins.h
src/builtins/cd.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/builtins/cd.o: libft/includes/printf.h libft/includes/dynbuf.h
src/builtins/env.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/builtins/env.o: includes/exec.h includes/structs.h includes/lexer.h
src/builtins/env.o: includes/lexer_struct.h libft/includes/dynbuf.h
src/builtins/env.o: includes/parser.h includes/builtins.h
src/builtins/env.o: libft/includes/printf.h
src/builtins/exit.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/builtins/pwd.o: libft/includes/printf.h libft/includes/libft.h
src/builtins/pwd.o: libft/includes/dynbuf.h includes/shell.h includes/utils.h
src/builtins/setenv.o: includes/shell.h libft/includes/libft.h
src/builtins/setenv.o: includes/utils.h includes/builtins.h includes/core.h
src/builtins/setenv.o: includes/structs.h includes/lexer.h
src/builtins/setenv.o: includes/lexer_struct.h libft/includes/dynbuf.h
src/builtins/setenv.o: includes/option.h
src/builtins/unsetenv.o: includes/shell.h libft/includes/libft.h
src/builtins/unsetenv.o: includes/utils.h
src/builtins/echo.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/builtins/echo.o: libft/includes/printf.h libft/includes/dynbuf.h
src/builtins/history.o: libft/includes/printf.h libft/includes/libft.h
src/builtins/history.o: libft/includes/dynbuf.h includes/shell.h
src/builtins/history.o: includes/utils.h includes/builtins.h
src/builtins/history.o: nboon/includes/nboon.h nboon/includes/basic.h
src/builtins/qexclamation.o: includes/shell.h libft/includes/libft.h
src/builtins/qexclamation.o: includes/utils.h nboon/includes/nboon.h
src/builtins/qexclamation.o: nboon/includes/basic.h includes/lexer.h
src/builtins/qexclamation.o: includes/lexer_struct.h includes/core.h
src/builtins/qexclamation.o: includes/structs.h libft/includes/dynbuf.h
src/builtins/qexclamation.o: includes/option.h includes/completion.h
src/builtins/qexclamation.o: includes/hash.h includes/array.h
src/builtins/w.o: nboon/includes/nboon.h nboon/includes/basic.h
src/builtins/w.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/builtins/w.o: libft/includes/printf.h libft/includes/dynbuf.h
src/builtins/yes.o: libft/includes/printf.h libft/includes/libft.h
src/builtins/yes.o: libft/includes/dynbuf.h
src/dynvars/dynvar_loader.o: includes/shell.h libft/includes/libft.h
src/dynvars/dynvar_loader.o: includes/utils.h includes/dynvars.h
src/dynvars/random.o: includes/shell.h libft/includes/libft.h
src/dynvars/random.o: includes/utils.h includes/dynvars.h
src/dynvars/seconds.o: includes/shell.h libft/includes/libft.h
src/dynvars/seconds.o: includes/utils.h includes/core.h includes/structs.h
src/dynvars/seconds.o: includes/lexer.h includes/lexer_struct.h
src/dynvars/seconds.o: libft/includes/dynbuf.h includes/option.h
src/dynvars/ps1.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/dynvars/ps2.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/dynvars/sh_histfile.o: includes/shell.h libft/includes/libft.h
src/dynvars/sh_histfile.o: includes/utils.h
src/dynvars/sh_histsize.o: includes/shell.h libft/includes/libft.h
src/dynvars/sh_histsize.o: includes/utils.h
src/dynvars/ifs.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/dynvars/char_question.o: includes/shell.h libft/includes/libft.h
src/dynvars/char_question.o: includes/utils.h includes/core.h
src/dynvars/char_question.o: includes/structs.h includes/lexer.h
src/dynvars/char_question.o: includes/lexer_struct.h libft/includes/dynbuf.h
src/dynvars/char_question.o: includes/option.h
src/dynvars/char_dollar.o: includes/shell.h libft/includes/libft.h
src/dynvars/char_dollar.o: includes/utils.h
src/hash/hash_function.o: includes/hash.h
src/hash/chainhash_init.o: includes/hash.h
src/hash/chainhash.o: libft/includes/libft.h includes/hash.h
src/array/array.o: libft/includes/libft.h includes/array.h
src/array/array_sort.o: libft/includes/libft.h includes/array.h
src/array/array_util.o: libft/includes/libft.h libft/includes/dynbuf.h
src/array/array_util.o: includes/array.h
src/core/core.o: includes/core.h includes/structs.h includes/lexer.h
src/core/core.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/core/core.o: includes/lexer_struct.h libft/includes/dynbuf.h
src/core/core.o: includes/option.h
src/core/path_list.o: includes/shell.h libft/includes/libft.h
src/core/path_list.o: includes/utils.h includes/core.h includes/structs.h
src/core/path_list.o: includes/lexer.h includes/lexer_struct.h
src/core/path_list.o: libft/includes/dynbuf.h includes/option.h
src/option/argv.o: includes/option.h
src/option/argv_parser.o: libft/includes/libft.h libft/includes/printf.h
src/option/argv_parser.o: libft/includes/dynbuf.h includes/option.h
src/utils/abspath.o: includes/shell.h libft/includes/libft.h includes/utils.h
src/utils/expanduser.o: includes/shell.h libft/includes/libft.h
src/utils/expanduser.o: includes/utils.h
src/utils/realpath.o: includes/shell.h libft/includes/libft.h
src/utils/realpath.o: includes/utils.h
src/utils/joinpath.o: includes/utils.h libft/includes/libft.h
src/utils/expandvar.o: includes/exec.h includes/structs.h includes/lexer.h
src/utils/expandvar.o: includes/shell.h libft/includes/libft.h
src/utils/expandvar.o: includes/utils.h includes/lexer_struct.h
src/utils/expandvar.o: libft/includes/dynbuf.h includes/parser.h
src/utils/expandvar.o: includes/builtins.h
src/utils/globalize.o: includes/utils.h libft/includes/libft.h
