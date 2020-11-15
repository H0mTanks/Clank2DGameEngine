build:
	g++ -w -std=c++14 -Wfatal-errors \
	./src/*.cpp \
	./src/Components/*.cpp \
	-o engine \
	-I".\lib\lua" \
	-L".\lib\lua" \
	-I".\lib\SDL2x86\include" \
	-L".\lib\SDL2x86\lib" \
	-llua54 \
	-lmingw32 \
	-lSDL2main \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer \

clean:
	del engine.exe

run:
	engine.exe
