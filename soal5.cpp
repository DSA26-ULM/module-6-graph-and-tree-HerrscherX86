#include <bits/stdc++.h>
#include "RedBlackTree.h"
using namespace std;

void preorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& res) {
    if (node->isNil) return;
    res.push_back(node->key);
    preorder(node->left, nil, res);
    preorder(node->right, nil, res);
}

void inorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& res) {
    if (node->isNil) return;
    inorder(node->left, nil, res);
    res.push_back(node->key);
    inorder(node->right, nil, res);
}

void postorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& res) {
    if (node->isNil) return;
    postorder(node->left, nil, res);
    postorder(node->right, nil, res);
    res.push_back(node->key);
}

void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    RedBlackTree tree;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!tree.contains(x)) {
            tree.insert(x);
        }
    }

    if (tree.empty()) {
        cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
        return 0;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string type;
        cin >> type;

        vector<int> pre, in, post;

        if (type == "PREORDER" || type == "ALL") {
            preorder(tree.root(), tree.nil(), pre);
        }
        if (type == "INORDER" || type == "ALL") {
            inorder(tree.root(), tree.nil(), in);
        }
        if (type == "POSTORDER" || type == "ALL") {
            postorder(tree.root(), tree.nil(), post);
        }

        if (type == "PREORDER") {
            cout << "[Preorder]: ";
            printVector(pre);
            cout << "\n";
        } else if (type == "INORDER") {
            cout << "[Inorder]: ";
            printVector(in);
            cout << "\n";
        } else if (type == "POSTORDER") {
            cout << "[Postorder]: ";
            printVector(post);
            cout << "\n";
        } else if (type == "ALL") {
            cout << "[Preorder]: ";
            printVector(pre);
            cout << "\n";
            cout << "[Inorder]: ";
            printVector(in);
            cout << "\n";
            cout << "[Postorder]: ";
            printVector(post);
            cout << "\n";
        }
    }

    return 0;
}
