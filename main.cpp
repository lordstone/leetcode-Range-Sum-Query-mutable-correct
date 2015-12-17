class NumArray {
public:

    vector<int> arr;
    vector<int> c;
    
    int lowbit(int i){
        return i&(-i);
    }

    int add(int index, int val){
        int pos = index;
        while(pos < c.size()){
            c[pos] += val;
            pos += lowbit(pos);
        }
    }
    
    int sum(int pos){
        int res = 0;
        while(pos > 0){
            res += c[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    NumArray(vector<int> &nums) {
        arr = nums;
        c.resize(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++){
            add(i+1,nums[i]);
        }
    }

    void update(int i, int val) {
        int old = arr[i];
        int delta = val - old;
        arr[i] = val;
        add(i+1, delta);
    }

    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
