build_c_lib:
	gcc QuantumRand.h -shared -O2 -o QuantumRand.so -lcurl -ljson-c