SUBDIRS := lib procexec

# Default target to build all subdirectories
all: $(SUBDIRS)

build_lib:
	$(MAKE) -C $(LIB_DIR)

build_program:
	$(MAKE) -C $(DIR) MAIN=$(MAIN) LIB_DIR=$(LIB_DIR)

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
