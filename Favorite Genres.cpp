class solution {
  public:
    unordered_map<string, vector<string>> songAndGenra(unordered_map<string, vector<string>> userSongs, unordered_map<string, vector<string>> songGenres) {
        unordered_map<string, vector<string>> ret;
        unorded_map<string, string> songGenres;
        if (songGenres.size() < 1) {
            return ret;
        }

        for (auto &genre : songGenres) {
            for (auto &song : genre.second) {
                songGenres[song] = genre.first;
            }
        }
        auto genre = [](string song) { return songGenres[song]; };
        auto cmp = [](string genre1, string genre2) { return genre1 < genre2; };
        for (auto &userSong : user) {
            for_each(userSong.second.begin(), userSong.second.end(), genre);
            sort(userSong.second.begin(), userSong.second.end(), cmp);
        } // Erbo: xx, xx, xx, xx list is sorted
        unordered_map<string, unordered_map<string, int>> userGenres;

        for
    }
};