include ../common.mk

TARGET=libuisim

SRCS = src/uisim.c
INC += $(SDL2_PATH) include

CFLAGS += $(addprefix -I,$(INC)) -D_REENTRANT  -O0  -gdwarf-2 -g3  -MMD -MP

OBJS = $(patsubst %c,%o,$(SRCS))
DEPS = $(patsubst %.o,%.d,$(OBJS))

ARFLAGS=rcs

all: $(OBJS)
	$(vecho) "CC $<"
	$(Q) $(AR) $(ARFLAGS) $(TARGET).a $(OBJS)

%.o: %.c
	$(vecho) "CC $<"
	$(Q) $(CC) -c $(CFLAGS) $< -o $@

%.o: %.cc
	$(vecho) "C++ $<"
	$(Q) $(CPP) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

%.o: %.s
	$(vecho) "AS $<"
	$(Q) $(AS) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(DEPS): ;
.PRECIOUS: $(DEPS)

clean:
	rm -vf $(TARGET).a
	rm -vf $(OBJS)
	rm -vf $(DEPS)

-include $(DEPS)
