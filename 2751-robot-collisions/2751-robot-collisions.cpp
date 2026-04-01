class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // {position, health, direction, original index}
        vector<tuple<int,int,char,int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        // Sort by position
        sort(robots.begin(), robots.end());
        
        stack<int> st;
        vector<int> h(n);
        
        for(int i = 0; i < n; i++) {
            h[i] = get<1>(robots[i]);
        }
        
        for(int i = 0; i < n; i++) {
            if(get<2>(robots[i]) == 'R') {
                st.push(i);
            } else {
                while(!st.empty() && h[i] > 0) {
                    int j = st.top();
                    
                    if(h[j] == h[i]) {
                        h[j] = 0;
                        h[i] = 0;
                        st.pop();
                        break;
                    }
                    else if(h[j] > h[i]) {
                        h[j]--;
                        h[i] = 0;
                        break;
                    }
                    else {
                        h[i]--;
                        h[j] = 0;
                        st.pop();
                    }
                }
            }
        }
        
        vector<int> res(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(h[i] > 0) {
                int idx = get<3>(robots[i]);
                res[idx] = h[i];
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(res[i] > 0) ans.push_back(res[i]);
        }
        
        return ans;
    }
};