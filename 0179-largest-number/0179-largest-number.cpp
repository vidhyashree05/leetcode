class Solution {
public:
    static bool compare(string a, string b) {
        return a + b > b + a;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        
        // Convert all numbers to strings
        for (int num : nums) {
            arr.push_back(to_string(num));
        }
        
        // Custom sort
        sort(arr.begin(), arr.end(), compare);
        
        // Edge case: if largest is "0"
        if (arr[0] == "0") 
            return "0";
        
        // Concatenate result
        string result = "";
        for (string s : arr) {
            result += s;
        }
        
        return result;
    }
};
