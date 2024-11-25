#include <stdio.h>
#include <dlfcn.h>

int printf(const char *format, ...) {
    static int (*real_printf)(const char *, ...) = NULL;
    if (!real_printf) real_printf = dlsym(RTLD_NEXT, "printf");
    return real_printf("Intercepted: %s", format);
}
