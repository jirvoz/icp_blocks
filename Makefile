# Block editor project to ICP course
# Authors: Jiri Vozar
#          Vaclav Dolezal

all: blockeditor

blockeditor: src/Makefile $(wildcard src/*.cpp src*.h src/*.ui)
	cd src && make
	cp -p src/blockeditor blockeditor

src/Makefile: src/block-editor.pro
	cd src && qmake-qt5

doxygen:
	doxygen Doxyfile

clean: src/Makefile
	cd src && make clean
	rm -rf blockeditor src/blockeditor src/Makefile doc/ xvozar04-xdolez76.tar.gz

pack:
	tar pczf xvozar04-xdolez76.tar.gz src/ examples/ README.md Makefile

.PHONY: all clean pack
