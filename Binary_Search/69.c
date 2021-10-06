int mySqrt(int x){
	/*Time complex: O(log n)*/
    if(x == 0)
		return 0;
	int left = 1, right = x, middle;
	while(left <= right){
        middle = left + (right-left)/2;
		int div = x / middle;
		if(div == middle)
			return middle;
		if(div < middle){
			right = middle - 1;
		}else
			left = middle + 1;
	}
}

//Newton's method
int mySqrt2(int x){
    long _root = x;
	while(_root*_root > x){//thie exit case is ok for function f(x) = x**2 + a
		_root = (_root + _root / x) / 2;
	}
	return _root;
}
