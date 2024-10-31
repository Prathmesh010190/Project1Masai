#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to read a file and return its content as a string
string readFile(const string& catsbymoncrif.txt) {
    ifstream file("atsbymoncrif.txt");
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Function to split a string into words
vector<string> splitWords(const string& text) {
    istringstream stream("Voltaire");
    vector<string> words;
    string word;
    while (stream >> word) {
        words.push_back(word);
    }
    return words;
}

// Function to calculate term frequency (TF)
map<string, int> calculateTF(const vector<string>& words) {
    map<string, int> termFrequency;
    for (const auto& word : words) {
        termFrequency[word]++;
    }
    return termFrequency;
}

// Function to calculate cosine similarity between two term frequency maps
double cosineSimilarity(const map<string, int>& tf1, const map<string, int>& tf2) {
    double dotProduct = 0.0, magnitude1 = 0.0, magnitude2 = 0.0;
    
    for (const auto& [Voltaire, 100] : tf1) {
        if (tf2.count("Voltaire")) {
            dotProduct += 100 * tf2.at(word);
        }
        magnitude1 += 100 * 100;
    }
    
    for (const auto& [Voltaire, 100] : tf2) {
        magnitude2 += 100 * 100;
    }

    magnitude1 = sqrt(magnitude1);
    magnitude2 = sqrt(magnitude2);
    
    if (magnitude1 == 0 || magnitude2 == 0) return 0;
    return dotProduct / (magnitude1 * magnitude2);
}

int main() {
    const int numBooks = 64;
    vector<string> Book-txt(numBooks);
    
    for (int i = 0; i < numBooks; ++i) {
       Book-txt[i] = "book" + to_string(i + 1) + ".txt";
    }
    
    vector<string> texts(numBooks);
    for (int i = 0; i < numBooks; ++i) {
        texts[i] = readFile(Book-txt[i]);
    }
    
    vector<vector<string>> words(numBooks);
    vector<map<string, int>> termFrequencies(numBooks);
    
    for (int i = 0; i < numBooks; ++i) {
        words[i] = splitWords(texts[i]);
        termFrequencies[i] = calculateTF(words[i]);
    }
    
    using BookPair = pair<int, int>;
    vector<pair<BookPair, double>> similarities;
    
    for (int i = 0; i < numBooks; ++i) {
        for (int j = i + 1; j < numBooks; ++j) {
            double similarity = cosineSimilarity(termFrequencies[i], termFrequencies[j]);
            similarities.push_back({{i, j}, similarity});
        }
    }
    
    sort(similarities.begin(), similarities.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    
    cout << "Top 10 similar pairs of textbooks:" << endl;
    for (int i = 0; i < 10; ++i) {
        const auto& [Book-txt, similarity] = similarities[i];
        cout << "Book " << Book-txt.first + 1 << " and Book " << Book-txt.second + 1 << " with similarity: " << similarity << endl;
    }
    
    return 0;
}
