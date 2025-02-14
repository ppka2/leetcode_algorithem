// have a fixed value through binary search.
class Solution {
    public:
        bool placeWithIntervalK(int k, vector<int>& position, int m) {
            int cnt = 0;
            int pre = INT_MIN;
            for (auto n : position) {
                if (n >= k + pre) {
                    cnt++;
                    pre = n;
                    //cout << pre << endl;
                }
                if (cnt >= m) {
                    return true;
                }
            }
            return false;
        }
        int maxDistance(vector<int>& position, int m) {
            sort(position.begin(), position.end());
            int l = 0;
            int lens = position.size();
            int r = position[lens - 1];
            // cout<<r<<endl;
            while (l + 1 < r) {
                int mid = (r - l) / 2 + l;
                if (placeWithIntervalK(mid, position, m)) {
                    //cout << "r" << endl;
                    l = mid;
                } else {
                    //cout << "l" << endl;
                    r = mid;
                }
            }
            return l;
        }
    };