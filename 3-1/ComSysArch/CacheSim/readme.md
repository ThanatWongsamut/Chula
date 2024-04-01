gcc -o direct CacheSimDirect.c
./direct ./gcc_ld_trace.txt

gcc -o lru CacheSimLRU.c
./lru ./gcc_ld_trace.txt

gcc -o rr CacheSimRR.c
./rr ./gcc_ld_trace.txt
