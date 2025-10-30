// #include <set>
// #include <tuple>
// #include <queue>
// #include <stack>
// #include <cstdio>
// #include <vector>
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// #include <unordered_set>
// #include <unordered_map>

// using namespace std;

// struct TupleHash {
//     template<typename T>
//     static void hash_combine(size_t& seed, const T& v) {
//         // 参考 boost::hash_combine
//         seed ^= hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//     }

//     template<typename Tuple, size_t Index = 0>
//     static void hash_tuple(size_t& seed, const Tuple& t) {
//         if constexpr (Index < tuple_size_v<Tuple>) {
//             hash_combine(seed, get<Index>(t));
//             hash_tuple<Tuple, Index + 1>(seed, t);
//         }
//     }

//     template<typename... Ts>
//     size_t operator()(const tuple<Ts...>& t) const {
//         size_t seed = 0;
//         hash_tuple(seed, t);
//         return seed;
//     }
// };

// class Router {
//     unordered_map<pair<int, int>, vector<int>> routers;

//     int memory_limit;
//     queue<tuple<int, int, int>> packet_q; // packet 队列
//     // 注：如果不想手写 TupleHash，可以用 set
//     unordered_set<tuple<int, int, int>, TupleHash> packet_set; // packet 集合
//     unordered_map<int, pair<vector<int>, int>> dest_to_timestamps; // destination -> ([timestamp], head)

// public:
//     Router(int memoryLimit) {
//         memory_limit = memoryLimit;
//     }

//     bool addPacket(int source, int destination, int timestamp) {
//         auto packet = tuple(source, destination, timestamp);
//         if (!packet_set.insert(packet).second) { // packet 在 packet_set 中
//             return false;
//         }
//         if (packet_q.size() == memory_limit) { // 太多了
//             forwardPacket();
//         }
//         packet_q.push(packet); // 入队
//         dest_to_timestamps[destination].first.push_back(timestamp);
//         return true;
//     }

//     vector<int> forwardPacket() {
//         if (packet_q.empty()) {
//             return {};
//         }
//         auto packet = packet_q.front(); // 出队
//         packet_q.pop();
//         packet_set.erase(packet);
//         auto [source, destination, timestamp] = packet;
//         dest_to_timestamps[destination].second++; // 队首下标加一，模拟出队
//         return {source, destination, timestamp};
//     }

//     int getCount(int destination, int startTime, int endTime) {
//         auto& [timestamps, head] = dest_to_timestamps[destination];
//         auto left = ranges::lower_bound(timestamps.begin() + head, timestamps.end(), startTime);
//         auto right = ranges::upper_bound(timestamps.begin() + head, timestamps.end(), endTime);
//         return right - left;
//     }
// };

// int main() {

//     return 0;
// }


// using pii = pair<int, int>;
// using ll = long long;
// ll MOD = 1e9 + 7;

// class Router {
// private:
//     int memoryLimit;
//     unordered_map<int, deque<ll>> memory;
//     // destination -> {timestamp<<32 | source}，保证实时更新
//     unordered_map<int, unordered_set<ll>> memorySet; //用于查找有无重复包
//     queue<tuple<int, int, int>> pq; // (source, destination, timestamp)
// public:
//     Router(int memoryLimit) {
//         this->memoryLimit = memoryLimit;
//         memory.clear();
//         memorySet.clear();
//         while (!pq.empty()) pq.pop();
//     }
    
//     bool addPacket(int source, int destination, int timestamp) {
//         // 检查是否有重复包
//         {
//             ll key = ((ll)timestamp << 32) | (ll)source;
//             if(memorySet[destination].count(key)) {
//                 return false; // 有重复包
//             }
//         }
//         // 没有重复包
//         if(pq.size() == memoryLimit) {
//             forwardPacket();
//         }
//         memory[destination].push_back(((ll)timestamp << 32) | (ll)source);
//         memorySet[destination].emplace(((ll)timestamp << 32) | (ll)source);
//         pq.emplace(source, destination, timestamp);
//         return true;
//     }
    
//     vector<int> forwardPacket() {
//         if(pq.empty()) return {};
//         auto [cur_source, cur_dest, cur_time] = pq.front();
//         // 在所有记录中删除这个包
//         memory[cur_dest].pop_front();
//         memorySet[cur_dest].erase(((ll)cur_time << 32) | (ll)cur_source);
//         pq.pop();
//         // 返回这个包的信息
//         return {cur_source, cur_dest, cur_time};
//     }
    
//     int getCount(int destination, int startTime, int endTime) {
//         auto& dq = memory[destination];+
//         // dq 中存储的是 (timestamp << 32) | source
//         // 需要找到 timestamp 在 [startTime, endTime] 范围内的数量
//         ll startKey = ((ll)startTime << 32);
//         ll endKey = ((ll)endTime << 32) | 0xFFFFFFFF; // 包含所有可能的 source
//         auto lower = lower_bound(dq.begin(), dq.end(), startKey);
//         auto upper = upper_bound(dq.begin(), dq.end(), endKey);
//         return distance(lower, upper);
//     }
// };