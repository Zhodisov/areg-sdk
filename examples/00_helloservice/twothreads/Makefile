00_twothreads_OUTPUT_OBJ := $(00_helloservice_OUTPUT_OBJ)/twothreads

00_twothreads_SRC  :=
00_twothreads_OBJS :=

include $(00_helloservice_BASE)/twothreads/src/Makefile

# define one target for each source file
$(foreach cpp, $(00_twothreads_SRC), $(eval $(call obj, $(cpp), $(00_twothreads_OUTPUT_OBJ), 00_twothreads_OBJS, $(00_helloservice_CXXFLAGS))))

DEPS = $(00_twothreads_OBJS:%.o=%.d)
-include $(DEPS)

$(00_twothreads_TARGET_BIN): $(areg_TARGET_BIN) $(00_twothreads_OBJS) $(00_helloservice_DEPEND)
	@echo "Linking $@ ..."
	@mkdir -p $(dir $@)
	$(AREG_TOOLCHAIN) $(CXXFLAGS) $(00_helloservice_CXXFLAGS) $(00_twothreads_OBJS) $(00_helloservice_LDFLAGS) -o $@
