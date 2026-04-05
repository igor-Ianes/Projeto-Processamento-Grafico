# Graficos3D

graficos3dSource3=graficos3d/source/
graficos3dHeader=graficos3d/headerFiles/engine
graficos3dHeader2=graficos3d/headerFiles/framework
graficos3dSource=graficos3d/source/engine/
graficos3dSource2=graficos3d/source/framework/
GLADHEAD=glads/include
GLADSRC=glads/src/

LINK=	-I$(graficos3dHeader)	-I$(graficos3dHeader2)	-I$(GLADHEAD)	$(graficos3dSource3)main.cpp	$(graficos3dSource2)Manager.cpp	$(graficos3dSource2)Timer.cpp	$(graficos3dSource2)InputManager.cpp	$(graficos3dSource2)Graphics.cpp	$(graficos3dSource)Graphics3d.cpp	$(graficos3dSource)Shader.cpp	$(graficos3dSource)math3d.cpp	$(GLADSRC)glad.c	$(graficos3dSource)Renderer3D.cpp	$(graficos3dSource)Scene.cpp	$(graficos3dSource2)TextureManager.cpp
OUTPUT=programa

INCHEAD=./glfw/glfw-3.4/include
INCLIBS=./glfw/glfw-3.4/lib-mingw-w64
INCS=-I$(INCHEAD)	-L$(INCLIBS)
LIBSW=-lglfw3	-lgdi32	-lopengl32

#Compilation options
CPP=g++	-frtti
CFLAGS=-Wall	-Wextra	-g	-O2
OPTS1=-Wall -Wextra -pedantic
OPTS2=-Wall	-o
OPTS=-Wall	-g	-o

all: programa run

programa:
	$(CPP)	$(OPTS)	$(OUTPUT)	$(LINK)	$(INCS)	$(LIBSW)

clean:
	del $(OUTPUT)
	
run:
	./programa

# Commands Windows
# mingw32-make all
# mingw32-make programa
# mingw32-make run
# mingw32-make clean

# Commands Linux
# make all
# make programa
# make run
# make clean
