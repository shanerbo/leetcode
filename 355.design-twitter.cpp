/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 *
 * https://leetcode.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (28.37%)
 * Likes:    603
 * Dislikes: 151
 * Total Accepted:    40.4K
 * Total Submissions: 142K
 * Testcase Example:  '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * Design a simplified version of Twitter where users can post tweets,
 * follow/unfollow another user and is able to see the 10 most recent tweets in
 * the user's news feed. Your design should support the following methods:
 * 
 * 
 * 
 * postTweet(userId, tweetId): Compose a new tweet.
 * getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's
 * news feed. Each item in the news feed must be posted by users who the user
 * followed or by the user herself. Tweets must be ordered from most recent to
 * least recent.
 * follow(followerId, followeeId): Follower follows a followee.
 * unfollow(followerId, followeeId): Follower unfollows a followee.
 * 
 * 
 * 
 * Example:
 * 
 * Twitter twitter = new Twitter();
 * 
 * // User 1 posts a new tweet (id = 5).
 * twitter.postTweet(1, 5);
 * 
 * // User 1's news feed should return a list with 1 tweet id -> [5].
 * twitter.getNewsFeed(1);
 * 
 * // User 1 follows user 2.
 * twitter.follow(1, 2);
 * 
 * // User 2 posts a new tweet (id = 6).
 * twitter.postTweet(2, 6);
 * 
 * // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
 * // Tweet id 6 should precede tweet id 5 because it is posted after tweet id
 * 5.
 * twitter.getNewsFeed(1);
 * 
 * // User 1 unfollows user 2.
 * twitter.unfollow(1, 2);
 * 
 * // User 1's news feed should return a list with 1 tweet id -> [5],
 * // since user 1 is no longer following user 2.
 * twitter.getNewsFeed(1);
 * 
 * 
 */

// @lc code=start
class Twitter {
  private:
    struct User {
        int userId;
        vector<pair<int, int>> tweets;
        vector<User *> follower;
        vector<User *> following;
        User(int _userid, pair<int, int> _pair) {
            userId = _userid;
            tweets.push_back(_pair);
        }
        User(int _userid) {
            userId = _userid;
        }
    };
    unordered_map<int, User *> twitter; // <userId, user DataStructure>

  public:
    /** Initialize your data structure here. */
    Twitter() {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (twitter.find(userId) == twitter.end()) {
            User *user = new User(userId, make_pair(userId, tweetId));
            twitter[userId] = user;
        } else {
            User *user = twitter[userId];
            pair<int, int> tweet = make_pair(userId, tweetId);
            user->tweets.push_back(tweet);
            for (auto follower : user->follower) {
                follower->tweets.push_back(tweet);
            }
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> tweets;
        if (twitter.find(userId) == twitter.end())
            return {};
        User *user = twitter[userId];
        auto userTweets = user->tweets;
        // auto cmp = [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; };
        // sort(userTweets.begin(), userTweets.end(), cmp);
        int len = userTweets.size() >= 10 ? 10 : userTweets.size();
        for (int i = userTweets.size() - 1; len > 0; --i, --len) {
            tweets.push_back(userTweets[i].second);
        }
        return tweets;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void
    follow(int followerId, int followeeId) {
        if (twitter.find(followeeId) == twitter.end()) {
            User *user = new User(followeeId);
            twitter[followeeId] = user;
        }
        if (twitter.find(followerId) == twitter.end()) {
            User *user = new User(followerId);
            twitter[followerId] = user;
        }
        twitter[followeeId]->follower.push_back(twitter[followerId]);
        twitter[followerId]->following.push_back(twitter[followeeId]);
        for (auto t : twitter[followeeId]->tweets) {
            twitter[followerId]->tweets.push_back(t);
        }
        // auto cmp = [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; };
        // sort(twitter[followerId]->tweets.begin(), twitter[followerId]->tweets.end(), cmp);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto *user = twitter[followerId];
        auto following = user->following;
        for (auto it = following.begin(); it != following.end();) {
            if ((*it)->userId == followeeId) {
                following.erase(it);
            } else {
                it++;
            }
        }

        auto *tweets = &user->tweets;
        for (auto it = tweets->begin(); it != tweets->end();) {
            if ((*it).first == followeeId) {
                tweets->erase(it);
                // cout << (*it).second << endl;
            } else {
                it++;
            }
        }

        auto *user2 = twitter[followeeId];
        auto following2 = user->following;
        for (auto it = following2.begin(); it != following2.end();) {
            if ((*it)->userId == followerId) {
                following2.erase(it);
            } else {
                it++;
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
