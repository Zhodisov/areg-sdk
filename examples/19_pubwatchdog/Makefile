19_pubwatchdog_BASE       := $(AREG_EXAMPLES)/19_pubwatchdog
19_pubwatchdog_OUTPUT_OBJ := $(AREG_OUTPUT_OBJ)/19_pubwatchdog

# Project and binary names
19_generated_PROJECT_NAME	:= 19_generated
19_generated_TARGET_BIN		:= $(AREG_OUTPUT_LIB)/$(AREG_LIB_PREFIX)$(19_generated_PROJECT_NAME)$(AREG_STATIC_LIB)

19_pubclient_PROJECT_NAME	:= 19_pubclient
19_pubclient_TARGET_BIN		:= $(AREG_OUTPUT_BIN)/$(19_pubclient_PROJECT_NAME)$(AREG_BIN_EXT)

19_pubservice_PROJECT_NAME	:= 19_pubservice
19_pubservice_TARGET_BIN	:= $(AREG_OUTPUT_BIN)/$(19_pubservice_PROJECT_NAME)$(AREG_BIN_EXT)

# Compiler and linker flags
19_pubwatchdog_CXXFLAGS = -I$(19_pubwatchdog_BASE) $(examples_CXXFLAGS)
19_pubwatchdog_LDFLAGS  = $(AREG_LIB_INCLUDES) -lareg -l$(19_generated_PROJECT_NAME) $(LDFLAGS)

# Set build dependencies
19_pubwatchdog_DEPEND	= $(AREG_DEPEND) $(19_generated_TARGET_BIN)

# 'generated' have to be first
include $(19_pubwatchdog_BASE)/generated/Makefile
include $(19_pubwatchdog_BASE)/pubservice/Makefile
include $(19_pubwatchdog_BASE)/pubclient/Makefile

19_pubwatchdog: $(19_generated_TARGET_BIN) $(19_pubclient_TARGET_BIN) $(19_pubservice_TARGET_BIN)

.PHONY: 19_pubwatchdog
