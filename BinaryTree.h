#pragma once

//TreeNode helper class!
template <typename T>
class BTreeNode {
	//public fields approach
public:
	T data;
	BTreeNode* left;
	BTreeNode* right;

	BTreeNode(T d, BTreeNode * l, BTreeNode* r) {
		data = d;
		left = l;
		right = r;
	}
	BTreeNode(T d) {
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

template <typename T>
class BinaryTree {
	//Fields
private:
	int size{ 0 };
	//BTreeNode* root{ nullptr };
public:
	//constructor
	BinaryTree() {

	}

	//Methods
	int getHeight() {
		if (height == 0) {
			return 0;
		}
		else if (height == 1) {
			return 1;
		}
		else {
			return getHeight() + 1;
		}
	}
};