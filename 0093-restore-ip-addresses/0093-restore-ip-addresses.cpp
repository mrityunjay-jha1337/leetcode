class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        stack<pair<int, pair<int, string>>> st;

        st.push({0, {0, ""}});

        while (!st.empty()) {
            auto curr = st.top();
            st.pop();

            int index = curr.first;
            int parts = curr.second.first;
            string ip = curr.second.second;

            if (parts == 4) {
                if (index == s.size()) {
                    ip.pop_back();
                    ans.push_back(ip);
                }
                continue;
            }

            for (int len = 1; len <= 3; len++) {
                if (index + len > s.size()) {
                    break;
                }

                string part = s.substr(index, len);
                int num = stoi(part);

                if (len > 1 && part[0] == '0') {
                    continue;
                }

                if (num > 255) {
                    continue;
                }

                st.push({
                    index + len,
                    {parts + 1, ip + part + "."}
                });
            }
        }

        return ans;
    }
};