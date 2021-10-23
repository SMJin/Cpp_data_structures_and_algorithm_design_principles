#include <iostream>
#include <queue>

struct node {
	std::string postion;
	node* first;
	node* second;
};

struct org_tree {
	node* root;

	static org_tree create_org_structure(const std::string& pos) {
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}

	static node* find(node* root, const std::string& value) {
		if (root == NULL) {
			return NULL;
		}

		if (root->postion == value) {
			return root;
		}

		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL) {
			return firstFound;
		}

		return org_tree::find(root->second, value);
	}

	bool addSubordinate(const std::string& manager, const std::string& subordinate) {
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode) {
			std::cout << manager << "을(를) 찾을 수 없습니다: " << std::endl;
			return false;
		}
		
		if (managerNode->first && managerNode->second) {
			std::cout << manager << " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << std::endl;
			return false;
		}

		if (!managerNode->first) {
			managerNode->first = new node{ subordinate, NULL, NULL };
		}
		else {
			managerNode->second = new node{ subordinate, NULL, NULL };
		}

		std::cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << std::endl;

		return true;
	}

	/*
	* 전위 순회
	*/
	static void preOrder(node* start) {
		if (!start) {
			return;
		}

		std::cout << start->postion << ", ";
		preOrder(start->first);
		preOrder(start->second);
	}

	/*
	* 중위 순회
	*/
	static void inOrder(node* start) {
		if (!start) {
			return;
		}

		inOrder(start->first);
		std::cout << start->postion << ", ";
		inOrder(start->second);
	}

	/*
	* 후위 순회
	*/
	static void postOrder(node* start) {
		if (!start) {
			return;
		}

		postOrder(start->first);
		postOrder(start->second);
		std::cout << start->postion << ", ";
	}
};

int main(int argc, char* argv[]) {
	auto tree = org_tree::create_org_structure("CEO");

	tree.addSubordinate("CEO", "부사장");
	tree.addSubordinate("부사장", "IT부장");
	tree.addSubordinate("부사장", "마케팅부장");
	tree.addSubordinate("IT부장", "보안팀장");
	tree.addSubordinate("IT부장", "앱개발팀장");
	tree.addSubordinate("마케팅부장", "물류팀장");
	tree.addSubordinate("마케팅부장", "홍보팀장");
	tree.addSubordinate("부사장", "재무부장");

	std::cout << "전위 순회" << std::endl;
	tree.preOrder(tree.root);
	std::cout << std::endl;

	std::cout << "중위 순회" << std::endl;
	tree.inOrder(tree.root);
	std::cout << std::endl;

	std::cout << "후위 순회" << std::endl;
	tree.postOrder(tree.root);
	std::cout << std::endl;
}