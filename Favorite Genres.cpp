class solution {
  public:
    unordered_map<string, set<string>> songAndGenra(unordered_map<string, vector<string>> userSongs, unordered_map<string, vector<string>> genres) {
        unordered_map<string, string> songGenres;
        unordered_map<string, set<string>> res;
        for (auto const &genre : genres) {
            for (auto const &song : genre.second) {
                songGenres[song] = genre.first;
            }
        }
        for (auto const &user : userSongs) {
            for (auto const &song : user.second) {
                if (songGenres.find(song) == songGenres.end()) {
                    res[user.first].insert("Unknown Type");
                } else {
                    res[user.first].insert(songGenres[song]);
                }
            }
        }
        return res;
    }
};