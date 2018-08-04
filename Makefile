ifeq ("$(V)","1")
Q :=
vecho := @true
else
Q := @
vecho := @echo
endif

TARGET=uisim_test

SRCS = main.c
INC += -I./lib/include
LIBS = -Llib -luisim -lSDL2

CFLAGS += $(INC) -D_REENTRANT  -O0  -gdwarf-2 -g3  -MMD -MP

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
	rm src

-include $(DEPS)
