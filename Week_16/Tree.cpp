#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;


struct Node {
    string title;                 
    int pages;                    
    vector<shared_ptr<Node>> children; 


    Node(string t, int p) : title(t), pages(p) {}
};

int countChapters(shared_ptr<Node> root) {
    return root->children.size();
}

void findLongestChapter(shared_ptr<Node> node, string& longestChapter, int& maxPages) {
    if (node->children.empty()) return;

    for (auto child : node->children) {
        if (child->pages > maxPages) {
            maxPages = child->pages;
            longestChapter = child->title;
        }
        findLongestChapter(child, longestChapter, maxPages);
    }
}

bool deleteNode(shared_ptr<Node> node, const string& targetTitle) {
    for (auto it = node->children.begin(); it != node->children.end(); ++it) {
        if ((*it)->title == targetTitle) {
            node->pages -= (*it)->pages;
            node->children.erase(it);
            return true;
        } else if (deleteNode(*it, targetTitle)) {
            node->pages -= (*it)->pages;
            return true;
        }
    }
    return false;
}

void printTree(shared_ptr<Node> node, int depth = 0) {
    for (int i = 0; i < depth; ++i) cout << "  ";
    cout << "- " << node->title << " (" << node->pages << " pages)" << endl;
    for (auto child : node->children) {
        printTree(child, depth + 1);
    }
}

int main() {
    auto book = make_shared<Node>("Book Title", 0); // Root node representing the book

    auto chapter1 = make_shared<Node>("Chapter 1", 50);
    auto chapter2 = make_shared<Node>("Chapter 2", 70);
    auto chapter3 = make_shared<Node>("Chapter 3", 40);

    auto section1 = make_shared<Node>("Section 1.1", 20);
    auto section2 = make_shared<Node>("Section 1.2", 30);

    chapter1->children.push_back(section1);
    chapter1->children.push_back(section2);

    auto section3 = make_shared<Node>("Section 2.1", 35);
    auto section4 = make_shared<Node>("Section 2.2", 35);

    chapter2->children.push_back(section3);
    chapter2->children.push_back(section4);

    book->children.push_back(chapter1);
    book->children.push_back(chapter2);
    book->children.push_back(chapter3);

    book->pages = chapter1->pages + chapter2->pages + chapter3->pages;

    cout << "Book Structure:" << endl;
    printTree(book);

    cout << "\nNumber of chapters: " << countChapters(book) << endl;

    string longestChapter = "";
    int maxPages = 0;
    findLongestChapter(book, longestChapter, maxPages);
    cout << "Longest chapter: " << longestChapter << " with " << maxPages << " pages" << endl;

    string target = "Section 1.1";
    if (deleteNode(book, target)) {
        cout << "\nDeleted section: " << target << endl;
    } else {
        cout << "\nSection not found: " << target << endl;
    }

    cout << "\nUpdated Book Structure:" << endl;
    printTree(book);

    return 0;
}
