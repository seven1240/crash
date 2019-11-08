# Have fun

```
(gdb) run
Starting program: /sw/src/modules/7/crash
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
[New Thread 0x7ffff53ff700 (LWP 14077)]
[New Thread 0x7ffff43ff700 (LWP 14078)]
[New Thread 0x7ffff33ff700 (LWP 14079)]
[New Thread 0x7ffff23ff700 (LWP 14080)]
waiting to crash ....
^C
Thread 1 "crash" received signal SIGINT, Interrupt.
0x00007ffff668a28d in nanosleep () at ../sysdeps/unix/syscall-template.S:84
84	../sysdeps/unix/syscall-template.S: No such file or directory.
(gdb) thread apply all bt

Thread 5 (Thread 0x7ffff23ff700 (LWP 14080)):
#0  0x00007ffff79957fd in nanosleep () at ../sysdeps/unix/syscall-template.S:84
#1  0x00007ffff738854b in std::__1::this_thread::sleep_for(std::__1::chrono::duration<long long, std::__1::ratio<1l, 1000000000l> > const&) () from /usr/lib/libagora_rtc_sdk.so
#2  0x00007ffff721467a in ?? () from /usr/lib/libagora_rtc_sdk.so
#3  0x00007ffff7248428 in ?? () from /usr/lib/libagora_rtc_sdk.so
#4  0x00007ffff72490a9 in ?? () from /usr/lib/libagora_rtc_sdk.so
#5  0x00007ffff798c4a4 in start_thread (arg=0x7ffff23ff700) at pthread_create.c:456
#6  0x00007ffff66bad0f in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:97

Thread 4 (Thread 0x7ffff33ff700 (LWP 14079)):
#0  syscall () at ../sysdeps/unix/sysv/linux/x86_64/syscall.S:38
#1  0x00007ffff6b39efd in ?? () from /usr/lib/libagora_rtc_sdk.so
#2  0x00007ffff6b2cbc6 in ?? () from /usr/lib/libagora_rtc_sdk.so
#3  0x00007ffff73286e1 in ?? () from /usr/lib/libagora_rtc_sdk.so
#4  0x00007ffff798c4a4 in start_thread (arg=0x7ffff33ff700) at pthread_create.c:456
#5  0x00007ffff66bad0f in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:97

Thread 3 (Thread 0x7ffff43ff700 (LWP 14078)):
#0  syscall () at ../sysdeps/unix/sysv/linux/x86_64/syscall.S:38
#1  0x00007ffff6b39efd in ?? () from /usr/lib/libagora_rtc_sdk.so
#2  0x00007ffff6b2cbc6 in ?? () from /usr/lib/libagora_rtc_sdk.so
#3  0x00007ffff73286e1 in ?? () from /usr/lib/libagora_rtc_sdk.so
#4  0x00007ffff798c4a4 in start_thread (arg=0x7ffff43ff700) at pthread_create.c:456
#5  0x00007ffff66bad0f in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:97

Thread 2 (Thread 0x7ffff53ff700 (LWP 14077)):
#0  syscall () at ../sysdeps/unix/sysv/linux/x86_64/syscall.S:38
#1  0x00007ffff6b39efd in ?? () from /usr/lib/libagora_rtc_sdk.so
#2  0x00007ffff6b2cbc6 in ?? () from /usr/lib/libagora_rtc_sdk.so
#3  0x00007ffff73286e1 in ?? () from /usr/lib/libagora_rtc_sdk.so
#4  0x00007ffff798c4a4 in start_thread (arg=0x7ffff53ff700) at pthread_create.c:456
#5  0x00007ffff66bad0f in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:97

---Type <return> to continue, or q <return> to quit---
Thread 1 (Thread 0x7ffff7fe6780 (LWP 14073)):
#0  0x00007ffff668a28d in nanosleep () at ../sysdeps/unix/syscall-template.S:84
#1  0x00007ffff668a1da in __sleep (seconds=0) at ../sysdeps/posix/sleep.c:55
#2  0x000055555555497c in main ()
```
