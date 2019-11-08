all: libcrash.so
	gcc -o crash -L. -lcrash -ldl crash.c

cpp:
	gcc -o crash -I. -I./agora/prebuilt/lib/linux/x64_agora_sdk/include \
	-L./agora/prebuilt/lib/linux/x64_agora_sdk \
	-std=c++11 \
	crash.cpp -lpthread -lagora_rtc_sdk

libcrash.so: libcrash.cpp
	gcc -fPIC -shared -o libcrash.so -I. -I./agora/prebuilt/lib/linux/x64_agora_sdk/include \
	-L./agora/prebuilt/lib/linux/x64_agora_sdk \
	-std=c++11 \
	libcrash.cpp -lpthread -lagora_rtc_sdk

run:
	LD_LIBRARY_PATH=. ./crash
