

template<typename T>
bool getBit(T data, int i){
	return ((data & ( 1 << i ))!= 0);
}

template<typename T>
T setBit(T data, int i){
	return data | (1<<i);
}

template<typename T>
T clearBit(T data, int i){
	return data & ~(1 << i);
}

template<typename T>
T clearBitsMSBthroughI(T num, int i){
	int mask = (1<< i) -1;
	return num & mask;
}

template<typename T>
T clearBitsIthrough0(T num, int i ){
	int mask = (-1 << (i+1));
	return num & mask;
}

template<typename T>
T updateBit(T num, int i, bool bitIs1){
	int value = bitIs1 ? 1 : 0;
	int mask = ~(1 <<i);
	return (num & mask) | value << i;
}
