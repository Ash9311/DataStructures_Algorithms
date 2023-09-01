//An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

//Given an integer n, return the nth ugly number.

class nthUglyNumber {
public:
	int solve(int n) {
    		vector<int> res(1, 1);
        int i = 0, j = 0, k = 0;//initially put all pointers on 0th index i.e 1 initially.

        while (res.size() < n) { //find the mmin
            int val = min(2 * res[i], min(3 * res[j], 5 * res[k])); //take out the min one push it and increment that pointer
            res.push_back(val);

            if (val == 2 * res[i]) i++;
            if (val == 3 * res[j]) j++;
            if (val == 5 * res[k]) k++;
        }
        
        return res.back(); //last number is our ans
      }
};
