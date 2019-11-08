#include <unistd.h>
#include <dlfcn.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef void *switch_dso_lib_t;
typedef int (*switch_dso_func_t) (void);

switch_dso_lib_t switch_dso_open(const char *path, int global, char **err)
{
	void *lib;

	if (global) {
		lib = dlopen(path, RTLD_NOW | RTLD_GLOBAL);
	} else {
		lib = dlopen(path, RTLD_NOW | RTLD_LOCAL);
	}

	if (lib == NULL) {
		const char *dlerr = dlerror();
		/* Work around broken uclibc returning NULL on both dlopen() and dlerror() */
		if (dlerr) {
			*err = strdup(dlerr);
		} else {
			*err = strdup("Unknown error");
		}
	}
	return lib;
}

switch_dso_func_t switch_dso_func_sym(switch_dso_lib_t lib, const char *sym, char **err)
{
	void *func = dlsym(lib, sym);
	if (!func) {
		*err = strdup(dlerror());
	}
	return (switch_dso_func_t) (intptr_t) func;
}

void switch_dso_destroy(switch_dso_lib_t *lib)
{
	if (lib && *lib) {
		dlclose(*lib);
		*lib = NULL;
	}
}

int main(int argc, char **argv)
{
	char *err = NULL;

	switch_dso_lib_t dso = switch_dso_open("./libcrash.so", 1, &err);
	assert(dso);

	switch_dso_func_t create_agora_service = switch_dso_func_sym(dso, "create_agora_service", &err);

	if (!create_agora_service) {
		printf("error: %s\n", err);
		exit(-1);
	}

	switch_dso_func_t destroy_agora_service = switch_dso_func_sym(dso, "destroy_agora_service", &err);

	if (!destroy_agora_service) {
		printf("error: %s\n", err);
		exit(-1);
	}

	printf("create agora service\n");
	int ret = create_agora_service();
	assert(ret);
	sleep(1);
	printf("destroy agora service\n");
	destroy_agora_service();	
	sleep(1);

	switch_dso_destroy(&dso);

	printf("waiting to crash ....\n");

	while (1) {
		sleep(3);
	}

	return 0;
}
