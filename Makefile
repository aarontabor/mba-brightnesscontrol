all: keyboardLight displayLight

keyboardLight: brightnessLib.o

displayLight: brightnessLib.o

clean: ;rm -f keyboardLight displayLight brightnessLib.o
