22_generated_OUTPUT_OBJ := $(22_pubsub_OUTPUT_OBJ)/generated

22_generated_SRC  :=
22_generated_OBJS :=

include $(22_pubsub_BASE)/generated/src/private/Makefile

# define one target for each source file
$(foreach cpp, $(22_generated_SRC), $(eval $(call obj, $(cpp), $(22_generated_OUTPUT_OBJ), 22_generated_OBJS, $(22_pubsub_CXXFLAGS))))

DEPS = $(22_generated_OBJS:%.o=%.d)
-include $(DEPS)

$(22_generated_TARGET_BIN): $(22_generated_OBJS)
	@echo "Linking $@ ..."
	@mkdir -p $(dir $@)
	$(AREG_AR) -rcs $@ $^
