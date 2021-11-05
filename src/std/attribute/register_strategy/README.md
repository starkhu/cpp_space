gcc print.c -fPIC -shared -o libprint.so
gcc attribute_constructor.c -L. -lprint -o m
