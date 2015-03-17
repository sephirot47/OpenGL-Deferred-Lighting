all: main.exe

main.exe: main.o Shader.o ShaderProgram.o stb_image.o Debug.o Time.o VBO.o VAO.o Image.o Texture.o FileLoader.o FrameBuffer.o FrameDrawer.o Mesh.o GBuffer.o Light.o
	g++ -std=c++11 *.o -o main.exe -Iinclude -lGL -lGLU -lSDL2

main.o: src/main.cpp
	g++ -std=c++11 -c src/main.cpp -Iinclude -lGL -lGLU -lSDL2

Shader.o: src/Shader.cpp
	g++ -std=c++11 -c src/Shader.cpp -Iinclude -lGL -lGLU -lSDL2

ShaderProgram.o: src/ShaderProgram.cpp
	g++ -std=c++11 -c src/ShaderProgram.cpp -Iinclude -lGL -lGLU -lSDL2

Debug.o: src/Debug.cpp
	g++ -std=c++11 -c src/Debug.cpp -Iinclude -lGL -lGLU -lSDL2

Time.o: src/Time.cpp
	g++ -std=c++11 -c src/Time.cpp -Iinclude -lGL -lGLU -lSDL2

VBO.o: src/VBO.cpp
	g++ -std=c++11 -c src/VBO.cpp -Iinclude -lGL -lGLU -lSDL2

VAO.o: src/VAO.cpp
	g++ -std=c++11 -c src/VAO.cpp -Iinclude -lGL -lGLU -lSDL2

Image.o: src/Image.cpp
	g++ -std=c++11 -c src/Image.cpp -Iinclude -lGL -lGLU -lSDL2

Texture.o: src/Texture.cpp
	g++ -std=c++11 -c src/Texture.cpp -Iinclude -lGL -lGLU -lSDL2

FileLoader.o: src/FileLoader.cpp
	g++ -std=c++11 -c src/FileLoader.cpp -Iinclude -lGL -lGLU -lSDL2

FrameBuffer.o: src/FrameBuffer.cpp
	g++ -std=c++11 -c src/FrameBuffer.cpp -Iinclude -lGL -lGLU -lSDL2

FrameDrawer.o: src/FrameDrawer.cpp
	g++ -std=c++11 -c src/FrameDrawer.cpp -Iinclude -lGL -lGLU -lSDL2

stb_image.o: src/stb_image.cpp
	g++ -std=c++11 -c src/stb_image.cpp -Iinclude -lGL -lGLU -lSDL2

Mesh.o: src/Mesh.cpp
	g++ -std=c++11 -c src/Mesh.cpp -Iinclude -lGL -lGLU -lSDL2

GBuffer.o: src/GBuffer.cpp
	g++ -std=c++11 -c src/GBuffer.cpp -Iinclude -lGL -lGLU -lSDL2

Light.o: src/Light.cpp
	g++ -std=c++11 -c src/Light.cpp -Iinclude -lGL -lGLU -lSDL2

clean:
	rm -rf *.exe *.o *~
