include ${ENV_DIR}/build/config.mk
OUT_DIR := $ENV_DIR/out

.PHONY: directories all clean

all: $(OUT_DIR)
	$(MAKE) -C src/ $(MAKECMDGOALS)

directories: $(OUT_DIR)

$(OUT_DIR):
	${MKDIR_P} $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)