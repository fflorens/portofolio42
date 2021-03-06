# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    nboon.make                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzak </var/mail/jzak>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/27 18:51:33 by jzak              #+#    #+#              #
#    Updated: 2014/03/27 18:51:33 by jzak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef config
  config=release
endif

ifndef verbose
  SILENT = @
endif

ifndef CC
  CC = gcc
endif

ifndef CXX
  CXX = g++
endif

ifndef AR
  AR = ar
endif

ifeq ($(config),release)
  OBJDIR     = bin/obj/Release/nboon
  TARGETDIR  = .
  TARGET     = $(TARGETDIR)/libnboon.a
  DEFINES   += 
  INCLUDES  += -Iincludes
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -Wall -Wextra -Werror
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -Wl,-x
  LIBS      += 
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug)
  OBJDIR     = bin/obj/Debug/nboon
  TARGETDIR  = .
  TARGET     = $(TARGETDIR)/libnboon.a
  DEFINES   += 
  INCLUDES  += -Iincludes
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -Wall -Wextra
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += 
  LIBS      += 
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

NAME = nboon

OBJECTS := \
	$(OBJDIR)/completion.o \
	$(OBJDIR)/error.o \
	$(OBJDIR)/evt.o \
	$(OBJDIR)/history.o \
	$(OBJDIR)/history_file.o \
	$(OBJDIR)/insert.o \
	$(OBJDIR)/lib.o \
	$(OBJDIR)/mode.o \
	$(OBJDIR)/nboon.o \
	$(OBJDIR)/prompt.o \
	$(OBJDIR)/refresh.o \
	$(OBJDIR)/string.o \
	$(OBJDIR)/unicode.o \
	$(OBJDIR)/backspace.o \
	$(OBJDIR)/clear_end_line.o \
	$(OBJDIR)/clear_line.o \
	$(OBJDIR)/clear_screen.o \
	$(OBJDIR)/del_word.o \
	$(OBJDIR)/delete.o \
	$(OBJDIR)/history_next.o \
	$(OBJDIR)/move_end.o \
	$(OBJDIR)/move_home.o \
	$(OBJDIR)/move_left.o \
	$(OBJDIR)/move_right.o \
	$(OBJDIR)/move_to_next_word.o \
	$(OBJDIR)/move_to_prev_word.o \
	$(OBJDIR)/paste_line.o \
	$(OBJDIR)/swap_letter.o \

RESOURCES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

.PHONY: clean prebuild prelink

all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

$(TARGET): $(GCH) $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking nboon
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

$(NAME): all

clean:
	@echo Cleaning nboon
	$(SILENT) rm -rf $(OBJDIR)

fclean: clean
	@echo Remove $(TARGET)
	$(SILENT) rm -f $(TARGET)

re: fclean all

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(GCH): $(PCH)
	@echo $(notdir $<)
	-$(SILENT) cp $< $(OBJDIR)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
endif

$(OBJDIR)/completion.o: srcs/completion.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/error.o: srcs/error.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/evt.o: srcs/evt.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/history.o: srcs/history.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/history_file.o: srcs/history_file.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/insert.o: srcs/insert.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/lib.o: srcs/lib.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/mode.o: srcs/mode.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/nboon.o: srcs/nboon.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/prompt.o: srcs/prompt.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/refresh.o: srcs/refresh.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/string.o: srcs/string.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/unicode.o: srcs/unicode.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/backspace.o: srcs/evt/backspace.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/clear_end_line.o: srcs/evt/clear_end_line.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/clear_line.o: srcs/evt/clear_line.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/clear_screen.o: srcs/evt/clear_screen.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/del_word.o: srcs/evt/del_word.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/delete.o: srcs/evt/delete.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/history_next.o: srcs/evt/history_next.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/move_end.o: srcs/evt/move_end.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/move_home.o: srcs/evt/move_home.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/move_left.o: srcs/evt/move_left.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/move_right.o: srcs/evt/move_right.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/move_to_next_word.o: srcs/evt/move_to_next_word.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/move_to_prev_word.o: srcs/evt/move_to_prev_word.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/paste_line.o: srcs/evt/paste_line.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/swap_letter.o: srcs/evt/swap_letter.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
