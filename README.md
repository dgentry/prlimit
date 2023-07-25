Demo prlimit().

To run, type "make" then "./run-prlimit.sh"

Only works on linux.

Here's what it does:

```console
$ ./run-prlimit.sh
Launching consumer
I think I can do 1000000 clocks per second
PID of the CPU consumer program: 106144
Message 1: CPU Time Used: 0.545675 seconds.
Setting CPU limit to 5 seconds

Previous limits: soft=-1; hard=-1
New limits: soft=5; hard=5

Sleeping 6 more seconds
Message 2: CPU Time Used: 1.101075 seconds.
Message 3: CPU Time Used: 1.612345 seconds.
Message 4: CPU Time Used: 2.150996 seconds.
Message 5: CPU Time Used: 2.660769 seconds.
Message 6: CPU Time Used: 3.176877 seconds.
Message 7: CPU Time Used: 3.690988 seconds.
Message 8: CPU Time Used: 4.211107 seconds.
Message 9: CPU Time Used: 4.751105 seconds.
./run-prlimit.sh: line 21: 106144 Killed                  ./consumer

real	0m4.999s
user	0m4.987s
sys	0m0.008s

$
```
