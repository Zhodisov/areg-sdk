18_locservice_OUTPUT_OBJ := $(18_locwatchdog_OUTPUT_OBJ)/locservice

18_locservice_SRC  :=
18_locservice_OBJS :=

include $(18_locwatchdog_BASE)/locservice/src/Makefile

# define one target for each source file
$(foreach cpp, $(18_locservice_SRC), $(eval $(call obj, $(cpp), $(18_locservice_OUTPUT_OBJ), 18_locservice_OBJS, $(18_locwatchdog_CXXFLAGS))))

DEPS = $(18_locservice_OBJS:%.o=%.d)
-include $(DEPS)

$(18_locservice_TARGET_BIN): $(areg_TARGET_BIN) $(18_locservice_OBJS) $(18_locwatchdog_DEPEND)
	@echo "Linking $@ ..."
	@mkdir -p $(dir $@)
	$(AREG_TOOLCHAIN) $(CXXFLAGS) $(18_locwatchdog_CXXFLAGS) $(18_locservice_OBJS) -o $@ $(18_locwatchdog_LDFLAGS)
