#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                // No carry needed
                digits[i]++;
                return digits;
            }
            
            // Current digit is 9, set to 0 and carry over
            digits[i] = 0;
        }
        
        // All digits were 9, need to add 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// different approach works well if we have to add any number not just one
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;// here we have to cHANGE CARRY VALUE IF WE HAVE TO ADD ANY OTHER NUMBER
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        
        // Special case: single digit 9 becomes [1, 0]
        if (digits.size() == 1 && digits[0] == 9)
            return {1, 0};
        
        // Iterate from rightmost digit to leftmost
        for (int i = digits.size() - 1; i >= 0; i--) {
            
            // Current digit is 9 (needs carry)
            if (digits[i] >= 9) {
                v.push_back(0);  // This digit becomes 0
                
                // If this is the leftmost digit, all digits were 9
                if (i == 0) {
                    v.push_back(1);  // Add leading 1 (e.g., 999 -> 1000)
                } 
                else {
                    // Carry over to the next digit (move left)
                    digits[i - 1] = digits[i - 1] + 1;
                    
                    // Special case: if we're at position 1 and after carry, position 0 becomes 9
                    // This means we had something like [8,9] -> [9,0] -> need [1,0,0] next
                    if (i - 1 == 0 && digits[i - 1] == 9) {
                        v.push_back(9);
                        reverse(v.begin(), v.end());
                        return v;
                    }
                    
                    // If after carrying, the previous digit is still 9
                    // This means we had something like [X,8,9] -> [X,9,0] and need to continue
                    if(digits[i-1] == 9){
                        v.push_back(9);
                        // Add all remaining digits to the left
                        for(int j = i-2; j>=0; j--){
                            v.push_back(digits[j]);
                        }
                        reverse(v.begin(), v.end());
                        return v;
                    }
                }
            } 
            // Current digit is less than 9 (no carry needed)
            else {
                // If we already processed some digits (v is not empty)
                // This happens when we had trailing 9s that became 0s
                if(i != digits.size()-1){
                    // Add all remaining digits from current position to start
                    for(int j = i; j>=0; j--){
                        v.push_back(digits[j]);
                    }
                    reverse(v.begin(), v.end());
                    return v;
                }
                
                // Simple case: last digit < 9, just increment and return original array
                digits[i] = digits[i] + 1;
                return digits;
            }
        }
        
        // If we exit the loop, reverse v and return
        // This handles cases where all digits were 9
        reverse(v.begin(), v.end());
        return v;
    }
};

//my code
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        if (digits.size() == 1 && digits[0] == 9)
            return {1, 0};
        for (int i = digits.size() - 1; i >= 0; i--) {
            // test
            cout << digits[i] << "ff" << endl;
            if (digits[i] >= 9) {
                v.push_back(0);
                cout << v.back() << "fff" << endl;
                if (i == 0) {
                    cout << digits[i] << "ffff--" << endl;
                    v.push_back(1);
                } else {
                    cout << digits[i] << "ffff+" << endl;
                    digits[i - 1] = digits[i - 1] + 1;
                    cout << digits[i - 1] << "ff++" << endl;
                    if (i - 1 == 0 && digits[i - 1] == 9) {
                        cout << v.back() << "ff+++" << endl;
                        v.push_back(9);
                        reverse(v.begin(), v.end());
                        return v;
                    }
                    if(digits[i-1]==9){
                        v.push_back(9);
                        for(int j = i-2; j>=0;j--){
                            v.push_back(digits[j]);
                        }
                        reverse(v.begin(), v.end());
                        return v;
                    }
                }
            } else {
                if(i != digits.size()-1){
                    for(int j = i; j>=0;j--){
                            v.push_back(digits[j]);
                        }
                        reverse(v.begin(), v.end());
                        return v;
                }
                digits[i] = digits[i] + 1;
                return digits;
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};