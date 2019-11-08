all:
	gcc -o crash -I. -I./agora/prebuilt/lib/linux/x64_agora_sdk/include \
	-L./agora/prebuilt/lib/linux/x64_agora_sdk \
	-std=c++11 \
	crash.cpp -lpthread -lagora_rtc_sdk
