20_pubclient_OUTPUT_OBJ := $(20_pubdatarate_OUTPUT_OBJ)/pubclient

20_pubclient_SRC  :=
20_pubclient_OBJS :=

include $(20_pubdatarate_BASE)/pubclient/src/Makefile

# define one target for each source file
$(foreach cpp, $(20_pubclient_SRC), $(eval $(call obj, $(cpp), $(20_pubclient_OUTPUT_OBJ), 20_pubclient_OBJS, $(20_pubdatarate_CXXFLAGS))))

DEPS = $(20_pubclient_OBJS:%.o=%.d)
-include $(DEPS)

$(20_pubclient_TARGET_BIN): $(areg_TARGET_BIN) $(20_pubclient_OBJS) $(20_pubdatarate_DEPEND)
	@echo "Linking $@ ..."
	@mkdir -p $(dir $@)
	$(AREG_TOOLCHAIN) $(CXXFLAGS) $(20_pubdatarate_CXXFLAGS) $(20_pubclient_OBJS) -o $@ $(20_pubdatarate_LDFLAGS)
