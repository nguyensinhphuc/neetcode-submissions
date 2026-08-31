class Twitter {
private:
    // following[u] = những user mà u đang follow
    unordered_map<int, unordered_set<int>> following;

    // tweets[u] = danh sách tweet của user u
    // pair = {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    int time = 0;

public:
    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        time++;

        tweets[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> allTweets;

        // Lấy tweet của chính user
        for (auto tweet : tweets[userId]) {
            allTweets.push_back(tweet);
        }

        // Lấy tweet của những người đang follow
        for (int followeeId : following[userId]) {
            for (auto tweet : tweets[followeeId]) {
                allTweets.push_back(tweet);
            }
        }

        // Tweet mới nhất đứng trước
        sort(allTweets.begin(), allTweets.end(),
             [](const pair<int, int>& a,
                const pair<int, int>& b) {
                 return a.first > b.first;
             });

        vector<int> result;

        // Chỉ lấy tối đa 10 tweet
        for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
            result.push_back(allTweets[i].second);
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};