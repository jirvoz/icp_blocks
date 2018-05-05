# Block editor project to ICP course
# Authors: Jiri Vozar
#          Vaclav Dolezal

all: block-editor

doxygen:
	doxygen Doxyfile

clean:
	rm -rf doc/ xvozar04-xdolez76.tar.gz

pack:
	tar pczf xvozar04-xdolez76.tar.gz src/ examples/ README.md Makefile

.PHONY: all clean pack
