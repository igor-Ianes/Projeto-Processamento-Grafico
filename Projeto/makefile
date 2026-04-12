#        Graficos3D

# Diretórios
graficos3dSource3 = graficos3d/source/
graficos3dHeader  = graficos3d/headerFiles/engine
graficos3dHeader2 = graficos3d/headerFiles/framework
graficos3dSource  = graficos3d/source/engine/
graficos3dSource2 = graficos3d/source/framework/
GLADHEAD = glads/include
GLADSRC  = glads/src/

# Arquivos fonte
SOURCES = \
$(graficos3dSource3)main.cpp \
$(graficos3dSource2)Manager.cpp \
$(graficos3dSource2)Timer.cpp \
$(graficos3dSource2)InputManager.cpp \
$(graficos3dSource2)Graphics.cpp \
$(graficos3dSource)Graphics3d.cpp \
$(graficos3dSource)Shader.cpp \
$(graficos3dSource)math3d.cpp \
$(graficos3dSource)Renderer3D.cpp \
$(graficos3dSource)Scene.cpp \
$(graficos3dSource2)TextureManager.cpp \
$(GLADSRC)glad.c

# Includes
INCLUDES = -I$(graficos3dHeader) -I$(graficos3dHeader2) -I$(GLADHEAD)

# Saída
OUTPUT = programa

# Compilador
CPP = g++
CFLAGS = -Wall -Wextra -g -O2

#   Detecção de Sistema
ifeq ($(OS),Windows_NT)

    # Windows (MinGW)
    INCHEAD = ./glfw/glfw-3.4/include
    INCLIBS = ./glfw/glfw-3.4/lib-mingw-w64

    INCLUDES += -I$(INCHEAD)
    LIBS = -L$(INCLIBS) -lglfw3 -lgdi32 -lopengl32

    RM = del
    EXEC = $(OUTPUT)

else

    # Linux
    LIBS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

    RM = rm -f
    EXEC = ./$(OUTPUT)

endif

#        Regras

all: programa

programa:
	$(CPP) $(CFLAGS) -o $(OUTPUT) $(SOURCES) $(INCLUDES) $(LIBS)

run: programa
	$(EXEC)

clean:
	$(RM) $(OUTPUT)
