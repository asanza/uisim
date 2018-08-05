include common.mk

TARGET=uisim_test

SRCS = examples/main.c examples/ugui/src/ugui.c
INC += -I./lib/include -I./examples/ugui/include
LIBS = -luisim -lSDL2

LIBRARY_PATHS = $(SDL2_LIBRARY_PATH) lib 

LDFLAGS += $(addprefix -L,$(LIBRARY_PATHS))

CFLAGS += $(INC) -D_REENTRANT  -O0  -gdwarf-2 -g3  -MMD -MP
CFLAGS += -DUSE_FONT_8X8

OBJS = $(patsubst %c,%o,$(SRCS))
DEPS = $(patsubst %.o,%.d,$(OBJS))

DIRS = lib

.PHONY: all $(DIRS)

all: $(DIRS) $(OBJS)
	$(vecho) "CC $<"
	$(Q) $(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

%.o: %.c
	$(vecho) "CC $<"
	$(Q) $(CC) -c $(CFLAGS) $< -o $@

%.o: %.cc
	$(vecho) "C++ $<"
	$(Q) $(CPP) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

%.o: %.s
	$(vecho) "AS $<"
	$(Q) $(AS) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(DIRS):
	$(MAKE) --directory=$@

$(DEPS): ;
.PRECIOUS: $(DEPS)

clean:
	rm -vf $(TARGET)
	rm -vf $(OBJS)
	rm -vf $(DEPS)
	make --directory=lib clean

-include $(DEPS)
