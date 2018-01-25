# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := tf_test
DEFS_Debug := \
	'-DNODE_GYP_MODULE_NAME=tf_test' \
	'-DUSING_UV_SHARED=1' \
	'-DUSING_V8_SHARED=1' \
	'-DV8_DEPRECATION_WARNINGS=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION' \
	'-DDEBUG' \
	'-D_DEBUG' \
	'-DV8_ENABLE_CHECKS'

# Flags passed to all source files.
CFLAGS_Debug := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++0x

INCS_Debug := \
	-I/home/kreeger/.node-gyp/8.9.1/include/node \
	-I/home/kreeger/.node-gyp/8.9.1/src \
	-I/home/kreeger/.node-gyp/8.9.1/deps/uv/include \
	-I/home/kreeger/.node-gyp/8.9.1/deps/v8/include \
	-I/usr/local/include

DEFS_Release := \
	'-DNODE_GYP_MODULE_NAME=tf_test' \
	'-DUSING_UV_SHARED=1' \
	'-DUSING_V8_SHARED=1' \
	'-DV8_DEPRECATION_WARNINGS=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION'

# Flags passed to all source files.
CFLAGS_Release := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-O3 \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++0x

INCS_Release := \
	-I/home/kreeger/.node-gyp/8.9.1/include/node \
	-I/home/kreeger/.node-gyp/8.9.1/src \
	-I/home/kreeger/.node-gyp/8.9.1/deps/uv/include \
	-I/home/kreeger/.node-gyp/8.9.1/deps/v8/include \
	-I/usr/local/include

OBJS := \
	$(obj).target/$(TARGET)/tf_test.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64

LIBS := \
	/usr/local/lib/libtensorflow.so \
	/usr/local/lib/libtensorflow_framework.so

$(obj).target/tf_test.node: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/tf_test.node: LIBS := $(LIBS)
$(obj).target/tf_test.node: TOOLSET := $(TOOLSET)
$(obj).target/tf_test.node: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,solink_module)

all_deps += $(obj).target/tf_test.node
# Add target alias
.PHONY: tf_test
tf_test: $(builddir)/tf_test.node

# Copy this to the executable output path.
$(builddir)/tf_test.node: TOOLSET := $(TOOLSET)
$(builddir)/tf_test.node: $(obj).target/tf_test.node FORCE_DO_CMD
	$(call do_cmd,copy)

all_deps += $(builddir)/tf_test.node
# Short alias for building this executable.
.PHONY: tf_test.node
tf_test.node: $(obj).target/tf_test.node $(builddir)/tf_test.node

# Add executable to "all" target.
.PHONY: all
all: $(builddir)/tf_test.node

