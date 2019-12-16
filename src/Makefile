include ${ENV_DIR}/build/config.mk

EXEC = ds_vis
OBJECTS = main.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: directories all clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
